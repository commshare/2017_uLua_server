#include "stdafx.h"
#include "logic_room.h"
#include "Landlord_RoomCFG.h"
#include "logic_player.h"
#include "game_db.h"
#include "game_engine.h"
#include "i_game_ehandler.h"
#include <enable_random.h>
#include "game_db_log.h"
#include "msg_type_def.pb.h"
#include <math.h>

using namespace std;

static const int MAX_TABLE_COUNT = 10000;
static const int MAX_ROBOT_COUNT = 10;

logic_room::logic_room(const Landlord_RoomCFGData* cfg, logic_lobby* _lobby):robCount(0),createRob_time(0)
{
	m_cfg = cfg;
	m_lobby = _lobby;

	logic_room_db::init_game_object();
	m_db_room_id->set_value(m_cfg->mRoomID);
	if(!load_room())
	{
		create_room();
	}

	for (int i = 1; i < 10; i++)
	{
		LTablePtr table = boost::make_shared<logic_table>(this,i);
		tableMap[i] = table;
	}
}

logic_room::~logic_room(void)
{
	
}

void logic_room::heartbeat(double elapsed)
{
	for (auto& var : tableMap)
	{
		var.second->heartbeat(elapsed);
	}

	if (robCount < MAX_ROBOT_COUNT)
	{
		if (createRob_time > 1.0)
		{
			game_engine::instance().request_robot(m_db_room_id->get_value(), global_random::instance().rand_int(10000, 100000), global_random::instance().rand_int(0, 3));
			createRob_time = 0.0;
		}
		createRob_time += elapsed;
	}
}

uint16_t logic_room::get_room_id()
{
	return m_cfg->mRoomID;
}

e_server_error_code logic_room::enter_room(LPlayerPtr player)
{
	if (playerMap.find(player->get_pid()) != playerMap.end())
		return e_error_code_failed;

	if (playerMap.size() >= 10000)		//��������
		return e_error_code_failed;;

	if (!player->enter_room(this))
		return e_error_code_failed;

	if (player->is_robot())
	{
		robCount++;
		SLOG_CRITICAL << "�����˼��뷿��" << std::endl;
	}
	
	playerMap.insert(std::make_pair(player->get_pid(), player));

	return enter_table(player);
}

e_server_error_code logic_room::leave_room(uint32_t playerid)
{
	auto it = playerMap.find(playerid);
	if(it == playerMap.end())
	{
		return e_error_code_success;
	}

	if (it->second->is_robot())
	{
		robCount--;
		SLOG_CRITICAL << "�������뿪����" << std::endl;
	}

	playerMap.erase(it);

	return e_error_code_success;
}

const Landlord_RoomCFGData* logic_room::get_room_cfg() const
{
	return m_cfg;
}

e_server_error_code logic_room::enter_table(LPlayerPtr player)
{
	logic_table* table = nullptr;
	for (auto var : tableMap)
	{
		if (var.second->get_table_state()==TableState_Prepare)
		{
			table= var.second.get();
			break;
		}
	}

	for (auto var : tableMap)
	{
		if (var.second->get_table_state() == TableState_None)
		{
			table = var.second.get();
			break;
		}
	}

	if (tableMap.size() == MAX_TABLE_COUNT)
	{
		return e_error_code_failed;
	}

	if (table == nullptr)
	{
		vector<int32_t> tableIdList;
		for (int i = 1; i < MAX_TABLE_COUNT; i++)
		{
			if (tableMap.find(i) == tableMap.end())
			{
				tableIdList.push_back(i);
				if (tableIdList.size() == tableMap.size())
				{
					break;
				}
			}

		}
		for (auto& v : tableIdList)
		{
			LTablePtr table1 = boost::make_shared<logic_table>(this,v);
			tableMap.insert(std::make_pair(v,table1));
		}

		table = tableMap[tableIdList[0]].get();
	}

	e_server_error_code code= table->enter_table(player);
	return code;
}

void logic_room_db::create_room()
{



}

//����������Ҫ���浽���ݿ��
bool logic_room_db::load_room()
{
	mongo::BSONObj b = db_game::instance().findone(DB_LANDLORD_ROOM, BSON("room_id" << m_db_room_id->get_value()));
	//����տ�ʼ������û���������
	if (b.isEmpty())
		return false;
	return from_bson(b);
}

void logic_room_db::init_game_object()
{
	m_db_room_id = CONVERT_POINT(Tfield<int16_t>, regedit_tfield(e_got_int16, "room_id"));
}

bool logic_room_db::store_game_object(bool to_all)
{
	if (!has_update())
		return true;

	auto err = db_game::instance().update(DB_LANDLORD_ROOM, BSON("room_id" << m_db_room_id->get_value()), BSON("$set" << to_bson(to_all)));
	if (!err.empty())
	{
		SLOG_ERROR << "logic_room::store_game_object :" << err;
		return false;
	}

	return true;
}







#include "stdafx.h"
#include "game_engine.h"
#include <i_game_engine.h>
#include <i_game_ehandler.h>
#include "logic_lobby.h"
#include "game_db.h"
#include "game_db_log.h"
#include <i_game_player.h>

game_engine::game_engine(void)
{
	
}


game_engine::~game_engine(void)
{
}

static const uint16_t GAME_ID = 14;
static const uint32_t GAME_VER = 1;

//----------------------------------------------------------------------------------
//��ʼ������
bool game_engine::init_engine(enable_xml_config& config)
{
	if(get_handler() == nullptr)
		return false;	

	std::string filename = config.get<std::string>("game_dll");
	size_t npos = filename.find_last_of('/');
	if(npos != std::string::npos)
		filename = filename.erase(0, npos+1);
	npos = filename.find_last_of('.');
	if(npos != std::string::npos)
		filename = filename.erase(npos);
	com_log::InitLog(filename);

	init_db(config);

	m_lobby.init_game();	

	std::string game_ver = config.get_ex<std::string>("game_ver", "1.0.0");
	get_handler()->on_init_engine(GAME_ID, game_ver);
	return true;
}

uint16_t game_engine::get_gameid()
{
	return GAME_ID;
}

//ÿ֡����
void game_engine::heartbeat( double elapsed )
{
	m_lobby.heartbeat(elapsed);
}

//�˳�����
void game_engine::exit_engine()
{
	m_lobby.release_game();
	//SLOG_CRITICAL<<"��������"<<std::endl;
	if(get_handler() != nullptr)
		get_handler()->on_exit_engine();

	com_log::flush();
}

//��ҽ�����Ϸ
bool game_engine::player_enter_game(iGPlayerPtr igplayer)
{
	//std::cout<<"Player Enter Game"<<std::endl;
	return m_lobby.player_enter_game(igplayer);
}

//����뿪��Ϸ
void game_engine::player_leave_game(uint32_t playerid, bool bforce)
{
	//std::cout<<"Player Leave Game"<<std::endl;
	m_lobby.player_leave_game(playerid);
}

int game_engine::player_join_friend_game(iGPlayerPtr igplayer, uint32_t friendid)
{
	//std::cout<<"Player Join Friend Game"<<std::endl;
	int ret = m_lobby.player_join_friend_game(igplayer, friendid);
	if(ret != 1)
		m_lobby.player_leave_game(igplayer->get_playerid());

	return ret;
}

void game_engine::init_db(enable_xml_config& xml_cfg)
{
	if(xml_cfg.check("gamedb_url") && xml_cfg.check("gamedb_name"))
	{
		db_game::instance().init_db(xml_cfg.get<std::string>("gamedb_url"), xml_cfg.get<std::string>("gamedb_name"));
	}

	if(xml_cfg.check("logdb_url") && xml_cfg.check("logdb_name"))
	{
		db_log::instance().init_db(xml_cfg.get<std::string>("logdb_url"), xml_cfg.get<std::string>("logdb_name"));
	}
}

//����һ�������� ���صĻ�����δ���뷿�䣿
void game_engine::response_robot(int32_t playerid, int tag)
{
	std::cout<<"����һ�������ˣ�PID:"<<playerid<<"TAG:"<<tag<<std::endl;
	m_lobby.response_robot(playerid, tag);
	
}
//--------------------------------------------------------------------------------------------


//����һ��������
void game_engine::request_robot(int tag, int needgold, int needvip)
{
	//std::cout<<"����һ��������: TAG:"<<tag<<std::endl;
	get_handler()->request_robot(tag, needgold, needvip);
}


void  game_engine::release_robot(int32_t playerid)
{
	//std::cout<<"����һ��������: PID:"<<playerid<<std::endl;
	get_handler()->release_robot(playerid);
}
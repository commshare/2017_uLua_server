#pragma once
#include <enable_singleton.h>
#include <enable_hashmap.h>
#include <string>
#include <vector>
#include "game_def.h"

class game_player;
class game_player_mgr
	:public enable_singleton<game_player_mgr>
{
public:
	game_player_mgr();
	virtual ~game_player_mgr();

	boost::shared_ptr<game_player> find_player(const std::string& acc);
	boost::shared_ptr<game_player> find_player(uint32_t sessionid);

	boost::shared_ptr<game_player> findPlayerById(int playerId);

	bool add_player(boost::shared_ptr<game_player> p);

	// ��ҵ�½�ɹ������Ҵ�Logicͬ���������ݺ����
	bool addPlayerById(boost::shared_ptr<game_player> p);

	void remove_player(boost::shared_ptr<game_player> p);
	void reset_player(boost::shared_ptr<game_player> p, uint32_t sessionid);
	void remove_session(uint32_t sessionid);
	void heartbeat(double elapsed);

	void set_del_player(boost::shared_ptr<game_player> p);

	uint32_t generic_playerid();

	void leave_game(uint16_t gameserverid);

	ENABLE_MAP<std::string, GPlayerPtr>& get_player_map()
	{
		return m_playersbyacc;
	}

	// һ����ҽ�����Ϸ
	void onEnterGame(int gameId);

	// һ������˳���Ϸ
	void onExitGame(int gameId);

	//������Ϸ
	void onClearGame(int gameId);

	// ������Ϸ��������
	int getOnlineNumInGame(int gameId);

	void set_close_state();

#ifdef _DEBUG
	void clear()
	{
		m_playersbyacc.clear();
		m_playersbysid.clear();
		m_dellist.clear();
		m_playerById.clear();
	}
#endif
private:
	ENABLE_MAP<std::string, boost::shared_ptr<game_player>> m_playersbyacc;
	ENABLE_MAP<uint32_t, boost::shared_ptr<game_player>> m_playersbysid;

	//ENABLE_MAP<uint32_t, boost::shared_ptr<game_player>> m_dellist;
	std::list<boost::shared_ptr<game_player>> m_dellist;

	ENABLE_MAP<int32_t, boost::shared_ptr<game_player>> m_playerById;

	uint32_t m_cur_playerid;
	double m_checktime;

	// ������Ϸ����������, ��ϷID->����
	ENABLE_MAP<int32_t, int> m_onlineNum;

	void log_playercount(int count = 0);

	void check_kickplayer();

	bool b_closing;
	void server_closing(double elapsed);

	std::vector<int32_t> m_kicklist;
};

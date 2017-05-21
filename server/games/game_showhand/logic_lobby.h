#pragma once
#include "logic_def.h"
#include <i_game_def.h>

SHOWHAND_SPACE_BEGIN

class logic_lobby {
public:
	logic_lobby(void);
	~logic_lobby(void);

	void init_game(int count);
	void release_game();

	void heartbeat( double elapsed );
//---------------------�����������
	bool logic_lobby::player_enter_game(iGPlayerPtr igplayer);
	void logic_lobby::player_leave_game(uint32_t playerid);
    int player_join_friend_game(iGPlayerPtr, int);

//-------------------------------------------------------------


	const LROOM_MAP& get_rooms();
    LRoomPtr get_room(int32_t rid);
	LPlayerPtr get_player(uint32_t pid);

	void response_robot(int32_t playerid, int tag);



private:
	void init_config();
	void init_protocol();

	LROOM_MAP m_rooms;//���з���
	LPLAYER_MAP m_all_players;//�������

	bool m_init;
	int m_max_player;
};

SHOWHAND_SPACE_END
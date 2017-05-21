#pragma once
#include "game_sys_def.h"

struct PassCFGData;
class game_battle_player;
class game_sys_vip;

// ��̨����ϵͳ
class GmSys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_gm);

	virtual void init_sys_object();

	/*
			��ҵ�¼
	*/
	void onPlayerLogin(game_player* player, bool isReLoadPlayerData);
private:
	void _payRMB(game_player* player, int payId);

	void _delIconCustom(game_player* player, time_t deadTime);
};





#pragma once

#include <enable_singleton.h>
#include "i_game_engine.h"
#include "logic_lobby.h"
#include <enable_xml_config.h>

class game_engine :
	public i_game_engine
	,public enable_singleton<game_engine>
{
public:
	game_engine(void);
	virtual ~game_engine(void);

	//��ʼ������
	virtual bool init_engine(enable_xml_config& config);

	//ÿ֡����
	virtual void heartbeat( double elapsed );

	//�˳�����
	virtual void exit_engine();

	//////////////////////////////////////////////////////////////////////////
	//������֪ͨ��Ϸ�߼�
	//��ҽ�����Ϸ
	virtual bool player_enter_game(iGPlayerPtr igplayer);

	//����뿪��Ϸ
	virtual void player_leave_game(uint32_t playerid, bool bforce = false);

	//��ҽ�����ѵ�����
	virtual int player_join_friend_game(iGPlayerPtr igplayer, uint32_t friendid);

	showhand_space::logic_lobby& get_lobby();

	virtual uint16_t game_engine::get_gameid();

	//����һ�������� ���صĻ�����δ���뷿�䣿
	virtual void response_robot(int32_t playerid, int tag);
	//����һ��������
	void request_robot(int tag, int needgold, int needvip = 0);
	//�ͷŻ�����
	void release_robot(int32_t playerid);
private:
	showhand_space::logic_lobby m_lobby;

	void init_db(enable_xml_config& xml_cfg);
};
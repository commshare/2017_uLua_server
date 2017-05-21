#pragma once
#include "logic_def.h"
#include <i_game_def.h>
#include "logic_room.h"

class logic_lobby
{
public:
	logic_lobby(void);
	~logic_lobby(void);

	void init_game();					//��Ϸ��ʼ��	//��Ϸ������������
	void release_game();							//ж����Ϸ	//�����������
	void heartbeat( double elapsed );				//��Ϸѭ��

	bool player_enter_game(iGPlayerPtr igplayer);	//��ҽ�����Ϸ
	void player_leave_game(uint32_t playerid);		//����뿪��Ϸ
	int player_join_friend_game(iGPlayerPtr igplayer, uint32_t friendid);	//������ѷ���

	//�����˽��뷿��
	int enter_room(uint32_t pid, uint16_t rid);		//����
	void leave_room(uint32_t pid);					//�뿪����

	void response_robot(int32_t playerid, int tag);

	const LROOM_MAP& get_rooms() const;				//�õ����з�����Ϣ
	LPlayerPtr& get_player(uint32_t pid);			//���������Ϣ
private:
	void init_config();				//��������
	void init_protocol();			//����Э��
	void init_room();			//��ʼ������
private:
	bool m_init;					//�Ƿ��ѳ�ʼ��
	int m_max_player;				//�����������

	LROOM_MAP roomMap;				//���з���
	LPLAYER_MAP playerMap;		//�������
};

#pragma once
#include "logic_def.h"
#include <i_game_def.h>

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
	int enter_room(uint32_t pid, uint16_t rid);		//��������
	void leave_room(uint32_t pid);					//�뿪����

	// ���ӷ��������루������Ѻע��ң�
	void addTodayIncome(int roomId, GOLD_TYPE addValue)
	{
		if(roomId >= 1 && roomId <= 4)
		{
			TempTodayIncomeArr[roomId - 1] += addValue;
			TempTodayIncome += addValue;
		}
	}

	// ���ӷ�����֧��
	void addTodayOutlay(int roomId, GOLD_TYPE/*int*/ addValue)
	{
		if(roomId >= 1 && roomId <= 4)
		{
			TempTodayOutlayArr[roomId - 1] += addValue;
			TempTodayOutlay += addValue;
		}
	}

	void response_robot(int32_t playerid, int tag);

	const LROOM_MAP& get_rooms() const;				//�õ����з�����Ϣ
	LPlayerPtr& get_player(uint32_t pid);			//���������Ϣ

	void save_cache();		//ͳ�Ƶ�������
private:
	void init_config();				//��������
	void init_protocol();			//����Э��
	void init_room();			//��ʼ������

	void resetToday();
	int64_t getTodayIncome(int roomId){ return TempTodayIncomeArr[roomId - 1];}
	int64_t getTodayOutlay(int roomId){return TempTodayOutlayArr[roomId - 1];}
private:
	bool m_init;					//�Ƿ��ѳ�ʼ��
	int m_max_player;				//�����������

	int64_t TempTodayOutlayArr[4];	// ���շ���洢�ĵ�������
	int64_t TempTodayIncomeArr[4];	// ���շ���洢�ĵ�������

	int64_t TempTodayOutlay;	//��ʱ��������
	int64_t TempTodayIncome;	//��ʱ��������

	LROOM_MAP roomMap;				//���з���
	LPLAYER_MAP playerMap;		//�������

	double m_check_cache;
};

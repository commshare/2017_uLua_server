#pragma once
#include <enable_hashmap.h>
#include <enable_queue.h>
#include <game_macro.h>

//struct idle_robot
//{
//	int playerid;
//	int vip;
//	int gold;
//	double elapsed;
//};

class robot_manager
{
public:
	robot_manager();
	~robot_manager();

	//���������  ����-1Ϊ��Ҫ��world�����»�����
	int request_robot(int tag, GOLD_TYPE needgold, int needvip);

	//�ͷŻ�����
	void release_robot(int playerid);
	
	int get_count();
	void inc_robot();
	void heartbeat(double elapsed);

	int pop_tag();
	void set_gameid(int gameid);
private:
	//ENABLE_MAP<int, idle_robot> m_idlelist;		//�����б�
	enable_queue<int> m_reqlist;		//�������
	int m_gameid;
	void leave_robot(int playerid);
	std::vector<int> m_dellist;
	int m_count;
};
#pragma once
#include "game_sys_def.h"
#include "game_def.h"
#include <list>

struct idle_robot
{
public:
	int playerid;
	int vip;
	GOLD_TYPE gold;
};


// �����˹���ϵͳ
class RobotsSys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_robots);

	RobotsSys();


	virtual void init_sys_object();

	//��������
	virtual bool sys_load();

	GPlayerPtr request_robot(GOLD_TYPE needgold, int needvip = 0);
	void release_robot(int playerid, int vip, GOLD_TYPE gold);
	int get_count();
private:
	std::list<idle_robot> m_robots;//���л�����id
	int m_robotcount;
};





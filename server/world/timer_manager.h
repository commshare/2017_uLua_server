#pragma once
#include <enable_singleton.h>
#include "enable_hashmap.h"

struct stTimerInfo
{
	int m_clock;
	boost::function<void()> m_call;
	int m_count;
};

class timer_manager:
	public enable_singleton<timer_manager>
{
public:
	timer_manager();
	~timer_manager();

	void init_timer(); 

	// ע��һ����ʱ��, clock���ռ��㴥��, callBack����ʱ�ص�������count��������,-1��ʾ����
	bool regTimer(int clock, boost::function<void()> callBack, int count = -1);

private:
	void start_daily_check();
	void on_daily_check();

	int _getSeconds(int clock);

	void _happen(int id);

private:
	ENABLE_MAP<int, stTimerInfo> m_timers;
	int m_timerId;
};

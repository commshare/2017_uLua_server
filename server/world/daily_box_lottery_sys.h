#pragma once
#include "game_sys_def.h"
#include "M_DialLotteryCFG.h"
#include "probability.h"
struct M_OnlineRewardCFGData;
struct OnlineRewardInfo;

// ÿ�ձ���齱ϵͳ
class DailyBoxLotterySys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_daily_box_lottery);

	virtual void init_sys_object();

	void resetBoxLottery();

	/*
			���߽�����̬����
	*/
	const OnlineRewardInfo* getOnlineRewardData(boost::posix_time::ptime& curPtime);
private:
	void _loadOnlineRewardData();
private:
	std::vector<OnlineRewardInfo> m_onlineRewardData;
};

struct OnlineRewardInfo
{
	const M_OnlineRewardCFGData *m_data;

	boost::posix_time::time_duration m_start;
	boost::posix_time::time_duration m_end;
};



#pragma once
#include "game_sys_def.h"

class game_player;

// ǩ�����
struct stSignResult
{
	// �Ƿ����¿�����
	bool m_hasMonthCardReward;

	// �鵽��ת�̱�ţ�ֻ�е���7���Ժ����ֵ��������
	int m_dialNum;

	void reset()
	{
		m_hasMonthCardReward = false;
		m_dialNum = -1;
	}
};

// ת�̳齱����
class DialLotteryMgr : public enable_obj_pool<DialLotteryMgr>, public game_sys_base
{
public:
	DialLotteryMgr();

	~DialLotteryMgr();

	MAKE_SYS_TYPE(e_gst_dial_lottery);

	MAKE_GET_OWNER(game_player);

	virtual void init_sys_object();

	/*
			�����Ƿ��ѳ����
	*/
	bool isLotteryToday();

	/*
			ǩ��
	*/
	int doSign(time_t curTime);

	/*
			����������ǩ������
	*/
	int getHasSignCount(boost::gregorian::date& curDate);

	/*
			�����Ƿ���ȡ���¿�����
	*/
	bool hasReceiveMonthCardReward(boost::gregorian::date& curDate);

	/*
			��ȡ�¿�����
	*/
	int receiveMonthCardReward(time_t curTime);

	// ����ǩ�����
	stSignResult* getSignResult(){ return &m_signResult; }
private:
	void _monthCardReward(time_t curTime, game_player *player);

	/*
			��ʼת�̳齱
			num		���ر��
			����ֵ����ֵ e_msg_result_def����
	*/
	int _doLottery(int& num, game_player *player);

	bool _isLotteryToday(boost::gregorian::date& curDate);
public:
	// �齱ʱ��
	Tfield<time_t>::TFieldPtr LotteryTime;	

	// ������ǩ������
	Tfield<int32_t>::TFieldPtr m_hasSignCount;

	// �ϴ��¿���������ȡʱ��
	Tfield<time_t>::TFieldPtr MonthCardRewardReceiveTime;	
private:
	stSignResult m_signResult;
};


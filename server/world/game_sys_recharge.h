#pragma once
#include "game_sys_def.h"
#include <enable_object_pool.h>
struct M_RechangeCFGData;

enum e_vip_type
{
	e_evt_OnlineReward,         // ���߽�������ȡ����
	e_evt_MaxGiftslimit,        // ÿ��������������
	e_evt_MaxBoxLotterylimit,   // ÿ�ձ���齱
};

class game_sys_recharge : public game_sys_base
	,public enable_obj_pool<game_sys_recharge>
{
public:
	game_sys_recharge();
	virtual ~game_sys_recharge();
	
	MAKE_SYS_TYPE(e_gst_recharge);
	MAKE_GET_OWNER(game_player);

	virtual void init_sys_object();

	// isGmOp�Ƿ�gm��̨��
	void payment_once(int payid, int rmb = 0, bool isGmOp = false, bool payment_lottery = false);

	void payment_once(const std::string& orderid, int pay_type, int pay_value, int rmb = 0);

	int shopping(int shopid);

	int getVipProfit(e_vip_type viptype);

	GOLD_TYPE getMaxLimit();

	/*
			��ȡ��ֵ����
	*/
	int recvRechargeReward();

	/*
			�����¿�ʣ������
	*/
	int getMonthCardRemainSecondTime();

	int getMonthCardRemainSecondTime(time_t curTime);

	/*
			VIP����������
	*/
	void addVipCardDays(int days, bool save);

	bool isBuyItem(int32_t payid);

public:
	Tfield<int16_t>::TFieldPtr		VipLevel;		    //VIP�ȼ�
	Tfield<int32_t>::TFieldPtr		VipExp;		        //VIP����
	Tfield<time_t>::TFieldPtr		VipCardEndTime;		//vip������ʱ��
	GArrayFieldPtr					PaymentCheck;		//֧�����
	Tfield<int32_t>::TFieldPtr		Recharged;			//�ۼƳ�ֵ���
	Tfield<int16_t>::TFieldPtr		LotteryCount;		//�ۼƳ齱����
	// �Ƿ���ȡ����ֵ������ǣ�ֻҪ���ֵ�Ϳ�����ȡһ�ν�������ֻ����ȡһ��
	Tfield<bool>::TFieldPtr			RechargeRewardFlag; 
private:
	void addVipExp(uint32_t exp);

	void _joinMemberMail();

	void _notifygame();

	int _sendMail(int playerId, const std::string& title, const std::string& content);

	time_t m_last_recharge;
	int m_last_payid;

	int _lottery(int payid);
	
	// ���ͳ齱ͨ��
	void _sendLotteryNotice(int rate);

	// ��ֵͨ��
	void _sendReChargeNotice(const M_RechangeCFGData *data);
};


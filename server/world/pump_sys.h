#pragma once
#include "game_sys_def.h"
struct stGift;

// ͳ��ϵͳ
class PumpSys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_pump);

	virtual void init_sys_object();	

	virtual void sys_time_update();

	virtual void sys_update(double delta);

	/*
			ͳ�����ϲ��
	*/
	void enterGame(int gameId, int playerId);

	/*
			��ң���ȯ�仯�ܱ�
	*/
	void moneyTotalLog(game_player* player, int gameId, int itemId, GOLD_TYPE addValue, int reason, const std::string& param = "");

	/*
			�仯��Ϊ0�������¼
	*/
	void moneyTotalLog(game_player* player, int gameId, int itemId, int reason, const std::string& param);

	/*
			����ͨ��ͳ��
	*/
	void addGeneralStatLog(int statType);

	/*
			�����˵���
	*/
	void buyItemLog(int itemId);

	/*
			��������
	*/
	void sendGiftLog(int giftId);

	void sendGiftLog(std::vector<stGift>& giftList);

	void sendGiftLog(int senderId, int receiverId, stGift& giftInfo);

	//ת��
	void pumpSendGold1(const std::string& mailid, game_player* sender, GOLD_TYPE sendgold, int recverid);
	void pumpSendGold2(const std::string& mailid, game_player* recver, GOLD_TYPE recvgold, GOLD_TYPE CounterFee);
private:
	// ��Ծ�������ظ�����
	void _activeCount(int gameId);

	void _activePerson(int gameId, int playerId);

	void _generalStat(int id, int tableType);

	void _recordCoinGrowth(int itemId, int addValue, game_player* player);

	void _statDailyMoney(int itemId, int addValue, int reason);

private:
	// ���������Ҹ���
	int m_maxOnlinePlayerNum;
	// ���ʱ��
	double m_checkTime;
};









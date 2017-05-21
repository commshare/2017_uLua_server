#pragma once
#include "game_sys_def.h"

struct stRankInfo
{
	int m_playerId;
	std::string m_nickName;
	GOLD_TYPE m_gold;
	int16_t m_vipLevel;
};

// ����ϵͳ
class GameRankSys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_rank);

	/*
			���ؽ�����а�
			rankList		�����б�
			selfRank		����player������, ��0��ʼ����
	*/
	int getCoinRankList(game_player* player, std::vector<stRankInfo>& rankList, int& selfRank);
	int getRechargeRankList(game_player* player, std::vector<stRankInfo>& rankList, int& selfRank, int& selfrmb, bool yesterday = false);

	virtual void sys_time_update();

	/*
			�������
	*/
	int getCoinGrowthList(game_player* player, std::vector<stRankInfo>& rankList, int& selfRank, GOLD_TYPE& selfGold);
private:
	void _coinGrowthProcess();
};


#pragma once
#include "game_sys_def.h"
struct stExchangeInfo;

// �һ�ϵͳ
class ExchangeSys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_exchange);

	/*
			�һ�
			player		�һ����
			chgId		�һ�id
			phone		��ҵ绰
			����ֵ  e_msg_result_def ����
	*/
	int exchange(game_player* player, int chgId, const std::string& phone);

	int getExchangeList(game_player* player, std::vector<stExchangeInfo>& infoList);
private:
	void _notice(game_player* player);
};

struct stExchangeInfo
{
	time_t m_genTime;
	int m_chgId;
	bool m_isReceive;
};


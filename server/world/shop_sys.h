#pragma once
#include "game_sys_def.h"

// �̳�ϵͳ
class ShopSys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_shop);

	virtual bool sys_load();
	virtual void init_sys_object();
	virtual void sys_update(double delta);

	/*
			������Ʒ
			player			�������
			commodityId		��Ʒid
			����ֵ  e_msg_result_def ����
	*/
	int buyCommodity(game_player* player, int commodityId);

	void player_recharge(game_player* player, int payId);
	void robot_recharge();
	const std::list<std::string>& get_charge_historys();
protected:
	void add_charge_history(const std::string& playername, const std::string& payname);
	void save_historys();
private:
	double m_elapsed;
	std::list<std::string> m_historys;
};


#pragma once
#include "game_sys_def.h"

class game_player;
class OnlineRewardArray;
class OnlineRewardItem;

// ���߽���
class OnlineRewardMgr : public enable_obj_pool<OnlineRewardMgr>, public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_online_reward);

	MAKE_GET_OWNER(game_player);

	virtual void init_sys_object();		

	virtual void sys_time_update();

	/*
			��ȡ����
			����ֵ����ֵ e_msg_result_def����
	*/
	int receiveReward();

	int receiveReward(boost::posix_time::ptime& curPtime);

	/*
			������ȡ������ʣ��ʱ��
			����0��ʾ����ȡ
	*/
	int getRemainTime();

	int getRecvCount();

	OnlineRewardItem* getOnlineRewardItem(int index);

	/*
			��������ȡ�Ľ���ID
	*/
	int getRewardId(){ return m_rewardId; }
private:
	int _getRemainTime(time_t curTime);
private:
	// �ϴ��콱ʱ��
	time_t m_lastReceiveTime;

	GArrayFieldPtr m_onlineReward;

	boost::shared_ptr<OnlineRewardArray> m_onlineRewardPtr;

	// ����ȡ���Ľ���ID
	int m_rewardId;
};

//////////////////////////////////////////////////////////////////////////

class OnlineRewardItem : public game_object, public enable_obj_pool<OnlineRewardItem>
{
public:
	OnlineRewardItem();

	virtual void init_game_object();

	virtual uint32_t get_id() { return m_id->get_value();}

	Tfield<int32_t>::TFieldPtr		m_id;			// id��
	Tfield<bool>::TFieldPtr			m_isReceive;	// �Ƿ���ȡ����
};

//////////////////////////////////////////////////////////////////////////

class OnlineRewardArray : public game_object_array, public enable_obj_pool<OnlineRewardArray>
{
public:
	virtual const std::string& get_cells_name();	

	virtual const std::string& get_id_name();

	virtual GObjPtr create_game_object(uint32_t object_id);

	virtual bool update_all(){ return true; }
};

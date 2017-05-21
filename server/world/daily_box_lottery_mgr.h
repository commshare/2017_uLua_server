#pragma once
#include "game_sys_def.h"

class game_player;
class BoxLotteryArray;
class BoxLotteryItem;

// �齱���
struct stBoxLotteryResult
{
	// 0 �鵽��  
	// 1 �鵽С��  
	// 2 �鵽С�������������лл����
	int m_resultType;
};

// ÿ�ձ���齱����
class DailyBoxLotteryMgr : public enable_obj_pool<DailyBoxLotteryMgr>, public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_daily_box_lottery);

	MAKE_GET_OWNER(game_player);

	virtual void init_sys_object();	

	virtual void sys_init();

	virtual bool sys_load();

#ifdef _DEBUG
	void resetBigPrize(int index);
#endif

	/*
			���ñ��估�齱����
	*/
	void reset(time_t curT = 0);

	/*
			�Ƿ�鵽�˴�
	*/
	bool hasLotteryBigPrize();

	/*
			����齱
	*/
	int doBoxLottery(int boxIndex);

	/*
			ͨ����ȯ�齱����Ҫ������ȯ
	*/
	int doBoxLotteryWithTicket(int boxIndex);

	/*
			лл����һ���ȯ
	*/
	int exchangeTicket();

	int getBoxCount();

	BoxLotteryItem* getBoxLotteryItem(int index);

	stBoxLotteryResult* getBoxLotteryResult(){ return &m_result; }

	int getLotteryCountToday(){ return m_lotteryCountToday->get_value(); }

	int getThankYouCount(){ return m_thankYouCount->get_value(); }

	void addThankYouCount(int cnt){ m_thankYouCount->add_value(cnt); }
private:
	void _randBoxReward();

	// ����齱
	int _lotteryBox(int boxIndex, game_player *player);
private:
	// ��������
	GArrayFieldPtr m_boxArray;

	boost::shared_ptr<BoxLotteryArray> m_boxArrayPtr;

	// �ϴα��������ʱ��
	Tfield<time_t>::TFieldPtr m_lastBoxResetTime;

	// �����ѳ齱����
	Tfield<int32_t>::TFieldPtr m_lotteryCountToday;

	// лл�������
	Tfield<int32_t>::TFieldPtr m_thankYouCount;

	stBoxLotteryResult m_result;
};

//////////////////////////////////////////////////////////////////////////

class BoxLotteryItem : public game_object, public enable_obj_pool<BoxLotteryItem>
{
public:
	BoxLotteryItem();

	virtual void init_game_object();

	// �����Ƿ����
	Tfield<bool>::TFieldPtr m_isOpen;
	
	// �������������
	Tfield<GOLD_TYPE>::TFieldPtr m_containGold;
};

//////////////////////////////////////////////////////////////////////////

class BoxLotteryArray : public game_object_array, public enable_obj_pool<BoxLotteryArray>
{
public:
	virtual const std::string& get_cells_name();	

	virtual const std::string& get_id_name();

	virtual GObjPtr create_game_object(uint32_t object_id);

	virtual bool update_all(){ return true; }
};

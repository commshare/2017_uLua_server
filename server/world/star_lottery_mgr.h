#pragma once
#include "game_sys_def.h"

class game_player;

// ǩ�����
struct stStarResult
{
	stStarResult()
	{
		clear();
	}

	int award;	//����
	int itemtype;	//��Ʒ����
	int itemcount;	//��Ʒ����

	void clear()
	{
		award = 0;
		itemtype = 0;
		itemcount = 0;
	}
};

// ת�̳齱����
class StarLotteryMgr : public enable_obj_pool<StarLotteryMgr>, public game_sys_base
{
public:
	StarLotteryMgr();

	~StarLotteryMgr();

	MAKE_SYS_TYPE(e_gst_star_lottery);

	MAKE_GET_OWNER(game_player);

	virtual void init_sys_object();

	bool Lottery(stStarResult& result);
public:	
	Tfield<int32_t>::TFieldPtr CurStar;		//��ǰ����
	Tfield<int32_t>::TFieldPtr CurAward;	//��ǰ����
	Tfield<int32_t>::TFieldPtr TotalChip;	//�ۼƻ�ȡ��Ƭ
	Tfield<int32_t>::TFieldPtr CurCount;		//��ǰ����

	void _lottery(int lvl, stStarResult& result);

	void _sendLotteryNotice(int itemType, int count);
};



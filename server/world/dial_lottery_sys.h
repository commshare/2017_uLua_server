#pragma once
#include "game_sys_def.h"
#include "M_DialLotteryCFG.h"
#include "probability.h"

// ת�̳齱ϵͳ
class DialLotterySys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_dial_lottery);

	virtual void init_sys_object();		

	/*
			�齱
			num   ���ؽ������
			coin  ���ؽ����Ľ��
			rtype ��������
			���س齱�Ƿ�ɹ���true�ɹ�,falseʧ��
	*/
	bool doLottery(int& num, GOLD_TYPE& coin, int& rtype);
private:
	std::vector<M_DialLotteryCFGData> m_items;

	Probability m_prob;
};


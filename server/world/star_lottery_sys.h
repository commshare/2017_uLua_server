#pragma once
#include "game_sys_def.h"

// ����ϵͳ
class StarLotterySys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_star_lottery);

	StarLotterySys();


	virtual void init_sys_object();

	//��������
	virtual bool sys_load();

	// ÿ֡����
	virtual void sys_update(double delta);

	//��ȡʣ��ֵ
	int get_surplus();
	//���µ�ǰֵ
	bool update_total(int v);
private:
	int m_total;
	bool m_update;
};
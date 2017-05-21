#pragma once

#include "game_sys_def.h"

class game_player;

// ���߽���
class BenefitsMgr : public enable_obj_pool<BenefitsMgr>, public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_benefits_sys);

	MAKE_GET_OWNER(game_player)

	virtual void init_sys_object();
	virtual void sys_time_update();

	//����ڽ�����ȡ�˾ȼý�Ĵ���
	int collected() const;
	//�������ݵ����ݿ�
	void store();
public:
	Tfield<int32_t>::TFieldPtr m_collected;
};
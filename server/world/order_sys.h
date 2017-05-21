#pragma once
#include "game_sys_def.h"
#include "enable_hashmap.h"
#include "url_param.h"

//class UrlParam;
class game_player;

/*
		�������ʵʱ���·֡�
		������web��̨��API�ӿ�����
*/
class OrderSys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_order_sys);

	virtual void sys_update(double delta);

	/*
			��url�����л�ȡ������Ϣ
	*/
	int addOrder(UrlParam& param);

private:


	// ������, ����ʧ��ԭ��
	void _process(UrlParam& param);


private:
	// �����б�
	ENABLE_MAP<std::string, UrlParam> m_orderList;
};



#define ORDER_COUNT_EACH_FRAME 20
#define MAX_ORDER_COUNT 1000




#include "stdafx.h"
#include "order_sys.h"
#include "msg_type_def.pb.h"
#include "url_param.h"
#include "game_player_mgr.h"
#include "game_player.h"
#include "game_db.h"
#include "pump_type.pb.h"
#include "proc_player_property.h"
#include "game_sys_recharge.h"

void OrderSys::sys_update(double delta)
{
	int count = m_orderList.size();
	if(count <= 0) // û�ж���
		return;

	auto it = m_orderList.begin();	
	for(int i = 0; i < ORDER_COUNT_EACH_FRAME && it != m_orderList.end(); i++)
	{
		_process(it->second);
		it = m_orderList.erase(it);		
	}
}

int OrderSys::addOrder(UrlParam& param)
{

	// �ﵽ��󶩵����������ִ����������������ط���
	if(m_orderList.size() > MAX_ORDER_COUNT)
	{
		return msg_type_def::e_rmt_fail;
	}

	auto it = m_orderList.find(param.getStringValue("orderid"));
	if(it != m_orderList.end()) // �ظ�����
		return msg_type_def::e_rmt_success;

	m_orderList[param.getStringValue("orderid")] = param;

	return msg_type_def::e_rmt_success;
}

void OrderSys::_process(UrlParam& param)
{
	auto player = game_player_mgr::instance().find_player(param.getStringValue("userid"));
	if(!player) // ��Ҳ�����	
		return ;	

	player->get_sys<game_sys_recharge>()->payment_once(param.getStringValue("orderid"), param.getIntValue("currencytype"), param.getIntValue("currencycount"));
}


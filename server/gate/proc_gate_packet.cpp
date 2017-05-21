#include "stdafx.h"
#include "proc_gate_packet.h"
#include "gate_server.h"
#include "clients_manager.h"
#include "backstage_manager.h"
#include "server_peer.h"

using namespace boost;

//�յ��ͻ��˷���������Э��
bool packetc2g_heartbeat_factory::packet_process(shared_ptr<gate_peer> peer, shared_ptr<packetc2g_heartbeat> msg)
{	
	__ENTER_FUNCTION_CHECK;
	
	std::cout << "����ʱ��" << std::endl;
	peer->reset_checktime();

	__LEAVE_FUNCTION_CHECK
	return !EX_CHECK;
}

//�յ��ͻ���ѡ�����ص�Э��
bool packetc2g_select_gate_factory::packet_process(shared_ptr<gate_peer> peer, shared_ptr<packetc2g_select_gate> msg)//���Ӧ���ǿͻ��˷�����
{	
	__ENTER_FUNCTION_CHECK;
	static int close_select = gate_server::instance().get_cfg().get_ex<int>("close_select", 0);
	std::cout << "ѡ������:"<<msg->packet_id() << std::endl;

	auto sendmsg = PACKET_CREATE(packetg2c_select_gate_result, e_mst_g2c_select_gate_result);	

	//��ѯgate��������
	static int maxcount = gate_server::instance().get_cfg().get<int>("maxcount");

	if(peer->is_ok() || close_select == 1)
	{
		SLOG_ERROR << "packetc2g_select_gate_factory peer->is_ok:" << peer->get_id();	
		peer->set_ok();
	}
	else if(clients_manager::instance().get_count() >= maxcount)//�ͻ����ѽ����ص�����
	{	

		for (auto it = backstage_manager::instance().SInfoMap.begin();it !=backstage_manager::instance().SInfoMap.end(); ++it )
		{
			if(it->second->server_type() != server_protocols::e_st_gate)
				continue;

			if(it->first == gate_server::instance().get_serverid())
				continue;

			if(it->second->mutable_attributes()->client_count() < maxcount)
			{
				sendmsg->set_new_ip(it->second->server_ip());
				sendmsg->set_new_port(it->second->server_port());
				sendmsg->set_result(msg_type_def::e_rmt_change_gate);
				break;
			}
		}
		if(sendmsg->result() != msg_type_def::e_rmt_change_gate)
		{
			peer->set_ok();
			SLOG_ERROR << "clients_manager::instance().get_count() >= maxcount " << peer->get_id();	
		}
	}
	else
	{
		SLOG_CRITICAL << "gate ���ӵĿͻ��������� " << clients_manager::instance().get_count()<<std::endl;
		peer->set_ok();
	}

	peer->send_msg(sendmsg);

	__LEAVE_FUNCTION_CHECK
		return !EX_CHECK;
}


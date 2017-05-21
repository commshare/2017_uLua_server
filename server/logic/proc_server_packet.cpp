#include "stdafx.h"
#include "proc_server_packet.h"
#include "backstage_manager.h"
#include <server_base.pb.h>
#include <enable_json_map.h>
#include <time_helper.h>
#include "timer_manager.h"

using namespace boost;

void init_server_protocol()
{
	//proc_server_packet
	packet_server_register_result_factory::regedit_factory();
	packet_other_server_connect_factory::regedit_factory();
	packet_other_server_disconnect_factory::regedit_factory();
	packet_updata_servers_info_factory::regedit_factory();
	packet_server_register_factory::regedit_factory();
	packet_heartbeat_factory::regedit_factory();
	packet_updata_self_info_factory::regedit_factory();

}


//////////////////////////////////////////////////////////////////////////
bool packet_updata_servers_info_factory::packet_process(shared_ptr<server_peer> peer, shared_ptr<packet_updata_servers_info> msg)
{	
	__ENTER_FUNCTION_CHECK;

	SINFO_MAP& simap = backstage_manager::instance().SInfoMap;

	auto silist = msg->sinfos();
	for (int i = 0;i<silist.size();i++)
	{
		auto sii = silist.Get(i);
		auto fit = simap.find(sii.server_port());
		if(fit != simap.end())
		{
			if(sii.has_attributes())
				fit->second->mutable_attributes()->CopyFrom(sii.attributes());
		}
		else
		{
			server_info_define sid = make_shared<server_protocols::server_info>();			
			sid->CopyFrom(sii);
			simap.insert(std::make_pair(sid->server_port(), sid));
		}		
	}

	backstage_manager::instance().connect_world();

	__LEAVE_FUNCTION_CHECK
		return !EX_CHECK;
}

//////////////////////////////////////////////////////////////////////////
bool packet_server_register_result_factory::packet_process(shared_ptr<server_peer> peer, shared_ptr<packet_server_register_result> msg)
{	
	__ENTER_FUNCTION_CHECK;
	time_helper::instance().set_base_time(msg->server_time());
	peer->set_remote_id(peer->get_remote_port());	

	//ͬ��ʱ��֮�����ִ�ж�ʱ����ʼ��
	timer_manager::instance().init_timer();

	__LEAVE_FUNCTION_CHECK
		return !EX_CHECK;
}

//////////////////////////////////////////////////////////////////////////
bool packet_other_server_disconnect_factory::packet_process(shared_ptr<server_peer> peer, shared_ptr<packet_other_server_disconnect> msg)
{	
	__ENTER_FUNCTION_CHECK;

	SINFO_MAP& simap = backstage_manager::instance().SInfoMap;
	auto fit = simap.find(msg->server_id());
	if(fit != simap.end())
		simap.erase(fit);

	SLOG_CRITICAL << "other_server_disconnect id:"<< msg->server_id();

	__LEAVE_FUNCTION_CHECK
		return !EX_CHECK;
}

//////////////////////////////////////////////////////////////////////////
bool packet_other_server_connect_factory::packet_process(shared_ptr<server_peer> peer, shared_ptr<packet_other_server_connect> msg)
{	
	__ENTER_FUNCTION_CHECK;

	SINFO_MAP& simap = backstage_manager::instance().SInfoMap;

	auto sii = msg->sinfo();
	auto fit = simap.find(sii.server_port());
	if(fit == simap.end())
	{
		server_info_define sid = make_shared<server_protocols::server_info>();			
		sid->CopyFrom(sii);
		simap.insert(std::make_pair(sid->server_port(), sid));
	}	

	SLOG_CRITICAL << "other_server_connect id:"<< sii.server_port() << " type:"<<sii.server_type();

	if(sii.server_type() == server_protocols::e_st_world)
		backstage_manager::instance().connect_world();

	__LEAVE_FUNCTION_CHECK
		return !EX_CHECK;
}


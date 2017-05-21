#include "stdafx.h"
#include "monitor_server.h"
#include "monitor_peer.h"
#include "monitor_peer_manager.h"
#include "servers_manager.h"
#include <boost/timer.hpp>
#include "http_cmd_manager.h"

using namespace boost;

monitor_server::monitor_server(void)
{
}


monitor_server::~monitor_server(void)
{
	
}

bool monitor_server::DumpCallback(const wchar_t* dump_path,
						  const wchar_t* minidump_id,
						  void* context,
						  EXCEPTION_POINTERS* exinfo,
						  MDRawAssertionInfo* assertion,
						  bool succeeded)
{
	//�쳣���⴦�� �����ϴ���������

	return true;
}

bool monitor_server::on_init()
{
	//��ʼ��
	init_packet();

	//http�˿�+1
	m_httpserver = boost::make_shared<http::server::http_server>(get_io_service(), 
		get_cfg().get<uint16_t>("out_port") + 1, this);

	return true;
}

void monitor_server::run()
{
	__ENTER_FUNCTION

		timer t;
	double elapsed=0;
	//��ѭ��
	while (is_runing())
	{
		t.restart();
		run_timer();
		monitor_peer_manager::instance().heartbeat( elapsed );
		servers_manager::instance().heartbeat( elapsed );
		HttpCmdManager::instance().heartbeat( elapsed );

		elapsed = t.elapsed();
		if(elapsed < 0.1)
		{
			this_thread::sleep(posix_time::milliseconds(1));
			elapsed = t.elapsed();
		}
		else 
		{
			SLOG_CRITICAL<< "server_run longtime:"<<elapsed;
		}
	}

	__LEAVE_FUNCTION
}

void monitor_server::on_exit()
{
	//�˳����� �������ݱ��� dump֮��Ҳ��������
	monitor_peer_manager::instance().clear();
	servers_manager::instance().clear();
}

boost::shared_ptr<peer_tcp> monitor_server::create_peer()
{
	__ENTER_FUNCTION
	lock_guard<boost::mutex> gurad(m_createlock);
	
	shared_ptr<monitor_peer> peer = monitor_peer::malloc();//make_shared<monitor_peer>(m_io_service, generate_id());
	peer->init_peer(m_io_service, generate_id());
	monitor_peer_manager::instance().add_obj(peer->get_id(), peer);

	return peer;
	__LEAVE_FUNCTION
		return nullptr;
}


//////////////////////////////////////////////////////////////////////////
#include "proc_server_packet.h"
bool monitor_server::handle_request(const std::string& info)
{
	auto world = servers_manager::instance().get_server_bytype(e_st_world);
	if (world)
	{
		/*boost::mutex::scoped_lock lock(io_mutex);
		auto sendmsg = PACKET_CREATE(packet_http_command, e_mst_http_command);
	//	sendmsg->set_cmdstr(info);
		world->send_msg(sendmsg);*/

		return HttpCmdManager::instance().addCommand(info);
	}
	return false;
}
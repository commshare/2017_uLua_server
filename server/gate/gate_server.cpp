#include "stdafx.h"
#include "gate_server.h"
#include "gate_peer.h"
#include "gate_peer_manager.h"
#include "clients_manager.h"
#include "backstage_manager.h"
#include "server_peer.h"
#include <server_base.pb.h>
#include <boost/timer.hpp>

using namespace boost;

gate_server::gate_server(void)
{
}


gate_server::~gate_server(void)
{
	
}

bool gate_server::DumpCallback(const wchar_t* dump_path,
						  const wchar_t* minidump_id,
						  void* context,
						  EXCEPTION_POINTERS* exinfo,
						  MDRawAssertionInfo* assertion,
						  bool succeeded)
{
	//�쳣���⴦�� �����ϴ���������

	return true;
}

bool gate_server::on_init()
{
	//��ʼ��
	init_packet();
	connect_monitor();


	return true;
}

void gate_server::run()
{
	__ENTER_FUNCTION
	timer t;
	double elapsed=0;

	//��ѭ��
	while (is_runing())
	{
		t.restart();
		run_timer();
		gate_peer_manager::instance().heartbeat( elapsed );
		clients_manager::instance().heartbeat( elapsed );
		backstage_manager::instance().heartbeat( elapsed );

		elapsed = t.elapsed();
		if(elapsed < 0.5)
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

void gate_server::on_exit()
{
	//�˳����� �������ݱ��� dump֮��Ҳ��������
	gate_peer_manager::instance().clear();
	clients_manager::instance().clear();
	backstage_manager::instance().clear();
	
}

shared_ptr<peer_tcp> gate_server::create_peer()
{
	__ENTER_FUNCTION
		SLOG_CRITICAL << "�����ͻ���Peer��" << std::endl;
	lock_guard<boost::mutex> gurad(m_createlock);	
	shared_ptr<gate_peer> peer = gate_peer::malloc();// make_shared<gate_peer>(m_io_service, generate_id());
	peer->init_peer(m_io_service, generate_id(), true);
	gate_peer_manager::instance().add_obj(peer->get_id(), peer);

	//�ر�ѡ������
	static int close_select = get_cfg().get_ex<int>("close_select", 0);
	if(close_select == 1)
		peer->set_ok();

	return peer;
	__LEAVE_FUNCTION
		return nullptr;
}

boost::shared_ptr<peer_tcp> gate_server::create_peer(uint16_t remote_type)
{
	__ENTER_FUNCTION
	lock_guard<boost::mutex> gurad(m_createlock);

	shared_ptr<server_peer> peer = server_peer::malloc();//ake_shared<server_peer>(m_io_service, generate_id());
	peer->init_peer(m_io_service, generate_id());
	peer->set_remote_type(remote_type);
	backstage_manager::instance().add_obj(peer->get_id(), peer);

	return peer;
	__LEAVE_FUNCTION
		return nullptr;
}

#include "server_peer.h"
#include <net/packet_manager.h>

void gate_server::connect_monitor()
{
	__ENTER_FUNCTION
	if(xml_cfg.check("monitor_ip") &&
		xml_cfg.check("monitor_port"))
	{
		auto peer = create_peer(server_protocols::e_st_monitor);
		
		std::string tarip = xml_cfg.get_ex<std::string>("monitor_ip", std::string("localhost"));
		uint16_t tarport = xml_cfg.get<uint16_t>("monitor_port");
		peer->connect(tarip.c_str(), tarport);		
	}
	__LEAVE_FUNCTION
}
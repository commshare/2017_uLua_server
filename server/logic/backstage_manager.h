#pragma once
#include <enable_object_manager.h>
#include <enable_singleton.h>
#include <server_manager_handler.h>
#include <server_define.h>

class server_peer;

namespace google
{
	namespace protobuf
	{
		class Message;
	};
};
typedef ENABLE_MAP<uint16_t, server_info_define> SINFO_MAP;
class backstage_manager:
	public enable_object_manager<server_peer, boost::mutex>,
	public enable_singleton<backstage_manager>,
	public server_manager_handler
{
public:
	backstage_manager(void);
	virtual ~backstage_manager(void);

	void set_world_state(bool vaild = true);
	boost::shared_ptr<server_peer> get_world();

	void heartbeat( double elapsed );	

	virtual void exec_event();
	virtual bool add_obj(int obj_id, boost::shared_ptr<server_peer> obj);


	SINFO_MAP SInfoMap;

	void connect_world();	
private:	
	bool is_vaild;
	boost::shared_ptr<server_peer> world_ptr;
		
};


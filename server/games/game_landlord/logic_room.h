#pragma once
#include "logic_def.h"
#include "logic_core.h"
#include "proc_game_landlord_protocol.h"
#include "logic_table.h"

struct Landlord_RoomCFGData;
class logic_room_db:public game_object
{
protected:
	void create_room();
	bool load_room();
	void reflush_rate();//������֧
public:
	virtual void init_game_object() override;//ע������
	virtual bool store_game_object(bool to_all = false) override;//������������ʵ�ִ˽ӿ�

	Tfield<int16_t>::TFieldPtr		m_db_room_id;			//����id
};

class logic_room :public logic_room_db
{
public:
	logic_room(const Landlord_RoomCFGData* cfg, logic_lobby* _lobby);
	~logic_room(void);

	void heartbeat( double elapsed );
	uint16_t get_room_id();			//����ID

	e_server_error_code enter_room(LPlayerPtr player);		//���뷿��
	e_server_error_code leave_room(uint32_t playerid);			//�뿪����

    e_server_error_code enter_table(LPlayerPtr player);

	const Landlord_RoomCFGData* get_room_cfg() const;
	logic_lobby* get_lobby(){return m_lobby;};
public:
	template<class T>
	int broadcast_msg_to_client(T msg, uint32_t except_id = 0)
	{
		return broadcast_msg_to_client(msg->packet_id(), msg, except_id);
	};
	int broadcast_msg_to_client(uint16_t packet_id, boost::shared_ptr<google::protobuf::Message> msg, uint32_t except_id);
private:
	const Landlord_RoomCFGData* m_cfg;
	logic_lobby* m_lobby;
	LPLAYER_MAP playerMap;		//��������ֵ�
	LTABLE_MAP tableMap;		//��������ֵ�
	int robCount;
	double createRob_time;
};

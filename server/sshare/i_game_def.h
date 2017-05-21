#pragma once

#include <enable_smart_ptr.h>
#include <game_macro.h>


//��Ϸ�߼�ʹ�õ���ҽӿ�
namespace google
{
	namespace protobuf
	{
		class Message;
	}
}

class i_game_phandler;
class i_game_player;
class i_game_ehandler;

typedef boost::shared_ptr<i_game_player> iGPlayerPtr;
typedef boost::shared_ptr<i_game_phandler> iGPhandlerPtr;

struct msg_packet_one
{
	uint16_t packet_id;
	boost::shared_ptr<google::protobuf::Message> msg_packet;

	msg_packet_one()
		:packet_id(0)
	{

	}

	msg_packet_one(uint16_t id, boost::shared_ptr<google::protobuf::Message> msg)
		:packet_id(id),
		msg_packet(msg)
	{

	}
};


////��������
//enum i_et_attr_type
//{
//	e_at_gold = 1,			//���
//	e_at_vip,				//vip
//	e_at_photoframe,		//ͷ���
//	e_at_ticket,			//��ȯ
//	e_at_sex,				//�Ա�
//};

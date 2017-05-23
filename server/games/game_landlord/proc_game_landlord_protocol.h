#pragma once
#include <net\packet_manager.h>
#include <game_landlord_protocol.pb.h>
#include <net\peer_tcp.h>

class i_game_player;
using namespace game_landlord_protocol;

void init_proc_landlord_protocol();


//����ս��
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_enter_room, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_enter_room_result);

//�뿪ս��
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_leave_room, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_leave_room_result);

//�������� ������Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_get_room_scene_info, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_get_room_scene_info_result);

//�����Ϸ״̬		//����Ϸ֮���ж��Ƿ��ڶ�����
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_check_state, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_check_state_result);

//֪ͨ��ʼ��Ϸ
PACKET_REGEDIT_SEND(packetl2c_notice_start_game);


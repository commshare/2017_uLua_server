#pragma once
#include <net\packet_manager.h>
#include <game_happysupremacy_protocol.pb.h>
#include <net\peer_tcp.h>

class i_game_player;
using namespace game_happysupremacy_protocols;

void init_proc_happysupremacy_protocol();

//��÷�����Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_get_room_info, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_get_room_info_result);

//�������Ӽ�����"������"
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_enter_room, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_enter_room_result);

//��������ڳ�����Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_get_room_scene_info, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_get_room_scene_info_result);

//�뿪���Ӽ��뿪"������"
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_leave_room, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_leave_room_result);

//��ע
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_add_bet, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_add_bet_result);

//��ѹ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_repeat_bet, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_repeat_bet_result);

//����
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_clear_bet, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_clear_bet_result);

//��ׯ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_ask_for_banker, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_ask_for_banker_result);

//��ׯ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_leave_banker, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_leave_banker_result);

//��ׯ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_ask_for_first_banker, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_ask_for_first_banker_result);

//��������б�
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_ask_for_player_list, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_ask_for_player_list_result);

//������ׯ�б�
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_ask_for_banker_list, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_ask_for_banker_list_result);

//������·
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_ask_for_history_list, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_ask_for_history_list_result);

//֪ͨ��ʼѺע
PACKET_REGEDIT_SEND(packetl2c_bc_begin_bet);

//֪ͨ����
PACKET_REGEDIT_SEND(packetl2c_bc_begin_award);

//֪ͨ���������ע��Ϣ
PACKET_REGEDIT_SEND(packetl2c_bc_total_bet_info);

//֪ͨ��ׯ��Ϣ
PACKET_REGEDIT_SEND(packetl2c_bc_rob_banker_info);

//֪ͨ����ׯ��
PACKET_REGEDIT_SEND(packetl2c_bc_change_banker);

//���Э�� ����Ƿ���������
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_check_state, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_check_state_result);

//�㲥�յ�����
PACKET_REGEDIT_SEND(packetl2c_bc_accept_gift);

//GM
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_gm, i_game_player);

/*//-----------------------------���ƿͻ���-----------------------------------------
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp,packetc2l_gm_talk_server, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_gm_talk_server);

PACKET_REGEDIT_RECVGATE_LOG(peer_tcp,packetc2l_gm_change_result, i_game_player);
PACKET_REGEDIT_SEND(packetl2c_gm_change_result);

PACKET_REGEDIT_SEND(packetl2c_notice_gm_all_bet_info);


//-----------------------------------------
PACKET_REGEDIT_SEND(packetl2c_notice_gm_stock_info);*/
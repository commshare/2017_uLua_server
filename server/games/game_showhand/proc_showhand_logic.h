#pragma once
#include <net\packet_manager.h>
#include <game_showhand_protocol.pb.h>
#include <net\peer_tcp.h>

class i_game_player;
using namespace game_showhand_protocols;

void init_proc_showhand_logic();

//���󷿼��б���Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_get_room_info, i_game_player);
//���뷿�䷵���б���Ϣ
PACKET_REGEDIT_SEND(packetl2c_get_room_info_result);

//������Ϸ����������Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_enter_game_room, i_game_player);
//������Ϸ������Ӧ��Ϣ
PACKET_REGEDIT_SEND(packetl2c_enter_game_room_result);

//�˳���Ϸ����������Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_quit_game_room, i_game_player);
//�˳���Ϸ������Ӧ��Ϣ
PACKET_REGEDIT_SEND(packetl2c_quit_game_room_result);

//�������ӣ����������Զ�ѡ�����룩������Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_choose_desk, i_game_player);
//���ѡ��һ�����ӣ���Ӧ��Ϣ
PACKET_REGEDIT_SEND(packetl2c_choose_desk_result);

//�������� ������Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_get_table_scene_info, i_game_player);
//��Ӧ������Ϣ
PACKET_REGEDIT_SEND( packetl2c_get_table_scene_result);

//�뿪���ӵ�����������Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_quit_desk, i_game_player);
//�뿪���ӵ�������Ӧ��Ϣ
PACKET_REGEDIT_SEND(packet_l2c_quit_desk_result);

//��ҽ���׼��״̬������Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_player_ready, i_game_player);
//�������׼��״̬ ��Ӧ��Ϣ
PACKET_REGEDIT_SEND(packetl2c_player_ready_result);

//��ҿ�����������Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_view_card, i_game_player);
//��ҿ�����Ӧ��Ϣ
PACKET_REGEDIT_SEND(packetl2c_view_card_result);

//�����ע������Ϣ
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp, packetc2l_bet_info, i_game_player);
//��ҿ�����Ӧ��Ϣ
PACKET_REGEDIT_SEND(packetl2c_bet_info_result);

//��鷿��״̬
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp,packetc2l_check_state,i_game_player);
//��鷿��״̬����
PACKET_REGEDIT_SEND(packetl2c_check_state_result);

//���� ��Ҽ��������б���Ϣ
PACKET_REGEDIT_SEND(packetl2c_notice_join_table);
//���� ����뿪�����б���Ϣ
PACKET_REGEDIT_SEND(packetl2c_notice_leave_table);
//���� ����뿪�����б���Ϣ
PACKET_REGEDIT_SEND(packetl2c_notice_table_player_state);

//���� ��ʼ��Ϸ��Ϣ
PACKET_REGEDIT_SEND(packetl2c_notice_start_game_message);
//���� ˭��ע��Ϣ
PACKET_REGEDIT_SEND(packetl2c_notice_bet);
//���� ������Ϣ
PACKET_REGEDIT_SEND(packetl2c_notice_sendcard_message);
//���� ��ҿ���
PACKET_REGEDIT_SEND(packetl2c_notice_award_message);

//���� GM ������ҵ���Ϣ
PACKET_REGEDIT_SEND(packetl2c_notice_gm_all_card_info);
PACKET_REGEDIT_RECVGATE_LOG(peer_tcp,packetc2l_gm_change_result,i_game_player);
PACKET_REGEDIT_SEND(packetl2c_gm_change_result);

PACKET_REGEDIT_SEND(packetl2c_notice_gm_stock_info);

PACKET_REGEDIT_SEND(packetl2c_notice_gm_luck_info); 



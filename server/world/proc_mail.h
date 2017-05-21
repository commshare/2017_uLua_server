#pragma once
#include <net\packet_manager.h>
#include "client2world_mail.pb.h"
#include "world_peer.h"

class game_player;
using namespace client2world_protocols;

void initMailPacket();

// ��ȡ�ʼ��б�����
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_get_mails, game_player);
// ��ȡ�ʼ��б��Ӧ
PACKET_REGEDIT_SEND(packetw2c_get_mails_result);

// ��ȡ�ʼ��е���������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_recv_mail_gifts, game_player);
// ��ȡ�ʼ��е�����������
PACKET_REGEDIT_SEND(packetw2c_recv_mail_gifts_result);

// �����ʼ�
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_send_mail, game_player);
// �����ʼ����
PACKET_REGEDIT_SEND(packetw2c_send_mail_result);

// ɾ��ĳ���ʼ�
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_remove_mail, game_player);
// ɾ��ĳ���ʼ����
PACKET_REGEDIT_SEND(packetw2c_remove_mail_result);

// �յ�����֪ͨ
PACKET_REGEDIT_SEND(packetw2c_accept_gift_notify);

// �������ʼ���־
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_send_mail_log, game_player);
// �������ʼ���־���
PACKET_REGEDIT_SEND(packetw2c_req_send_mail_log_result);

// ɾ��ĳ���ʼ���־
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_remove_mail_log, game_player);
// ɾ��ĳ���ʼ���־���
PACKET_REGEDIT_SEND(packetw2c_remove_mail_log_result);

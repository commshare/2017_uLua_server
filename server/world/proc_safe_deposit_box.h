#pragma once
#include <net\packet_manager.h>
#include "client2world_safe_deposit_box.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initSafeDepositBoxPacket();

// ���ñ���������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_set_password, game_player);
// ���ñ�����������
PACKET_REGEDIT_SEND(packetw2c_set_password_result);

// �޸ı���������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_modify_password, game_player);
// �޸ı�����������
PACKET_REGEDIT_SEND(packetw2c_modify_password_result);

// ���ñ���������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_reset_password, game_player);
// ���ñ�����������
PACKET_REGEDIT_SEND(packetw2c_reset_password_result);

// ���ñ���������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_check_password, game_player);
// ���ñ�����������
PACKET_REGEDIT_SEND(packetw2c_check_password_result);

// ������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_deposit_gold, game_player);
// �����ҽ��
PACKET_REGEDIT_SEND(packetw2c_deposit_gold_result);

// ȡ�����
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_draw_gold, game_player);
// ȡ����ҽ��
PACKET_REGEDIT_SEND(packetw2c_draw_gold_result);

// ��ȡ���������֤��
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_get_safe_box_security_code, game_player);
// ��ȡ���������֤����
PACKET_REGEDIT_SEND(packetw2c_get_safe_box_security_code_result);

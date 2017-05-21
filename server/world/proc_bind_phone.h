#pragma once
#include <net\packet_manager.h>
#include "client2world_bind_phone.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initBindPhonePacket();

// ������ֻ�
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_bind_phone, game_player);
// ������ֻ����
PACKET_REGEDIT_SEND(packetw2c_req_bind_phone_result);

// ������֤
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_verify_code, game_player);
// ������֤���
PACKET_REGEDIT_SEND(packetw2c_req_verify_code_result);


// �������ֻ�
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_relieve_phone, game_player);
PACKET_REGEDIT_SEND(packetw2c_req_relieve_phone_result);

// ��������֤
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_relieve_verify, game_player);
PACKET_REGEDIT_SEND(packetw2c_req_relieve_verify_result);
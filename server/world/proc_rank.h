#pragma once
#include <net\packet_manager.h>
#include "world_peer.h"
#include "client2world_rank.pb.h"

using namespace client2world_protocols;
class game_player;

void initRankPacket();

// ����������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_coin_rank, game_player);
// ���������н��
PACKET_REGEDIT_SEND(packetw2c_req_coin_rank_result);



PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_recharge_rank, game_player);

PACKET_REGEDIT_SEND(packetw2c_req_recharge_rank_result);

// ��������������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_coin_growth, game_player);
// �����������������
PACKET_REGEDIT_SEND(packetw2c_req_coin_growth_result);

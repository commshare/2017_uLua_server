#pragma once
#include <net\packet_manager.h>
#include "client2world_star_lottery.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initStarLotteryPacket();

// ����ת�̳齱
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_star_lottery_info, game_player);
// ����ת�̳齱���
PACKET_REGEDIT_SEND(packetw2c_star_lottery_info_result);

// ����ת�̱�־
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_star_lottery, game_player);
// ����齱���
PACKET_REGEDIT_SEND(packetc2w_req_star_lottery_result);



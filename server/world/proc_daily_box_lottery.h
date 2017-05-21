#pragma once
#include <net\packet_manager.h>
#include "client2world_daily_box_lottery.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initDailyBoxLotteryPacket();

// ������齱
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_lottery_box, game_player);
// ������齱���
PACKET_REGEDIT_SEND(packetw2c_req_lottery_box_result);

// лл����һ���ȯ
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_thankyou_exchange_ticket, game_player);
// лл����һ���ȯ���
PACKET_REGEDIT_SEND(packetw2c_thankyou_exchange_ticket_result);



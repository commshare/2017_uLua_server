#pragma once
#include <net\packet_manager.h>
#include "client2world_notice.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initNoticePacket();

// ���󹫸�
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_notice, game_player);
// ���󹫸���
PACKET_REGEDIT_SEND(packetw2c_req_notice_result);



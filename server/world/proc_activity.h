#pragma once
#include <net\packet_manager.h>
#include "client2world_activity.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initActivityPacket();

// ��ȡ�����
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_receive_activity_reward, game_player);
// ��ȡ��������
PACKET_REGEDIT_SEND(packetw2c_receive_activity_reward_result);



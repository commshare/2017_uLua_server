#pragma once
#include <net\packet_manager.h>
#include "client2world_exchange.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initExchangePacket();

// ����һ�
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_exchange, game_player);
// ����һ����
PACKET_REGEDIT_SEND(packetw2c_exchange_result);

// ȡ�öһ�״̬
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_get_exchange_state, game_player);
// ȡ�öһ�״̬���
PACKET_REGEDIT_SEND(packetw2c_get_exchange_state_result);


// ����
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_shopping, game_player);
// ������
PACKET_REGEDIT_SEND(packetw2c_shopping_result);

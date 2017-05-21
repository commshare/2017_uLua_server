#pragma once
#include <net\packet_manager.h>
#include "client2world_chat.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initChatPacket();

// ��������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_chat, game_player);
// ����������
PACKET_REGEDIT_SEND(packetw2c_chat_result);

// ͨ��
PACKET_REGEDIT_SEND(packetw2c_notify);

// ��ҷ����ͨ����Ϣ
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_player_notify, game_player);
// ��ҷ����ͨ����Ϣ
PACKET_REGEDIT_SEND(packetw2c_player_notify_result);

// ���������С����
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_player_continuous_send_speaker, game_player);
// ���������С������Ϣ
PACKET_REGEDIT_SEND(packetw2c_player_continuous_send_speaker_result);

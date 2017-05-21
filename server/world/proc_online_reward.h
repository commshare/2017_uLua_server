#pragma once
#include <net\packet_manager.h>
#include "client2world_online_reward.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initOnlineRewardPacket();

// ��ȡ���߽���
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_receive_online_reward, game_player);
// ��ȡ���߽������
PACKET_REGEDIT_SEND(packetw2c_receive_online_reward_result);

// ��ȡ��ֵ����
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_receive_recharge_reward, game_player);
// ��ȡ��ֵ�������
PACKET_REGEDIT_SEND(packetw2c_receive_recharge_reward_result);

// �������߽�������ȡ��Ϣ
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_online_reward_info, game_player);
// �������߽�������ȡ��Ϣ���
PACKET_REGEDIT_SEND(packetw2c_req_online_reward_info_result);


#pragma once
#include <net\packet_manager.h>
#include "client2world_dial_lottery.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initDialLotteryPacket();

// ����ת�̳齱
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_dial_lottery, game_player);
// ����ת�̳齱���
PACKET_REGEDIT_SEND(packetw2c_req_dial_lottery_result);

// ����ת�̱�־
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_dial_lottery_flag, game_player);
// ����ת�̱�־���
PACKET_REGEDIT_SEND(packetw2c_req_dial_lottery_flag_result);

// ��ȡ�¿�����
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_month_card_reward, game_player);
// ��ȡ�¿��������
PACKET_REGEDIT_SEND(packetw2c_req_month_card_reward_result);


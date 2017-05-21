#pragma once
#include <net\packet_manager.h>
#include "client2world_friend.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initFriendPacket();

// ��Ӻ���
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_add_friend, game_player);
// ��Ӻ��ѽ��
PACKET_REGEDIT_SEND(packetw2c_add_friend_result);

// �Ƴ�����
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_remove_friend, game_player);
// �Ƴ����ѽ��
PACKET_REGEDIT_SEND(packetw2c_remove_friend_result);

// ��������б�
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_friend_list, game_player);
// ��������б���
PACKET_REGEDIT_SEND(packetw2c_req_friend_list_result);

// ��������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_search_friend, game_player);
// �������ѽ��
PACKET_REGEDIT_SEND(packetw2c_search_friend_result);

// ������ѷ���
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_enter_friend_room, game_player);
// ������ѷ�����
PACKET_REGEDIT_SEND(packetw2c_enter_friend_room_result);


// ��ȡ����������Ϸid
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_get_friend_gameid, game_player);
// ���غ�����Ϸid
PACKET_REGEDIT_SEND(packetw2c_get_friend_gameid_result);


#pragma once
#include <net\packet_manager.h>
#include "client2world_player_property.pb.h"
#include "world_peer.h"

using namespace client2world_protocols;
class game_player;

void initPlayerPropertyPacket();

// �޸�ͷ��
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_update_playerhead, game_player);
// �޸�ͷ����
PACKET_REGEDIT_SEND(packetw2c_update_playerhead_result);

// �޸��ǳ�
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_update_nickname, game_player);
// �޸��ǳƽ��
PACKET_REGEDIT_SEND(packetw2c_update_nickname_result);

// �޸��Ա�
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_update_sex, game_player);
// �޸��Ա���
PACKET_REGEDIT_SEND(packetw2c_update_sex_result);

// �޸�ǩ��
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_update_signature, game_player);
// �޸�ǩ�����
PACKET_REGEDIT_SEND(packetw2c_update_signature_result);

// �ı����
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_change_photo_frame, game_player);
// �ı������
PACKET_REGEDIT_SEND(packetw2c_change_photo_frame_result);

// ��ȡս��ͳ��
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_game_stat, game_player);
// �����ս��ͳ�ƽ��
PACKET_REGEDIT_SEND(packetw2c_fishlord_stat_result);
// ������ս��ͳ�ƽ��
PACKET_REGEDIT_SEND(packetw2c_dice_stat_result);
// �����ս��ͳ�ƽ��
PACKET_REGEDIT_SEND(packetw2c_crocodile_stat_result);

// ���˼�¼
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_self_record, game_player);
// ���˼�¼���
PACKET_REGEDIT_SEND(packetw2c_req_self_record_result);

// ���ĳ����������
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_finish_one_new_guild, game_player);
// ���ĳ�������������
PACKET_REGEDIT_SEND(packetw2c_finish_one_new_guild_result);

// ����������־
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_send_gift_log, game_player);
// ����������־���
PACKET_REGEDIT_SEND(packetw2c_req_send_gift_log_result);

// ����������־
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_req_safebox_log, game_player);
// ����������־���
PACKET_REGEDIT_SEND(packetw2c_req_safebox_log_result);

// �ٱ�ͷ��
PACKET_REGEDIT_RECVGATE(world_peer, packetc2w_inform_playerhead, game_player);
// �ٱ�ͷ����
PACKET_REGEDIT_SEND(packetw2c_inform_playerhead_result);



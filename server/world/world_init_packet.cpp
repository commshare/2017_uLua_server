#include "stdafx.h"
#include "world_server.h"
#include "proc_server_packet.h"
#include "proc_world_packet.h"
#include "proc_c2w_lobby_protocol.h"
#include "proc_logic2world_protocol.h"
#include "proc_dial_lottery.h"
#include "proc_player_property.h"
#include "proc_mail.h"
#include "proc_rank.h"
#include "proc_chat.h"
#include "proc_exchange.h"
#include "proc_shop.h"
#include "proc_friend.h"
#include "proc_online_reward.h"
#include "proc_safe_deposit_box.h"
#include "proc_logic2world_friend.h"
#include "proc_benefits.h"
#include "proc_notice.h"
#include "proc_bind_phone.h"
#include "proc_daily_box_lottery.h"
#include "proc_logic2world_robot.h"
#include "proc_activity.h"
#include "proc_star_lottery.h"
#include "proc_player_quest.h"

void world_server::init_packet()
{
	__ENTER_FUNCTION;
	//�ȼý�
	initBenefitsPacket();

	//gate��world��ͨ��,�������û���¼,֧��,��gm����
	initLobbyProtocol();

	//���칦��
	initChatPacket();

	//logic��worldͨ��
	initLogic2WorldPacket();

	//ת�̳齱
	initDialLotteryPacket();

	//������Ե�һЩ����
	initPlayerPropertyPacket();

	//montior��world���ͨ��
	initServerPacket();

	//�ʼ�
	initMailPacket();

	//����ϵͳ
	initRankPacket();

	//�һ�
	initExchangePacket();

	//�̵�
	initShopPacket();

	//����
	initFriendPacket();

	//���߽���
	initOnlineRewardPacket();

	//������
	initSafeDepositBoxPacket();

	//login��worldͨ����������ѵķ���
	initLogic2WorldFriend();

	//���������ͨ��,�������з�����
	initWorldPacket();

	initNoticePacket();

	initBindPhonePacket();

	initDailyBoxLotteryPacket();

	initLogic2WorldRobot();

	initActivityPacket();

	initStarLotteryPacket();

	initQuestPacket();
	__LEAVE_FUNCTION
}
using System;
using System.Collections.Generic;
using System.Web;
using System.IO;

public struct TableName
{
    // �����Ϣ��
    public const string PLAYER_INFO = "player_info";

    // �ʼ���
    public const string PLAYER_MAIL = "playerMail";

    // �ʼ�����
    public const string CHECK_MAIL = "checkMail";

    // ����˺ű�
    public const string PLAYER_ACCOUNT = "AccountTable";

    // GM�˺ű�
    public const string GM_ACCOUNT = "GmAccount";

    // ������
    public const string COUNT_TABLE = "OpLogCurID_DWC";

    // GM������־��
    public const string OPLOG = "OpLogDWC";

    // Ȩ�ޱ�
    public const string RIGHT = "rightDWC";

    // ��ҵ�½��ʷ
    public const string PLAYER_LOGIN = "LoginLog";

    // ��IP��
    public const string BLOCK_IP = "blockIP";

    // ��̨��ֵ
    public const string GM_RECHARGE = "gmRecharge";

    // ����Ӧ��
    public const string JPUSH_APP = "jpushAppInfoList";

    // ��ҽ�ң���ʯ�仯�ܱ�
    public const string PUMP_PLAYER_MONEY = "pumpPlayerMoney";

    // ÿ�������
    public const string PUMP_DAILY_TASK = "pumpDailyTask";

    // �ɾ�
    public const string PUMP_TASK = "pumpTask";

    // �齱
    public const string PUMP_LOTTERY = "pumpLottery";

    // �ʼ�
    public const string PUMP_MAIL = "pumpMail";

    // ǩ��
    public const string PUMP_PLAYER_SIGN = "pumpPlayerSign";

    // �̵깺��
    public const string PUMP_SHOP_BUY = "pumpShopBuy";

    // ��Ծ����
    public const string PUMP_ACTIVE_COUNT = "pumpActiveCount";

    // ��Ծ����
    public const string PUMP_ACTIVE_PERSON = "pumpActivePerson";

    // ͨ������ͳ��
    public const string PUMP_GENERAL_STAT = "pumpGeneralStat";

    // ��������
    public const string PUMP_SEND_GIFT = "pumpSendGift";

    // ���ͳ��
    public const string PUMP_PHOTO_FRAME = "pumpPhotoFrame";

    // �ܵ�����ͳ��
    public const string PUMP_TOTAL_CONSUME = "pumpTotalConsume";

    // ����ÿ����������
    public const string PUMP_FISHLORD_EVERY_DAY = "fishlordEveryDay";

    // ����ÿ����������
    public const string PUMP_CROCODILE_EVERY_DAY = "CrocodileEveryday";

    // ����ÿ����������
    public const string PUMP_DICE_EVERY_DAY = "DiceEveryday";

    // ������ע���񽱴���
    public const string PUMP_CROCODILE_BET = "CrocodileBetInfo";

    // ����������ע�������
    public const string PUMP_DICE = "dice_table";

    // ���ͳ��
    public const string PUMP_ALL_FISH = "AllFishLog";

    // ����ʱ�ɵ�ӯ����
    public const string PUMP_OLD_EARNINGS_RATE = "pumpOldEarningsRate";

    // ���䲶��׶α�
    public const string PUMP_FISH_TABLE_LOG = "FishTableLog";

    // ���
    public const string GIFT = "gift";

    // ������
    public const string GIFT_CODE = "giftCode";

    // �һ���
    public const string EXCHANGE = "exchange";

    // ��Ӫ�����
    public const string OPERATION_NOTIFY = "optionNotify";

    // ���㷿��
    public const string FISHLORD_ROOM = "fishlord_room";

    // ���㷿��
    public const string CROCODILE_ROOM = "crocodile_room";

    // ��������
    public const string DICE_ROOM = "dice_room";

    // ���¼������
    public const string RELOAD_FISHCFG = "fishlord_cfg";

    // �ͷ���Ϣ��
    public const string SERVICE_INFO = "serviceInfo";

    public const string COMMON_CONFIG = "common_config";

    // ��Ϸ��ֵ��Ϣ
    public const string GAME_RECHARGE_INFO = "pay_infos";
}

public enum ItemType
{
    e_itd_material = 1,		    //����

    e_itd_heroChip = 2,		    //��Ƭ//Ӣ�ۿ���

    e_itd_equip = 3,	        //װ��

    e_itd_consumables = 4,	    //����Ʒ

    e_itd_gold = 5,			    //���

    e_itd_gem = 6,			    //��ʯ

    e_itd_spirit = 7,			//����	

    e_itd_playerexp = 8,		//��Ҿ���

    e_itd_heroexp = 9,		    //Ӣ�۾���

    e_itd_hero = 10,			//Ӣ��

    e_itd_arena_money = 11,     // ����������

    e_itd_expedition_money = 12, // Զ������

    e_itd_guild_money = 13,		 // �������

    e_itd_materialChip = 14,	//������Ƭ
}

public struct StrName
{
    // �������
    public static string[] s_MineName = { "С", "��", "��" };

    // �����Դ����
    public static string[] s_resType = { "���", "ҩƷ", "��ʯ" };

    public static string[] s_rechargeType = { "�����" };

    public static string[] s_jobName = { "�᳤", "��Ӣ", "��ͨ��Ա" };

    public static string[] s_statLobbyName = { "ȫ��", "��������", "С����", "vip�ȼ��ֲ����", "�ϴ�ͷ��",
                                               "�ǳ��޸�", "ǩ���޸�", "�Ա��޸�", "ͷ�����", "���߽���",
                                             "�ȼý�","���������","������ȡ��"};

    public static string[] s_gameName = { "����", "���䲶��", "������", "��������" };

    public static string[] s_roomName = { "������", "�м���", "�߼���", "VIPר��" };

    public static string[] s_stageName = { "������", "������", "С����", "����", "С����", "�е���", "�����" };
}

public enum PaymentType
{
    e_pt_none = 0,
    e_pt_anysdk,        //anysdk�ۺ�
    e_pt_qbao,          //Ǯ��
    e_pt_max,
}

// ��ҽ�ң���ʯ�ı仯ԭ��
public enum PropertyReasonType
{
    // ÿ�յ�¼ת�̳齱
	type_reason_dial_lottery = 1,

	// ���߽���
	type_reason_online_reward = 2,

	// ���������
	type_reason_deposit_safebox = 3,

	// ������ȡ��
	type_reason_draw_safebox = 4,

	// ��������
	type_reason_send_gift = 5,

	// ��������
	type_reason_accept_gift = 6,

	// ��ҷ�С���ȣ�ȫ��ͨ��
	type_reason_player_notify = 7,
	
	// ��Ҷһ�����
	type_reason_exchange = 8,

	// ������Ʒ���
	type_reason_buy_commodity_gain = 9,

	// ��ȡ�ȼý�
	type_reason_receive_alms = 10,

	// ���ֽ���
	type_reason_single_round_balance = 11,

	// ������Ʒ����
	type_reason_buy_commodity_expend = 12,
	
	//������ȼ�
	type_reason_buy_fishlevel = 13,

	//���������
	type_reason_buy_fishitem = 14,

	//��������
    type_reason_fish_uplevel = 15,

    // ��������
    type_reason_new_guild = 16,

    // �޸�ͷ��
	type_reason_update_icon = 17,

	// ��ֵ
	type_reason_recharge = 18,

	// �޸��ǳ�
	type_reason_modify_nickname = 19,

    // ��ֵ����
	type_reason_recharge_send = 20,

    // ��̨��ֵ
	type_reason_gm_recharge = 21,

	// ��̨��ֵ����
	type_reason_gm_recharge_send = 22,

    // �¿�ÿ����ȡ
    type_reason_month_card_daily_recv = 23,

    // ��ֵ���
    type_reason_recharge_gift = 24,

    type_max,
};

// ���ӵ�е���������
public enum PropertyType
{
    property_type_full,

    // ���
    property_type_gold,

    // ��ȯ
    property_type_ticket,
}

public enum DataStatType
{
    // ��������
    stat_send_gift = 1,

    // С����
    stat_player_notify,

    // vip�ȼ��ֲ����
    stat_player_vip_level,

    // �ϴ�ͷ��
    stat_upload_head_icon,

    // �ǳ��޸�
    stat_nickname_modify,

    // ǩ���޸�
    stat_self_signature_modify,

    // �Ա��޸�
    stat_sex_modify,

    // ͷ�����
    stat_photo_frame,

    // ���߽���
    stat_online_reward,

    // �ȼý�
    stat_relief,

    // ���������
    stat_safe_box_deposit,

    // ������ȡ��
    stat_safe_box_draw,

    stat_max,
};

public enum GameId 
{
    lobby = 0,   // ����
    fishlord = 1, // ���䲶��

    crocodile,    // ������

    dice,         // ��������

    gameMax,
}


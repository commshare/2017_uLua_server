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

    // �����
    public const string PLAYER_QUEST = "player_quest";

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
    // ţţ���ֵ����ͱ�
    public const string PUMP_COWS_CARD = "logCowsInfo";

    // ��ҽ�ң���ʯ�仯��ϸ��
    public const string PUMP_PLAYER_MONEY_DETAIL = "logPlayerInfo";

    // ÿ�������
    public const string PUMP_DAILY_TASK = "pumpDailyTask";

    // �ɾ�
    public const string PUMP_TASK = "pumpTask";

    // �ʼ�
    public const string PUMP_MAIL = "pumpMail";

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

    // �����������
    public const string PUMP_COIN_GROWTH = "pumpCoinGrowth";

    // ���������ʷ����
    public const string PUMP_COIN_GROWTH_HISTORY = "pumpCoinGrowthHistory";

    // ���䲶�����ı�
    public const string FISH_CONSUME = "pumpFishConsume";

    // ����ÿ����������
    public const string PUMP_FISHLORD_EVERY_DAY = "fishlordEveryDay";

    // ����ÿ����������
    public const string PUMP_CROCODILE_EVERY_DAY = "CrocodileEveryday";

    // ����ÿ����������
    public const string PUMP_DICE_EVERY_DAY = "DiceEveryday";

    // �ټ���ÿ����������
    public const string PUMP_BACCARAT_EVERY_DAY = "BaccaratEveryday";

    // ����ÿ����������
    public const string PUMP_DRAGON_EVERY_DAY = "DragonEveryday";

    // ���㹫԰ÿ����������
    public const string PUMP_FISHPARK_EVERY_DAY = "fishParkEveryDay";

    // �ں�÷��ÿ����������
    public const string PUMP_SHCD_EVERY_DAY = "ShcdCardsEveryday";

    // ��ţÿ����������
    public const string PUMP_CALFROPING_EVERY_DAY = "ropingEveryDay";

    // �ټ��������ׯ�����ѯ
    public const string PUMP_PLAYER_BANKER = "pumpBaccaratPlayerBanker";

    // ţţÿ����������
    public const string PUMP_COWS_EVERY_DAY = "CowsEveryday";

    // ţţ�����ׯ�����ѯ
    public const string PUMP_PLAYER_BANKER_COWS = "pumpCowsPlayerBanker";

    // ������ע���񽱴���
    public const string PUMP_CROCODILE_BET = "CrocodileBetInfo";

    // ����������ע�������
    public const string PUMP_DICE = "dice_table";

    // ���ͳ��
    public const string PUMP_ALL_FISH = "AllFishLog";
    // ���㹫԰���ͳ��
    public const string PUMP_ALL_FISH_PARK = "AllFishParkLog";

    // ����ʱ�ɵ�ӯ����
    public const string PUMP_OLD_EARNINGS_RATE = "pumpOldEarningsRate";

    // ���䲶��׶α�
    public const string PUMP_FISH_TABLE_LOG = "FishTableLog";
    // ���㹫԰�׶α�
    public const string PUMP_FISH_PARK_TABLE_LOG = "FishParkTableLog";

    // ����������
    public const string PUMP_MAXONLINE_PLAYER = "pumpMaxOnlinePlayer";

    // ÿ��0��������ҵĽ���ܺ�ͳ�Ʊ�
    public const string PUMP_PLAYER_TOTAL_MONEY = "pumpPlayerTotalMoney";

    // ���ѵ�ͳ��
    public const string PUMP_RECHARGE = "pumpRecharge";

    // ��ֵ�û�ͳ��
    public const string PUMP_RECHARGE_PLAYER = "pumpRechargePlayer";

    // ���
    public const string GIFT = "gift";

    // ������
    public const string GIFT_CODE = "giftCode";

    // �һ���
    public const string EXCHANGE = "exchange";

    // ��Ӫ�����
    public const string OPERATION_NOTIFY = "optionNotify";

    // ͨ����Ϣ
    public const string OPERATION_SPEAKER = "operationSpeaker";

    // ���㷿��
    public const string FISHLORD_ROOM = "fishlord_room";
    // ���㹫԰����
    public const string FISHPARK_ROOM = "fishpark_room";

    // ��������
    public const string FISHLORD_ROOM_DESK = "fishlord_table";
    // ���㹫԰����
    public const string FISHPARK_ROOM_DESK = "fishpark_table";

    // ���㷿��
    public const string CROCODILE_ROOM = "crocodile_room";

    // ��������
    public const string DICE_ROOM = "dice_room";

    // �ټ��ַ���
    public const string BACCARAT_ROOM = "baccarat_room";

    // ţţ����
    public const string COWS_ROOM = "cows_room";

    // ��������
    public const string DRAGON_ROOM = "dragons_room";

    // �ں�÷������
    public const string SHCDCARDS_ROOM = "shcdcards_room";

    // ��ţ����
    public const string CALF_ROPING_ROOM = "calfRoping_lobby";
    // ��ţ ţ�ķ��� ͳ��
    public const string CALF_ROPING_LOG = "ropingLog";
    // ��ţ�ؿ�ͳ��
    public const string CALF_ROPING_PASS_LOG = "ropingPassLog";

    // ������Ϸģʽ�µ�ӯ����
    public const string DRAGON_TABLE = "dragons_table";

    // ţţ�����ͱ�
    public const string COWS_CARDS = "cows_cards";

    // �ں�÷���Ľ������
    public const string SHCD_RESULT = "shcdcards_gm_cards";

    // ���¼������
    public const string RELOAD_FISHCFG = "fishlord_cfg";
    public const string RELOAD_FISHPARK_CFG = "fishpark_cfg";

    // �ټ�����ʷ��¼
    public const string HISTORY_BACCARAT = "HistoryBaccarat";
    // ������ʷ��¼
    public const string HISTORY_DICE = "HistoryDice";
    // ţţ��ʷ��¼
    public const string HISTORY_COWS = "logCowsInfo";
    // ��������ʷ��¼
    public const string HISTORY_CROCODILE = "HistoryCrocodile";
    // �ں�÷����ʷ��¼
    public const string HISTORY_SHCD = "pumpShcdCardsLog";

    // �ͷ���Ϣ��
    public const string SERVICE_INFO = "serviceInfo";

    public const string COMMON_CONFIG = "common_config";

    // ��Ϸ��ֵ��Ϣ
    public const string GAME_RECHARGE_INFO = "pay_infos";

    // ������Ϸ��
    public const string TEST_SERVER = "TestServers";

    // ���䲶����ұ�
    public const string FISHLORD_PLAYER = "fishlord_player";
    // ���㹫԰��ұ�
    public const string FISHPARK_PLAYER = "fishpark_player";

    // ͷ��ٱ�
    public const string INFORM_HEAD = "informHead";

    // �߳����
    public const string KICK_PLAYER = "KickPlayer";

    public const string DAY_ACTIVATION = "day_activation";
    // ��������ͳ����
    public const string CHANNEL_STAT_DAY = "channelStatDay";
    // ������ص�ͳ������
    public const string CHANNEL_TD = "channelTalkingData";
    // ������صĳ�ֵͳ��
    public const string CHANNEL_TD_PAY = "channelTalkingDataPay";

    // ���ӵ�е��ܽ��ͳ����
    public const string TOTAL_MONEY_STAT_DAY = "totalMoneyStatDay";

    // �����ܹھ�
    public const string MATCH_GRAND_PRIX_WEEK_CHAMPION = "fishlord_match_champion";

    public const string MATCH_GRAND_PRIX_DAY = "fishlord_match_day";

    // ��֧�ܼ� ��
    public const string STAT_INCOME_EXPENSES_NEW = "statIncomeExpensesNew";
    // ÿ����֧�������ݿ����
    public const string STAT_INCOME_EXPENSES_REMAIN = "statIncomeExpensesRemain";
}

public static class StrName
{
    public static string[] s_rechargeType = { "�����" };

    public static string[] s_statLobbyName = { "ȫ��", "��������", "С����", "vip�ȼ��ֲ����", "�ϴ�ͷ��",
                                               "�ǳ��޸�", "ǩ���޸�", "�Ա��޸�", "ͷ�����", "���߽���",
                                             "�ȼý�","���������","������ȡ��"};

    public static string[] s_gameName = { "����", "���䲶��", "������", "��������", "����ţţ", "�ټ���", "����", "��ţ", 
                                            "ץ����", "���㹫԰", "�ں�÷��" };

    public static string[] s_gameName1 = { "ϵͳ", s_gameName[1], s_gameName[2], s_gameName[3], 
                                             s_gameName[4], s_gameName[5], s_gameName[6],
                                             s_gameName[7], s_gameName[8], s_gameName[9],s_gameName[10] };

    public static string[] s_roomName = { "������", "�м���", "�߼���", "VIPר��" };

    public static string[] s_fishRoomName = { s_roomName[0], s_roomName[1], s_roomName[2], s_roomName[3], 
                                                "��ͨ��������", "��ͨ���м���", "��ͨ���߼���", "��ͨ����ʦ��", "����" };

    public static string[] s_dragonRoomName = { "������", "�߼���", "��ʦ��" };

    public static string[] s_stageName = { "������", "������", "С����", "����", "С����", "�е���", "�����" };

    private static Dictionary<string, string> s_gameName2 = new Dictionary<string, string>();

    public static string[] s_cowsArea = { "��", "��", "��", "��" };

    public static string[] s_shcdArea = { "����", "����", "÷��", "����", "��С��" };

    public static string[] s_wishCurse = { "ף��", "����" };

    public static string getGameName(string key)
    {     
        if (s_gameName2.Count == 0)
        {
            s_gameName2.Add("lobby", s_gameName[0]);
            s_gameName2.Add("fish", s_gameName[1]);
            s_gameName2.Add("crocodile", s_gameName[2]);
            s_gameName2.Add("dice", s_gameName[3]);
            s_gameName2.Add("Cows", s_gameName[4]);
            s_gameName2.Add("baccarat", s_gameName[5]);
            s_gameName2.Add("ShcdCards", s_gameName[10]);
            s_gameName2.Add("5Dragons", s_gameName[(int)GameId.dragon]);
        }

        if (s_gameName2.ContainsKey(key))
            return s_gameName2[key];
        return key;
    }
}

public enum PaymentType
{
    e_pt_none = 0,
    e_pt_anysdk,        //anysdk�ۺ�
    e_pt_qbao,          //Ǯ��
    e_pt_baidu,         //�ٶ�
    e_pt_yoyangs,
    e_pt_shuanglong,      
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

    // ÿ��ǩ��
	type_reason_daily_sign = 25,

	// ÿ�ձ���齱
	type_reason_daily_box_lottery = 26,

	// лл����һ�
	type_reason_thank_you_exchange = 27,

	// ������С����
	type_reason_continuous_send_speaker = 28,

	// ��ȡ�ʼ�
	type_reason_receive_mail = 29,

    // �������
	type_reason_fishlord_drop = 30,

    // �����˺�
	type_reason_create_account = 31,

    // ��ȡ�����
	type_reason_receive_activity_reward = 32,

    // �ټ�����ׯ
	type_reason_rob_banker = 33,
	
	// �ټ�����ǰ��ׯ
	type_reason_leave_banker = 34,

	// ʹ�ü���
    type_reason_use_skill = 35,

    //����������Ϸʹ����ʯ
	type_reason_double_game = 36,
	
	//�������� //��ʯ����ͽ��֧��
	type_reason_dragons_lv = 37,	

	//���ǽ���
	type_reason_star_award = 38,
	//���ǳ齱	
	type_reason_star_lottery = 39,

	//�������
	type_reason_new_player = 40,

    //����
	type_reason_daily_task = 41,
	//�ɾ�
	type_reason_achievement = 42,

    // ��������
    type_reason_missile = 43,

    // ��ֵ�齱
    type_reason_recharge_lottery = 44,

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

    // ������Ƭ
    property_type_chip = 11,	
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

    cows,         // ����ţţ
    
    baccarat,     // �ټ���
    
    dragon,       // ����

    calf_roping,   // ��ţ
    prize_claw,    // ץ����

    fishpark,     // ���㹫԰

    shcd,         // �ں�÷��

    gameMax,
}

//////////////////////////////////////////////////////////////////////////

// ������������
public enum FishLordExpend
{
    fish_buyitem_start,			//������Ʒ Fish_ItemCFG
    fish_buyitem_end = fish_buyitem_start + 31,

    fish_useskill_start = 100,	//ʹ�ü��� Fish_BuffCFG
    fish_useskill_end = fish_useskill_start + 10,

    fish_turrent_uplevel_start = 150,         // ��̨������ʼ
    fish_turrent_uplevel_end = fish_turrent_uplevel_start + 55,

    fish_unlock_level_start = 300,
    fish_unlock_level_end = fish_unlock_level_start + 55,

    // ��������
    fish_missile = 500,
    fish_missile_end = 500 + 3,
};

//////////////////////////////////////////////////////////////////////////
public class GameStatData
{
    // ����ע������
    public int m_regeditCount;

    // �����豸��������
    public int m_deviceActivationCount;

    // ��Ծ����
    public int m_activeCount;

    // ����������
    public int m_totalIncome;

    // ��������
    public int m_rechargePersonNum;

    // ���Ѵ���
    public int m_rechargeCount;

    // �����������û������ܼ�
    public int m_newAccIncome;
    // �����������û��У������û�����
    public int m_newAccRechargePersonNum;

    // �����ʼ���ʱ����ע������
    //public int m_2DayRegeditCount;

    // ������������
    public int m_2DayRemainCount;

    //public int m_3DayRegeditCount;

    // 3����������
    public int m_3DayRemainCount;

    //public int m_7DayRegeditCount;

    // 7����������
    public int m_7DayRemainCount;

    //public int m_30DayRegeditCount;

    // 30����������
    public int m_30DayRemainCount;

    // 1���ܳ�ֵ�� -1��ʾ��û������
    public int m_1DayTotalRecharge = -1;
    // 3���ܳ�ֵ�� -1��ʾ��û������
    public int m_3DayTotalRecharge = -1;
    // 7���ܳ�ֵ�� -1��ʾ��û������
    public int m_7DayTotalRecharge = -1;
    // 14���ܳ�ֵ�� -1��ʾ��û������
    public int m_14DayTotalRecharge = -1;
    // 30���ܳ�ֵ�� -1��ʾ��û������
    public int m_30DayTotalRecharge = -1;
    // 60���ܳ�ֵ�� -1��ʾ��û������
    public int m_60DayTotalRecharge = -1;
    // 90���ܳ�ֵ�� -1��ʾ��û������
    public int m_90DayTotalRecharge = -1;

    //////////////////////////////////////////////////////////////////////////
    // �����豸������������ʱ����
    public int m_2DayDevRemainCount = -1;

    // 3���豸��������
    public int m_3DayDevRemainCount = -1;

    // 7���豸��������
    public int m_7DayDevRemainCount = -1;

    // 30���豸��������
    public int m_30DayDevRemainCount = -1;

    //////////////////////////////////////////////////////////////////////////
    // ���ո���������������ʱ����
    public int m_2DayRemainCountRecharge = -1;

    // 3�ո�����������
    public int m_3DayRemainCountRecharge = -1;

    // 7�ո�����������
    public int m_7DayRemainCountRecharge = -1;

    // 30�ո�����������
    public int m_30DayRemainCountRecharge = -1;
}

public struct ConstDef
{
    // 24Сʱʱ���ʽ
    public static string DATE_TIME24 = "yyyy-MM-dd HH:mm:ss";
}

//////////////////////////////////////////////////////////////////////////
public class ResultRPlayerItem
{
    public int m_playerId;
    public int m_rechargeCount;
    public int m_rechargeMoney;
    public int m_loginCount;
    public Dictionary<int, int> m_games = new Dictionary<int, int>();

    public DateTime m_regTime;
    public DateTime m_lastLoginTime;
    public int m_remainGold;
    public int m_mostGold;

    public void addEnterCount(int gameId, int count)
    {
        m_games.Add(gameId, count);
    }

    public int getEnterCount(int gameId)
    {
        if (m_games.ContainsKey(gameId))
        {
            return m_games[gameId];
        }

        return 0;
    }
}

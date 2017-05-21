using System;
using System.Collections.Generic;
using System.Web;
using System.IO;

public struct TableName
{
    // �����Ϣ��
    public const string PLAYER_INFO = "player_info";

    // ����ڸ�����Ϸ�ڵ�Ͷע��ӯ�����
    public const string LOG_PLAYER_INFO = "logPlayerInfo";

    // ��Ӯͳ�Ʊ�
    public const string PLAYER_WIN_LOSE = "player_win_lose";

    // ��ͳ����Ӯ�ܶ�ı���ҵ�¼�ǳ���
    public const string PLAYER_FOR_WIN_LOSE = "playerForWinLoseStat";

    // �ʼ���
    public const string PLAYER_MAIL = "playerMail";

    // �ʼ�����
    public const string CHECK_MAIL = "checkMail";

    // ����˺ű�
    public const string PLAYER_ACCOUNT = "AccountTable";

    // GM�˺ŵĺ�׺��
    //public const string GM_ACCOUNT_POSTFIX = "account_postfix";

    // GM�˺ű�
    public const string GM_ACCOUNT = "gm_account";

    // ��������˺ű�
    public const string PLAYER_ACCOUNT_XIANXIA = "player_account";
    
    // ����GM�˺�����Ҫ������
    public const string CREATE_CONFIG = "count_config";

    // GM�Ϸ֣��·ֱ�
    public const string GM_SCORE = "log_score";

    // ��̨GM��¼��־
    public const string GM_LOGIN_LOG = "log_login";

    // ������Ϸ�ı�
    public const string PLAYER_GAME_SCORE = "player_game_score";

    // API��������
    public const string API_APPROVE = "api_approve";

    // �ȴ��������Ҷ���
    public const string PLAYER_ORDER_WAIT = "player_order_wait";

    // ����ɵ���Ҷ���
    public const string PLAYER_ORDER_FINISH = "player_order_finish";

    // ������
    public const string COUNT_TABLE = "OpLogCurID_DWC";

    // GM������־��
    public const string OPLOG = "log_gm_op";

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
    public const string PUMP_PLAYER_MONEY = "logPlayerInfo";
    // ţţ���ֵ����ͱ�
    public const string PUMP_COWS_CARD = "logCowsInfo";

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

    // ���㹫԰ÿ����������
    public const string PUMP_FISHPARK_EVERY_DAY = "fishParkEveryDay";

    // �ټ��������ׯ�����ѯ
    public const string PUMP_PLAYER_BANKER = "pumpBaccaratPlayerBanker";
    
    // ����ÿ����������
    public const string PUMP_DRAGON_EVERY_DAY = "DragonEveryday";

    // �ں�÷��ÿ����������
    public const string PUMP_SHCD_EVERY_DAY = "ShcdCardsEveryday";

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

    // �߳����
    public const string KICK_PLAYER = "KickPlayer";

    // ���䲶����ұ�
    public const string FISHLORD_PLAYER = "fishlord_player";
    // ���㹫԰��ұ�
    public const string FISHPARK_PLAYER = "fishpark_player";

    // �������Ĵ�������������mongodb
    public const string PLAYER_ORDER_REQ = "playerOrderReq";
    // ����������·� ����ɶ���
    public const string PLAYER_ORDER_COMPLETE = "order_complete";
    // api�����ص�����
    public const string API_ORDER_CALL = "apiOrderCall";

    // API���õ������ע����
    public const string API_MAX_BET_LIMIT = "apiMaxBetLimit";

    public const string API_MAX_BET_SETTING_LIMIT = "apiMaxBetSettingLimit";

    // ���ӵ�е��ܽ��ͳ����
    public const string TOTAL_MONEY_STAT_DAY = "statTimeByDay";
}

public class GameInfo
{
    public string m_gameName;
    public int m_gameId;

    public GameInfo(string name, int id)
    {
        m_gameName = name;
        m_gameId = id;
    }
}

// ������Ϣ
public class MoneyInfo
{
    public string m_moneyCode;
    public string m_moneyDesc;

    public MoneyInfo(string code, string desc)
    {
        m_moneyCode = code;
        m_moneyDesc = desc;
    }
}

public static class StrName
{
    public static string[] s_rechargeType = { "�����" };

    public static string[] s_statLobbyName = { "ȫ��", "��������", "С����", "vip�ȼ��ֲ����", "�ϴ�ͷ��",
                                               "�ǳ��޸�", "ǩ���޸�", "�Ա��޸�", "ͷ�����", "���߽���",
                                             "�ȼý�","���������","������ȡ��"};

    public static string[] s_gameName = { "����", "���䲶��", "������", "��������", "����ţţ", "�ټ���", "����", "��ţ", "ץ����", "����", "�ں�÷��", "", "", "���泡" };

    public static string[] s_gameName1 = { "ϵͳ", s_gameName[1], s_gameName[2], s_gameName[3], s_gameName[4], s_gameName[5], s_gameName[6], s_gameName[7], s_gameName[8], s_gameName[9] };

    public static string[] s_roomName = { "������", "�м���", "�߼���", "VIPר��" };

    public static string[] s_dragonRoomName = { "������", "�߼���", "��ʦ��" };

    public static string[] s_stageName = { "������", "������", "С����", "����", "С����", "�е���", "�����" };

    private static Dictionary<string, string> s_gameName2 = new Dictionary<string, string>();

    public static string[] s_cowsArea = { "��", "��", "��", "��" };

    public static string[] s_shcdArea = { "����", "����", "÷��", "����", "��С��" };
    public static string[] s_dragonArea = { "���ձ���", "��������", "��������" };

   // public static string[] s_moneyType = { "CNY", "USD" };

    public static string[] s_logFrom = { "", "��̨����", "API����", "��Ҷ���" };

    public static string[] s_accountType = { "��������Ա", 
                                             "�ܴ���", "����", "API��",
                                             "�������˺�", "��Ա", "API����Ա",
                                           "����Ա���˺�"};

    public static string s_rightDesc = "�����¼�����:{0}<br/>����API��:{1}";

    public static string[] s_stateName = { "����", "����", "��ͣ��" };

    public static string[] s_gmStateName = { "����", "ͣ��" };

    public static string[] s_scoreOpName = { "����", "���" };

    public static string[] s_playerOrderIdName = { "��ֵ", "���" };

    public static string[] s_playerOrderState = { "���", "������", "��ȡ��", "������� ���ύ" };

    public static string[] s_wishCurse = { "ף��", "����" };

    public static string[] s_realTimeOrderState = { "�ɹ�", "ʧ��" };

    private static Dictionary<int, string> s_realTimeOrderFailReason = new Dictionary<int, string>();

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
        }

        if (s_gameName2.ContainsKey(key))
            return s_gameName2[key];
        return key;
    }

    public static List<GameInfo> s_gameList = new List<GameInfo>();

    static StrName()
    {
        addGame((int)GameId.crocodile);
        addGame((int)GameId.dice);
        addGame((int)GameId.cows);
        addGame((int)GameId.baccarat);
        addGame((int)GameId.dragon);
        addGame((int)GameId.fishpark);
        addGame((int)GameId.shcd);
       // initMoneyInfo();
        initRealTimeOrderFailReason();
    }

    static void addGame(int id)
    {
        GameInfo info = new GameInfo(s_gameName[id], id);
        s_gameList.Add(info);
    }

    public static List<MoneyInfo> s_moneyInfo = new List<MoneyInfo>();

    static void initMoneyInfo()
    {
        addMoney("CNY", "�����CNY");
        addMoney("USD", "��ԪUSD");
        addMoney("HKD", "�۱�HKD");
        addMoney("KRW", "��ԪKRW");
        addMoney("MYR", "�������Ǳ�MYR");

        addMoney("SGD", "�¼��±�SGD");
        addMoney("JPY", "��ԪJPY");
        addMoney("THB", "̩��THB");
        addMoney("BTC", "���ر�BTC");

        addMoney("IDR", "ӡ���IDR");
        addMoney("VND", "Խ�϶�VND");
        addMoney("EUR", "ŷԪEUR");
        addMoney("AUD", "��ԪAUD");
        addMoney("GBP", "Ӣ��GBP");

        addMoney("CHF", "��ʿԪCHF");
        addMoney("MXP", "ī�������MXP");
        addMoney("CAD", "���ô�ԪCAD");
        addMoney("RUB", "����˹¬��RUB");
        addMoney("INR", "ӡ��¬��INR");

        addMoney("RON", "�������Ǳ�RON");
        addMoney("DKK", "�������DKK");
        addMoney("NOK", "Ų������NOK");
    }

    static void addMoney(string code, string desc)
    {
        MoneyInfo info = new MoneyInfo(code, desc);
        s_moneyInfo.Add(info);
    }

    public static string getMoneyCode(int moneyType)
    {
        return "";

        if (moneyType < 0 || moneyType >= s_moneyInfo.Count)
            return "";

        return s_moneyInfo[moneyType].m_moneyCode;
    }

    public static string getMoneyDesc(int moneyType)
    {
        if (moneyType < 0 || moneyType >= s_moneyInfo.Count)
            return "";

        return s_moneyInfo[moneyType].m_moneyDesc;
    }

    static void initRealTimeOrderFailReason()
    {
        s_realTimeOrderFailReason.Add(RetCode.RET_MONEY_NOT_ENOUGH, "����");
        s_realTimeOrderFailReason.Add(RetCode.RET_PLAYER_NOT_IN_LOBBY, "��Ҳ��ڴ���");
        s_realTimeOrderFailReason.Add(RetCode.RET_PLAYER_OFFLINE, "�������");
        s_realTimeOrderFailReason.Add(RetCode.RET_NO_PLAYER, "��Ҳ�����");
        s_realTimeOrderFailReason.Add(RetCode.RET_DB_ERROR, "db����");
        s_realTimeOrderFailReason.Add(RetCode.RET_PLYAER_LOCKED, "��ұ�����");
    }

    public static string getRealTimeOrderFailReason(int reason)
    {
        if (s_realTimeOrderFailReason.ContainsKey(reason))
            return s_realTimeOrderFailReason[reason];

        return reason.ToString();
    }
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

   //����������Ϸ����
	type_reason_double_game = 36,

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

    cows,         // ����ţţ
    
    baccarat,     // �ټ���

    dragon,       // ����

    calf_roping,   // ��ţ
    prize_claw,    // ץ����

    fishpark,     // ���㹫԰
    shcd,         // �ں�÷��
    fish_practice = 13,         // �������泡
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
};

public struct PlayerState
{
    // ���У�����
    public const int STATE_IDLE = 0;

    // ��Ϸ��
    public const int STATE_GAME = 1;

    // �˺ű�ͣ��
    public const int STATE_BLOCK = 2;
}

public struct GmState
{
    // ����
    public const int STATE_NORMAL = 0;

    // ͣ��
    public const int STATE_BLOCK = 1;
}

public struct OrderState
{
    // �����
    public const int STATE_FINISH = 0;

    // �ȴ�����
    public const int STATE_WAIT = 1;

    // ��ȡ��
    public const int STATE_CANCEL = 2;

    // ������ߣ��������ύ����
    public const int STATE_HAS_SUB = 3;
}

public struct AccType
{
    // ��������Ա
    public const int ACC_SUPER_ADMIN = 0;

    // �ܴ���
    public const int ACC_GENERAL_AGENCY = 1;

    // ����
    public const int ACC_AGENCY = 2;

    // API��
    public const int ACC_API = 3;

    // �������˺�
    public const int ACC_AGENCY_SUB = 4;

    // ���
    public const int ACC_PLAYER = 5;

    // API����Ա
    public const int ACC_API_ADMIN = 6;

    // ����Ա���˺�
    public const int ACC_SUPER_ADMIN_SUB = 7;
}

public struct ScropOpType
{
    // ����
    public const int ADD_SCORE = 0;
    // ��ȡ
    public const int EXTRACT_SCORE = 1;

    public static bool isAddScore(int opType)
    {
        return opType == ADD_SCORE;
    }
}

public struct SqlStrCMD
{
    public const string SQL_COUNT_INT = "SELECT COUNT(*) as cnt FROM {0} WHERE {1}={2}";

    public const string SQL_COUNT_CHAR = "SELECT COUNT(*) as cnt FROM {0} WHERE {1}='{2}'";

    public const string SQL_COUNT_WHERE = "SELECT COUNT(*) as cnt FROM {0} WHERE {1}";

    public const string SQL_COUNT_NO_WHERE = "SELECT COUNT(*) as cnt FROM {0} {1}";

//    public const string SQL_CREATE_GM_ACCOUNT = "INSERT into {0} (acc,pwd,accType,createTime,owner,generalAgency,postfix,money,moneyType,devSecretKey,gmRight,depth,createCode,aliasName) " +
//        " VALUES ('{1}','{2}', {3},'{4}','{5}','{6}','{7}',{8},{9},'{10}','{11}',{12},'{13}','{14}') ";

//     public const string SQL_CREATE_PLAYER_ACCOUNT =
//         "INSERT into {0} (acc,creator,money,moneyType,state,createTime,createCode,aliasName)" +
//         " VALUES ('{1}','{2}',{3},{4},{5},'{6}','{7}','{8}')";

    // ��ѯ��������һ�Ա{0}����˺ű� {1}gm�˺ű�
    public const string SQL_QUERY_PLAYER_MEMBER = "SELECT " +
                        " {0}.acc as playerAcc,{0}.sellerAdmin,{0}.createTime, {0}.money, {1}.owner as seller, {1}.moneyType  from " +
                        " {0}, {1} " +
                        " where {0}.sellerAdmin={1}.acc {2} " +
                        " LIMIT {3}, {4} ";

    // ��ʱ��ͳ�ƣ������ͳ��
    public const string STR_FTM1 = "SELECT date_format(opTime,'{0}' ) as dtime, COUNT(*) as cnt,  SUM(opScore) as sum, opType " +
                                    " from {1}" +
                                    " where {2} " +
                                    " GROUP BY dtime, opType ORDER BY opTime";

    // ���ۻ�ͤͳ��
    public const string STR_FTM2 = "SELECT COUNT(*) as cnt,  SUM(opScore) as sum, opType,opSrc " +
                                    " from {0}" +
                                    " where opSrc='{1}' and opTime >= '{2}' and opTime < '{3}' " +
                                    " GROUP BY opType,opSrc";

    // ���ۻ�ͤͳ��
    public const string SQL_STAT_STEP = "SELECT COUNT(*) as cnt,  SUM(opScore) as sum, opType,opSrc " +
                                        " from {0}" +
                                        " where {1} " +
                                        " GROUP BY opType,opSrc";

    // ���ۻ�ͤ����ͳ��
    public const string SQL_SELLER_STAT_ADMIN = "SELECT COUNT(*) as cnt,  SUM(opScore) as sum, opType,opDst " +
                                    " from {0}" +
                                    " where opTime >= '{1}' and opTime < '{2}' and " +
                                    " opDst in (SELECT {3}.acc from {3} where {3}.owner='{4}' and {3}.accType={5} ) " +
                                    " GROUP BY opType,opDst";

    // ��ѯGM�˺�
    public const string SQL_QUERY_GM_ACCOUNT = " SELECT * from {0}" +
                                               " where {1} " +
                                               " LIMIT {2}, {3} ";

    public const string SQL_CMD_PLAYER_SCORE = "INSERT into {0} (opTime,opSrc,opDst,opType,opScore,moneyType,opSrcDepth,opSrcCreateCode,opDstType,opDstRemainMoney) " +
                                                " VALUES ('{1}','{2}', '{3}',{4},{5},{6},{7},'{8}',{9},{10})";

    // ������Ϸ�
    public const string SQL_ADD_SCORE_TO_PLAYER = " UPDATE {0} set money=money+{1} where acc='{2}' and state={3} and creator='{4}' ";
    // ������Ϸ� Խ��
    public const string SQL_ADD_SCORE_TO_PLAYER_BYPASS = " UPDATE {0} set money=money+{1} where acc='{2}' and state={3} ";

    // ������·�
    public const string SQL_DEC_SCORE_TO_PLAYER = " UPDATE {0} set money=money-{1} where acc='{2}' and state={3} and money>={4} and creator='{5}' ";
    // ������·� Խ��
    public const string SQL_DEC_SCORE_TO_PLAYER_BYPASS = " UPDATE {0} set money=money-{1} where acc='{2}' and state={3} and money>={4} ";

    // �������Ϸ�
    public const string SQL_ADD_SCORE_TO_MGR = " UPDATE {0} set money=money+{1} where acc='{2}' ";

    // �������·�
    public const string SQL_DEC_SCORE_TO_MGR = " UPDATE {0} set money=money-{1} where acc='{2}' and money>={3} ";

    // �������Ϸ�
    public const string SQL_ADD_SCORE_TO_MGR_DIRECT = " UPDATE {0} set money=money+{1} where acc='{2}' ";

    // �������·�
    public const string SQL_DEC_SCORE_TO_MGR_DIRECT = " UPDATE {0} set money=money-{1} where acc='{2}' and money>={3} ";

    // ��������
    public const string SQL_UPDATE_PWD = " UPDATE {0} set pwd='{1}' where acc='{2}' and owner='{3}' ";

    public const string SQL_UPDATE_PWD_DIRECT = " UPDATE {0} set pwd='{1}' where acc='{2}' ";

    // ���·ּ�¼��ѯ
    public const string SQL_QUERY_SCORE_OP = " SELECT opId,opTime,opSrc,opType,opScore, opDst,{0}.moneyType,aliasName,opDstRemainMoney,opRemainMoney," +
                                         " userOrderId,opResult,failReason,logFrom,finishTime,orderId " +
                                         " from {0},{1} " +
                                           " {2} " +
                                           " order by opTime desc LIMIT {3}, {4} ";
}

public struct RetCode
{
    // �ɹ�
    public const int RET_SUCCESS = 0;

    // �����Ƿ�
    public const int RET_PARAM_NOT_VALID = 1;

    // ����ʧ��
    public const int RET_OP_FAILED = 2;

    // GM��¼ʧ��
    public const int RET_GM_LOGIN_FAILED = 3;

    // Ȩ�޲���
    public const int RET_NO_RIGHT = 4;

    // ����
    public const int RET_MONEY_NOT_ENOUGH = 5;

    // ���ݿ����
    public const int RET_DB_ERROR = 6;

    // ��Ҳ�����
    public const int RET_PLAYER_OFFLINE = 7;

    // �������
    public const int RET_PLAYER_ONLINE = 8;

    // ��Ҳ�����
    public const int RET_NO_PLAYER = 9;

    // ǩ������
    public const int RET_SIGN_ERROR = 10;

    // ���û�б�����
    public const int RET_PLYAER_NOT_LOCKED = 11;

    // �˺��Ѵ���
    public const int RET_ACCOUNT_HAS_EXISTS = 12;

    // �˺Ż������ʽ����
    public const int RET_ACC_PWD_FORMAT_ERROR = 13;

    // �˺ű�ͣ��
    public const int RET_ACC_BLOCKED = 14;

    // �Ҳ����ϼ��˺�
    public const int RET_NO_SUP_ACC = 15;

    // ���Ϸ�
    public const int RET_MONEY_NOT_VALID = 16;

    // ��Ҳ��ڴ���
    public const int RET_PLAYER_NOT_IN_LOBBY = 17;

    // ��ұ���������Ҫ����
    public const int RET_PLYAER_LOCKED = 18;

    // ������ߣ����ύ���·ֶ�������
    public const int RET_HAS_SUBMIT_ORDER = 19;

    // �����Ѵ���
    public const int RET_ORDER_EXISTS = 20;
}

//////////////////////////////////////////////////////////////////////////
// ��������
public struct ConstDef
{
    // 24Сʱʱ���ʽ
    public static string DATE_TIME24 = "yyyy-MM-dd HH:mm:ss";

    // ϴ��ȵ����ֵ
    public const double MAX_WASH_RATIO = 0.012;

    // ����ռ�ɵ����ֵ
    public const double MAX_AGENT_RATIO = 1.0;

    // gm ID�ŵ�ƫ��
    public const long GM_ID_OFFSET = 10000;
}

//////////////////////////////////////////////////////////////////////////
// ���ʵʱ���·֣�����������״̬
public struct PlayerReqOrderState
{
    // �����ѳɹ����
    public const int STATE_FINISH = 0;

    // ��������ʧ��
    public const int STATE_FAILED = 1;

    // �ȴ�����
    public const int STATE_WAIT = 2;

    // ����������
    public const int STATE_PROCESSING = 3;
}

/*
 *     ��������ʧ�ܵ�ԭ����
 *     
 *     ����  ��Ҳ��ڴ���  ��Ҳ�����  û�и���� db����  ���Ϸ� ��ұ�����
 *     
 *     ����ֵ�ο�RetCode�ж���ĳ���
 */

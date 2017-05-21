using System;
using System.Collections.Generic;
using System.Web;
using System.IO;

public enum RechargeType
{
    // �������
    rechargeRMB,

    // ɾ���Զ���ͷ��
    delIconCustom,

    gold,   // ���
    gem,    // ��ʯ
    vipExp,  // VIP����
    dragonBall, // ����
};


public struct DefCC
{
    // ����鿴ҳ
    public const string ASPX_GAME_DETAIL = "/appaspx/stat/gamedetail/GameDetailViewer.aspx";
    // �ټ�������
    public const string ASPX_GAME_DETAIL_BACCARAT = "/appaspx/stat/gamedetail/GameDetailBaccarat.aspx?index={0}";
    // ţţ����
    public const string ASPX_GAME_DETAIL_COWS = "/appaspx/stat/gamedetail/GameDetailCows.aspx?index={0}";
    // ����������
    public const string ASPX_GAME_DETAIL_CROCODILE = "/appaspx/stat/gamedetail/GameDetailCrocodile.aspx?index={0}";
    // ��������
    public const string ASPX_GAME_DETAIL_DICE = "/appaspx/stat/gamedetail/GameDetailDice.aspx?index={0}";
    // ���㹫԰����
    public const string ASPX_GAME_DETAIL_FISH_PARK = "/appaspx/stat/gamedetail/GameDetailFishPark.aspx?index={0}";
    // ��������
    public const string ASPX_GAME_DETAIL_DRAGON = "/appaspx/stat/gamedetail/GameDetailDragon.aspx?index={0}";

    // �˿�����
    public static string[] s_poker = { "diamond", "club", "spade", "heart" };

    public static string[] s_pokerCows = { "diamond", "club", "heart", "spade" };
    public static string[] s_pokerColorCows = { "����", "÷��", "����", "����" };

    // �������������
    public static string[] s_diceStr = { "��", "С", "����" };

    public static string[] s_isBanker = { "�Ƿ���ׯ:��", "�Ƿ���ׯ:��" };

    // �˿�����ֵ
    public static string[] s_pokerNum = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

    // �ټ��ֵĽ��
    public static string[] s_baccaratResult = { "��", "��", "�ж�", "ׯ��", "ׯ" };

    public const int OP_ADD = 0;      // ���
    public const int OP_REMOVE = 1;   // �Ƴ�
    public const int OP_MODIFY = 2;   // �޸�
    public const int OP_VIEW = 3;     // �鿴
}

public enum QueryType
{
    // GM�˺�
    queryTypeGmAccount,

    // ��ң���ʯ�仯
    queryTypeMoney,
    // ��ϸ
    queryTypeMoneyDetail,

    // �ͷ���Ϣ��ѯ
    queryTypeServiceInfo,

    // �ʼ�
    queryTypeMail,

    // ��ֵ��¼
    queryTypeRecharge,

    // �˺Ų�ѯ
    queryTypeAccount,

    // ��½��ʷ
    queryTypeLoginHistory,

    // �����ѯ
    queryTypeGift,

    // ������ѯ
    queryTypeGiftCode,

    // �һ�
    queryTypeExchange,

    // ����ͨ������
    queryTypeLobby,

    // ����������
    queryTypeServerEarnings,

    // �����������
    queryTypeIndependentFishlord,

    // �����������
    queryTypeIndependentCrocodile,

    // ������������
    queryTypeIndependentDice,

    // ţţ��������
    queryTypeIndependentCows,

    // ����ӯ����
    queryTypeDiceEarnings,

    // �ټ���ӯ����
    queryTypeBaccaratEarnings,

    // �ټ�����ׯ���
    queryTypeBaccaratPlayerBanker,

    // ţţ��ׯ���
    queryTypeCowsPlayerBanker,

    // ��ǰ����
    queryTypeCurNotice,

    // ���������ѯ
    queryTypeFishlordParam,
    // ���㹫԰������ѯ
    queryTypeFishParkParam,

    // �������Ӳ�����ѯ
    queryTypeFishlordDeskParam,
    // ���㹫԰���Ӳ�����ѯ
    queryTypeFishParkDeskParam,

    // �����������ѯ
    queryTypeCrocodileParam,

    // ţţ������ѯ
    queryTypeQueryCowsParam,

    // ����������ѯ��ÿ�������ϵͳ�����룬��֧����ӯ����..
    queryTypeDragonParam,

    // ��������Ϸģʽ�µĲ�����ѯ
    queryTypeDragonGameModeEarning,

    // �ں�÷��������ѯ
    queryTypeShcdParam,
    // �ں�÷����������
    queryTypeIndependentShcd,

    // ��ѯ��ţ��Ϸ���
    queryTypeGameCalfRoping,

    // ������ͳ��
    queryTypeFishStat,
    // ���㹫԰������ͳ��
    queryTypeFishParkStat,

    // �����������
    queryTypeMoneyAtMost,

    // �ɵ�ӯ����
    queryTypeOldEaringsRate,

    // ���䲶��׶η���
    queryTypeFishlordStage,
    // ���㹫԰�׶η���
    queryTypeFishParkStage,

    // ��ǰ����
    queryTypeOnlinePlayerCount,

    // ������־
    queryTypeOpLog,

    // ��ѯ���ͷ��
    queryTypePlayerHead,

    // �����ܼ�
    queryTypeTotalConsume,

    // ����Ϸ����
    queryTypeGameRecharge,

    // �����������
    queryTypeCoinGrowthRank,

    // ��ʧ��ѯ
    queryTypeAccountCoinLessValue,

    // ��������
    queryTypeFishConsume,

    // ţţ���Ͳ�ѯ
    queryTypeCowsCardsType,

    // ��Ϸ������Ʋ�ѯ
    queryTypeGameResultControl,

    // ͷ��ٱ�
    queryTypeInformHead,

    // ��ѯtd��Ծ
    queryTypeTdActivation,
    // LTV��ֵ
    queryTypeLTV,

    // ��ѯ�������
    queryTypeMaxOnline,

    // ��ҽ���ܺ�
    queryTypeTotalPlayerMoney,

    // ������ز�ѯ
    queryTypeGrandPrix,

    // bossͳ��
    queryTypeFishBoss,

    // �һ�ͳ��
    queryTypeExchangeStat,

    // ���ѵ�
    queryTypeRechargePointStat,

    // ���ǳ齱
    queryTypeStarLottery,

    queryTypeRLose,
    // ÿ������
    queryTypeDragonBallDaily,
    // ��ҳ�ֵ���
    queryTypeRechargePlayerMonitor,

    // ÿСʱ����
    queryTypeRechargePerHour,
    // ÿСʱ��������
    queryTypeOnlinePlayerNumPerHour,
    // ƽ����Ϸʱ���ֲ�
    queryTypeGameTimeDistribution,
    // �û�ϲ��-ƽ������ʱ��
    queryTypeGameTimePlayerFavor,
    // �׸���Ϸʱ���ֲ�
    queryTypeFirstRechargeGameTimeDistribution,
    // �״ι���Ʒѵ�ֲ�
    queryTypeFirstRechargePointDistribution,
    // �û���ע���
    queryTypePlayerGameBet,
    // ��ѯ�����֧ͳ��
    queryTypePlayerIncomeExpenses,

    // �����û�����
    queryTypeNewPlayer,
}


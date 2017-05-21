using System;
using System.Collections.Generic;
using System.Web;
using System.IO;
using System.Web.Configuration;

public enum RechargeType
{
    // �������
    rechargeRMB,

    // ɾ���Զ���ͷ��
    delIconCustom,
};

// ͳ��
delegate void statData(List<Dictionary<string, object>> dataList);

public struct DefCC
{
    public const string ASPX_GM_INFO = "/appaspx/account/AccountGmInfo.aspx?acc={0}";

    public const string ASPX_GM_INFO_NO_PARAM = "/appaspx/account/AccountGmInfo.aspx";

    public const string ASPX_GM_INFO_VIEW_TREE_NO_PARAM = "/appaspx/account/GmInfoViewTree.aspx";

    public const string ASPX_EMPTY = "/appaspx/Empty.aspx";

   // public const string ASPX_EMPTY_FOR_COMMON_SCORE = "/appaspx/account/sub/AccountEmptyForCommonScore.aspx";
   // public const string ASPX_EMPTY_FOR_COMMON_REPORT = "/appaspx/account/sub/AccountEmptyForCommonReport.aspx";
   // public const string ASPX_EMPTY_FOR_COMMON_ACCMGR = "/appaspx/account/sub/AccountEmptyForCommonAccMgr.aspx";

    public const string ASPX_SUB_PLAYER = "/appaspx/account/sub/AccountSubPlayer.aspx";

    public const string ASPX_SUB_SCORE_PLAYER = "/appaspx/account/AccountScorePlayer.aspx";

    public const string ASPX_SUB_Agency = "/appaspx/account/sub/AccountAgencySub.aspx";

    public const string ASPX_AGENCY_RIGHT = "/appaspx/account/sub/AccountAgencyRight.aspx";

    public const string ASPX_PLAYER_OP = "/appaspx/account/AccountPlayerOp.aspx";

    public const string ASPX_SCORE_GM = "/appaspx/account/AccountScore.aspx";

    public const string ASPX_MODIFY_LOGIN_PWD = "/appaspx/account/AccountModifyLoginPwd.aspx?acc={0}";

    public const string ASPX_MODIFY_HOME = "/appaspx/account/AccountModifyHome.aspx?acc={0}&home={1}";

    public const string ASPX_MODIFY_ALIASNAME = "/appaspx/account/sub/AccountSubModifyAliasName.aspx?acc={0}";

    // ��Ӯͳ��ҳ��
    public const string ASPX_WIN_LOSE = "/appaspx/account/report/AccountWinLoseReport.aspx";

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
    // �ں�÷������
    public const string ASPX_GAME_DETAIL_SHCD = "/appaspx/stat/gamedetail/GameDetailShcd.aspx?index={0}";
    // ��������
    public const string ASPX_GAME_DETAIL_DRAGON = "/appaspx/stat/gamedetail/GameDetailDragon.aspx?index={0}";

    //public const string ASPX_LOGIN_STEP1 = "/appaspx/Login.aspx";
    // ����1
    public const string ASPX_LOGIN_STEP1 = "/appaspx/LoginAccount.aspx";
    // ����2
    public const string ASPX_LOGIN_STEP2 = "/appaspx/LoginPwd.aspx";
    // ����3
    public const string ASPX_LOGIN_STEP3 = "/appaspx/LoginCode.aspx";

    //public const string ASPX_LOGIN_ENTER = "/appaspx/account/AccountCreateSwitch.aspx";
    public const string ASPX_LOGIN_ENTER = "/appaspx/account/AccountSelfInfo.aspx";

    public const string ASPX_API_APPROVE = "/appaspx/account/AccountApiApprove.aspx";

    public const string ASPX_PLAYER_ORDER = "/appaspx/account/AccountPlayerOrder.aspx";

    // �������-���� URL
    public static string URL_UNLOCK_PLAYER_RET = WebConfigurationManager.AppSettings["unLockPlayerRet"];

    // �����¼ʧ�ܴ���
    public static string URL_CLEAR_FAILED_LOGIN = WebConfigurationManager.AppSettings["clearFailedLoginCount"];

    // ���ҵ�λ
    public static int MONEY_BASE = Convert.ToInt32(WebConfigurationManager.AppSettings["moneyBase"]);

    public static string HTTP_MONITOR = Convert.ToString(WebConfigurationManager.AppSettings["httpMonitor"]);

    // ��֤key
    public const string KEY_VERIFICATION = "keyver";

    // ��֤���������
    public const string CODE_SERIAL = "0,1,2,3,4,5,6,7,8,9";

    // �˿�����
    public static string[] s_poker = { "diamond", "club", "spade", "heart" };

    public static string[] s_pokerCows = { "diamond", "club", "heart", "spade" };
    public static string[] s_pokerColorCows = { "����", "÷��", "����", "����" };

    // �ں�÷�����˿���
    public static string[] s_pokerShcd = { "spade", "heart", "club", "diamond", "joker" };

    // �������������
    public static string[] s_diceStr = { "��", "С", "����" };

    public static string[] s_isBanker = { "�Ƿ���ׯ:��", "�Ƿ���ׯ:��" };

    // �˿�����ֵ
    public static string[] s_pokerNum = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

    // �ټ��ֵĽ��
    public static string[] s_baccaratResult = { "��", "��", "�ж�", "ׯ��", "ׯ" };
}

//////////////////////////////////////////////////////////////////////////

public enum DyOpType
{
    // ���ʼ�
    opTypeSendMail,

    // �޸�����
    opTypeModifyPwd,

    // ͣ���˺�
    opTypeBlockAcc,

    // ͣ�����ID
    opTypeBlockId,

    // ͣ��IP
    opTypeBlockIP,

    // ��̨��ֵ
    opTypeRecharge,

    // �������APPӦ����Ϣ
    opTypePushApp,

    // ���ֻ�
    opTypeBindPhone,

    // �������
    opTypeGift,

    // ���������
    opTypeGiftCode,

    // �һ�
    opTypeExchange,

    // ͨ��
    opTypeNotify,

    // ��Ӫά��
    opTypeMaintenance,

    // �����������
    opTypeFishlordParamAdjust,
    // ���㹫԰��������
    opTypeFishParkParamAdjust,

    // �������������
    opTypeCrocodileParamAdjust,

    // ������������
    opTypeDiceParamAdjust,

    // �ټ��ֲ�������
    opTypeBaccaratParamAdjust,

    // ţţ��������
    opTypeCowsParamAdjust,

    // ������������
    opTypeDragonParamAdjust,

    // �����ͳ�Ʊ�
    opTypeClearFishTable,

    // ���¼��ر��
    opTypeReLoadTable,

    // �ͷ���Ϣ
    opTypeServiceInfo,

    // ����ͷ��
    opTypeFreezeHead,

    // �����༭
    opTypeEditChannel,

    // ͨ����Ϣ
    opTypeSpeaker,

    // ����ţţ����
    opTypeSetCowsCard,
    // ף������
    opTypeWishCurse,

    // ��Ϸ�������
    opTypeDyOpGameResult,

    // ��Ϸ��������
    opTypeGameParamAdjust,

    // �޸���Ϸ�����ע����
    opTypeModifyMaxBetLimit,
    //////////////////////////////////////////////////////////////////////////
    // ��������Ա�˺�
    opTypeDyOpCreateGmAccount,

    // �����������
    opTypeDyOpCreatePlayer,

    // �Ϸ֣��·�
    opTypeDyOpScore,

    // �޸ĵ�¼��̨������
    opTypeModifyLoginPwd,

    // �����
    opTypeKickPlayer,
    // �������
    opTypeUnlockPlayer,
    // �����¼ʧ�ܴ���
    opTypeClearLoginFailed,
    // ����Ҵ������ǣ�������Ƿ��¼ӯ����
    opTypeSetPlayerSpecialFlag,
    // �޸�Ȩ��
    opTypeDyOpModiyGmRight,
    // ����ͣ��GM�˺�
    opTypeDyOpStartStopGmAcc,

    // API�����˺�
    opTypeDyOpApiApprove,
    // ��Ҷ�������
    opTypeDyOpPlayerOrder,

    // �޸�GM����
    opTypeDyOpModifyGmProperty,

    // ɾ������־
    opTypeDelData,

    // ɾ��GM�˺ţ�����˺�
    opTypeDelAccount,

    // ��Ϸ����
    opTypeOpenGame,

    // API��������ע�������
    opTypeModifyAPISetLimit,

    opTypePlayerOp,
}

public enum QueryType
{
    // GM�˺�
    queryTypeGmAccount,

    // ��ң���ʯ�仯
    queryTypeMoney,

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

    // ��Ϸ��ʷ��¼
    queryTypeGameHistory,

    // ��ѯ��һ�Ա
    queryTypePlayerMember,

    // �����˺�
    queryTypeGmAccountCascade,

    queryTypeQueryGmAccountDetail,

    // �Ϸ�/�·ּ�¼
    queryTypeQueryScoreOpRecord,

    // api��������ѯ
    queryTypeQueryApiApprove,

    // ��ѯ��Ҷ���
    queryTypeQueryPlayerOrder,

    // ���·�ʵʱ��������¼�Ѵ���������߶������������ߣ����Բ鿴���·ּ�¼
    queryTypeQueryRealTimeOrder,
}

public enum StatType
{
    // ��ֵͳ��
    statTypeRecharge,

    // ��ͬ�����ŵ�ͳ��
    statTypeSameOrderId,

    // ��Ծ����
    statTypeActiveCount,

    // ��Ծ����
    statTypeActivePerson,

    // vip�ȼ��ֲ�
    statTypeVipLevel,

    // �ۻ�ͤͳ��
    statTypeSeller,

    // �ۻ�ͤ����Աͳ��
    statTypeSellerAdmin,

    // ��ҵ�����ͳ��
    statTypePlayer,

    // ��ͳ��
    statTypeSellerStep,

    // ��Ӯͳ��
    statTypeWinLose,
}




using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Web.Configuration;
using System.Text;
using MySql.Data.MySqlClient;
using System.Collections.Specialized;
using System.Web;
using Newtonsoft.Json;
using System.IO;
using MongoDB.Bson;
using MongoDB.Driver;
using MongoDB.Driver.Builders;

// ��̬����
public class DyOpBase
{
    // GM�˺�
    protected GMUser m_gmUser;

    protected Dictionary<string, object> m_retData = new Dictionary<string, object>();

    // ����json����ʽ
    public virtual string doDyop(object param)
    {
        return "";
    }

    // ����ѯ, ����json����ʽ
    public virtual string doQuery(object param) { return ""; }

    // ����GM�˺ţ�����true�����ɹ�
    public bool createGMUser(ParamBase param)
    {
        m_gmUser = new GMUser(param);
        if (!m_gmUser.isLogin)
        {
            m_retData.Add("result", RetCode.RET_GM_LOGIN_FAILED);
        }
        return m_gmUser.isLogin;
    }
}

public class ParamBase
{
    // �����˺�
    public string m_gmAccount;

    // �������룬������ʱ����Ҫ��MD5����
    public string m_gmPwd;

    public string m_playerAcc = "";

    // ǩ��
    public string m_sign;

    protected int m_fieldIndex;

    public int fieldIndex
    {
        get { return m_fieldIndex; }
        set { m_fieldIndex = value; }
    }

    public virtual bool isParamValid()
    {
        if (string.IsNullOrEmpty(m_gmAccount))
            return false;

        if (string.IsNullOrEmpty(m_gmPwd))
            return false;

        if (!playerAccIsValid())
            return false;

        if (string.IsNullOrEmpty(m_sign))
            return false;

        return true;
    }

    // ���ǩ��
    public virtual bool checkSign(GMUser user)
    {
        string sign = Tool.getMD5Hash(m_gmAccount + m_gmPwd + m_playerAcc + user.m_devSecretKey);
        return m_sign == sign;
    }

    protected virtual bool playerAccIsValid()
    {
        if (string.IsNullOrEmpty(m_playerAcc))
            return false;

        return true;
    }
}

//////////////////////////////////////////////////////////////////////////

public class ParamCreatePlayer : ParamBase
{
    public string m_pwd = "";
    // ϴ���
    public string m_washRatioStr;

    public double m_washRatio;

    // ����
    public string m_aliasName;

    public ParamCreatePlayer()
    {
        m_fieldIndex = 0;
    }

    public override bool isParamValid()
    {
        if (!base.isParamValid())
            return false;

        if (string.IsNullOrEmpty(m_pwd))
            return false;

        if (!string.IsNullOrEmpty(m_washRatioStr))
        {
            if (!double.TryParse(m_washRatioStr, out m_washRatio))
            {
                return false;
            }
        }
        if (string.IsNullOrEmpty(m_aliasName))
        {
            m_aliasName = "";
        }

        return true;
    }

    // ���ǩ��
    public override bool checkSign(GMUser user)
    {
        string sign = Tool.getMD5Hash(m_gmAccount + m_gmPwd + m_playerAcc + m_pwd + user.m_devSecretKey);
        return m_sign == sign;
    }
}

// �������
public class DyOpCreatePlayer : DyOpBase
{
    const string AES_KEY = "&@*(#kas9081fajk";

    public override string doDyop(object param)
    {
        ParamCreatePlayer p = (ParamCreatePlayer)param;
        bool cres = createGMUser(p);
        if (!cres)
        {
            return Helper.genJsonStr(m_retData);
        }
        if (!p.checkSign(m_gmUser))
        {
            m_retData.Add("result", RetCode.RET_SIGN_ERROR);
            return Helper.genJsonStr(m_retData);
        }

        // ֻ��API�Ųſ��Դ������
        if (m_gmUser.m_accType != AccType.ACC_API) 
        {
            m_retData.Add("result", RetCode.RET_NO_RIGHT);
            return Helper.genJsonStr(m_retData);
        }

        // ϴ��ȵ��ж�
        if (p.m_washRatio < 0 || p.m_washRatio > m_gmUser.m_washRatio)
        {
            m_retData.Add("result", RetCode.RET_PARAM_NOT_VALID);
            return Helper.genJsonStr(m_retData);
        }

        // ����˺���API��ƴ�ӣ���������ж�
        // �˺�������Ҫ��ǰ׺
        if (p.m_playerAcc.IndexOf(m_gmUser.m_postfix) != 0)
        {
            m_retData.Add("result", RetCode.RET_ACC_PWD_FORMAT_ERROR);
            return Helper.genJsonStr(m_retData);
        }
        //string tmpAcc = p.m_playerAcc.Remove(0, m_gmUser.m_postfix.Length);

        if (!Regex.IsMatch(p.m_playerAcc, Exp.ACCOUNT_PLAYER))
        {
            m_retData.Add("result", RetCode.RET_PARAM_NOT_VALID);
            return Helper.genJsonStr(m_retData);
        }

        if (!Regex.IsMatch(p.m_pwd, Exp.ACCOUNT_PLAYER_PWD))
        {
            m_retData.Add("result", RetCode.RET_PARAM_NOT_VALID);
            return Helper.genJsonStr(m_retData);
        }

        string error = "";
        bool res = createAccToServer(p.m_playerAcc, p.m_pwd, ref error);
        int retCode = RetCode.RET_OP_FAILED;

        if (res || error == "-12")
        {
            retCode = createAcc(p.m_playerAcc, m_gmUser, p);
        }
        else
        {
            /*if (error == "-12") // ���˺��Ѵ���
            {
                m_retData.Add("result", RetCode.RET_ACCOUNT_HAS_EXISTS);
            }*/
            if (error == "-11") // ���ݿ������
            {
                retCode = RetCode.RET_DB_ERROR;
                //m_retData.Add("result", RetCode.RET_DB_ERROR);
            }
            else if (error == "-14" || error == "-20") // �˺������ʽ����
            {
                retCode = RetCode.RET_ACC_PWD_FORMAT_ERROR;
                //m_retData.Add("result", RetCode.RET_ACC_PWD_FORMAT_ERROR);
            }
        }

        //if (res)
        {
            if (retCode == RetCode.RET_SUCCESS)
            {
                m_retData.Add("result", RetCode.RET_SUCCESS);
                m_retData.Add("playerAcc", p.m_playerAcc);
            }
            else
            {
                m_retData.Add("result", retCode);
            }
        }
       
        return Helper.genJsonStr(m_retData);
    }

    // ����0�ɹ�����������
    private int createAcc(string accName, GMUser user, ParamCreatePlayer param)
    {
        bool exists = user.sqlDb.keyStrExists(TableName.PLAYER_ACCOUNT_XIANXIA, "acc", accName, MySqlDbName.DB_XIANXIA);
        if (exists)
            return RetCode.RET_ACCOUNT_HAS_EXISTS;

        SqlInsertGenerator gen = new SqlInsertGenerator();
        gen.addField("acc", accName, FieldType.TypeString);
        gen.addField("creator", user.m_acc, FieldType.TypeString);
        gen.addField("money", 0, FieldType.TypeNumber);
        gen.addField("moneyType", user.m_moneyType, FieldType.TypeNumber);
        gen.addField("state", PlayerState.STATE_IDLE, FieldType.TypeNumber);
        gen.addField("createTime", DateTime.Now.ToString(ConstDef.DATE_TIME24), FieldType.TypeString);
        gen.addField("createCode", user.m_createCode, FieldType.TypeString);
        gen.addField("aliasName", param.m_aliasName, FieldType.TypeString);
        gen.addField("playerWashRatio", param.m_washRatio, FieldType.TypeNumber);
       
        string sqlCmd = gen.getResultSql(TableName.PLAYER_ACCOUNT_XIANXIA);
        int count = user.sqlDb.executeOp(sqlCmd, MySqlDbName.DB_XIANXIA);
        return count > 0 ? 0 : RetCode.RET_DB_ERROR;
    }

    private bool createAccToServer(string accName, string pwd, ref string error)
    {
        RSAHelper rsa = new RSAHelper();
        rsa.init();
        Dictionary<string, object> data = new Dictionary<string, object>();
        data["n1"] = accName;
        string md5Pwd = Tool.getMD5Hash(pwd);
        data["n2"] = AESHelper.AESEncrypt(md5Pwd, AES_KEY);
        data["n3"] = rsa.getModulus();

        string jsonstr = JsonHelper.ConvertToStr(data);
        string md5 = AESHelper.MD5Encrypt(jsonstr + AES_KEY);
        string urlstr = Convert.ToBase64String(Encoding.Default.GetBytes(jsonstr));
            
        string fmt = WebConfigurationManager.AppSettings["createAccount"];
        string aspx = string.Format(fmt, urlstr, md5);
        var ret = HttpPost.Get(new Uri(aspx));
        if (ret != null)
        {
            string retStr = Encoding.UTF8.GetString(ret);
            string oriStr = Encoding.Default.GetString(Convert.FromBase64String(retStr));
            Dictionary<string, object> retData =
                JsonHelper.ParseFromStr<Dictionary<string, object>>(oriStr);
            if (retData.ContainsKey("result"))
            {
                if (retData.ContainsKey("error"))
                {
                    error = Convert.ToString(retData["error"]);
                }
                return Convert.ToBoolean(retData["result"]);
            }
        }
        return false;
    }
}

//////////////////////////////////////////////////////////////////////////

public class ParamScore : ParamBase
{
    // 0�Ϸ� 1�·�
    public int m_op;
    public string m_score;

    // �û��Զ��嶩��ID[0-200]����ĸ�������
    public string m_userOrderId;

    // api�ص�ҳ��
    public string m_apiCallBack;

    public ParamScore() 
    {
        m_fieldIndex = 1;
    }

    public override bool isParamValid()
    {
        if (!base.isParamValid())
            return false;

        if (string.IsNullOrEmpty(m_score))
            return false;

        if (string.IsNullOrEmpty(m_userOrderId))
        {
            return false;
            //m_userOrderId = "";
        }
        else
        {
            if (!Regex.IsMatch(m_userOrderId, Exp.USER_ORDER_ID))
            {
                return false;
            }
        }
        if (string.IsNullOrEmpty(m_apiCallBack))
        {
            m_apiCallBack = "";
        }
        return true;
    }

    // ���ǩ��
    public override bool checkSign(GMUser user)
    {
        string sign = Tool.getMD5Hash(m_gmAccount + m_gmPwd + m_playerAcc + m_score + m_userOrderId + user.m_devSecretKey);
        return m_sign == sign;
    }
}

// �Ϸ֣��·�
public class DyOpScore : DyOpBase
{
    public override string doDyop(object param)
    {
        ParamScore p = (ParamScore)param;
        long oriScore = 0;
        if (!long.TryParse(p.m_score, out oriScore))
        {
            m_retData.Add("result", RetCode.RET_PARAM_NOT_VALID);
            return Helper.genJsonStr(m_retData);
        }

        if (oriScore <= 0)
        {
            m_retData.Add("result", RetCode.RET_PARAM_NOT_VALID);
            return Helper.genJsonStr(m_retData);
        }

        bool cres = createGMUser(p);
        if (!cres)
        {
            return Helper.genJsonStr(m_retData);
        }

        if (!p.checkSign(m_gmUser))
        {
            m_retData.Add("result", RetCode.RET_SIGN_ERROR);
            return Helper.genJsonStr(m_retData);
        }

        if (orderIdExists(p))
        {
            m_retData.Add("result", RetCode.RET_ORDER_EXISTS);
            return Helper.genJsonStr(m_retData);
        }

        long score = Helper.saveMoneyValue(oriScore);

        int code = canDoScoreToPlayer(p.m_playerAcc, score, ScropOpType.isAddScore(p.m_op));
         // ���ߣ��������·֣�ֱ�ӷ���ʧ��
        if (code == RetCode.RET_PLAYER_ONLINE && !ScropOpType.isAddScore(p.m_op))
        {
            m_retData.Add("result", RetCode.RET_PLAYER_ONLINE);
        }
        else if (code == RetCode.RET_PLAYER_ONLINE && ScropOpType.isAddScore(p.m_op)) // �������ʱ�ύ���·ֶ���
        {
            //if (ScropOpType.isAddScore(p.m_op)) // �Ϸֲ���,�ȿ�GM��Ǯ�����������մ���ʧ�ܣ��᷵��GM�ⲿ��Ǯ
            {
                decScore(score);
            }

            OrderGenerator or = new OrderGenerator();
            Dictionary<string, object> orData = or.genOrder(p.m_gmAccount, p.m_playerAcc, score, p.m_op,
                AccType.ACC_PLAYER,
                OrderGenerator.ORDER_FROM_API,
                "",
                p.m_userOrderId, p.m_apiCallBack);

            bool res = MongodbPlayer.Instance.ExecuteInsert(TableName.PLAYER_ORDER_REQ, orData);
            if (res)
            {
                m_retData.Add("orderId", Convert.ToString(orData["orderId"]));
                m_retData.Add("result", RetCode.RET_HAS_SUBMIT_ORDER);
            }
            else
            {
                m_retData.Add("result", RetCode.RET_DB_ERROR);
            }
        }
        else if (code == RetCode.RET_SUCCESS) // ������ߣ���ֱ���޸����ݿ����·�
        {
            bool res = doScorePlayer(p, score);
            if (res)
            {
                m_retData.Add("result", RetCode.RET_SUCCESS);
                m_retData.Add("playerAcc", p.m_playerAcc);
                m_retData.Add("score", oriScore);

                /*string cmd = string.Format(CONST.SQL_ORDER_ID, TableName.GM_SCORE, m_gmUser.m_acc, p.m_playerAcc, p.m_op);

                Dictionary<string, object> order = m_gmUser.sqlDb.queryOne(cmd, MySqlDbName.DB_XIANXIA);
                if (order != null)
                {
                    int orderId = Convert.ToInt32(order["opId"]);
                    m_retData.Add("orderId", orderId);
                }*/

                OrderInfo oinfo = writeOfflineOrderToMySql(p, score);
                m_retData.Add("orderId", oinfo.m_orderId);
                m_retData.Add("userOrderId", p.m_userOrderId);
            }
        }
        else
        {
            m_retData.Add("result", code);
        }
        return Helper.genJsonStr(m_retData);
    }

    private bool doScorePlayer(ParamScore p, long score)
    {
        bool res = false;
        if (p.m_op == 0) // �ӷ�
        {
            if (m_gmUser.m_money < score)
            {
                m_retData.Add("result", RetCode.RET_MONEY_NOT_ENOUGH);
                return false;
            }

            res = addScorePlayer(p.m_playerAcc, score);
            if (res)
            {
                decScore(score);
            }
            else
            {
                m_retData.Add("result", RetCode.RET_DB_ERROR);
                return false;
            }
        }
        else
        {
            res = decScorePlayer(p.m_playerAcc, score);
            if (res)
            {
                addScore(score);
            }
            else
            {
                m_retData.Add("result", RetCode.RET_DB_ERROR);
                return false;
            }
        }

        /*if (res)
        {
            long remainMoney = Helper.getRemainMoney(p.m_playerAcc, m_gmUser);
            SqlInsertGenerator gen = new SqlInsertGenerator();
            gen.addField("opTime", DateTime.Now.ToString(ConstDef.DATE_TIME24), FieldType.TypeString);
            gen.addField("opSrc", m_gmUser.m_acc, FieldType.TypeString);
            gen.addField("opDst", p.m_playerAcc, FieldType.TypeString);
            gen.addField("opType", p.m_op, FieldType.TypeNumber);
            gen.addField("opScore", score, FieldType.TypeNumber);
            gen.addField("moneyType", m_gmUser.m_moneyType, FieldType.TypeNumber);
            gen.addField("opSrcDepth", m_gmUser.m_depth, FieldType.TypeNumber);
            gen.addField("opSrcCreateCode", m_gmUser.m_createCode, FieldType.TypeString);
            gen.addField("opDstType", AccType.ACC_PLAYER, FieldType.TypeNumber);
            gen.addField("opDstRemainMoney", remainMoney, FieldType.TypeNumber);
            gen.addField("userOrderId", p.m_userOrderId, FieldType.TypeString);

            string cmd = gen.getResultSql(TableName.GM_SCORE);
            m_gmUser.sqlDb.executeOp(cmd, MySqlDbName.DB_XIANXIA);
        }*/
        return res;
    }

    private bool addScore(long score)
    {
        string cmd = string.Format(SqlStrCMD.SQL_ADD_SCORE_TO_MGR_DIRECT,
                                    TableName.GM_ACCOUNT,
                                    score,
                                    m_gmUser.m_acc);

        int count = m_gmUser.sqlDb.executeOp(cmd, MySqlDbName.DB_XIANXIA);
        if (count > 0)
        {
            m_gmUser.m_money += score;
        }
        return count > 0;
    }

    // score������
    private bool decScore(long score)
    {
        string cmd = string.Format(SqlStrCMD.SQL_DEC_SCORE_TO_MGR_DIRECT,
                                    TableName.GM_ACCOUNT,
                                    score,
                                    m_gmUser.m_acc,
                                    score);
        int count = m_gmUser.sqlDb.executeOp(cmd, MySqlDbName.DB_XIANXIA);
        if (count > 0)
        {
            m_gmUser.m_money -= score;
        }
        return count > 0;
    }

    private bool addScorePlayer(string acc, long score)
    {
        string cmd = string.Format(SqlStrCMD.SQL_ADD_SCORE_TO_PLAYER,
                                    TableName.PLAYER_ACCOUNT_XIANXIA,
                                    score,
                                    acc,
                                    PlayerState.STATE_IDLE,
                                    m_gmUser.m_acc);

        int count = m_gmUser.sqlDb.executeOp(cmd, MySqlDbName.DB_XIANXIA);
        return count > 0;
    }

    // score������
    private bool decScorePlayer(string acc, long score)
    {
        string cmd = string.Format(SqlStrCMD.SQL_DEC_SCORE_TO_PLAYER,
                                      TableName.PLAYER_ACCOUNT_XIANXIA,
                                      score,
                                      acc,
                                      PlayerState.STATE_IDLE,
                                      score,
                                      m_gmUser.m_acc);
        int count = m_gmUser.sqlDb.executeOp(cmd, MySqlDbName.DB_XIANXIA);
        return count > 0;
    }

    // �Ƿ���Զ�����˺Ž����Ϸ��·ֲ���
    private int canDoScoreToPlayer(string acc, long score, bool isAddScore)
    {
        Player player = new Player(acc, m_gmUser);
        if (!player.m_isExists)
            return RetCode.RET_NO_PLAYER;

        if (player.isAccStop())
            return RetCode.RET_ACC_BLOCKED;

        if (!player.isOwner(m_gmUser.m_acc))
        {
            return RetCode.RET_NO_RIGHT;
        }

        if (isAddScore) // ������Ϸ�ʱ���ж�GM����Ƿ��㹻
        {
            if (m_gmUser.m_money < score)
            {
                return RetCode.RET_MONEY_NOT_ENOUGH;
            }
        }
        else
        {
            if (!player.isMoneyEnough(score)) // �·�ʱ���ж��������Ƿ����
                return RetCode.RET_MONEY_NOT_ENOUGH;
        }

        Dictionary<string, object> data = Helper.getPlayerPropertyByAcc(acc, new string[] { "SyncLock" });
        if (data != null)
        {
            if (data.ContainsKey("SyncLock"))
            {
                int state = Convert.ToInt32(data["SyncLock"]);
                if (state == 2)
                {
                    return RetCode.RET_PLYAER_LOCKED;
                }
            }
        }

        if (player.isInGame())
            return RetCode.RET_PLAYER_ONLINE;

        return RetCode.RET_SUCCESS;
    }

    private OrderInfo writeOfflineOrderToMySql(ParamScore p, long score)
    {
        long remainMoney = Helper.getRemainMoney(p.m_playerAcc, m_gmUser);

        OrderInfo oinfo =
                    OrderGenerator.genOfflineSuccessOrder(p.m_gmAccount, p.m_playerAcc, score,
                    p.m_op, AccType.ACC_PLAYER, remainMoney, OrderGenerator.ORDER_FROM_API, p.m_userOrderId);
        // �������·ּ�¼
        string cmd = OrderGenerator.genSqlForLogScore(oinfo, m_gmUser.m_createCode, m_gmUser.m_money);
        m_gmUser.sqlDb.executeOp(cmd, MySqlDbName.DB_XIANXIA);
        return oinfo;
    }

    // ����id�Ƿ����
    private bool orderIdExists(ParamScore p)
    {
        List<IMongoQuery> queryList = new List<IMongoQuery>();
        queryList.Add(Query.EQ("gmAcc", BsonValue.Create(p.m_gmAccount)));
        queryList.Add(Query.EQ("apiOrderId", BsonValue.Create(p.m_userOrderId)));
        IMongoQuery imq = Query.And(queryList);
        bool res = MongodbPlayer.Instance.KeyExistsByQuery(TableName.PLAYER_ORDER_REQ, imq);
        if (res)
        {
            return true;
        }

        string cond = string.Format(" userOrderId='{0}' and opSrc='{1}' ", p.m_userOrderId, p.m_gmAccount);
        res = m_gmUser.sqlDb.keyExists(TableName.GM_SCORE, cond, MySqlDbName.DB_XIANXIA);
        return res;
    }
}

//////////////////////////////////////////////////////////////////////////

public class ParamOnline : ParamBase
{
    public ParamOnline()
    {
        m_fieldIndex = 2;
    }
}

// ����Ƿ�����
public class DyOpOnline : DyOpBase
{
    public override string doDyop(object param)
    {
        ParamOnline p = (ParamOnline)param;

        bool cres = createGMUser(p);
        if (!cres)
        {
            return Helper.genJsonStr(m_retData);
        }

        if (!p.checkSign(m_gmUser))
        {
            m_retData.Add("result", RetCode.RET_SIGN_ERROR);
            return Helper.genJsonStr(m_retData);
        }

        Player player = new Player(p.m_playerAcc, m_gmUser);
        if (!player.m_isExists)
        {
            m_retData.Add("result", RetCode.RET_NO_PLAYER);
            return Helper.genJsonStr(m_retData);
        }
        if (!player.isOwner(m_gmUser.m_acc))
        {
            m_retData.Add("result", RetCode.RET_NO_RIGHT);
            return Helper.genJsonStr(m_retData);
        }

        m_retData.Add("result", RetCode.RET_SUCCESS);
        m_retData.Add("playerAcc", p.m_playerAcc);
        m_retData.Add("online", player.isInGame());
        return Helper.genJsonStr(m_retData);
    }
}

//////////////////////////////////////////////////////////////////////////

// ���������
public class ParamKickPlayer : ParamBase
{
    public string m_timeStr;

    public int m_time;  // ��λ�룬�೤ʱ�����ڲ������µ�¼

    public ParamKickPlayer()
    {
        m_fieldIndex = 2;    
    }

    public override bool isParamValid()
    {
        if (!base.isParamValid())
            return false;

        if (string.IsNullOrEmpty(m_timeStr))
            return false;

        if (!int.TryParse(m_timeStr, out m_time))
        {
            return false;
        }

        return true;
    }

    // ���ǩ��
    public override bool checkSign(GMUser user)
    {
        string sign = Tool.getMD5Hash(m_gmAccount + m_gmPwd + m_playerAcc + m_timeStr + user.m_devSecretKey);
        return m_sign == sign;
    }
}

// �����
public class DyOpKickPlayer : DyOpBase
{
    public override string doDyop(object param)
    {
        ParamKickPlayer p = (ParamKickPlayer)param;

        bool cres = createGMUser(p);
        if (!cres)
        {
            return Helper.genJsonStr(m_retData);
        }

        if (!p.checkSign(m_gmUser))
        {
            m_retData.Add("result", RetCode.RET_SIGN_ERROR);
            return Helper.genJsonStr(m_retData);
        }

        Player player = new Player(p.m_playerAcc, m_gmUser);
        if (!player.m_isExists)
        {
            m_retData.Add("result", RetCode.RET_NO_PLAYER);
            return Helper.genJsonStr(m_retData);
        }
        if (!player.isOwner(m_gmUser.m_acc))
        {
            m_retData.Add("result", RetCode.RET_NO_RIGHT);
            return Helper.genJsonStr(m_retData);
        }
        /*if (!player.isInGame()) // ��Ҳ�����Ϸ��
        {
            m_retData.Add("result", RetCode.RET_SUCCESS);
            return Helper.genJsonStr(m_retData);
        }*/

       /* string url = string.Format(CONST.URL_KICK_PLAYER, p.m_playerAcc, p.m_time);
        var ret = HttpPost.Get(new Uri(url));
        if (ret != null)
        {
            string retStr = Encoding.UTF8.GetString(ret);
            Dictionary<string, object> retData =
                JsonHelper.ParseFromStr<Dictionary<string, object>>(retStr);
            if (retData.ContainsKey("result"))
            {
                m_retData.Add("result", retData["result"]);
            }
        }*/
        kickPlayer(p);
        return Helper.genJsonStr(m_retData);
    }

    void kickPlayer(ParamKickPlayer p)
    {
        var ret = MongodbPlayer.Instance.ExecuteGetBykey(TableName.PLAYER_INFO, "account", p.m_playerAcc, new string[] { "SyncLock" });
        if (ret == null)
        {
            m_retData.Add("result", RetCode.RET_NO_PLAYER);
            return;
        }

        int state = Convert.ToInt32(ret["SyncLock"]);
        if (state != 1)
        {
            m_retData.Add("result", RetCode.RET_SUCCESS);
            return;
        }

        int nt = p.m_time;
        if (nt < 480) nt = 480;

        Dictionary<string, object> data = new Dictionary<string, object>();
        data["time"] = nt;

        string err = MongodbPlayer.Instance.ExecuteStoreBykey(TableName.KICK_PLAYER, "key", p.m_playerAcc, data);
        if (string.IsNullOrEmpty(err))
        {
            m_retData.Add("result", RetCode.RET_SUCCESS);
        }
        else
        {
            m_retData.Add("result", RetCode.RET_DB_ERROR);
        }
    }
}

//////////////////////////////////////////////////////////////////////////

// �������
public class ParamUnLockPlayer : ParamBase
{
    public ParamUnLockPlayer()
    {
        m_fieldIndex = 2;  
    }
}

// �������
public class DyOpUnLockPlayer : DyOpBase
{
    public override string doDyop(object param)
    {
        ParamUnLockPlayer p = (ParamUnLockPlayer)param;

        bool cres = createGMUser(p);
        if (!cres)
        {
            return Helper.genJsonStr(m_retData);
        }

        if (!p.checkSign(m_gmUser))
        {
            m_retData.Add("result", RetCode.RET_SIGN_ERROR);
            return Helper.genJsonStr(m_retData);
        }

        Player player = new Player(p.m_playerAcc, m_gmUser);
        if (!player.m_isExists)
        {
            m_retData.Add("result", RetCode.RET_NO_PLAYER);
            return Helper.genJsonStr(m_retData);
        }
        if (!player.isOwner(m_gmUser.m_acc))
        {
            m_retData.Add("result", RetCode.RET_NO_RIGHT);
            return Helper.genJsonStr(m_retData);
        }
        if (player.isInGame()) // �������Ϸ��
        {
            m_retData.Add("result", RetCode.RET_SUCCESS);
            return Helper.genJsonStr(m_retData);
        }
        unlock(p.m_playerAcc);

       /* string url = string.Format(CONST.URL_UNLOCK_PLAYER, p.m_playerAcc);
        var ret = HttpPost.Get(new Uri(url));
        if (ret != null)
        {
            string retStr = Encoding.UTF8.GetString(ret);
            Dictionary<string, object> retData =
                JsonHelper.ParseFromStr<Dictionary<string, object>>(retStr);
            if (retData.ContainsKey("result"))
            {
                int retCode = Convert.ToInt32(retData["result"]);

                m_retData.Add("result", retCode);

                if (retCode == RetCode.RET_SUCCESS && 
                    retData.ContainsKey("info"))
                {
                    string retURL = string.Format(CONST.URL_UNLOCK_PLAYER_RET, p.m_playerAcc, retData["info"]);
                    HttpPost.Get(new Uri(retURL));
                }
            }
        }*/

        return Helper.genJsonStr(m_retData);
    }

    void unlock(string acc)
    {
        var ret = MongodbPlayer.Instance.ExecuteGetBykey(TableName.PLAYER_INFO, "account", acc, new string[] { "SyncLock", "gold" });
        if (ret == null)
        {
            m_retData.Add("result", RetCode.RET_NO_PLAYER);
            return;
        }

        if (!ret.ContainsKey("SyncLock"))
        {
            m_retData.Add("result", RetCode.RET_SUCCESS);
            return;
        }
        int state = Convert.ToInt32(ret["SyncLock"]);
        if (state == 1 || state == 0) // �������
        {
            m_retData.Add("result", RetCode.RET_SUCCESS);
            return;
        }

        string retURL = string.Format(CONST.URL_UNLOCK_PLAYER_RET, acc, ret["gold"]);
        byte[] byarr = HttpPost.Get(new Uri(retURL));
        string retStr = Encoding.UTF8.GetString(byarr);
        if (retStr == "ok")
        {
            Dictionary<string, object> data = new Dictionary<string, object>();
            data["SyncLock"] = (sbyte)0;
            data["gold"] = 0;

            string err = MongodbPlayer.Instance.ExecuteUpdate(TableName.PLAYER_INFO, "account", acc, data);
            if (string.IsNullOrEmpty(err))
            {
                m_retData.Add("result", RetCode.RET_SUCCESS);
            }
            else
            {
                m_retData.Add("result", RetCode.RET_DB_ERROR);
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////

// ���������Ϣ
public class ParamUpdatePlayerInfo : ParamBase
{
    SqlUpdateGenerator m_gen = new SqlUpdateGenerator();

    public ParamUpdatePlayerInfo()
    {
        m_fieldIndex = 2;  
    }

    public void addField(HttpRequest Request)
    {
        foreach(var key in Request.QueryString.AllKeys)
        {
            if (DbFieldSet.getInstance().hasField(key))
            {
                m_gen.addField(key, Request.QueryString[key], DbFieldSet.getInstance().getDbField(key).m_fieldType);
            }
        }
    }

    public string genUpdateSql()
    {
        string sql = m_gen.getResultSql(TableName.PLAYER_ACCOUNT_XIANXIA,
                                        string.Format(" acc='{0}' ", m_playerAcc));
        return sql;
    }

    public override bool isParamValid()
    {
        if (!base.isParamValid())
            return false;

        if (m_gen.count() == 0) // û�п��Ը��µ���Ϣ
            return false;

        return true;
    }
}

// ���������Ϣ
public class DyOpUpdatePlayerInfo : DyOpBase
{
    public override string doDyop(object param)
    {
        ParamUpdatePlayerInfo p = (ParamUpdatePlayerInfo)param;

        bool cres = createGMUser(p);
        if (!cres)
        {
            return Helper.genJsonStr(m_retData);
        }

        if (!p.checkSign(m_gmUser))
        {
            m_retData.Add("result", RetCode.RET_SIGN_ERROR);
            return Helper.genJsonStr(m_retData);
        }

        Player player = new Player(p.m_playerAcc, m_gmUser);
        if (!player.m_isExists)
        {
            m_retData.Add("result", RetCode.RET_NO_PLAYER);
            return Helper.genJsonStr(m_retData);
        }
        if (!player.isOwner(m_gmUser.m_acc))
        {
            m_retData.Add("result", RetCode.RET_NO_RIGHT);
            return Helper.genJsonStr(m_retData);
        }

        string cmd = p.genUpdateSql();
        int count = m_gmUser.sqlDb.executeOp(cmd, MySqlDbName.DB_XIANXIA);
        if (count > 0)
        {
            m_retData.Add("result", RetCode.RET_SUCCESS);
        }
        else
        {
            m_retData.Add("result", RetCode.RET_DB_ERROR);
        }
        return Helper.genJsonStr(m_retData);
    }
}

//////////////////////////////////////////////////////////////////////////

// �����¼ʧ�ܴ���
public class DyOpClearLoginFailedCount : DyOpBase
{
    public override string doDyop(object param)
    {
        ParamBase p = (ParamBase)param;
        p.fieldIndex = 2;
        bool cres = createGMUser(p);
        if (!cres)
        {
            return Helper.genJsonStr(m_retData);
        }

        if (!p.checkSign(m_gmUser))
        {
            m_retData.Add("result", RetCode.RET_SIGN_ERROR);
            return Helper.genJsonStr(m_retData);
        }

        Player player = new Player(p.m_playerAcc, m_gmUser);
        if (!player.m_isExists)
        {
            m_retData.Add("result", RetCode.RET_NO_PLAYER);
            return Helper.genJsonStr(m_retData);
        }
        if (!player.isOwner(m_gmUser.m_acc))
        {
            m_retData.Add("result", RetCode.RET_NO_RIGHT);
            return Helper.genJsonStr(m_retData);
        }

        string url = string.Format(CONST.URL_CLEAR_FAILED_LOGIN, p.m_playerAcc);
        var ret = HttpPost.Get(new Uri(url));
        if (ret != null)
        {
            string retStr = Encoding.UTF8.GetString(ret);
            if (retStr == "0")
            {
                m_retData.Add("result", RetCode.RET_SUCCESS);
            }
            else
            {
                m_retData.Add("result", RetCode.RET_OP_FAILED);
            }
        }
        else
        {
            m_retData.Add("result", RetCode.RET_OP_FAILED);
        }
        return Helper.genJsonStr(m_retData);
    }
}

//////////////////////////////////////////////////////////////////////////
public class ParamModifyPlayerPwd : ParamBase
{
    // ������
    public string m_oldPwd = "";
    // �����õ�����
    public string m_newPwd = "";

    public ParamModifyPlayerPwd()
    {
        m_fieldIndex = 2;
    }

    public override bool isParamValid()
    {
        if (!base.isParamValid())
            return false;

        //if (string.IsNullOrEmpty(m_oldPwd))
        //    return false;

        if (string.IsNullOrEmpty(m_newPwd))
            return false;

        return true;
    }

    // ���ǩ��
    public override bool checkSign(GMUser user)
    {
        string sign = Tool.getMD5Hash(m_gmAccount + m_gmPwd + m_playerAcc + m_oldPwd + m_newPwd + user.m_devSecretKey);
        return m_sign == sign;
    }
}

// �޸��������
public class DyOpModifyPlayerPwd : DyOpBase
{
    const string AES_KEY = "959D!@23ia@!#86e";

    public override string doDyop(object param)
    {
        ParamModifyPlayerPwd p = (ParamModifyPlayerPwd)param;
        bool cres = createGMUser(p);
        if (!cres)
        {
            return Helper.genJsonStr(m_retData);
        }
        if (!p.checkSign(m_gmUser))
        {
            m_retData.Add("result", RetCode.RET_SIGN_ERROR);
            return Helper.genJsonStr(m_retData);
        }

        if (m_gmUser.m_accType != AccType.ACC_API)
        {
            m_retData.Add("result", RetCode.RET_NO_RIGHT);
            return Helper.genJsonStr(m_retData);
        }

        if (!Regex.IsMatch(p.m_newPwd, Exp.ACCOUNT_PLAYER_PWD))
        {
            m_retData.Add("result", RetCode.RET_PARAM_NOT_VALID);
            return Helper.genJsonStr(m_retData);
        }

        string error = modifyPwd(p);
        if (error == "err_success")
        {
            m_retData.Add("result", RetCode.RET_SUCCESS);
            m_retData.Add("playerAcc", p.m_playerAcc);
        }
        else if (error == "err_pwd_error") // ԭ�������
        {
            m_retData.Add("result", RetCode.RET_ACC_PWD_FORMAT_ERROR);
            m_retData.Add("playerAcc", p.m_playerAcc);
        }
        else
        {
            m_retData.Add("result", RetCode.RET_OP_FAILED);
            m_retData.Add("playerAcc", p.m_playerAcc);
        }
        return Helper.genJsonStr(m_retData);
    }

    private string modifyPwd(ParamModifyPlayerPwd p)
    {
        RSAHelper rsa = new RSAHelper();
        rsa.init();
        Dictionary<string, object> data = new Dictionary<string, object>();
        data["n1"] = p.m_playerAcc;
        string old = Tool.getMD5Hash(p.m_oldPwd);
        data["n2"] = AESHelper.AESEncrypt(old, AES_KEY);

        string newPwd = Tool.getMD5Hash(p.m_newPwd);
        data["n3"] = AESHelper.AESEncrypt(newPwd, AES_KEY);

        string jsonstr = JsonHelper.ConvertToStr(data);
        string md5 = AESHelper.MD5Encrypt(jsonstr + AES_KEY);
        string urlstr = Convert.ToBase64String(Encoding.Default.GetBytes(jsonstr));

        string fmt = CONST.URL_MODIFY_PLAYER_PWD;
        string aspx = string.Format(fmt, urlstr, md5);
        var ret = HttpPost.Get(new Uri(aspx));
        if (ret != null)
        {
            string retStr = Encoding.UTF8.GetString(ret);
            return retStr;
        }
        return "";
    }
}

//////////////////////////////////////////////////////////////////////////
public class ParamPlayerOp : ParamBase
{
    public string m_opStr;
    
    // 0 ͣ���˺� 1 ����˺�
    public int m_op;

    public override bool isParamValid()
    {
        if (!base.isParamValid())
            return false;

        if (string.IsNullOrEmpty(m_opStr))
            return false;

        if (!int.TryParse(m_opStr, out m_op))
            return false;

        return true;
    }

    // ���ǩ��
    public override bool checkSign(GMUser user)
    {
        string sign = Tool.getMD5Hash(m_gmAccount + m_gmPwd + m_playerAcc + m_opStr + user.m_devSecretKey);
        return m_sign == sign;
    }
}

// �����ز���
public class DyOpPlayerOp : DyOpBase
{
    public override string doDyop(object param)
    {
        ParamPlayerOp p = (ParamPlayerOp)param;
        bool cres = createGMUser(p);
        if (!cres)
        {
            return Helper.genJsonStr(m_retData);
        }
        if (!p.checkSign(m_gmUser))
        {
            m_retData.Add("result", RetCode.RET_SIGN_ERROR);
            return Helper.genJsonStr(m_retData);
        }

        Player player = new Player(p.m_playerAcc, m_gmUser);
        if (!player.m_isExists)
        {
            m_retData.Add("result", RetCode.RET_NO_PLAYER);
            return Helper.genJsonStr(m_retData);
        }
        if (!player.isOwner(m_gmUser.m_acc))
        {
            m_retData.Add("result", RetCode.RET_NO_RIGHT);
            return Helper.genJsonStr(m_retData);
        }

        int retCode = RetCode.RET_PARAM_NOT_VALID;
        switch (p.m_op)
        {
            case 0:
                {
                    retCode = stopPlayerAcc(p);
                }
                break;
            case 1:
                {
                    retCode = startPlayerAcc(p);
                }
                break;
        }

        m_retData.Add("result", retCode);
        return Helper.genJsonStr(m_retData);
    }

    // ͣ������˺�
    int stopPlayerAcc(ParamPlayerOp p)
    {
        SqlUpdateGenerator gen = new SqlUpdateGenerator();

        gen.addField("enable", 0, FieldType.TypeNumber);
        string sql = gen.getResultSql(TableName.PLAYER_ACCOUNT_XIANXIA,
             string.Format(" acc='{0}' ", p.m_playerAcc));
        int count = m_gmUser.sqlDb.executeOp(sql, MySqlDbName.DB_XIANXIA);
        return count > 0 ? RetCode.RET_SUCCESS : RetCode.RET_DB_ERROR;
    }

    // �������˺�
    int startPlayerAcc(ParamPlayerOp p)
    {
        SqlUpdateGenerator gen = new SqlUpdateGenerator();

        gen.addField("enable", 1, FieldType.TypeNumber);
        string sql = gen.getResultSql(TableName.PLAYER_ACCOUNT_XIANXIA,
             string.Format(" acc='{0}' ", p.m_playerAcc));
        int count = m_gmUser.sqlDb.executeOp(sql, MySqlDbName.DB_XIANXIA);
        return count > 0 ? RetCode.RET_SUCCESS : RetCode.RET_DB_ERROR;
    }
}

using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using MongoDB.Bson;
using MongoDB.Driver;
using MongoDB.Driver.Builders;

class FishDelInfo
{
    public FishDelInfo(string data, string viewname)
    {
        m_data = data;
        m_tableName = viewname;
    }

    // ��������
    public string m_data;
    // ������
    public string m_tableName;
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
    // ��ֵ��ֵ
    statTypeLTV,
    // ��ֵ�û�ͳ��
    statTypeRechargePlayer,
}

class StatMgr : SysBase
{
    // �洢ɾ��ͳ�Ƶ������Ϣ
    private List<FishDelInfo> m_dels = new List<FishDelInfo>();
   
    // ͳ��ʵ��
    private Dictionary<StatType, PumpBase> m_items = new Dictionary<StatType, PumpBase>();

    public StatMgr()
    {
        m_sysType = SysType.sysTypeStat;
    }

    // ��ȡ��ɾ���б�
    public List<FishDelInfo> getDelList()
    {
        return m_dels;
    }

    // ɾ��ͳ������
    public OpRes delAllStatData(int index, GMUser user)
    {
        if (user == null)
        {
            return OpRes.op_res_failed;
        }
        if (index < 0 || index >= m_dels.Count)
        {
            return OpRes.op_res_failed;
        }

        FishDelInfo info = m_dels[index];
        // ���ָ�����е���������
        bool res = DBMgr.getInstance().clearTable(info.m_tableName, user.getDbServerID(), DbName.DB_PUMP);
        if (res) // ���LOG
        {
            //OpLogMgr.getInstance().addLog(LogType.LOG_TYPE_DEL_STAT_DATA, new ParamDelStatData(info.m_data), user);
            return OpRes.opres_success;
        }
        return OpRes.op_res_failed;
    }

    // ��ͳ��
    public OpRes doStat(object param, StatType statName, GMUser user)
    {
        if (!m_items.ContainsKey(statName))
        {
            LOGW.Info("����������Ϊ[{0}]��ͳ��", statName);
            return OpRes.op_res_failed;
        }
        return m_items[statName].doStat(param, user);
    }

    // ����ͳ�ƽ��
    public object getStatResult(StatType statName)
    {
        if (!m_items.ContainsKey(statName))
        {
            LOGW.Info("����������Ϊ[{0}]��ͳ��", statName);
            return null;
        }
        return m_items[statName].getStatResult();
    }

    public PumpBase getPump(StatType statName)
    {
        if (m_items.ContainsKey(statName))
        {
            return m_items[statName];
        }
        return null;
    }

    // ���ɲ�ѯ����
    public OpRes makeQuery(object param, StatType queryType, GMUser user, QueryCondition imq)
    {
        if (!m_items.ContainsKey(queryType))
        {
            return OpRes.op_res_failed;
        }
        return m_items[queryType].makeQuery(param, user, imq);
    }

    public override void initSys()
    {
        m_items.Add(StatType.statTypeRecharge, new StatRecharge());
        m_items.Add(StatType.statTypeSameOrderId, new StatSameOrderId());
        m_items.Add(StatType.statTypeActiveCount, new StatActiveCount());
        m_items.Add(StatType.statTypeActivePerson, new StatActivePerson());
        m_items.Add(StatType.statTypeVipLevel, new StatVipLevel());

        m_items.Add(StatType.statTypeLTV, new StatLTV());
        m_items.Add(StatType.statTypeRechargePlayer, new StatRechargePlayer());
    }
}

//////////////////////////////////////////////////////////////////////////

public class PumpBase
{
    // ��ʼͳ��
    public virtual OpRes doStat(object param, GMUser user) { return OpRes.op_res_failed; }
    // ����ͳ�ƽ��
    public virtual object getStatResult() { return null; }

    public virtual OpRes makeQuery(object param, GMUser user, QueryCondition imq) { return OpRes.op_res_failed; }
}

//////////////////////////////////////////////////////////////////////////

public class ResultStatRecharge
{
    public int m_total = 0;
    // ��ֵ����
    public int m_rechargeCount = 0;
    // ��ֵ����
    public int m_rechargePersonNum = 0;
    
    public void reset()
    {
        m_total = 0;
        m_rechargeCount = 0;
        m_rechargePersonNum = 0;
    }
}

// ��ֵ�ܼ�
public class StatRecharge : PumpBase
{
    private ResultStatRecharge m_result = new ResultStatRecharge();
    private QueryCondition m_cond = new QueryCondition();

    // ��ʼͳ��
    public override OpRes doStat(object param, GMUser user)
    {
        ParamQueryRecharge p = (ParamQueryRecharge)param;
        QueryMgr mgr = user.getSys<QueryMgr>(SysType.sysTypeQuery);
        m_cond.startQuery();
        OpRes res = mgr.makeQuery(param, QueryType.queryTypeRecharge, user, m_cond);
        if (res != OpRes.opres_success)
            return res;

        IMongoQuery imq = m_cond.getImq();
        m_result.reset();
        QueryRecharge rq = mgr.getQuery<QueryRecharge>(QueryType.queryTypeRecharge);
        int serverId = DBMgr.getInstance().getSpecialServerId(DbName.DB_PAYMENT);
        MapReduceResult map_result = DBMgr.getInstance().executeMapReduce(rq.getPlatInfo().m_tableName,
                                                                            serverId,
                                                                            DbName.DB_PAYMENT,
                                                                            imq,
                                                                            MapReduceTable.getMap("recharge"),
                                                                            MapReduceTable.getReduce("recharge"));
        if (map_result != null)
        {
            IEnumerable<BsonDocument> bson = map_result.GetResults();
            foreach (BsonDocument d in bson)
            {
                BsonValue resValue = d["value"];
                m_result.m_total += resValue["total"].ToInt32();
                m_result.m_rechargePersonNum++;
                m_result.m_rechargeCount += resValue["rechargeCount"].ToInt32();
            }
        }
        return OpRes.opres_success;
    }

    public override object getStatResult() { return m_result; }
}

//////////////////////////////////////////////////////////////////////////

public class ResultSameOrderIdItem
{
    public string m_orderId = "";
    
    // ���ִ���
    public int m_count = 0;
}

// ��ͬ�����ŵ�ͳ��
public class StatSameOrderId : PumpBase
{
    private List<ResultSameOrderIdItem> m_result = new List<ResultSameOrderIdItem>();
    private QueryCondition m_cond = new QueryCondition();

    // ��ʼͳ��
    public override OpRes doStat(object param, GMUser user)
    {
        ParamQueryRecharge p = (ParamQueryRecharge)param;
        QueryMgr mgr = user.getSys<QueryMgr>(SysType.sysTypeQuery);
        m_cond.startQuery();
        OpRes res = mgr.makeQuery(param, QueryType.queryTypeRecharge, user, m_cond);
        if (res != OpRes.opres_success)
            return res;

        IMongoQuery imq = m_cond.getImq();
        QueryDocument qd = (QueryDocument)imq;
        if (!qd.Contains("PayTime"))
        {
            return OpRes.op_res_time_format_error;
        }

        m_result.Clear();
        QueryRecharge rq = mgr.getQuery<QueryRecharge>(QueryType.queryTypeRecharge);
        int serverId = DBMgr.getInstance().getSpecialServerId(DbName.DB_PAYMENT);
        MapReduceResult map_result = DBMgr.getInstance().executeMapReduce(rq.getPlatInfo().m_tableName,
                                                                            serverId,
                                                                            DbName.DB_PAYMENT,
                                                                            imq,
                                                                            MapReduceTable.getMap("sameOrderId"),
                                                                            MapReduceTable.getReduce("sameOrderId"));
        int count = 0;
        if (map_result != null)
        {
            IEnumerable<BsonDocument> bson = map_result.GetResults();
            foreach (BsonDocument d in bson)
            {
                BsonValue resValue = d["value"];
                count = resValue["total"].ToInt32();
                if (count > 1)
                {
                    ResultSameOrderIdItem tmp = new ResultSameOrderIdItem();
                    m_result.Add(tmp);
                    tmp.m_count = count;
                    tmp.m_orderId = Convert.ToString(d["_id"]);
                }
            }
        }
        return OpRes.opres_success;
    }

    public override object getStatResult() { return m_result; }
}

//////////////////////////////////////////////////////////////////////////

public class ResultActive
{
    // ʱ��
    public string m_time = "";
    // ����
    public int m_game1 = 0; 
    // ����
    public int m_game2 = 0;
    // Ѻ��
    public int m_game3 = 0;
    // ����ţţ
    public int m_game4 = 0;
    // �ټ���
    public int m_game5 = 0;
    // ������
    public int m_game6 = 0;
    // �齫
    public int m_game7 = 0;
    // ���
    public int m_game8 = 0;
}

// ��Ծ
public class StatActive: PumpBase
{
    private List<ResultActive> m_result = new List<ResultActive>();

    // ��ʼͳ��
    public override OpRes doStat(object param, GMUser user)
    {
        string time = (string)param;
        DateTime mint = DateTime.Now, maxt = DateTime.Now;
        bool res = Tool.splitTimeStr(time, ref mint, ref maxt);
        if (!res)
            return OpRes.op_res_time_format_error;

        IMongoQuery imq1 = Query.LT("genTime", BsonValue.Create(maxt));
        IMongoQuery imq2 = Query.GTE("genTime", BsonValue.Create(mint));
        IMongoQuery imq = Query.And(imq1, imq2);

        m_result.Clear();
        MapReduceResult mapResult = getMapReduceResult(imq, user);

        if (mapResult != null)
        {
            IEnumerable<BsonDocument> bson = mapResult.GetResults();
            foreach (BsonDocument d in bson)
            {
                BsonValue resValue = d["value"];
                ResultActive tmp = new ResultActive();
                m_result.Add(tmp);
                tmp.m_time = Convert.ToDateTime(d["_id"]).ToLocalTime().ToString();
                tmp.m_game1 = resValue["game1"].ToInt32();
                tmp.m_game2 = resValue["game2"].ToInt32();
                tmp.m_game3 = resValue["game3"].ToInt32();
                tmp.m_game4 = resValue["game4"].ToInt32();
                tmp.m_game5 = resValue["game5"].ToInt32();
                tmp.m_game6 = resValue["game6"].ToInt32();
                tmp.m_game7 = resValue["game7"].ToInt32();
                tmp.m_game8 = resValue["game8"].ToInt32();
            }
        }
        return OpRes.opres_success;
    }

    public override object getStatResult() { return m_result; }

    protected virtual MapReduceResult getMapReduceResult(IMongoQuery imq, GMUser user)
    {
        return null;
    }
}

// ��Ծ����ͳ��
public class StatActiveCount : StatActive
{
    protected override MapReduceResult getMapReduceResult(IMongoQuery imq, GMUser user)
    {
        MapReduceResult mapResult = DBMgr.getInstance().executeMapReduce(TableName.PUMP_ACTIVE_COUNT,
                                                                    user.getDbServerID(),
                                                                    DbName.DB_PUMP,
                                                                    imq,
                                                                    MapReduceTable.getMap("activeCount"),
                                                                    MapReduceTable.getReduce("activeCount"));
        return mapResult;
    }
}

// ��Ծ����ͳ��
public class StatActivePerson : StatActive
{
    protected override MapReduceResult getMapReduceResult(IMongoQuery imq, GMUser user)
    {
        MapReduceResult mapResult = DBMgr.getInstance().executeMapReduce(TableName.PUMP_ACTIVE_PERSON,
                                                                    user.getDbServerID(),
                                                                    DbName.DB_PUMP,
                                                                    imq,
                                                                    MapReduceTable.getMap("activePerson"),
                                                                    MapReduceTable.getReduce("activePerson"));
        return mapResult;
    }
}

//////////////////////////////////////////////////////////////////////////

public class StatResultVipLevel
{
    // vip�ȼ��ֲ�
    public Dictionary<int, int> m_vipLevel = new Dictionary<int, int>();

    public void reset()
    {
        m_vipLevel.Clear();
    }

    public void addVipLevel(int vip, int count)
    {
        if (m_vipLevel.ContainsKey(vip))
        {
            m_vipLevel[vip] += count;
        }
        else
        {
            m_vipLevel.Add(vip, count);
        }
    }
}

// vip�ȼ��ķֲ�ͳ��
public class StatVipLevel : PumpBase
{
    private StatResultVipLevel m_result = new StatResultVipLevel();

    // ��ʼͳ��
    public override OpRes doStat(object param, GMUser user)
    {
        IMongoQuery imqTime = null;
        string time = (string)param;
        if (!string.IsNullOrEmpty(time))
        {
            DateTime mint = DateTime.Now, maxt = DateTime.Now;
            bool res = Tool.splitTimeStr(time, ref mint, ref maxt);
            if (!res)
                return OpRes.op_res_time_format_error;

            m_result.reset();

            IMongoQuery imq1 = Query.LT("create_time", BsonValue.Create(maxt));
            IMongoQuery imq2 = Query.GTE("create_time", BsonValue.Create(mint));
            imqTime = Query.And(imq1, imq2);
        }
        
        m_result.reset();
        MapReduceResult map_result = DBMgr.getInstance().executeMapReduce(TableName.PLAYER_INFO,
                                                                            user.getDbServerID(),
                                                                            DbName.DB_PLAYER,
                                                                            imqTime,
                                                                            MapReduceTable.getMap("vipLevel"),
                                                                            MapReduceTable.getReduce("vipLevel"));
        if (map_result != null)
        {
            IEnumerable<BsonDocument> bson = map_result.GetResults();
            foreach (BsonDocument d in bson)
            {
                try
                {
                    BsonValue resValue = d["value"];
                    int count = resValue["count"].ToInt32();
                    int vip = Convert.ToInt32(d["_id"]);
                    m_result.addVipLevel(vip, count);
                }
                catch (System.Exception ex)
                {
                }
            }
        }
        return OpRes.opres_success;
    }

    public override object getStatResult() { return m_result; }
}

//////////////////////////////////////////////////////////////////////////
public class StatLTV : PumpBase
{
    private List<ResultLTVItem> m_result = new List<ResultLTVItem>();

    // ��ʼͳ��
    public override OpRes doStat(object param, GMUser user)
    {
        ParamQuery p = (ParamQuery)param;

        if (string.IsNullOrEmpty(p.m_time))
            return OpRes.op_res_time_format_error;

        DateTime mint = DateTime.Now, maxt = DateTime.Now;
        bool res = Tool.splitTimeStr(p.m_time, ref mint, ref maxt);
        if (!res)
            return OpRes.op_res_time_format_error;

        m_result.Clear();

        int serverId = DBMgr.getInstance().getSpecialServerId(DbName.DB_ACCOUNT);
        if (serverId == -1)
            return OpRes.op_res_failed;

        IMongoQuery imq1 = Query.LT("genTime", BsonValue.Create(maxt));
        IMongoQuery imq2 = Query.GTE("genTime", BsonValue.Create(mint));
        IMongoQuery imqTime = Query.And(imq1, imq2);

        MapReduceResult map_result = DBMgr.getInstance().executeMapReduce(TableName.CHANNEL_TD,
                                                                            serverId,
                                                                            DbName.DB_ACCOUNT,
                                                                            imqTime,
                                                                            MapReduceTable.getMap("LTV"),
                                                                            MapReduceTable.getReduce("LTV"));
        if (map_result != null)
        {
            IEnumerable<BsonDocument> bson = map_result.GetResults();
            foreach (BsonDocument d in bson)
            {
                try
                {
                    ResultLTVItem tmp = new ResultLTVItem();
                    tmp.m_genTime = Convert.ToDateTime(d["_id"]).ToLocalTime().ToShortDateString();
                    BsonValue resValue = d["value"];
                    tmp.m_regeditCount = resValue["regeditCount"].ToInt32();
                    tmp.m_1DayTotalRecharge = resValue["day1TotalRecharge"].ToInt32();
                    tmp.m_3DayTotalRecharge = resValue["day3TotalRecharge"].ToInt32();
                    tmp.m_7DayTotalRecharge = resValue["day7TotalRecharge"].ToInt32();
                    tmp.m_14DayTotalRecharge = resValue["day14TotalRecharge"].ToInt32();
                    tmp.m_30DayTotalRecharge = resValue["day30TotalRecharge"].ToInt32();
                    tmp.m_60DayTotalRecharge = resValue["day60TotalRecharge"].ToInt32();
                    tmp.m_90DayTotalRecharge = resValue["day90TotalRecharge"].ToInt32();

                    m_result.Add(tmp);
                }
                catch (System.Exception ex)
                {
                }
            }
        }
        return OpRes.opres_success;
    }

    public override object getStatResult() { return m_result; }
}

//////////////////////////////////////////////////////////////////////////
public class RechargePlayerItem : ResultRPlayerItem
{
    public string m_channelId;

    public string getChannelName()
    {
        TdChannelInfo info = TdChannel.getInstance().getValue(m_channelId);
        if (info != null)
        {
            return info.m_channelName;
        }
        return m_channelId;
    }
}

public class StatRechargePlayer : PumpBase
{
    static string[] s_fields = { "create_time", "gold", "maxGold", "logout_time", "ChannelID" };
    static string MapTable = TableName.PUMP_RECHARGE_PLAYER + "_map";
    private List<RechargePlayerItem> m_result = new List<RechargePlayerItem>();
    private QueryCondition m_cond = new QueryCondition();
    private string m_lastSearchTime = "";

    // ��ʼͳ��
    public override OpRes doStat(object param, GMUser user)
    {
        m_result.Clear();
        m_cond.startQuery();
        OpRes res = makeQuery(param, user, m_cond);
        if (res != OpRes.opres_success)
            return res;

        ParamQuery p = (ParamQuery)param;

        if (p.m_time == m_lastSearchTime)
        {
            return query(p, null, user);
        }
        else
        {
            m_lastSearchTime = p.m_time;
        }

        IMongoQuery imqTime = m_cond.getImq();

        MapReduceResult map_result = DBMgr.getInstance().executeMapReduce(TableName.PUMP_RECHARGE_PLAYER,
                                                                            user.getDbServerID(),
                                                                            DbName.DB_PUMP,
                                                                            imqTime,
                                                                            MapReduceTable.getMap("rechargePlayer"),
                                                                            MapReduceTable.getReduce("rechargePlayer"),
                                                                            MapTable);
        if (map_result != null)
        {
            return query(p, null, user);
        }
        return OpRes.opres_success;
    }

    public override object getStatResult() { return m_result; }

    public override OpRes makeQuery(object param, GMUser user, QueryCondition queryCond)
    {
        ParamQuery p = (ParamQuery)param;

        if (string.IsNullOrEmpty(p.m_time))
            return OpRes.op_res_time_format_error;

        DateTime mint = DateTime.Now, maxt = DateTime.Now;
        bool res = Tool.splitTimeStr(p.m_time, ref mint, ref maxt);
        if (!res)
            return OpRes.op_res_time_format_error;

        if (queryCond.isExport())
        {
            queryCond.addCond("time", p.m_time);
        }
        else
        {
            IMongoQuery imq1 = Query.LT("genTime", BsonValue.Create(maxt));
            IMongoQuery imq2 = Query.GTE("genTime", BsonValue.Create(mint));
            queryCond.addImq(Query.And(imq1, imq2));

            IMongoQuery imq3 = Query.GT("rechargeCount", 0);
            queryCond.addImq(imq3);
        }
        return OpRes.opres_success;
    }

    protected virtual OpRes query(ParamQuery param, IMongoQuery imq, GMUser user)
    {
        // �鿴���������ļǵ�����
        user.totalRecord = DBMgr.getInstance().getRecordCount(MapTable, null, user.getDbServerID(), DbName.DB_PUMP);

        List<BsonDocument> data =
             DBMgr.getInstance().executeQueryBsonDoc(MapTable, user.getDbServerID(), DbName.DB_PUMP, null,
                                              (param.m_curPage - 1) * param.m_countEachPage, param.m_countEachPage,
                                              null, "value.rechargeMoney", false);

        if (data == null || data.Count == 0)
        {
            return OpRes.op_res_not_found_data;
        }

        int i = 0;
        for (i = 0; i < data.Count; i++)
        {
            addResult(data[i], user);
        }
        return OpRes.opres_success;
    }

    void addResult(BsonDocument d, GMUser user)
    {
        try
        {
            RechargePlayerItem tmp = new RechargePlayerItem();
            m_result.Add(tmp);

            tmp.m_playerId = Convert.ToInt32(d["_id"]);
            BsonValue resValue = d["value"];
            tmp.m_rechargeCount = resValue["rechargeCount"].ToInt32();
            tmp.m_rechargeMoney = resValue["rechargeMoney"].ToInt32();
            tmp.m_loginCount = resValue["loginCount"].ToInt32();

            var arr = resValue["enterGame"].AsBsonArray;
            for (int i = 0; i < arr.Count; i++)
            {
                tmp.addEnterCount(i + 1, arr[i].ToInt32());
            }

            Dictionary<string, object> pd = QueryBase.getPlayerProperty(tmp.m_playerId, user, s_fields);
            if (pd != null)
            {
                tmp.m_mostGold = Convert.ToInt32(pd["maxGold"]);
                tmp.m_remainGold = Convert.ToInt32(pd["gold"]);
                tmp.m_regTime = Convert.ToDateTime(pd["create_time"]).ToLocalTime();
                tmp.m_lastLoginTime = Convert.ToDateTime(pd["logout_time"]).ToLocalTime();
                if (pd.ContainsKey("ChannelID"))
                {
                    tmp.m_channelId = Convert.ToString(pd["ChannelID"]).PadLeft(6, '0');
                }
            }
        }
        catch (System.Exception ex)
        {
        }
    }
}

using System;
using System.Web.Configuration;
using System.Collections.Generic;

// ��½GM�û����
public class GMUser : SysMgr
{
    // ��½�ʺ���
    public string m_user = "";

    // �ʺ�Ȩ��
    public string m_right = "";

    // ��½����
    public string m_pwd = "";

    public string m_type = "";
    
    // �ɲ鿴������
    public string m_viewChannel = "";

    // ��½���ʺ�IP
    public string m_ip = "";
    // Ҫ���������ݿ�IP
    public string m_dbIP="";
    // GM�Ϲҽӵ�DB��ÿ��GM���Բ�����db��ͬ
    private int m_dbId = 0;
    // ֮ǰ��URL
    private string m_preURL = "";
    private long m_totalRecord = 0;

    // �Ƿ��¼��
    private bool m_isLogin = false;

    public string preURL
    {
        get { return m_preURL; }
        set
        {
            if (value != "/appaspx/SelectMachine.aspx")
            {
                m_preURL = value;
            }
        }
    }

    // �û�������ܼ�¼����
    public long totalRecord
    {
        get { return m_totalRecord; }
        set { m_totalRecord = value; }
    }

    public GMUser() { }

    public bool isLogin { get { return m_isLogin; } }

    // ���عҽӵĲ���DB
    public int getDbServerID()
    {
        return m_dbId;
    }

    // ��ʼ��
    public void init()
    {
        m_dbIP = WebConfigurationManager.AppSettings["account"];
        m_dbId = DBMgr.getInstance().getDbId(m_dbIP);

        addSys(new QueryMgr());
        initSys();
    }

    public void exitLogin()
    {
        exit();
        m_sys.Clear();
    }

    public bool doLogin(string accLogin, string pwdLogin)
    {
        if (m_isLogin)
            return true;

        Dictionary<string, object> ret =
            DBMgr.getInstance().getTableData(TableName.GM_ACCOUNT, "user", accLogin, 0, DbName.DB_ACCOUNT);
        if (ret == null)
            return false;

        string user = Convert.ToString(ret["user"]);
        string tpwd = Convert.ToString(ret["password"]);
        string p = Tool.getMD5Hash(pwdLogin);

        if (user == accLogin && tpwd == p)
        {
            init();

            m_user = user;
            m_type = Convert.ToString(ret["type"]);
            m_viewChannel = Convert.ToString(ret["viewChannel"]);
            m_isLogin = true;
            return true;
        }

        return false;
    }

    // ����Ҫ��������Ϸ���ݿ�
    public bool changeGameDb(string pools)
    {
        int id = DBMgr.getInstance().getDbId(pools);
        if (id == -1)
        {
            return false;
        }
        m_dbId = id;
        m_dbIP = pools;
        return true;
    }

    // ��ѯ
    public OpRes doQuery(object param, QueryType queryType)
    {
        QueryMgr mgr = getSys<QueryMgr>(SysType.sysTypeQuery);
        OpRes res = mgr.doQuery(param, queryType, this);
        return res;
    }

    // ���ز�ѯ���
    public object getQueryResult(QueryType queryType)
    {
        QueryMgr mgr = getSys<QueryMgr>(SysType.sysTypeQuery);
        return mgr.getQueryResult(queryType);
    }

    // �ɷ�鿴����
    public bool canViewChannel(string channelId)
    {
        if (m_viewChannel == "all")
            return true;

        int index = m_viewChannel.IndexOf(channelId);
        return index >= 0;
    }

    // ���ؿɲ鿴�������б�
    public List<string> getViewChannelList()
    {
        List<string> channelList = new List<string>();
        if (m_viewChannel == "all")
        {
            List<ChannelInfo> cList = Channel.getInstance().m_cList;
            foreach (var info in cList)
            {
                channelList.Add(info.channelNo);
            }
        }
        else
        {
            string[] arr = Tool.split(m_viewChannel, ',', StringSplitOptions.RemoveEmptyEntries);
            foreach (var str in arr)
            {
                channelList.Add(str);
            }
        }

        return channelList;
    }
}



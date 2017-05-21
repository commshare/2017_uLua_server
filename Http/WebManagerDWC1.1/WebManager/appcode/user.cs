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

    // ��½���ʺ�IP
    public string m_ip = "";
    // Ҫ���������ݿ�IP
    public string m_dbIP="";
    // GM�Ϲҽӵ�DB��ÿ��GM���Բ�����db��ͬ
    private int m_dbId = 0;
    // ���ò������
    private string m_opResult = "";
    // ֮ǰ��URL
    private string m_preURL = "";
    private long m_totalRecord = 0;

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
    public GMUser(AccountInfo info)
    {
        m_user = info.m_user;
        m_right = info.m_right;
        m_pwd = info.m_pwd;
        m_ip = info.m_ip;
        m_type = info.m_type;
    }

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
        addSys(new DyOpMgr());
        addSys(new StatMgr());
        addSys(new ExportMgr());
        initSys();
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

    public string getOpResultString()
    {
        return m_opResult;
    }

    public void setOpResult(OpRes res)
    {
        m_opResult = OpResMgr.getInstance().getResultString(res);
    }
}



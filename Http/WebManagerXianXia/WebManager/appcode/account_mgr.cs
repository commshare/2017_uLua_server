using System;
using System.Web.SessionState;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Text;

class AccountMgr : SysBase
{
    private static AccountMgr s_mgr = null;
    // �洢��½�û����û�����Ựӳ��
    private Dictionary<string, HttpSessionState> m_user = new Dictionary<string, HttpSessionState>();
    // �˺������б�
    private List<AccountType> m_accountType = new List<AccountType>();

    public AccountMgr()
    {
        m_sysType = SysType.sysTypeAccount;
    }

    public static AccountMgr getInstance(GMUser user = null)
    {
        AccountMgr mgr = user.getSys<AccountMgr>(SysType.sysTypeAccount);
        return mgr;
    }

    public List<AccountType> getAccountTypeList()
    {
        return m_accountType;
    }

    public AccountType getAccountTypeByType(string type)
    {
        int i = 0;
        for (; i < m_accountType.Count; i++)
        {
            if (m_accountType[i].m_type == type)
            {
                return m_accountType[i];
            }
        }
        return null;
    }

    // ����һ���˺�
    public bool addAccount(string account, string key1, string key2, int sel, GMUser user)
    {
        bool res = true;
        if (account == null || account == "")
            res = false;
        if (key1 != key2)
            res = false;
        if (key1 == null)
        {
            res = false;
        }
        if (sel < 0 || sel >= m_accountType.Count)
            res = false;
        // ����˺�
        if (res)
        {
            Dictionary<string, object> data = genAccount("GM_" + account, m_accountType[sel].m_type, key1);
            res = DBMgr.getInstance().addTableData(TableName.GM_ACCOUNT, data, "user", Convert.ToString(data["user"]), 0, DbName.DB_ACCOUNT);

            if (res) // ���LOG
            {
                //OpLogMgr.getInstance().addLog(LogType.LOG_TYPE_ADD_ACCOUNT, new ParamAddAccount(account), user);
            }
        }
        user.setOpResult(res ? OpRes.opres_success : OpRes.op_res_failed);
        return res;
    }

    public OpRes delAccount(string account, GMUser user)
    {
        bool res = DBMgr.getInstance().remove(TableName.GM_ACCOUNT, "user", account, 0, DbName.DB_ACCOUNT);
        return res ? OpRes.opres_success : OpRes.op_res_failed;
    }

    // �����˺ŷ�����Ϣ
    public void updateAccount(List<GMAccountItem> gm_list)
    {
        Dictionary<string, object> data = new Dictionary<string, object>();
        for (int i = 0; i < gm_list.Count; i++)
        {
            data["type"] = gm_list[i].m_type;
            DBMgr.getInstance().update(TableName.GM_ACCOUNT, data, "user", gm_list[i].m_user, 0, DbName.DB_ACCOUNT);
        }
    }

    // ��ʼ��Ĭ���ʺ�
    private void initAccount()
    {
        List<Dictionary<string, object>> accountlist = new List<Dictionary<string, object>>();
        accountlist.Add(genAccount("GM_admin", "admin", "123456"));
       
        foreach(Dictionary<string, object> acc in accountlist)
        {
            DBMgr.getInstance().addTableData(TableName.GM_ACCOUNT, acc, "user", Convert.ToString(acc["user"]), 0, DbName.DB_ACCOUNT);
        }
        
        // �˺����͵��б�
        m_accountType.Add(new AccountType("program", "����"));
        m_accountType.Add(new AccountType("plan", "�߻�"));
        m_accountType.Add(new AccountType("operation", "��Ӫ"));
        m_accountType.Add(new AccountType("service", "�ͷ�"));
        m_accountType.Add(new AccountType("opDirector", "��Ӫ�ܼ�"));
        m_accountType.Add(new AccountType("ceo", "CEO"));
    }

    // ����һ���˺�
    private Dictionary<string, object> genAccount(string user, string type, string password)
    {
        Dictionary<string, object> data = new Dictionary<string, object>();
        data["user"] = user;
        data["type"] = type;
        data["password"] = Tool.getMD5Hash(password);
        return data;
    }
}




















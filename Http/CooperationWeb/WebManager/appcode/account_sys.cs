using System;
using System.Web.SessionState;
using System.Collections.Generic;
using System.Text;

public class AccountType
{
    public AccountType(string type, string name)
    {
        m_type = type;
        m_name = name;
    }

    public string m_type;
    public string m_name;
}

public class AccountSys : SysBase
{
    // �洢��½�û����û�����Ựӳ��
    private Dictionary<string, HttpSessionState> m_user = new Dictionary<string, HttpSessionState>();
   
    // �˺������б�
    private List<AccountType> m_accountType = new List<AccountType>();

    public AccountSys()
    {
        m_sysType = SysType.sysTypeAccount;
    }

    public static AccountSys getInstance()
    {
        return SysMgr.getGlobalSys<AccountSys>(SysType.sysTypeAccount);
    }

    public override void initSys() 
    {
        initAccount();
    }

    // �Ự�˳�
    public void sessionEnd(HttpSessionState session)
    {
        if (session["user"] == null)
            return;

        GMUser info = (GMUser)session["user"];
        if (m_user.ContainsKey(info.m_user))
        {
            m_user.Remove(info.m_user);
        }
    }

    // �û�user�Ƿ��ѵ�½
    public bool isLogin(string user)
    {
        return m_user.ContainsKey(user);
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
    public bool addAccount(string account, string key1, string key2, GMUser user)
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
       
        // ����˺�
        if (res)
        {
            Dictionary<string, object> data = genAccount(account, "other", key1, "", "");
            res = DBMgr.getInstance().addTableData(TableName.GM_ACCOUNT, data, "user", 
                Convert.ToString(data["user"]), 0, DbName.DB_ACCOUNT);
        }
        return res;
    }

    public OpRes delAccount(string account)
    {
        bool res = DBMgr.getInstance().remove(TableName.GM_ACCOUNT, "user", account, 0, DbName.DB_ACCOUNT);
        return res ? OpRes.opres_success : OpRes.op_res_failed;
    }

    public bool modifyViewChannel(string account, string viewChannel)
    {
        Dictionary<string, object> data = new Dictionary<string, object>();
        data.Add("viewChannel", viewChannel);
        return DBMgr.getInstance().update(TableName.GM_ACCOUNT, data, "user", account, 0, DbName.DB_ACCOUNT);
    }

    // ��ʼ��Ĭ���ʺ�
    private void initAccount()
    {
        List<Dictionary<string, object>> accountlist = new List<Dictionary<string, object>>();
        accountlist.Add(genAccount("admin", "admin", "yoyang001", "all", "all"));
        accountlist.Add(genAccount("lujieying", "admin", "yoyang002", "all", "all"));

        foreach(Dictionary<string, object> acc in accountlist)
        {
            DBMgr.getInstance().addTableData(TableName.GM_ACCOUNT, acc, "user", Convert.ToString(acc["user"]), 0, DbName.DB_ACCOUNT);
        }
    }

    // ����һ���˺�
    private Dictionary<string, object> genAccount(string user, string type, string password, 
                                                  string right, string viewChannel)
    {
        Dictionary<string, object> data = new Dictionary<string, object>();
        data["user"] = user;
        data["type"] = type;
        data["password"] = Tool.getMD5Hash(password);
        data["right"] = right;
        data["viewChannel"] = viewChannel;
        return data;
    }
}




















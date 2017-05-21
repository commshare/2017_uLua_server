using System;
using System.Web.SessionState;
using System.Web;
using System.Collections.Generic;
using System.Text;
using System.Xml;

/*
    all:ӵ������Ȩ��
*/

// Ȩ�޵ļ����
enum RightResCode
{
    right_success,              // �ɹ�
    right_not_login,            // δ��½
    right_no_right,             // û��Ȩ�޲���
}

// Ȩ�޹���
class RightSys : SysBase
{
    // Ȩ�޴�
    Dictionary<string, string> m_rightMap = new Dictionary<string, string>();

    // �����ݿ��ж�����Ȩ�޴�����Ա����->Ȩ�޴�
    Dictionary<string, string> m_rightCheck = new Dictionary<string, string>();

    public RightSys()
    {
        m_sysType = SysType.sysTypeRight;
    }

    public static RightSys getInstance()
    {
        return SysMgr.getGlobalSys<RightSys>(SysType.sysTypeRight);
    }

    // �ж�account�Ƿ����Ȩ��right
    private RightResCode hasRight(string right, HttpSessionState session)
    {
        if (session["user"] == null)
        {
            return RightResCode.right_not_login;
        }

        GMUser user = (GMUser)session["user"];
        if (!user.isLogin)
            return RightResCode.right_not_login;

        if (right != "") // Ϊ�յģ��κ��˺ſ��Բ鿴����Ϊ�յ�ֻ��admin���Բ鿴
        {
            if (user.m_type != "admin")
                return RightResCode.right_no_right;
        }
        return RightResCode.right_success;
    }

    // �Ե�ǰҪ���еĲ������м���
    public bool opCheck(string right, HttpSessionState session, HttpResponse response)
    {
        RightResCode code = hasRight(right, session);
        if (code == RightResCode.right_success)
            return true;
        if (code == RightResCode.right_not_login)
        {
            response.Redirect("~/appaspx/UserLogin.aspx");
        }
        if (code == RightResCode.right_no_right)
        {
            response.Redirect("~/appaspx/Error.aspx");
        }
        return false;
    }

    // ����Ȩ������
    public string getRrightName(string right)
    {
        if (m_rightMap.ContainsKey(right))
            return m_rightMap[right];
        return "";
    }

    // ��ȡȨ���б�
    public Dictionary<string, string> getRightMap()
    {
        return m_rightMap;
    }

    public override void initSys()
    {
        try
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(HttpRuntime.BinDirectory + "..\\" + "data\\right.xml");

            XmlNode node = doc.SelectSingleNode("/configuration");

            for (node = node.FirstChild; node != null; node = node.NextSibling)
            {
                string right = node.Attributes["right"].Value;
                string fmt = node.Attributes["fmt"].Value;
                if (m_rightMap.ContainsKey(right))
                {
                  //  LOGW.Info("��right.xmlʱ�������˴��󣬳������ظ���Ȩ�� {0}", right);
                }
                else
                {
                    m_rightMap.Add(right, fmt);
                }
            }
        }
        catch (System.Exception ex)
        {
        }
    }
}





using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Web;
using MongoDB.Bson;
using MongoDB.Driver;
using MongoDB.Driver.Builders;
using System.Reflection;

// �����ṹ
[Serializable]
class LogMsg
{
    // log ID��
    public long m_id = 0; 
    // ������DB������IP
    public string m_opDbIP = "";   
    // �����˺�
    public string m_account = "";   
    // �˺�IP
    public string m_accountIP = ""; 
    // ��������
    public int m_opType = 0;
    // ����ʱ��
    public long m_opTime = 0;
    // ��������
    public string m_opParam = "";
}

class OpInfo
{
    // ��������
    public int m_opType;
    // ��������
    public string m_opName;
    // ��ʽ��
    public string m_fmt = "";
    public OpParam m_param = null;

    public OpInfo(int type, string name, string fmt, string class_name)
    {
        m_opType = type;
        m_opName = name;
        m_fmt = fmt;
        if (class_name != "")
        {
            m_param = createOpParam(class_name);
        }
    }

    private OpParam createOpParam(string class_name)
    {
        Assembly t = Assembly.Load("WebManager");
        OpParam obj = (OpParam)t.CreateInstance(class_name);
        return obj;
    }
}

// ������־�Ĺ���
class OpLogMgr
{
    private static OpLogMgr s_mgr = null;
    private Dictionary<int, OpInfo> m_opFmt = new Dictionary<int, OpInfo>();
    public StringBuilder m_textBuilder = new StringBuilder();

    public static OpLogMgr getInstance()
    {
        if (s_mgr == null)
        {
            s_mgr = new OpLogMgr();
            s_mgr.init();
        }
        return s_mgr;
    }

    // ������ƴ������Ҫ�Ĳ���
    public void addLog(int opType, OpParam opParam, GMUser user, string comment = "")
    {
        SqlInsertGenerator gen = new SqlInsertGenerator();
        gen.addField("opAcc", user.m_user, FieldType.TypeString);
        gen.addField("opAccIP", user.m_ip, FieldType.TypeString);
        gen.addField("opType", opType, FieldType.TypeNumber);
        gen.addField("opTime", DateTime.Now.ToString(ConstDef.DATE_TIME24), FieldType.TypeString);
        gen.addField("opParam", opParam.getString(), FieldType.TypeString);
        gen.addField("opComment", comment, FieldType.TypeString);
        string sql = gen.getResultSql(TableName.OPLOG);
        user.sqlDb.executeOp(sql, user.getMySqlServerID(), MySqlDbName.DB_XIANXIA);
    }

    public OpInfo getOpInfo(int opid)
    {
        if (m_opFmt.ContainsKey(opid))
        {
            return m_opFmt[opid];
        }
        return null;
    }

    public int getOpInfoCount() { return m_opFmt.Count; }

    private void init()
    {
        // ���ظ�ʽXML ------------------------------------------------
        try
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(HttpRuntime.BinDirectory + "..\\" + "data\\format.xml");

            XmlNode node = doc.SelectSingleNode("/configuration");

            for (node = node.FirstChild; node != null; node = node.NextSibling)
            {
                string sid = node.Attributes["opid"].Value;
                int id = Convert.ToInt32(sid);
                string name = node.Attributes["opname"].Value;
                string fmt = node.Attributes["fmt"].Value;
                string classname = "";
                if (node.Attributes["class"] != null)
                {
                    classname = node.Attributes["class"].Value;
                }
                if (m_opFmt.ContainsKey(id))
                {
                    LOGW.Info("��format.xmlʱ�������˴��󣬳������ظ���ID {0}", id);
                }
                else
                {
                    m_opFmt.Add(id, new OpInfo(id, name, fmt, classname));
                }
            }
        }
        catch (System.Exception ex)
        {
            LOGW.Info(ex.Message);
            LOGW.Info(ex.StackTrace);
        }
    }
}




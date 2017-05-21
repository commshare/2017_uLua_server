using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Web;

// ���ֲ�����Ϣ
class OpResInfo
{
    // ��������
    public int m_opType;
    // ��ʽ��
    public string m_fmt = "";

    public OpResInfo(int type, string fmt)
    {
        m_opType = type;
        m_fmt = fmt;
    }
}

class OpResMgr
{
    private static OpResMgr s_mgr = null;
    private Dictionary<int, OpResInfo> m_ops = new Dictionary<int, OpResInfo>();

    public static OpResMgr getInstance()
    {
        if (s_mgr == null)
        {
            s_mgr = new OpResMgr();
            s_mgr.init();
        }
        return s_mgr;
    }

    // ȡ�ý����
    public string getResultString(OpRes res)
    {
        int id = (int)res;
        if (m_ops.ContainsKey(id))
        {
            OpResInfo info = m_ops[id];
            return info.m_fmt;
        }
        return "";
    }

    private void init()
    {
        try
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(HttpRuntime.BinDirectory + "..\\" + "data\\opres.xml");

            XmlNode node = doc.SelectSingleNode("/configuration");

            for (node = node.FirstChild; node != null; node = node.NextSibling)
            {
                string sid = node.Attributes["opres"].Value;
                int id = Convert.ToInt32(sid);
                string fmt = node.Attributes["fmt"].Value;
                if (m_ops.ContainsKey(id))
                {
                   // LOGW.Info("��opres.xmlʱ�������˴��󣬳������ظ���ID {0}", id);
                }
                else
                {
                    m_ops.Add(id, new OpResInfo(id, fmt));
                }
            }
        }
        catch (System.Exception ex)
        {
        }
    }
}

public enum OpRes
{
    opres_success,              // �ɹ�
    op_res_failed,              // ʧ��
    op_res_time_format_error,   // ʱ���ʽ��
    op_res_not_found_data,      // û���ҵ��������
    op_res_not_select_any_item, // û��ѡ���κ���Ŀ
    op_res_param_not_valid,     // �����Ƿ�
    op_res_item_not_exist,      // �����ڸõ���
    op_res_pwd_not_valid,       // �����ʽ����ȷ
    op_res_export_excel_not_open,  // ����Excel����δ����
    op_res_has_commit_export,      // ���ύ�������Ժ� Excel����  ҳ���ȡ
    op_res_export_service_busy,    // ����Excel����æ�����Ժ�����
    op_res_need_at_least_one_cond,  // ������Ҫ����һ������
    op_res_has_bind_mobile_phone,   // �Ѱ��ֻ����������һ�
    op_res_need_sel_platform,       // ��Ҫѡ��ƽ̨
    op_res_not_bind_phone,          // û�а��ֻ�
    op_res_player_not_exist,        // ��Ҳ�����
    op_res_data_duplicate,          // �����ظ�
    op_res_reward_beyond_limit,     // ���������޶�
}


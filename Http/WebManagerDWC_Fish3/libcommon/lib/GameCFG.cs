using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Xml;

public interface IXmlData
{
    void init();
}

public class XmlDataTable<T, KEY, VALUE> where T : IXmlData, new()
{
    public static T s_obj = default(T);

    protected Dictionary<KEY, VALUE> m_data = new Dictionary<KEY, VALUE>();

    public static T getInstance()
    {
        if (s_obj == null)
        {
            s_obj = new T();
            s_obj.init();
        }
        return s_obj;
    }

    public VALUE getValue(KEY k)
    {
        if (m_data.ContainsKey(k))
            return m_data[k];

        return default(VALUE);
    }

    public Dictionary<KEY, VALUE> getAllData()
    {
        return m_data;
    }
}

public class ItemCFGData
{
    public int m_itemId;
    public string m_itemName = "";
}

// �ճ���ɾ����
public class QusetCFGData
{
    // ����ID
    public int m_questId;
    // ��������
    public int m_questType;
    // ��������
    public string m_questName = "";
}

public enum TaskType
{
    taskTypeDaily = 1,
    taskTypeAchieve = 2,
}

// ���
public class FishCFGData
{
    // ��ID
    public int m_fishId;

    // ������
    public string m_fishName = "";
}

// ��������
public class Crocodile_RateCFGData
{
    // ����ID
    public int m_areaId;

    // ����
    public string m_name = "";

    public string m_icon;
    public string m_color;
}


public class Dice_BetAreaCFGData
{
    // ����ID
    public int m_areaId;

    // ����
    public string m_name;

    public int m_span = 0;

    public string m_desc;
}

#pragma once

enum ActivityType
{
	// ����-�ۼƳ�ֵ
	activity_type_recharge = 1,

	// ����-���ʳ�ֵ
	activity_type_single_recharge,

	// ����-��ָ���յ�¼
	activity_type_login_at_day,
};

// ��������
enum ConditionType
{
	// ����-��ֵ���
	cond_type_ConditionRecharge,    

	// ����-���ʳ�ֵ
	cond_type_ConditionSingleRecharge,

	// ����-��ָ���յ�¼
	cond_type_ConditionLoginAtDay,

	// ����-VIP�ȼ�
	cond_type_ConditionPlayerVIPLevel,
};

struct stActivityEvent
{
	int m_activityType;
	int m_param1;
	int m_param2;

	stActivityEvent(){}

	stActivityEvent(int atype, int param1)
	{
		m_activityType = atype;
		m_param1 = param1;
	}
};

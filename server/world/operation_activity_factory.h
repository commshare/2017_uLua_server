#pragma once

struct ConditionFactoryParam;

class ActivityConditionFactory
{
public:
	virtual ~ActivityConditionFactory(){}

	virtual bool createCondition(ConditionFactoryParam* param) = 0;
};

// �ۼƳ�ֵ�
class ConditionRechargeFactory : public ActivityConditionFactory
{
public:	
	virtual bool createCondition(ConditionFactoryParam* param);
};

// ���ʳ�ֵ�
class ConditionSingleRechargeFactory : public ActivityConditionFactory
{
public:	
	virtual bool createCondition(ConditionFactoryParam* param);
};

// ָ���յ�¼
class ConditionLoginAtDayFactory : public ActivityConditionFactory
{
public:
	virtual bool createCondition(ConditionFactoryParam* param);
};


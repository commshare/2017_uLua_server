#pragma once

struct ConditionParam;

class ActivityCondition
{
public:
	virtual ~ActivityCondition(){}

	virtual bool isSatisfy(ConditionParam* param) = 0;

	int getType(){ return m_type; }
protected:
	int m_type;
};

// �ۼƳ�ֵ���
class ConditionRecharge : public ActivityCondition
{
public:
	ConditionRecharge();
	virtual bool isSatisfy(ConditionParam* param);
	void set(int param);
	int getParam(){ return m_param; }
protected:
	int m_param;
};

// ���ʳ�ֵ
class ConditionSingleRecharge : public ActivityCondition
{
public:
	ConditionSingleRecharge();
	virtual bool isSatisfy(ConditionParam* param);
	void set(int param);
	int getParam(){ return m_param; }
protected:
	int m_param;
};

// ָ���յ�¼
class ConditionLoginAtDay : public ActivityCondition
{
public:
	ConditionLoginAtDay();
	virtual bool isSatisfy(ConditionParam* param);
	void set(boost::posix_time::ptime param);
protected:
	boost::posix_time::ptime m_param;
};

// ���VIP�ȼ�
class ConditionPlayerVIPLevel : public ActivityCondition
{
public:
	ConditionPlayerVIPLevel();
	virtual bool isSatisfy(ConditionParam* param);
	void set(int low, int up);
protected:
	int m_low;
	int m_up;
};
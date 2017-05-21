#pragma once
#include "game_sys_def.h"
#include "operation_activity_type.h"

struct stActivityInfo;
struct M_ActivityCFGData;
class game_player;
class ActivityConditionFactory;
class OperationActivity;

// ��Ӫ�ϵͳ
class OperationActivitySys : public game_sys_base
{
public:
	typedef boost::shared_ptr<stActivityInfo> TypeActivityInfo;
	typedef boost::shared_ptr<ActivityConditionFactory> TypeActivityConditionFactory;
public:
	MAKE_SYS_TYPE(e_gst_operation_activity);

	virtual void init_sys_object();

	virtual void sys_time_update();

	/*
			�����ݱ��¼����һ���
			����true�ɹ�
	*/
	bool createActivity(const M_ActivityCFGData* data);

	/*
			��һ�¼�
	*/
	int onPlayerEvent(game_player* player, stActivityEvent* evt, time_t curTime = 0);

	/*
			�����һ�Ƿ����
	*/
	bool isFinish(game_player* player, int activityId);

	bool isFinish(game_player* player, stActivityInfo* info);

	bool giveOutReward(game_player* player, stActivityInfo* info);

	TypeActivityInfo findActivity(int activityId);

	/*
			��Ƿ�Ϸ�
	*/
	bool isActivityValid(int activityId, time_t curTime = 0);

	bool isInTimeRange(stActivityInfo* info, time_t curTime);

	/*
			�ֶ���ȡ�����
	*/
	int receiveActivityRewardManual(game_player *player, int activityId, time_t curTime = 0);
private:
	void _createCondition(stActivityInfo* ptr, const M_ActivityCFGData* data);

	void _initFactory();

	int _onPlayerEvent(game_player* player, stActivityEvent* evt, time_t curTime);
private:
	// �ID-->���Ϣ
	std::map<int, TypeActivityInfo> m_act;

	// �����--->�ID�б�
	std::map<int, std::vector<int> > m_atypeToId;

	// ActivityType �����--->��������
	std::map<int, TypeActivityConditionFactory> m_condFactory;

	std::string m_sender;

	// ActivityType �����-->OperationActivity
	// ������Ԫ
	std::map<int, boost::shared_ptr<OperationActivity> > m_actUnit;
};






#pragma once
#include "game_object.h"
#include "game_object_array.h"

class ActivityCondition;
typedef boost::shared_ptr<ActivityCondition> TypeCondition;
class game_player;
struct M_ActivityCFGData;

// һ���
struct stActivityInfo
{
	// ��Ӧ����������
	const M_ActivityCFGData *m_cfgData;

	// �ID
	int m_activityId;

	// ���ʼʱ��
	time_t m_startTime;

	// �����ʱ��
	time_t m_endTime;

	// ��������--->����ʵ��
	std::map<int, TypeCondition> m_conditions;

	template<class TypeCond>
	boost::shared_ptr<TypeCond> getCond()
	{
		TypeCond t;
		auto it = m_conditions.find(t.getType());
		if(it != m_conditions.end())
		{			
			return CONVERT_POINT(TypeCond, it->second);
		}
		return nullptr;
	}
};

struct ConditionParam
{
	game_player* m_player;
	stActivityInfo* m_info;
};

struct ConditionFactoryParam
{
	stActivityInfo* m_ptr;
	const M_ActivityCFGData* m_data;
};

// ���Ϣ
struct ActivityStoreInfo : public game_object, public enable_obj_pool<ActivityStoreInfo>
{
	ActivityStoreInfo();

	virtual void init_game_object();

	virtual uint32_t get_id(){ return m_activityId->get_value(); }

	// �ID
	Tfield<int32_t>::TFieldPtr m_activityId;

	// ����1
	Tfield<int32_t>::TFieldPtr m_param1;

	// ����2
	Tfield<time_t>::TFieldPtr m_param2;

	Tfield<bool>::TFieldPtr m_isFinish;
};

class ActivityStoreInfoArray : public game_object_array, public enable_obj_pool<ActivityStoreInfoArray>
{
public:
	virtual const std::string& get_cells_name();		
	virtual const std::string& get_id_name();		
	virtual GObjPtr create_game_object(uint32_t object_id);
};


extern boost::regex DATE_TIME2;
extern boost::regex DATE_TIME;

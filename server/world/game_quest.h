#pragma once
#include "game_def.h"
#include "quest_def.h"
#include "game_object_container.h"


struct M_QuestCFGData;
class game_quest
	:public game_object
	,public enable_obj_pool<game_quest>
{
public:
	game_quest();
	virtual ~game_quest();

	virtual void init_game_object();//ע������
	virtual uint32_t get_id();

	Tfield<int32_t>::TFieldPtr	QuestID;
	Tfield<int32_t>::TFieldPtr	Count;
	Tfield<bool>::TFieldPtr		Received;

	const M_QuestCFGData* get_quest_data();

	bool init_quest(int questid, int qtype= 2);

private:
	const M_QuestCFGData* m_sdata;
};

//////////////////////////////////////////////////////////////////////////
class quest_map
	:public game_object_container
	,public enable_obj_pool<quest_map>
{
public:
	quest_map();
	virtual ~quest_map();
	virtual const std::string& get_cells_name();		//map��
	virtual const std::string& get_id_name();		//map key ��
	virtual GObjPtr create_game_object(uint32_t object_id);	//ͨ��id�����������
	virtual const std::string& get_container_name();	//����		
	virtual bool is_load();		
	virtual uint32_t get_index_id();
	virtual const std::string& get_index_name();
	virtual db_base* get_db();
	virtual const mongo::BSONObj& get_id_finder();

	void attach(game_player* player, std::string cellsname, int qtype = 2);

	bool change_quest(uint16_t questtype, uint32_t count = 1, uint32_t param=0);
	bool check_quest(uint32_t questid);
	void receive_quest(uint32_t questid, std::vector<stItem>& items);	
	void init_quest();
	void insert_quest(uint16_t questtype, uint32_t count = 1, uint32_t param=0);

	//����ӿ�
	void remove_quest(uint16_t questtype);
	void add_quest(uint16_t questtype, uint32_t count = 0, uint32_t param=0);
private:
	game_player* m_player;
	int m_qtype;
	std::string m_cellsname;
};

//////////////////////////////////////////////////////////////////////////
//��������
enum e_quest_type
{
	e_qt_none = 0,
	e_qt_daily_login,		//ÿ�յ�½
	e_qt_photo_frame,		//ͷ���
	e_qt_vip,				//vip
	e_qt_month_card,		//�¿�
	e_qt_head_icon,			//��ͷ��
	e_qt_update_name,		//����
	e_qt_star_lottery,		//���ǳ齱
	e_qt_loudspeaker,		//ʹ������


	
};

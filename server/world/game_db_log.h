#pragma once

#include <enable_singleton.h>
#include <db_query.h>
#include "game_def.h"

//��־��
enum e_db_log_table
{
	// ��Ծ����
	e_dlt_pump_active_count,

	// ��Ծ����
	e_dlt_pump_active_person,

	// ��ң���ȯ�仯
	e_dlt_pump_player_money,

	// ��������
	e_dlt_pump_send_gift,

	// ���ͳ��
	e_dlt_pump_photo_frame,

	// ͨ��ͳ��
	e_dlt_pump_general_stat,

	// ���˵�����������־
	e_dlt_pump_personal_send_gift,

	// �����ܵ�ͳ��
	e_dlt_pump_total_consume,

	// ��ҽ������
	e_dlt_pump_coin_growth,

	//��ҽ��������ʷ
	e_dlt_pump_coin_growth_history,
	
	//world��Ҽ�¼
	e_dlt_player_gold_log,

	// ���ͬʱ������ұ�
	e_dlt_max_online_player,

	// ��ҵ�½��¼
	e_dlt_player_login,

	// ת�˼�¼
	e_dlt_pump_send_gold,

	e_dlt_max,
};

enum gold_log_type
{
	gold_log_type_unknown = 100,
	gold_log_type_save,
	gold_log_type_load,
	gold_log_type_gift,
	gold_log_type_item,
	gold_log_type_other,
};


//////////////////////////////////////////////////////////////////////////
//��־���ݿ�
class db_log : public db_queue
	, public enable_singleton<db_log>
{
public:
	db_log();
	virtual ~db_log();
	virtual void init_index();

	virtual const std::string& get_tablename(uint16_t table_type);

	void player_gold_log(int32_t player_id, GOLD_TYPE old_value, GOLD_TYPE new_value, int32_t reason);

	void player_login_log(int32_t player_id, const std::string& ip, int port, const std::string& mcode,const std::string& mtype);
};

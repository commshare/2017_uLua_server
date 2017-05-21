#pragma once

#include <enable_singleton.h>
#include <db_query.h>
#include "game_macro.h"

//��־��
enum e_db_log_table
{
	e_dlt_none = 0,
};

class logic_player;

//��־���ݿ�
class db_log : public db_queue
	, public enable_singleton<db_log>
{
public:
	db_log();
	virtual ~db_log();
	virtual void init_index();

	virtual const std::string& get_tablename(uint16_t table_type);
};

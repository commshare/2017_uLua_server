#pragma once

#include <db_base.h>
#include <enable_singleton.h>
#include <db_query.h>

//////////////////////////////////////////////////////////////////////////
static const std::string unknown_table = "DefaultTable";
static const std::string DB_PLAYER_INFO = "player_info";
static const std::string DB_COMMON_CONFIG = "common_config";
//�������
static const std::string DB_PLAYER_INDEX = "player_id";

// �ʼ�
static const std::string DB_MAIL = "playerMail";

static const std::string DB_FISHLORD = "fishlord_player";

static const std::string DB_CROCODILE = "crocodile_player";

static const std::string DB_DICE = "dice";

// �һ�
static const std::string DB_EXCHANGE = "exchange";

// ��ұ���
static const std::string DB_PLAYER_BAG = "playerBag";

// ���ϲ��
static const std::string DB_PLAYER_FAVOR = "playerFavor";

// ��̨��ֵ
static const std::string DB_GM_RECHARGE = "gmRecharge";

//ÿ�ճ�ֵ
static const std::string DB_TODAY_RECHARGE = "todayRecharge";
static const std::string DB_YESTERDAY_RECHARGE = "yesterdayRecharge";

// �������С����
static const std::string DB_SPEAKER = "playerSpeaker";

static const std::string DB_PLAYER_QUEST = "player_quest";

// ͷ��ٱ�
static const std::string DB_INFORM_HEAD = "informHead";

static const std::string DB_RECHARGE_HISTORY = "recharge_history";

//������ݿ�
class db_player : public db_base
	, public enable_singleton<db_player>
{
public:
	db_player();
	virtual ~db_player();
	virtual void init_index();
};


//////////////////////////////////////////////////////////////////////////
//��־���ݿ�
/*class db_log : public db_queue
	, public enable_singleton<db_log>
{
public:
	db_log();
	virtual ~db_log();
	virtual void init_index();

	virtual const std::string& get_tablename(uint16_t table_type);

};
*/
//////////////////////////////////////////////////////////////////////////

//��Ϸ���ݿ�
class db_game : public db_base
	, public enable_singleton<db_game>
{
public:
	db_game();
	virtual ~db_game();
	virtual void init_index();
};
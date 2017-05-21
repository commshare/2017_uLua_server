#pragma once
#include "logic_def.h"
#include "game_showhand_def.pb.h"
#include "ShowHand_RoomCFG.h"
#include "i_game_ehandler.h"
SHOWHAND_SPACE_BEGIN

class logic_room :public game_object 
{
public:
	logic_room(const ShowHand_RoomCFGData* cfg);
	~logic_room(void);

	void heartbeat(double elapsed);

    int enter_room(LPlayerPtr player);
    int leave_room(logic_player*  player);

	void release();

	uint16_t get_player_cout();
    LTABLE_MAP &get_all_tables();
    LTablePtr get_table(int table_id);
	int get_room_id(){return m_room_id;}
    void inform_others(LPlayerPtr, int, int, int);
	GOLD_TYPE get_EnterGold();
	GOLD_TYPE get_EnterTableGold();
	void add_rob_income(GOLD_TYPE income);
	void add_rob_outcome(GOLD_TYPE outcome);

	void add_Stock_income(GOLD_TYPE Income,GOLD_TYPE outcome);//�����ɸ�
	double get_rob_earn_rate();
	void set_rob_earn_rate();
	int get_rob_count(){return m_rob_count;}
    template <class T>
    void broast_msg_to_room_layers(T msg, uint32_t mypid) 
	{
        LPLAYER_MAP::iterator it = m_room_players.begin();
		std::vector<uint32_t> pids;
        for (; it != m_room_players.end(); ++it) 
		{
			if(!it->second->is_inTable() &&it->second->get_pid() != mypid && !it->second->is_android())
				pids.push_back(it->second->get_pid());
        }
		game_engine::instance().get_handler()->broadcast_msg_to_client(pids, msg->packet_id(), msg);
    };

//--------------------------------Э�����------------------------------------------
	int match_auto_table(int last_select_table_id=0);//�Զ�ƥ������
	void do_protobuf_notice_enter_table(logic_player* player); 
	void do_protobuf_notice_leave_table(int table_id,int pid);
	void do_protobuf_notice_table_player_state(logic_table* table);
	void do_protobuf_notice_Stock_Info(logic_player* player=nullptr);
	void copy_tablelist(google::protobuf::RepeatedPtrField< ::game_showhand_protocols::msg_table_info >* table_list);

	int set_and_decrease_count();//�õ������˵�����
	int rob_match_auto_table();
	logic_player* get_room_Idle_robot();
//-----------------------------------------------------------------------------------------
private:
    void init_tables();
	void create_room();
	bool load_room();
    bool test_probability(int p);
    int can_enter_room(LPlayerPtr);
private:
	void create_robot();
public:
	virtual void init_game_object();//ע������
	virtual bool store_game_object(bool to_all = false);//������������ʵ�ִ˽ӿ�

	Tfield<int16_t>::TFieldPtr		m_db_RoomID;			//����id
	Tfield<int64_t>::TFieldPtr		m_db_TotalIncome;		//��ǰ����
	Tfield<int64_t>::TFieldPtr		m_db_TotalOutlay;		//��ǰ����
	Tfield<int64_t>::TFieldPtr		m_db_EnterCount;	   //�������

	Tfield<int64_t>::TFieldPtr		m_db_rob_income;		//����������
	Tfield<int64_t>::TFieldPtr		m_db_rob_outcome;		//������֧��
	Tfield<double>::TFieldPtr		m_db_rob_EarningsRate;	//ӯ����

	Tfield<double>::TFieldPtr		EarningsRate;	    //��ҳ�ˮ
	Tfield<int64_t>::TFieldPtr		TotalProfit;		//��ӯ��
	Tfield<int64_t>::TFieldPtr		TotalStock;			//�ܿ��

private:
	LTABLE_MAP m_tables;
	double m_check_rate;
	double m_checksave;//��鱣���ʱ��
    int m_room_id;
	std::string	m_room_name;
    int m_room_max_player_count;
    int m_room_max_table_count;
	double	m_rob_earn_rate;//������ӯ����
    bool m_is_open;
    int m_room_enter_gold_condition;
	int m_table_enter_gold_condition;
    int m_illegal_quit_gold_count;
    //��ע
    int m_ante;
    //��ǰ��������
    LPLAYER_MAP m_room_players;

	bool IsOpenRob;
	double m_rob_cd;
	GOLD_TYPE Stock_add_value;
	GOLD_TYPE Profit_add_value;
private:
	int m_rob_count;

	int rob_count;
	double rob_count_cd;
};


SHOWHAND_SPACE_END

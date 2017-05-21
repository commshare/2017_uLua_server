#pragma once
#include "logic_def.h"
#include <i_game_phandler.h>
#include <i_game_player.h>
#include "game_showhand_protocol.pb.h"

SHOWHAND_SPACE_BEGIN

enum player_table_state
{
	e_table_state_none=0,
	e_table_state_no_prepare=1,//δ׼��
	e_table_state_prepare=2,//׼��
	e_table_state_in_game=3,//����Ϸ��
};

class logic_player_db:public game_object
{
public:
	bool create_player();
	bool load_player();
	virtual void init_game_object() override;//ע������
	virtual bool store_game_object(bool to_all = false) override;//������������ʵ�ִ˽ӿ�
public:
	Tfield<int32_t>::TFieldPtr m_db_player_id;
	Tfield<GOLD_TYPE>::TFieldPtr m_db_once_win_maxgold;			//���������ӯ����
	Tfield<int32_t>::TFieldPtr m_db_win_count;    //���ǳ齱�ۼ�ӮǮ���� 
};

class logic_player: public enable_obj_pool<logic_player>,public i_game_phandler, public logic_player_db
{
public:
    typedef boost::shared_ptr<logic_player> ptr;

	logic_player(void);
	virtual ~logic_player(void);

	void heartbeat( double elapsed );

	//�ӷ�����֪ͨ�߼��Ľӿ�
	//����
	virtual void on_attribute_change(int atype, int v);

	virtual void on_attribute64_change(int atype, GOLD_TYPE v = 0);

    //���״̬�ı�ӿ�
	virtual void on_change_state(void);
    //�˳�������Ϸ
	void release();

    bool is_offline();
	uint32_t get_pid();//���ID
	int get_lucky();
	bool change_lucky(int v);
	bool Is_Luckly_Valid(int addgold);
	bool is_GM_CONTROL();
	//��ȡ��ҵ�ǰ���(��Ϸ����)
	GOLD_TYPE get_gold();
	//��ȡ���VIP�ȼ�
	int16_t get_viplvl();
	//�Ƿ�����VIP
	bool is_ExperienceVIP();
	//�Ƿ������
    bool is_android();
	//��ȡ��ȯ
	int get_ticket();
	//�ı���(��Ϸ����)
	bool change_gold(GOLD_TYPE v, bool needbc = false);
    bool synchronization_gold();
	//�ı���ȯ(��Ϸ����)
	bool change_ticket(int v, bool needbc = false);
	//��ȡ�ǳ�
	const std::string& get_nickname();
	int get_sex();
	int get_photo_frame();
	const std::string& get_icon_custom();
	void bc_game_msg(int money, const std::string& sinfo, int mtype = 1);

	void init_tickettime();
	int check_ticket();//���ÿ������ȯ
    int get_player_type();

	bool is_inRoom();
	bool is_inTable();

	//�õ��������״̬
    int get_player_world_state();

	//�õ��������״̬
    int get_player_table_state();
	void set_player_table_state(player_table_state state);

    void start_offline_timer();

	template<class T>
	int send_msg_to_client(T msg) 
	{
		return m_player->send_msg_to_client(msg->packet_id(), msg);
	}

	void copy_player_info(game_showhand_protocols::msg_player_info* player_info);
public:
	void enter_game(logic_lobby* lobby);
	int enter_lobby();
	int leave_lobby();
	int enter_room(int);
	int leave_room();
	int enter_table(int);
	int leave_table(); 
	logic_room* get_room();
	logic_table* get_table();

	int prepare_game();
	void seecard();
	int set_min_bet(GOLD_TYPE count);
	int add_bet(const game_showhand_protocols::msg_bet_info& betinfo); 
	GOLD_TYPE getbetCount();//�õ���ѹע
	GOLD_TYPE getlastbetCount();//�õ���һ�ε�Ѻע
	int get_last_select_table_id(){return last_select_table_id;}
	void set_last_select_table_id(int t_id){last_select_table_id=t_id;}
	void do_protobuf_notice_Luck_Info();
	GOLD_TYPE TempIncome;	//����ֵ����
	GOLD_TYPE TotalIncome; //����ֵ������
private:
	void robot_heartbeat(double elapsed );
	void get_rob_bet(game_showhand_protocols::p_bet_state* mstate,game_showhand_protocols::msg_bet_info* betinfo1);
	bool judge_rob_win_lose(int currentCardIndex);
	void get_rob_cheat_bet(game_showhand_protocols::p_bet_state* mstate,game_showhand_protocols::msg_bet_info* betinfo1);
	game_showhand_protocols::e_bet_type get_rob_bet_type(game_showhand_protocols::p_bet_state* mstate);//���AIs
	game_showhand_protocols::e_bet_type get_rob_bet_type_1(game_showhand_protocols::p_bet_state* mstate);//�߼�AI
private:
	int last_select_table_id;
	int64_t m_logic_gold;
	int64_t m_change_gold;

	double m_check_sync;
	double m_check_ticket;
	double m_cur_tickettime;
	double m_kich_rubbish_cd;

	logic_room* m_room;
	logic_table* m_table;
	player_table_state m_player_table_state;
	//game_showhand_protocols::msg_bet_info mLastTakeCard;
	//std::vector<game_showhand_protocols::msg_bet_info> bet_list;//��ע�б�

	double clearrubbish_cd;
	double entertable_cd;
	double prepare_cd;
	double bet_cd;
	double bet_max_cd;
	double viewcard_cd;
	double viewcard_max_cd;
	bool or_once_bet;
	int rob_continuePlayCount;
	int rob_continuePlayCount_max;
	double robot_auto_quittable_cd;
	double quit_table_rob_cd_max;

	int Luck_add_value;//���ӵ�����ֵ
};

SHOWHAND_SPACE_END
#pragma once
#include "logic_def.h"
#include "logic_core.h"
#include "proc_game_happysupremacy_protocol.h"

struct HappySupremacy_RoomCFGData;
struct HappySupremacy_RoomStockCFGData;
class HistoryArray;

class logic_room_db:public game_object
{
protected:
	void create_room();
	bool load_room();
	void reflush_rate();//������֧
public:
	virtual void init_game_object() override;//ע������
	virtual bool store_game_object(bool to_all = false) override;//������������ʵ�ִ˽ӿ�

	Tfield<int16_t>::TFieldPtr		m_db_room_id;			//����id
	Tfield<int64_t>::TFieldPtr		m_db_room_income;		//��ǰ����(���������Ѻע)
	Tfield<int64_t>::TFieldPtr		m_db_room_outcome;		//��ǰ���ģ�������������棩
	Tfield<int64_t>::TFieldPtr		m_db_enter_count;		//�������
	Tfield<double>::TFieldPtr		m_db_ExpectEarnRate;		//Ԥ��ӯ����
	Tfield<int64_t>::TFieldPtr		m_db_player_charge;	//�����ׯ��ˮ

	GArrayFieldPtr					m_db_room_history;  //��·
	boost::shared_ptr<HistoryArray> m_db_room_historyPtr;

	Tfield<int64_t>::TFieldPtr		m_db_rob_income;		//����������
	Tfield<int64_t>::TFieldPtr		m_db_rob_outcome;		//������֧��

	Tfield<double>::TFieldPtr		EarningsRate;	//��ˮ����
	Tfield<int64_t>::TFieldPtr		TotalProfit;		//��ӯ��
	Tfield<int64_t>::TFieldPtr		TotalStock;			//�ܿ��
};

class logic_room :public logic_room_db
{
public:
	logic_room(const HappySupremacy_RoomCFGData* cfg, logic_lobby* _lobby);
	~logic_room(void);

	void heartbeat( double elapsed );
	uint16_t get_room_id();			//����ID
	e_game_state get_room_state(){return m_game_state;}
	void set_is_have_bet(bool is_have);		//��ע�ڼ��Ƿ���Ѻע

	bool room_is_full();
	uint16_t enter_room(LPlayerPtr player);		//���뷿��
	void leave_room(uint32_t playerid);			//�뿪����

	const HappySupremacy_RoomCFGData* get_room_cfg() const;
	logic_lobby* get_lobby(){return m_lobby;};

	void adjust_earn_rate(); //����
	bool sync_bet_to_room(); //�����ռ����������ע��Ϣ
	void bc_begin_bet();		//֪ͨ��ʼ��ע
	void compute_reward();		//���������ҵĽ���
	bool refreshBanker();		//ˢ��ׯ��

	void bc_begin_reward();		//�㲥��Ӯ���
	void bc_sync_bet_info();	//�㲥����ע��Ϣ
	void bc_change_banker(bool is_rob);	//�㲥����ׯ��
	void bc_rob_banker_info();	//�㲥��ׯ��Ϣ

	msg_type_def::e_msg_result_def add_banker_list(uint32_t playerid);		//���������ׯ�б�
	int32_t get_continue_banker_count(){return m_continue_banker_count;}
	void set_now_banker_null(int32_t playerid);//����ׯ�ң���ʼ��ׯ��״̬
	void add_history_list();		//���浽��·

	msg_type_def::e_msg_result_def set_rob_banker(int32_t playerid);//������ׯ�����Ϣ
	int32_t get_now_banker_id(){return m_now_banker_id;}
	bool is_real_banker();	//�Ƿ���ʵׯ�ң�������˵�����

	GOLD_TYPE get_can_bet_count();//�õ�������һ�������ע������
	int32_t get_win_index();
	int32_t get_no_banker_count();//�õ�������ׯ����������ϵͳСׯ��
	int32_t get_banker_list_size(){return m_banker_list.size();}	//ׯ�������б�
	GOLD_TYPE get_banker_win(){return m_banker_total_win;}	//�õ�ׯ��ӮǮ������
	int32_t get_continue_count(){return m_continue_banker_count;}	//�õ�������ׯ�ľ���
	double get_cd_time(){return m_cd_time;}

	GOLD_TYPE get_total_bet_count(){return m_total_bet_count;}
	double getRobEarnRate(){return m_rob_earn_rate;} //������Ӯ�ø���
	//gm���
	void set_gm(int count);
	int get_gm_result();//��̨�����¾ֽ��

	void set_GM_CONTROL_COMMAND(int command){GM_CONTROL_COMMAND=command;}
	void set_GM_CONTROL_COMMAND_LIST(const std::vector<e_bet_type>& list)
	{
		GM_CONTROL_COMMAND_LIST=list;
	}

	void set_Stock(GOLD_TYPE Income,GOLD_TYPE outcome);//���ÿ��//���ÿ��
	void get_pre_Stock_Income(GOLD_TYPE* income,GOLD_TYPE* outcome);
	void set_player_Stock_bet_count();
public:
	template<class T>
	int broadcast_msg_to_client(T msg, uint32_t except_id = 0)
	{
		return broadcast_msg_to_client(msg->packet_id(), msg, except_id);
	};
	int broadcast_msg_to_client(uint16_t packet_id, boost::shared_ptr<google::protobuf::Message> msg, uint32_t except_id);

	boost::shared_ptr<game_happysupremacy_protocols::packetl2c_get_room_scene_info_result> get_room_scene_info();		//��ó���Э��
	boost::shared_ptr<game_happysupremacy_protocols::packetl2c_ask_for_player_list_result> get_room_player_list();	//�������б�Э��
	boost::shared_ptr<game_happysupremacy_protocols::packetl2c_ask_for_banker_list_result> get_room_banker_list();	//���ׯ���б�Э��
	boost::shared_ptr<game_happysupremacy_protocols::packetl2c_ask_for_history_list_result> get_room_history_list();	//���ׯ���б�Э��
private:
	const HappySupremacy_RoomCFGData* m_cfg;
	const HappySupremacy_RoomStockCFGData* m_StockCFG;
	logic_lobby* m_lobby;
	LPLAYER_MAP playerMap;		//��������ֵ�
	logic_core* m_core_engine;	//������

	e_game_state m_game_state;
	double m_cd_time;
	bool is_have_bet;
	double m_elapse;
	double m_checksave;

	double m_rob_cd;	//�����˽�����
	int m_rob_count;	//����������
	double	m_rob_earn_rate; //�����˵ĸ���

	int m_no_banker_count;			//��ׯ��������

	GOLD_TYPE m_total_bet_count; //��������ע����
	std::map<e_bet_type,GOLD_TYPE> m_room_bet_list;//�������͵���ע����
	std::map<e_bet_type,GOLD_TYPE> m_room_player_bet_list;//��������ע����

	std::list<history_info> m_history_list;	//��¼��ע�������ʷ��¼
	bool is_refresh_history;				//�Ƿ�ˢ����·

	GOLD_TYPE m_once_income;			//�����յ���Ѻע
	GOLD_TYPE m_once_outcome;			//��������Ľ��
	GOLD_TYPE m_banker_once_win;		//����ׯ������
	GOLD_TYPE m_banker_total_win;		//ׯ�������棨��ׯ��һֱ�ۼӣ�

	double m_draw_water_rate;		//��˰����
	GOLD_TYPE m_system_draw_water;    //ׯ����ׯ��ϵͳ��˰����������ׯ��ʱ���Ž���˰�գ�

	std::list<uint32_t> m_banker_list;   //������ׯ�б�
	int32_t m_continue_banker_count;		//��ׯ����
	int32_t m_now_banker_id;				//��ǰׯ��ID

	int32_t m_old_banker_id;	            //�ϴ�ׯ��ID

	bool is_change_banker;					//ׯ���Ƿ��иı�
	bool is_have_banker;					//��ǰ�Ƿ��������ׯ

	bool is_can_rob_banker;					//�Ƿ�����ׯ
	int32_t m_rob_banker_id;				//��ǰ��ׯ���ID
	GOLD_TYPE m_rob_banker_cost;			//��ǰ��ׯ����
	bool is_have_rob_banker;				//�Ƿ���Ҫ�㲥��ׯ��Ϣ

	bool is_gm;
	int32_t gm_index;
	int32_t gm_max;

	int GM_CONTROL_COMMAND;//�Ƿ���ƿͻ��˷�������1:�շ֣�2:�ŷ�,3:ȫ��
	std::vector<e_bet_type> GM_CONTROL_COMMAND_LIST;//7��ȫ�䣩
private:
	int IsOpenRob;
	int IsOpenGM;
	int robMinCount;
	int currentNeedRobCount;
	double currentNeedRobCount_cd;
	void create_robot();
private:
	int GetPeopleRate(int iMaxNum);
	int SetCurrentNeedRobCount();
	void InitBetInfo();//��ʼ��������������ע��Ϣ
	void saveHistoryRecord();
};

class HistoryItem : public game_object, public enable_obj_pool<HistoryItem>
{
public:
	HistoryItem();

	virtual void init_game_object() override;

	Tfield<bool>::TFieldPtr is_forwarddoor_win;
	Tfield<bool>::TFieldPtr is_reversedoor_win;
	Tfield<bool>::TFieldPtr is_oppositedoor_win;
};

class HistoryArray : public game_object_array, public enable_obj_pool<HistoryArray>
{
public:
	virtual const std::string& get_cells_name() override;	

	virtual GObjPtr create_game_object(uint32_t object_id) override;

	virtual const std::string& get_id_name() override;

	virtual bool update_all() override { return true; }
};

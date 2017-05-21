#pragma once
#include "logic_def.h"
#include "i_game_def.h"
#include "game_showhand_def.pb.h"
#include "cardmanager.h"
#include <vector>
#include <string>
#include "ShowHand_RoomStockCFG.h"
class cardmanager;
SHOWHAND_SPACE_BEGIN

class logic_player;
class show_hand_result;
typedef std::shared_ptr<cardmanager> PCARDMANAGER;
class logic_table: public enable_obj_pool<logic_table>
{
public:
	logic_table(logic_room*,int);
	virtual ~logic_table();

	void heartbeat(double elapsed);

	virtual uint32_t get_id();
	int enter_table(logic_player* player);//��������
	int quit_table(logic_player* player);//�뿪����

	logic_player* get_player_left();//�õ�������
	logic_player* get_player_right();//�õ��ұ����

	game_showhand_protocols::p_bet_state* get_left_betstate();//�õ���������ע״̬
	game_showhand_protocols::p_bet_state* get_right_betstate();//�õ��ұ������ע״̬

	GOLD_TYPE get_betcount(int32_t pid);//�õ��������ע

	void set_bet_gold_count(); //���û���
	GOLD_TYPE get_min_bet_gold();
	int get_player_count();//�õ��������
	bool is_empty();
	bool get_or_have_hasuo();
	game_showhand_protocols::e_game_state get_game_state();

	GOLD_TYPE get_rob_income();//����
	GOLD_TYPE get_rob_outcome();//֧��
	GOLD_TYPE set_rob_income();//���û����˵�����
	PCARDMANAGER get_cardmanager();
	int get_currentCardIndex(){return currentCardIndex;}
	void initTablePlayer(bool left);
	void set_GM_CONTROL_COMMAND(int command);
public:
	void do_protobuf_player_ready(int pid,int result) ;//���׼��
	void do_protobuf_notice_start_game();//����
	void do_protobuf_notice_view_card(int whoSeeCardId);//����
	void do_protobuf_notice_bet(int32_t playerId, const game_showhand_protocols::msg_bet_info& betinfo); //�����ע
	void do_protobuf_notice_sendcard();//��ҷ���
	void do_protobuf_notice_award();//��ҽ���
	void do_protobuf_notice_enter_table(logic_player* player);//�������ӣ�ֻ֪ͨ���������һ���ˣ�
	void do_protobuf_notice_leave_table(int pid);//�뿪���ӣ�ֻ֪ͨ��������һ���ˣ�
	void do_protobuf_get_table_scene_info(logic_player* player);
	void do_protobuf_notice_gm_private_Info();
	void kich_table_rubbish(logic_player* lcplayer);
	//void kich_room_rubbish(logic_player* lcplayer);
	GOLD_TYPE get_bet_cout(const int32_t& pid,const game_showhand_protocols::msg_bet_info& betinfo);//�õ������ע������
	void copy_table_info(game_showhand_protocols::msg_table_info* table_info);

	int get_once_bet_size(){ return once_bet_list.size();}
private:
	void adjust_earn_rate();
	void start_game_prepare();//��Ϸ��ʼ׼������
	void ImmediatelyOpenAward();//��������
	void set_bet_state(game_showhand_protocols::p_bet_state* bet_state,logic_player* player,int32_t player_id,const game_showhand_protocols::msg_bet_info* betinfo);
	void robot_heart(double elapsed);
public:
	//�㲥Э�飬���̷���
	template<class T>
	int broadcast_msg_to_client(T msg, int32_t mypid = 0)
	{
		std::vector<uint32_t> pids;	
		if (m_player_left != nullptr && !m_player_left->is_android() && m_player_left->get_pid()!=mypid) 
		{
			pids.push_back(m_player_left->get_pid());
		}

		if (m_player_right != nullptr && !m_player_right->is_android() && m_player_right->get_pid()!=mypid) 
		{
			pids.push_back(m_player_right->get_pid());
		}
		
		return game_engine::instance().get_handler()->broadcast_msg_to_client(pids, msg->packet_id(), msg);
	}
private:
	double m_bet_time;//��עʱ��20��
	double m_checksave;//��鱣���ʱ��
	logic_room* m_room;
	int16_t m_table_Id;

	logic_player* m_player_left;
	logic_player* m_player_right;

	GOLD_TYPE min_bet_count;//������Ϸ��С��ע���
	GOLD_TYPE max_bet_count;//������Ϸ�����ע���

	GOLD_TYPE left_bet_cout;//����ע�ܽ��
	GOLD_TYPE right_bet_cout;//����ע�ܽ��

	bool Is_left_abandonCard;//�Ƿ�����
	bool Is_right_abandonCard;

	bool Is_left_ShowHands;//�Ƿ����
	bool Is_right_ShowHands;

	int32_t left_escape_pid;//�Ƿ�����
	int32_t right_escape_pid;

	std::vector<GOLD_TYPE> once_bet_list;//ÿ�η������Ѻע����б�

	std::vector<game_showhand_protocols::msg_bet_info> once_betinfo_list;//��������������ÿ�η����Ƶ�Ѻע��Ϣ�б�

	//std::vector<game_showhand_protocols::msg_bet_info> left_bet_list;//�����ע�б�
	//std::vector<game_showhand_protocols::msg_bet_info> right_type_list;//�ұ���ע�б�

	game_showhand_protocols::p_bet_state* left_bet_state;//������״̬
	game_showhand_protocols::p_bet_state* right_bet_state;//�ұ����״̬
	int currentCardIndex;
	PCARDMANAGER m_cardmanager;
	game_showhand_protocols::e_game_state m_game_state;//��Ϸ״̬

	double award_time;
	double takecard_time;
	double left_kichRubbish_cd;
	double right_kichRubbish_cd;


	GOLD_TYPE m_rob_income;
	GOLD_TYPE m_rob_outcome;

	double m_rob_cd;

	int GM_COMMAND;//1:������Ӯ��2���ұ����Ӯ
};

SHOWHAND_SPACE_END
#pragma once
#include "logic_def.h"
#include <i_game_phandler.h>
#include <vector>
#include "proc_game_landlord_protocol.h"
#include "i_game_player.h"

class logic_lobby;
class logic_player_db:public game_object
{
public:
	bool load_player();
	virtual void init_game_object() override;//ע������
	virtual bool store_game_object(bool to_all = false) override;//������������ʵ�ִ˽ӿ�
public:
	Tfield<int32_t>::TFieldPtr m_player_id;
	Tfield<GOLD_TYPE>::TFieldPtr m_once_win_maxgold;			//���������ӯ����
	Tfield<int32_t>::TFieldPtr m_win_count;    //���ǳ齱�ۼ�ӮǮ���� 
};

class logic_player: 
	public enable_obj_pool<logic_player>
	,public i_game_phandler
	,public logic_player_db
{
public:
	logic_player(void);
	virtual ~logic_player(void);

	void heartbeat( double elapsed );

	//-----------------------------------------------------------------------
	//�ӷ�����֪ͨ�߼��Ľӿ�
	virtual void on_attribute_change(int atype, int v) override;			//��Ǯ�ı�

	virtual void on_change_state() override;					//��ҵ���

	virtual void on_attribute64_change(int atype, GOLD_TYPE v = 0) override;

	//------------------------------------------------------------------------
	bool is_robot();

	const std::string& get_nickname();
	const std::string& get_icon_custom();
	const uint32_t get_head_frame_id();
	const int16_t get_player_sex();
	bool is_GM_CONTROL();
	uint32_t get_pid();
	uint16_t get_viplvl();
	GOLD_TYPE get_gold();
	int get_ticket();
	bool change_gold(GOLD_TYPE v);
	bool change_gold2(int v, int season);
	bool change_ticket(int count,int reason = -1);

	void set_bet_max();

	void enter_game(logic_lobby* lobby);		//������Ϸ
	bool enter_room(logic_room* room);			//���뷿��
	void leave_room();							//�뿪����
	void escapeHandle();
	logic_room* get_room(){return m_room;}
	e_player_state get_game_state();
	void release();								//�˳�������Ϸ�ͻ���

	void clear_once_data();						//������Ѻע

	void sycn_gold();
	void onAcceptGift(int receiverId, int giftId);

	void add_star_lottery_info(int32_t award,int32_t star = 0);

	void quest_change(int quest_type,int count,int param = 0);
public:
	void clear_table_data();//

	void bc_game_msg(int money, const std::string& sinfo, int mtype = 1);

	template<class T>
	int send_msg_to_client(T msg)
	{
		return m_player->send_msg_to_client(msg);
	};
private:
	logic_lobby* m_lobby;
	logic_room* m_room;

	double m_checksave;
	bool is_first_save;

	GOLD_TYPE m_logic_gold;
	GOLD_TYPE m_change_gold;
public:
	void robot_heartbeat(double elapsed);
};
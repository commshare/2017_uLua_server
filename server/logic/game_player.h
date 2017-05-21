#pragma once
#include "game_def.h"
#include <mongo/db/jsobj.h>
#include <game_sys_mgr.h>
#include <i_game_player.h>

class logic_peer;
class game_player:
	public i_game_player,
	public enable_obj_pool<game_player>
	,public boost::enable_shared_from_this<game_player>
	,public game_sys_mgr
{
public:
	game_player();
	virtual ~game_player();

	void heartbeat( double elapsed );

	uint32_t get_sessionid();
	void set_sessionid(uint32_t sessionid);
	
	void set_state(e_player_state eps);
	
	boost::weak_ptr<logic_peer> GatePeer;

	void init_sys();
	void leave_game();
private:
	uint32_t m_sessionid;
	e_player_state m_state;		
	double m_check_kick;


public:	
	//std::string Account;
	std::string NickName;
	uint32_t PlayerID;
	GOLD_TYPE Gold;
	int16_t VIPLevel;
	int PhotoFrame;
	std::string IconCustom;
	int16_t Sex;
	int Ticket;
	time_t ExperienceVIP;
	time_t CreateTime;
	bool IsRobot;
	time_t MonthCard;
	bool IsBuyFirstGift;
	int Lucky;
	int64_t TempIncome;
	int64_t TotalIncome;
	int Privilege;

	void world_attribute_change(int atype, int v = 0);
	void world_attribute64_change(int atype, int64_t v = 0);
public:
	//��ȡ���id
	virtual uint32_t get_playerid();

	//��ȡ��ҵ�ǰ���
	virtual int get_attribute(int atype);

	//��ȡ��ҽ��
	virtual GOLD_TYPE get_attribute64(int atype);

	//��ȡ�ǳ�
	virtual const std::string& get_nickname();

	//��ȡ�Զ���ͷ��
	virtual const std::string& get_icon_custom();

	//�Ƿ�����VIP
	virtual bool is_ExperienceVIP();
	//�׳�
	virtual bool is_BuyFirstGift();

	//�޸���ҽ��(��ҪƵ������)
	virtual bool change_gold(GOLD_TYPE cgold);
	//�޸���ȯ
	virtual bool change_ticket(int cticket);
	//�޸�����
	virtual bool change_lucky(int clucky, int64_t tempincome, int64_t totalincome);
	//�ı���������
	virtual bool add_starinfo(int addaward, int addstar = 0);
	//��ȡ��ǰ״̬
	virtual e_player_state get_state();
	//�Ƿ��ڱ�����
	virtual bool is_protect();
	//�Ƿ������
	virtual bool is_robot();
	//�¿��Ƿ���Ч
	virtual bool check_monthcard(); 

	//����ɾ͸ı�
	virtual void quest_change(int questid, int count=1, int param=0);

	//������ݸı��¼
	virtual void player_property_log(int ptype, int changecount, int reason, const std::string& param);

	//����Э�鵽�ͻ���
	virtual int send_msg_to_client(uint16_t packet_id, boost::shared_ptr<google::protobuf::Message> msg);

	//�㲥��Ϸ��Ϣ
	virtual void game_broadcast(const std::string& roomname, int infotype, const std::string& strinfo, int money, int moneytype);

	// ���ض�����
	virtual const std::string* getLan(const std::string& lanKey);

	// �㲥��Ϣ
	virtual void gameBroadcast(const std::string& msg);

	void reset_robot_life();
private:
	double m_life;
	double m_check_life;
};




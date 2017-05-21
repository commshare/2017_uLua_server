#pragma once
#include <boost/cstdint.hpp>
#include "game_def.h"
#include <string>
#include <game_sys_mgr.h>

enum e_player_state
{
	e_ps_none = 0, //δ��ʼ��
	e_ps_checking, //У����
	e_ps_playing,	//��Ϸ��
	e_ps_disconnect, //����
};

class world_peer;
class GiftMap;

class game_player:
	public game_object
	,public enable_obj_pool<game_player>
	,public boost::enable_shared_from_this<game_player>
	,public game_sys_mgr
{
public:
	game_player();
	virtual ~game_player();

	void heartbeat( double elapsed );

	
	void player_logout();
	void on_logout();
	void player_login(uint32_t sessionid,
		const std::string& account, const std::string& token, const std::string& platform, const std::string& login_platform);
	void player_relogin(const std::string& token);

	
	uint32_t get_sessionid();
	void set_sessionid(uint32_t sessionid);
	e_player_state get_state();

	static bool check_token(const std::string& account, const std::string& token, const std::string& sign);

	boost::shared_ptr<world_peer> get_logic();//��ȡ�߼�
	boost::shared_ptr<world_peer> get_gate();//��ȡ����
	bool check_logic();//����߼�����������
	void clear_logic(uint16_t lid = 0);
	template<class T>
	int send_msg_to_client(T msg)//����Э�鵽�ͻ���
	{
		return send_msg_to_client(msg->packet_id(), msg);
	};

	GOLD_TYPE get_gold();

	void change_property(int type);
	int change_gold(GOLD_TYPE dif_gold, bool needsend = true, bool check = false, int reason = 100);
	void change_ticket(int dif_ticket, bool needsend = true);
	void change_chip(int dif_chip);
	void change_vip(int vip);
	void change_lucky(int dif_lucky);
	bool is_gaming();
	bool join_game(uint16_t gameid,uint16_t serverid);

	// ������������ڵ���ϷID������logic id
	bool setGameIdServerId(uint16_t gameId, uint16_t serverId);

	// ������ϷID��Logic id
	bool resetGameIdServerId();

	void leave_game();
	uint16_t get_logicid();
	uint16_t get_gameid();
	void on_joingame(bool blogin = true);
	void init_sys();

	const mongo::BSONObj& get_id_finder();
	bool load_player();
	
	bool loadPlayer(mongo::BSONObj& b);

	//���ػ�����
	void load_robot(int playerid);

	bool http_run(const std::string& respose);
	void http_check(bool success, const std::string& respose, bool isrelogin = false);

	// �޸�����ǳ�
	int updateNickname(const std::string& newname);

	// �յ�����
	int addGift(int giftId, GOLD_TYPE count, const std::string& param);

	int addItem(int itemId, GOLD_TYPE count, int reason = 0, const std::string& param = "");

	// 0�����������Ϣ
	void resetPlayerInfo();

	void setFirstGift();
	//��������vipʱ��
	bool addExperienceVIP(int day);
	//int get_channel();

	int get_viplvl();
	bool first_login();
	void check_firstgift(int32_t gold);

	bool is_goldshop();

	bool IsLogin()
	{
		return islogin_success;
	}
protected:
	void player_gold_log(GOLD_TYPE old_value, GOLD_TYPE new_value, int32_t reason);
private:
	uint32_t m_sessionid;
	uint16_t m_logicid;
	uint16_t m_gameid;
	e_player_state m_state;

	std::string m_token;

	time_t m_login_time;
	double m_check_logout;
	double m_check_save;
	mongo::BSONObj m_id_finder;
	void start_check(bool isrelogin = false);

	void reset_logicpeer();
	void reset_gatepeer();
	boost::weak_ptr<world_peer> m_logicpeer;
	boost::weak_ptr<world_peer> m_gatepeer;
	int send_msg_to_client(uint16_t packet_id, boost::shared_ptr<google::protobuf::Message> msg);
	
private:	
	//////////////////////////////////////////////////////////////////////////
	//����
	virtual void init_game_object();//ע������
	virtual void to_bson_ex(mongo::BSONObjBuilder& ba);//��չ

	void create_player(bool isRobot = false);

	bool _checkReflush();

	std::string _newAccountName();
	bool islogin_success;

	void heartbeatRobotVip(double elapsed);
	double m_robotVipTime;
public:
	//һ�β���ִ�н��� �������޸ĵ���һ��  �������޸Ĳ�Ҫ����
	virtual bool store_game_object(bool to_all = false);

	GStringFieldPtr					Account;			//�˺�
	GStringFieldPtr					NickName;			//�ǳ�
	GStringFieldPtr					Platform;			//ƽ̨
	GStringFieldPtr					LoginPlatform;		//ƽ̨
	//Tfield<int16_t>::TFieldPtr		IconId;				//ͷ��id
	Tfield<int32_t>::TFieldPtr		PlayerId;			//���id
	Tfield<GOLD_TYPE>::TFieldPtr		Gold;				//���
	Tfield<int32_t>::TFieldPtr		Ticket;				//��ȯ
	Tfield<int32_t>::TFieldPtr		Chip;				//��Ƭ

	Tfield<int32_t>::TFieldPtr		OnlineTime;			//����ʱ��
	Tfield<time_t>::TFieldPtr		LogoutTime;			//����ʱ��
	GStringFieldPtr					IconCustom;			//�Զ���ͷ��
	Tfield<time_t>::TFieldPtr		ExperienceVIP;		//����vip

	// �ϴ��Զ���ͷ��Ķ����ֹʱ��
	Tfield<time_t>::TFieldPtr		UpLoadCustomHeadFreezeDeadTime;		

	Tfield<int16_t>::TFieldPtr		UpdateIconCount;	//�޸�ͷ�����

	Tfield<int8_t>::TFieldPtr		Sex;				//�Ա�0������1�У�2Ů
	GStringFieldPtr					SelfSignature;		//ǩ��
	GMapFieldPtr					m_giftStat;			//�������ͳ��
	boost::shared_ptr<GiftMap>		m_giftStatPtr;
	Tfield<GOLD_TYPE>::TFieldPtr		MaxGold;			//��������м�¼
	Tfield<int32_t>::TFieldPtr		MaxTicket;			//��ȯ�����м�¼

	Tfield<time_t>::TFieldPtr		LastCheckTime;		//���1�μ��ˢ�µ�ʱ��
	Tfield<int16_t>::TFieldPtr		OnlineRewardCount;	//�������콱����
	Tfield<int32_t>::TFieldPtr		PhotoFrameId;		//��ǰ���ID

	time_t						    LastGameChatTime;   // �ϴ����緢��ʱ��
	GStringFieldPtr					BindPhone;			// �󶨵��ֻ�
	Tfield<int8_t>::TFieldPtr		BindCount;			// ���հ��ֻ��Ĵ���
	Tfield<int32_t>::TFieldPtr		NewGuildHasFinishStep; // ������������ɲ���

	Tfield<GOLD_TYPE>::TFieldPtr	SendGiftCoinCount;	// ���������������������ܺ�
	Tfield<int8_t>::TFieldPtr		FetchSafeBoxSecurityCodeCount; // ���ջ�ȡ��������֤�����

	Tfield<int8_t>::TFieldPtr		UpdateNickCount;	// ��������

	Tfield<time_t>::TFieldPtr		CreateTime;		//����ʱ��
	Tfield<bool>::TFieldPtr			IsRobot;	// �Ƿ������

	Tfield<int32_t>::TFieldPtr		ChannelID;			//����ID
	GStringFieldPtr					OldAcc;			//���˺�

	GMapFieldPtr					CheckMap;			//ͨ�õı�ʶmap
	Tfield<time_t>::TFieldPtr		KickEndTime;		//�����߽���

	Tfield<int32_t>::TFieldPtr		FirstGiftTime;	// �׳����ʱ��		-1��ʾ����
	Tfield<int32_t>::TFieldPtr		WinCount;	// Ӯ����

	Tfield<int32_t>::TFieldPtr			PlayerType;	// �������


	Tfield<int32_t>::TFieldPtr		Lucky;				//�������
	Tfield<int64_t>::TFieldPtr		TempIncome;			//�����ʱ����(����ֵ���������棬��������ֵ����������)
	Tfield<int64_t>::TFieldPtr		TotalIncome;		//���������(����ֵ���������棬������)
	Tfield<int32_t>::TFieldPtr		Privilege;			//��Ȩ
	GStringFieldPtr					LastIP;
	Tfield<int16_t>::TFieldPtr		LastPort;
	
	std::string MachineCode;
	std::string MachineType;
	int32_t m_channel;
};


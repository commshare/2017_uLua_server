#pragma once
#include <i_game_def.h>

enum e_player_state
{
	e_ps_none = 0, //δ��ʼ��
	e_ps_loading, //У����
	e_ps_playing,	//��Ϸ��
	e_ps_disconnect, //����
};

class i_game_player
{
public:
	i_game_player();
	virtual ~i_game_player();

	//��ȡ���id
	virtual uint32_t get_playerid() = 0;

	//��ȡ�������
	virtual int get_attribute(int atype) = 0;

	//��ȡ���64λ����
	virtual GOLD_TYPE get_attribute64(int atype) = 0;

	//��ȡ�ǳ�
	virtual const std::string& get_nickname() = 0;

	//��ȡ�Զ���ͷ��
	virtual const std::string& get_icon_custom() = 0;

	//�Ƿ�����VIP
	virtual bool is_ExperienceVIP() = 0; 

	//�޸���ҽ��(��ҪƵ������)���ܲ���ʧ��
	virtual bool change_gold(GOLD_TYPE cgold) = 0;
	//�޸���ȯ
	virtual bool change_ticket(int cticket) = 0;
	//�޸�����
	virtual bool change_lucky(int clucky, int64_t tempincome, int64_t totalincome) = 0;
	//��ȡ��ǰ״̬
	virtual e_player_state get_state() = 0;
	//�ı���������
	virtual bool add_starinfo(int addaward, int addstar = 0) = 0;
	//�¿��Ƿ���Ч
	virtual bool check_monthcard() = 0; 

	//�Ƿ��ڱ�����
	virtual bool is_protect() = 0;
	//�Ƿ������
	virtual bool is_robot() = 0;

	virtual bool is_BuyFirstGift() = 0;

	//����ɾ͸ı�
	virtual void quest_change(int questid, int count=1, int param = 0) = 0;

	//������ݸı��¼
	virtual void player_property_log(int at, int changecount, int reason, const std::string& param)=0;

	//�㲥��Ϸ��Ϣ
	virtual void game_broadcast(const std::string& roomname, int infotype, const std::string& strinfo, int money, int moneytype) = 0;

	template<class T>
	int send_msg_to_client(T msg)
	{
		return send_msg_to_client(msg->packet_id(), msg);
	};

	//����Э�鵽�ͻ���
	virtual int send_msg_to_client(uint16_t packet_id, boost::shared_ptr<google::protobuf::Message> msg) = 0;

	// ���ض�����
	virtual const std::string* getLan(const std::string& lanKey) = 0;

	// �㲥��Ϣ
	virtual void gameBroadcast(const std::string& msg) = 0;
public:	
	void set_handler(iGPhandlerPtr phandler);
	iGPhandlerPtr get_handler();
protected:
	

	boost::weak_ptr<i_game_phandler> m_phandler;
};

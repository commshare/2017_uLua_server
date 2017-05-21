#pragma once
#include <i_game_def.h>
#include <vector>
class db_base;

//��Ϸ����ص����������ӿ�
class i_game_ehandler
{
public:
	i_game_ehandler();
	virtual ~i_game_ehandler();

	//��Ϸ�����ʼ����ɣ����ɹ����ã�
	virtual void on_init_engine(uint16_t game_id, const std::string& game_ver) = 0;

	//�������ر� ��Ϸ�����˳�
	virtual void on_exit_engine() = 0;

	//��������� ����Ļ����˲�һ����ʱ����  
	//Ҫ���vip Ҫ���gold  �Զ����־tag
	virtual void request_robot(int tag, GOLD_TYPE needgold, int needvip = 0) = 0;
	
	//������Ҫʹ�û�����ʱ ֻҪ�˳�������ѡ��Ȼ����ô˺���
	virtual void release_robot(int playerid) = 0;

	//��ȡ��ǰ��������
	virtual int get_robot_count() = 0;

	template<class T>
	int broadcast_msg_to_client(std::vector<uint32_t>& pids,T msg)
	{
		return broadcast_msg_to_client(pids, msg->packet_id(), msg);
	};

	//����Э�鵽�ͻ���
	virtual int broadcast_msg_to_client(std::vector<uint32_t>& pids, uint16_t packet_id, boost::shared_ptr<google::protobuf::Message> msg) = 0;

	//����Э���б�
	virtual int broadcast_msglist_to_client(std::vector<uint32_t>& pids, std::vector<msg_packet_one>& msglist) = 0;

	virtual bool setGameDb(db_base *dgGame) = 0;

	// ���ص�ǰ�ľ���id
	virtual int64_t getCurId(const std::string& key) = 0;
};


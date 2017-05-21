#pragma once

//�˹����֧��win�����Ը���ace����ƽ̨

#include "windows.h"
#include <enable_singleton.h>
#include "i_game_ehandler.h"
#include "robot_manager.h"

class i_game_engine;
class packet_manager;

class game_manager : 
	public enable_singleton<game_manager>
	,public i_game_ehandler
{
public:
	game_manager();
	~game_manager();


	bool open();
	void close();

	i_game_engine* get_game_engine();
	packet_manager* get_packet_mgr();

	//��ʼ������
	virtual void on_init_engine(uint16_t game_id, const std::string& game_ver);

	//��Ϸ�ر�
	virtual void on_exit_engine();

	//�㲥Э��
	virtual int broadcast_msg_to_client(std::vector<uint32_t>& pids, uint16_t packet_id, boost::shared_ptr<google::protobuf::Message> msg);

	//����Э���б�
	virtual int broadcast_msglist_to_client(std::vector<uint32_t>& pids, std::vector<msg_packet_one>& msglist);

	uint16_t get_gameid();
	int get_gamever();

	//��������� ����Ļ����˲�һ����ʱ����  
	//Ҫ���vip Ҫ���gold  �Զ����־tag
	virtual void request_robot(int tag, GOLD_TYPE needgold, int needvip = 0);
	
	//������Ҫʹ�û�����ʱ ֻҪ�˳�������ѡ��Ȼ����ô˺���
	virtual void release_robot(int playerid);
	//��ȡ��ǰ��������
	virtual int get_robot_count();
	//���ػ�����
	void response_robot(int32_t playerid);

	void heartbeat(double elapsed);

	virtual bool setGameDb(db_base *dgGame);

	virtual int64_t getCurId(const std::string& key);
private:
	void game_regedit();

	robot_manager m_robotmgr;
	i_game_engine* m_engine;
	packet_manager* m_pkmgr;
	uint16_t m_gameid;
	int m_gamever;
	HMODULE m_mod;
};


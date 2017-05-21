#pragma once
#include "game_sys_def.h"

struct stSendGiftLogInfo;
struct stSendMailLogInfo;
struct stPlayerInfo;

namespace client2world_protocols 
{
	class packetw2c_req_safebox_log_result;
}

// �����־
class PlayerLogMgr : public enable_obj_pool<PlayerLogMgr>, public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_player_log);

	MAKE_GET_OWNER(game_player)

	virtual void init_sys_object();

	virtual bool sys_load();

	/*
			�����������﷢����־
	*/
	int getSendGiftLog(time_t minT, time_t& Last, std::deque<stSendGiftLogInfo>& res);

	/*
			�����ʼ�������־
	*/
	int getSendMailLog(time_t minT, time_t& Last, std::deque<stSendMailLogInfo>& res);

	/*
			���ر�������־
	*/
	int getSafeBoxLog(time_t start_time, boost::shared_ptr<client2world_protocols::packetw2c_req_safebox_log_result>& msg);

	/*
			������ͼ�¼
	*/
	int addSendGiftLog(int playerId, int giftId, GOLD_TYPE giftCount, const std::string& mailId, bool send, int maxLogCount);
	/*
			��ӱ������¼
	*/
	int addSafeBoxLog(GOLD_TYPE gold, GOLD_TYPE playerGold, int maxLogCount);

	/*
			��ӷ����ʼ���¼
	*/
	int addSendMailLog(int friendId, const std::string& title, const std::string& content, const std::string& mailId, int maxLogCount);

	/*
			ɾ���ʼ���־
	*/
	int delSendMailLog(const std::string& mailId);
private:
	bool _getPlayerInfo(int playerId, stPlayerInfo& info);
private:
	// �����б�
	GArrayFieldPtr m_sendList;

	// �ʼ��б�
	GArrayFieldPtr m_mailList;
	//�������¼
	GArrayFieldPtr m_safeBoxList;
};

struct stSendGiftLogInfo
{
	time_t m_sendTime;
	int32_t m_friendId;
	std::string m_friendNickName;
	int32_t m_giftId;
	int32_t m_count;
	bool m_sendgold;
	std::string m_mailid;
};

struct stSendMailLogInfo
{
	time_t m_sendTime;
	int32_t m_friendId;
	std::string m_title;
	std::string m_content;
	std::string m_mailId;
	std::string m_friendNickName;
};
#pragma once
#include "game_sys_def.h"

class game_player;
class FriendMap;
struct stFriendInfo;

// ���ѹ���
class FriendMgr : public enable_obj_pool<FriendMgr>, public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_friend);

	MAKE_GET_OWNER(game_player);

	virtual void init_sys_object();	

	virtual bool sys_load();

	/*
			��Ӻ���
			����ֵ����ֵ e_msg_result_def����
	*/
	int addFriend(int friendId);

	/*
			�Ƴ�����
			����ֵ����ֵ e_msg_result_def����
	*/
	int removeFriend(int friendId);

	/*
			��ȡ�����б�
	*/
	void getFriendList(std::vector<stFriendInfo>& friendList);

	/*
			���غ�����Ϣ
			friendId		����ID
			����true�ɹ���falseʧ��
	*/
	bool getFriendInfo(int friendId, stFriendInfo& info);

	/*
			�Ƿ����ĳ����
	*/
	bool hasFriend(int friendId);

	/*
			�������
			playerId		���ID����һ��Ϊ����
			����ֵ����ֵ e_msg_result_def����
	*/
	int searchPlayer(int playerId, stFriendInfo& info);
private:
	bool _getFriendInfo(int friendId, stFriendInfo& info);
private:
	// ����
	GMapFieldPtr m_friends;

	boost::shared_ptr<FriendMap> m_friendsPtr;
};


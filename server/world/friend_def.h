#pragma once
#include "game_object.h"
#include "game_object_container.h"
#include "gift_def.h"

// ������Ϣ
class FriendItem : public game_object, public enable_obj_pool<FriendItem>
{
public:
	FriendItem();
	
	virtual void init_game_object();
	
	virtual uint32_t get_id();
public:
	// ����ID
	Tfield<int32_t>::TFieldPtr m_friendId;
};

class FriendMap : public game_object_container, public enable_obj_pool<FriendMap>
{
public:
	FriendMap();

	virtual const std::string& get_cells_name();		

	virtual const std::string& get_index_name();

	virtual uint32_t get_index_id();

	virtual GObjPtr create_game_object(uint32_t object_id);

	virtual const std::string& get_container_name();

	virtual bool is_load();		

	virtual db_base* get_db();

	virtual const mongo::BSONObj& get_id_finder();

	virtual const std::string& get_id_name();

	void setPlayerId(int playerId);
private:
	int m_playerId;
	mongo::BSONObj m_idFinder;
};

struct stGift;

struct stFriendInfo
{
	// ���ID
	int m_friendId;
	
	// �Ƿ�����
	bool m_isOnLine;

	// �Ա�
	int m_sex;

	// VIP�ȼ�
	int m_vipLevel;

	std::string m_nickName;

	//int m_headId;

	std::string m_iconCustom;

	int m_photoFrameId;

	// ǩ��
	std::string m_selfSignature;

	// �����б�
	std::vector<stGift> m_giftList;

	// ��������������
	GOLD_TYPE m_sendGiftCoinCount;

	// ���
	GOLD_TYPE m_gold;

	// ���䲶��ȼ�
	int m_fishLevel;
};


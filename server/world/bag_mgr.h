#pragma once
#include "game_sys_def.h"

class GameItem;
class BagMap;

// ��������
class BagMgr : public game_sys_base, public game_object, public enable_obj_pool<BagMgr>
{
public:
	MAKE_SYS_TYPE(e_gst_bag);

	MAKE_GET_OWNER(game_player);

	virtual void init_game_object();

	virtual void init_sys_object();

	// ��db��������
	virtual bool sys_load();

	/*
			�򱳰���ӵ���
			id		����ID
			count	������<0��ʾɾ�����ɵ���
	*/
	bool addItem(int id, int count);

	// �������Ƴ�������
	bool removeItem(int id, int count);

	// ������idȫ���Ƴ�
	bool removeItem(int id);

	// �����Ƿ�Ϊ��
	bool empty();

	// ����ĳ������
	GameItem* getItem(int id);

	// ��ȡ��Ʒ����
	int getItemCount(int id);

	// ���ص���map
	BagMap* getBagMap();

	/*
			���һЩ���û
	*/
	void doActivity();

	void doActivity(int rechargeVal);
public:
	// ���id
	Tfield<int32_t>::TFieldPtr m_playerId;			

	// �����б�
	GMapFieldPtr m_items;
	boost::shared_ptr<BagMap> m_itemsPtr;
};

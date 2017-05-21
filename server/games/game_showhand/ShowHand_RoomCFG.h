#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct ShowHand_RoomCFGData
{
	//����ID
	int mRoomId;
	//��������
	std::string mRoomName;
	//��������������
	int mRoomMaxPlayerCount;
	//���������������
	int mTableMaxPlayerCount;
	//�Ƿ񿪷�
	bool mIsOpen;
	//��������������
	int mEnterGoldCondition;
	//�������ӽ����������
	int mEnterTableGoldCondition;
	//�Ƿ��˳���Ϸ�ͷ������
	int mIllegalQuitGoldCount;
	//��ע
	int mAnte;
	//����������
	int mAndroidCount;
	//��������С�����
	int mRobMinGold;
	//�������������
	int mRobMaxGold;
	//���������VIP
	int mRobMinVip;
	//���������VIP
	int mRobMaxVip;
	//���������ӯ����ƽ����
	float mRoomAndroidYield;
};

class ShowHand_RoomCFG
{
public:
private:
	static std::auto_ptr<ShowHand_RoomCFG> msSingleton;
public:
	int GetCount();
	const ShowHand_RoomCFGData* GetData(int RoomId);
	boost::unordered_map<int, ShowHand_RoomCFGData>& GetMapData();
	void Reload();
	void Load();
	static ShowHand_RoomCFG* GetSingleton();
private:
	boost::unordered_map<int, ShowHand_RoomCFGData> mMapData;
};

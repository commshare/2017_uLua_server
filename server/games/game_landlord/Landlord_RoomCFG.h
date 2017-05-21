#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct Landlord_RoomCFGData
{
	//����id
	int mRoomID;
	//������
	std::string mRoomName;
	//�Ƿ񿪷�
	bool mIsOpen;
	//�����˱�ǩ
	std::vector<int> mRobTag;
	//����ͼƬ
	std::string mRoomImage;
	//����VIP����
	int mVipCondition;
	//�����������
	int mGoldCondition;
	//�����ע��
	int mBetMax;
	//����������
	int mRobCount;
};

class Landlord_RoomCFG
{
public:
private:
	static std::auto_ptr<Landlord_RoomCFG> msSingleton;
public:
	int GetCount();
	const Landlord_RoomCFGData* GetData(int RoomID);
	boost::unordered_map<int, Landlord_RoomCFGData>& GetMapData();
	void Reload();
	void Load();
	static Landlord_RoomCFG* GetSingleton();
private:
	boost::unordered_map<int, Landlord_RoomCFGData> mMapData;
};

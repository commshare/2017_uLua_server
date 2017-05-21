#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct ShowHand_RoomStockCFGData
{
	//����id
	int mRoomID;
	//��ˮ
	float mDeduct;
	//Ĭ�Ͽ��
	int mDefaultStock;
	//���ˮλ(10��)
	std::vector<int> mStock;
	//�ŷָ��ʣ�10����
	std::vector<int> mScoreId;
	//���˿����չ
	int mLuckyEx;
	//�������ұ���
	int mLuckyGoldRate;
	//��������
	float mLuckyIncBuff;
	//���˼���
	float mLuckyDecBuff;
};

class ShowHand_RoomStockCFG
{
public:
private:
	static std::auto_ptr<ShowHand_RoomStockCFG> msSingleton;
public:
	int GetCount();
	const ShowHand_RoomStockCFGData* GetData(int RoomID);
	boost::unordered_map<int, ShowHand_RoomStockCFGData>& GetMapData();
	void Reload();
	void Load();
	static ShowHand_RoomStockCFG* GetSingleton();
private:
	boost::unordered_map<int, ShowHand_RoomStockCFGData> mMapData;
};

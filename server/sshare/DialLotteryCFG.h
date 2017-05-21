#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct DialLotteryCFGData
{
	//���
	int mID;
	//�������
	int mRewardCoin;
	//�񽱸���
	int mProbability;
};

class DialLotteryCFG
{
public:
private:
	static std::auto_ptr<DialLotteryCFG> msSingleton;
public:
	int GetCount();
	const DialLotteryCFGData* GetData(int ID);
	boost::unordered_map<int, DialLotteryCFGData>& GetMapData();
	void Reload();
	void Load();
	static DialLotteryCFG* GetSingleton();
private:
	boost::unordered_map<int, DialLotteryCFGData> mMapData;
};

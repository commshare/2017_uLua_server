#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct ShoaHand_BetMaxCFGData
{
	//Key
	int mID;
	//�������
	int mGoldCount;
	//����Ͷע����
	int mBetMax;
	//���ó������
	std::vector<int> mCanUseWeight;
};

class ShoaHand_BetMaxCFG
{
public:
private:
	static std::auto_ptr<ShoaHand_BetMaxCFG> msSingleton;
public:
	int GetCount();
	const ShoaHand_BetMaxCFGData* GetData(int ID);
	boost::unordered_map<int, ShoaHand_BetMaxCFGData>& GetMapData();
	void Reload();
	void Load();
	static ShoaHand_BetMaxCFG* GetSingleton();
private:
	boost::unordered_map<int, ShoaHand_BetMaxCFGData> mMapData;
};

#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct HappySupremacy_CombineCardsCFGData
{
	//�����ID
	int mCombineCardID;
	//����Ƶ�����
	std::string mCombineCardsName;
};

class HappySupremacy_CombineCardsCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_CombineCardsCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_CombineCardsCFGData* GetData(int CombineCardID);
	boost::unordered_map<int, HappySupremacy_CombineCardsCFGData>& GetMapData();
	void Reload();
	void Load();
	static HappySupremacy_CombineCardsCFG* GetSingleton();
private:
	boost::unordered_map<int, HappySupremacy_CombineCardsCFGData> mMapData;
};

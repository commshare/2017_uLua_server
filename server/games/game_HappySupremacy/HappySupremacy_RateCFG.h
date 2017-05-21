#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct HappySupremacy_RateCFGData
{
	//���
	int mKey;
	//����
	std::string mName;
	//ӮǮ����
	int mRate1;
	//���䲻Ӯ����
	int mRate2;
};

class HappySupremacy_RateCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_RateCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_RateCFGData* GetData(int Key);
	boost::unordered_map<int, HappySupremacy_RateCFGData>& GetMapData();
	void Reload();
	void Load();
	static HappySupremacy_RateCFG* GetSingleton();
private:
	boost::unordered_map<int, HappySupremacy_RateCFGData> mMapData;
};

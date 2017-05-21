#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct HappySupremacy_RobCFGData
{
	//Key
	int mID;
	//��ұ�ǩ
	std::string mName;
	//�����Сֵ
	int mGoldMin;
	//������ֵ
	int mGoldMax;
	//VIP��Сֵ
	int mVipMin;
	//VIP���ֵ
	int mVipMax;
};

class HappySupremacy_RobCFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_RobCFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_RobCFGData* GetData(int ID);
	boost::unordered_map<int, HappySupremacy_RobCFGData>& GetMapData();
	void Reload();
	void Load();
	static HappySupremacy_RobCFG* GetSingleton();
private:
	boost::unordered_map<int, HappySupremacy_RobCFGData> mMapData;
};

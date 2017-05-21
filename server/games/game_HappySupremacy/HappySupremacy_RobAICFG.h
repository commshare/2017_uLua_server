#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct HappySupremacy_RobAICFGData
{
	//Key
	int mID;
	//��עƫ��
	std::string mBetName;
	//��ע����(˳��:0������,1��˳�ǣ�2������,3:˳���ţ��ǣ�,4:�����ţ��ǣ�,5:˳���ţ��ţ����ţ�)(�ٷֱ�)
	std::vector<int> mBetRate;
};

class HappySupremacy_RobAICFG
{
public:
private:
	static std::auto_ptr<HappySupremacy_RobAICFG> msSingleton;
public:
	int GetCount();
	const HappySupremacy_RobAICFGData* GetData(int ID);
	boost::unordered_map<int, HappySupremacy_RobAICFGData>& GetMapData();
	void Reload();
	void Load();
	static HappySupremacy_RobAICFG* GetSingleton();
private:
	boost::unordered_map<int, HappySupremacy_RobAICFGData> mMapData;
};

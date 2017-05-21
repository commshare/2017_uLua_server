#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct ShowHand_RobAICFGData
{
	//Key
	int mID;
	//��עƫ��
	std::string mBetName;
	//��ע����(˳��:�͡��С��жԡ����ԡ���)(�ٷֱ�)
	std::vector<int> mBetRate;
};

class ShowHand_RobAICFG
{
public:
private:
	static std::auto_ptr<ShowHand_RobAICFG> msSingleton;
public:
	int GetCount();
	const ShowHand_RobAICFGData* GetData(int ID);
	boost::unordered_map<int, ShowHand_RobAICFGData>& GetMapData();
	void Reload();
	void Load();
	static ShowHand_RobAICFG* GetSingleton();
private:
	boost::unordered_map<int, ShowHand_RobAICFGData> mMapData;
};

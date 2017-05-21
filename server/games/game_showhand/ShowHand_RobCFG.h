#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct ShowHand_RobCFGData
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

class ShowHand_RobCFG
{
public:
private:
	static std::auto_ptr<ShowHand_RobCFG> msSingleton;
public:
	int GetCount();
	const ShowHand_RobCFGData* GetData(int ID);
	boost::unordered_map<int, ShowHand_RobCFGData>& GetMapData();
	void Reload();
	void Load();
	static ShowHand_RobCFG* GetSingleton();
private:
	boost::unordered_map<int, ShowHand_RobCFGData> mMapData;
};

#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_OnlineRewardCFGData
{
	//Key
	int mID;
	//��ʼʱ��,���ڲ��ֲ�������
	std::string mStartTime;
	//����ʱ��,,���ڲ��ֲ�������
	std::string mEndTime;
	//VIP����
	int mConditionVip;
	//��ҽ���
	int mRewardCoin;
};

class M_OnlineRewardCFG
{
public:
private:
	static std::auto_ptr<M_OnlineRewardCFG> msSingleton;
public:
	int GetCount();
	const M_OnlineRewardCFGData* GetData(int ID);
	boost::unordered_map<int, M_OnlineRewardCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_OnlineRewardCFG* GetSingleton();
private:
	boost::unordered_map<int, M_OnlineRewardCFGData> mMapData;
};

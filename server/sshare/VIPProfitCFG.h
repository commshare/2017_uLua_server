#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct VIPProfitCFGData
{
	//vip�ȼ�
	int mVipLv;
	//�������辭��
	int mVipExp;
	//��ȡ���߽�������
	int mOnlineReward;
};

class VIPProfitCFG
{
public:
private:
	static std::auto_ptr<VIPProfitCFG> msSingleton;
public:
	int GetCount();
	const VIPProfitCFGData* GetData(int VipLv);
	boost::unordered_map<int, VIPProfitCFGData>& GetMapData();
	void Reload();
	void Load();
	static VIPProfitCFG* GetSingleton();
private:
	boost::unordered_map<int, VIPProfitCFGData> mMapData;
};

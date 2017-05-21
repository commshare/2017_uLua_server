#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_VIPProfitCFGData
{
	//vip�ȼ�
	int mVipLv;
	//�������辭��
	int mVipExp;
	//��ȡ���߽�������
	int mOnlineReward;
	//ÿ����������
	long long mMaxGiftslimit;
	//��������
	std::vector<std::string> mGiftUnlock;
	//�������
	std::vector<std::string> mRoomUnlock;
	//������߽���
	std::vector<std::string> mFishItemUnlock;
	//���VIP��־
	int mVipName;
	//ÿ��������ȯ
	int mGiveTicket;
	//ÿ�ճ齱��������
	int mDailyLottery;
};

class M_VIPProfitCFG
{
public:
private:
	static std::auto_ptr<M_VIPProfitCFG> msSingleton;
public:
	int GetCount();
	const M_VIPProfitCFGData* GetData(int VipLv);
	boost::unordered_map<int, M_VIPProfitCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_VIPProfitCFG* GetSingleton();
private:
	boost::unordered_map<int, M_VIPProfitCFGData> mMapData;
};

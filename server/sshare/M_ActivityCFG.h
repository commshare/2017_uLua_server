#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_ActivityCFGData
{
	//Key
	int mID;
	//�����
	std::string mActivityName;
	//��ʼʱ��
	std::string mStartTime;
	//����ʱ�� 
	std::string mEndTime;
	//�����
	int mActivityType;
	//��ֵ
	int mRechargeRMB;
	//VIP�ȼ�����
	int mVipLevel;
	//��½����
	std::string mLoginDay;
	//�����б�
	std::vector<int> mRewardList;
	//��������
	std::vector<int> mRewardCount;
	//�����ʼ�����
	std::string mActivityRewardMailTitle;
	//�����ʼ�����
	std::string mActivityRewardMailContent;
	//������ȡ��ʽ, 0:ͨ���ʼ� 1:�ֶ������ť��ȡ
	int mReceiveWay;
};

class M_ActivityCFG
{
public:
private:
	static std::auto_ptr<M_ActivityCFG> msSingleton;
public:
	int GetCount();
	const M_ActivityCFGData* GetData(int ID);
	boost::unordered_map<int, M_ActivityCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_ActivityCFG* GetSingleton();
private:
	boost::unordered_map<int, M_ActivityCFGData> mMapData;
};

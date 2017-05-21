#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_DialLotteryCFGData
{
	//���
	int mID;
	//�������
	int mRewardCoin;
	//��������(1:���    2:��ȯ)
	int mRewardType;
	//ͼ�����ű���
	float mScale;
	//��ƷICON
	std::string mIcon;
	//�񽱸���
	int mProbability;
};

class M_DialLotteryCFG
{
public:
private:
	static std::auto_ptr<M_DialLotteryCFG> msSingleton;
public:
	int GetCount();
	const M_DialLotteryCFGData* GetData(int ID);
	boost::unordered_map<int, M_DialLotteryCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_DialLotteryCFG* GetSingleton();
private:
	boost::unordered_map<int, M_DialLotteryCFGData> mMapData;
};

#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_ExchangeCFGData
{
	//�һ�ID
	int mChangeId;
	//�����ѻ��Ѿ�����(��λ��)
	int mCostTicket;
	//����ID����ItemCFG.xld����ID��Ӧ)
	int mItemId;
	//Ҫ�ﵽ�õȼ����ܶһ�
	int mVip;
	//ͼ���ӦͼƬ
	std::string mItemIcon;
	//�����ӦͼƬ
	std::string mItemName;
	//��Ʒ����
	int mItemCount;
};

class M_ExchangeCFG
{
public:
private:
	static std::auto_ptr<M_ExchangeCFG> msSingleton;
public:
	int GetCount();
	const M_ExchangeCFGData* GetData(int ChangeId);
	boost::unordered_map<int, M_ExchangeCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_ExchangeCFG* GetSingleton();
private:
	boost::unordered_map<int, M_ExchangeCFGData> mMapData;
};

#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_CommodityCFGData
{
	//��ƷID
	int mCommodityId;
	//��Ʒ����
	std::string mName;
	//��Ʒ����(3.����5.���)
	int mCommodityType;
	//�۸�����(1��� 2��ȯ)
	int mPriceType;
	//ʵ�ʼ۸�
	int mPrice;
	//�������ߣ���ӦItemCFG.xls��
	std::vector<int> mItem;
	//�Ƿ��ܹ���(�Ƿ���ʾ)
	bool mIsCanBuy;
	//����
	std::vector<int> mCount;
};

class M_CommodityCFG
{
public:
private:
	static std::auto_ptr<M_CommodityCFG> msSingleton;
public:
	int GetCount();
	const M_CommodityCFGData* GetData(int CommodityId);
	boost::unordered_map<int, M_CommodityCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_CommodityCFG* GetSingleton();
private:
	boost::unordered_map<int, M_CommodityCFGData> mMapData;
};

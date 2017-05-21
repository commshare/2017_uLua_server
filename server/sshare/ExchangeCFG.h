#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct ExchangeCFGData
{
	//�һ�ID
	int mChangeId;
	//��������ȯ����
	int mCostTicket;
	//����ID����ItemCFG.xld����ID��Ӧ)
	int mItemId;
};

class ExchangeCFG
{
public:
private:
	static std::auto_ptr<ExchangeCFG> msSingleton;
public:
	int GetCount();
	const ExchangeCFGData* GetData(int ChangeId);
	boost::unordered_map<int, ExchangeCFGData>& GetMapData();
	void Reload();
	void Load();
	static ExchangeCFG* GetSingleton();
private:
	boost::unordered_map<int, ExchangeCFGData> mMapData;
};

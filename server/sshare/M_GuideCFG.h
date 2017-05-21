#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_GuideCFGData
{
	//����ID
	int mID;
	//�ı�����
	std::string mContent;
	//���ͽ��
	int mSendGold;
};

class M_GuideCFG
{
public:
private:
	static std::auto_ptr<M_GuideCFG> msSingleton;
public:
	int GetCount();
	const M_GuideCFGData* GetData(int ID);
	boost::unordered_map<int, M_GuideCFGData>& GetMapData();
	void Reload();
	void Load();
	static M_GuideCFG* GetSingleton();
private:
	boost::unordered_map<int, M_GuideCFGData> mMapData;
};

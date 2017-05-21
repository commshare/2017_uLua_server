#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_RechangeLotteryCFGData
{
	//�н�����
	int mMuch;
	//�״μ��ʣ�10000��
	int mFirstRate;
	//Ĭ�ϼ���(10000)
	int mDefaultRate;
};

class M_RechangeLotteryCFG
{
public:
private:
	static std::auto_ptr<M_RechangeLotteryCFG> msSingleton;
public:
	int GetCount();
	const M_RechangeLotteryCFGData* GetData(int Much);
	boost::unordered_map<int, M_RechangeLotteryCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_RechangeLotteryCFG* GetSingleton();
private:
	boost::unordered_map<int, M_RechangeLotteryCFGData> mMapData;
};

#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_DailyLoginCFGData
{
	//���
	int mID;
	//���֣�ͼ�������������
	std::string mName;
	//����
	int mTpye;
	//������/VIP���鿨������
	int mCount;
	//ͼ��
	std::string mIcon;
};

class M_DailyLoginCFG
{
public:
private:
	static std::auto_ptr<M_DailyLoginCFG> msSingleton;
public:
	int GetCount();
	const M_DailyLoginCFGData* GetData(int ID);
	boost::unordered_map<int, M_DailyLoginCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_DailyLoginCFG* GetSingleton();
private:
	boost::unordered_map<int, M_DailyLoginCFGData> mMapData;
};

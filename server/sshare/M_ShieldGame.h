#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_ShieldGameData
{
	//����ID
	int mChannelID;
	//��������(1Ϊֻ����2Ϊֻ����)
	int mType;
	//��������\������Ϸ�б�
	std::vector<int> mShieldGameList;
	//��ʾ�ɾ�����
	std::vector<int> mShowAchieveList;
};

class M_ShieldGame
{
public:
private:
	static std::auto_ptr<M_ShieldGame> msSingleton;
public:
	int GetCount();
	const M_ShieldGameData* GetData(int ChannelID);
	boost::unordered_map<int, M_ShieldGameData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_ShieldGame* GetSingleton();
private:
	boost::unordered_map<int, M_ShieldGameData> mMapData;
};

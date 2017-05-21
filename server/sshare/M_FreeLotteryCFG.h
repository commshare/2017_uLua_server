#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_FreeLotteryCFGData
{
	//key
	int mID;
	//˵��
	std::string mInfo;
	//��С����
	int mBaseGold;
	//ICON
	std::string mAwardIcon;
	//��������
	std::string mAwardTitle;
	//������Ʒ1
	std::vector<int> mAwardItem1;
	//������Ʒ2
	std::vector<int> mAwardItem2;
	//������Ʒ3
	std::vector<int> mAwardItem3;
	//������Ʒ4
	std::vector<int> mAwardItem4;
	//������Ʒ5
	std::vector<int> mAwardItem5;
};

class M_FreeLotteryCFG
{
public:
private:
	static std::auto_ptr<M_FreeLotteryCFG> msSingleton;
public:
	int GetCount();
	const M_FreeLotteryCFGData* GetData(int ID);
	boost::unordered_map<int, M_FreeLotteryCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_FreeLotteryCFG* GetSingleton();
private:
	boost::unordered_map<int, M_FreeLotteryCFGData> mMapData;
};

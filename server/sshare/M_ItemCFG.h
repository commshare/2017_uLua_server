#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_ItemCFGData
{
	//����ID
	int mItemId;
	//��Ʒ����
	std::string mItemName;
	//����
	std::string mItemDesc;
	//��Ʒͼ��
	std::string mIcon;
	//��Ʒ����
	int mItemCategory;
	//���߼�ֵ
	int mItemValue;
};

class M_ItemCFG
{
public:
private:
	static std::auto_ptr<M_ItemCFG> msSingleton;
public:
	int GetCount();
	const M_ItemCFGData* GetData(int ItemId);
	boost::unordered_map<int, M_ItemCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_ItemCFG* GetSingleton();
private:
	boost::unordered_map<int, M_ItemCFGData> mMapData;
};

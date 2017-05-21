#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_ShopCFGData
{
	//��ֵID
	int mID;
	//����
	std::string mName;
	//����
	std::string mDesc;
	//����ICON
	std::string mNameIcon;
	//ICON
	std::string mIcon;
	//���� 1��� 2�¿� 3���
	int mType;
	//�۸�(��ʯ)
	int mPrice;
	//���
	int mGold;
	//��ʾ���
	int mIndex;
	//��ʾ�̵�
	int mShopType;
};

class M_ShopCFG
{
public:
private:
	static std::auto_ptr<M_ShopCFG> msSingleton;
public:
	int GetCount();
	const M_ShopCFGData* GetData(int ID);
	boost::unordered_map<int, M_ShopCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_ShopCFG* GetSingleton();
private:
	boost::unordered_map<int, M_ShopCFGData> mMapData;
};

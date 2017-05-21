#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_RechangeCFGData
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
	//֧������ 1������ƽ̨ 2����֧����
	int mPayType;
	//���� 1��ʯ����ʯ 2�¿� 3���
	int mType;
	//�۸�
	int mPrice;
	//���
	int mGold;
	//�״��ͽ��
	int mFirstGold;
	//ÿ���ͽ��
	int mGiveGold;
	//ÿ������ȯ
	int mGiveTicket;
	//����vip����
	int mVIPExp;
	//��ʾ���
	int mIndex;
	//��ʾ�̵�
	int mShopType;
	//�������
	bool mFlag;
	//AppStore��ƷID
	std::string mAppStoreID;
};

class M_RechangeCFG
{
public:
private:
	static std::auto_ptr<M_RechangeCFG> msSingleton;
public:
	int GetCount();
	const M_RechangeCFGData* GetData(int ID);
	boost::unordered_map<int, M_RechangeCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_RechangeCFG* GetSingleton();
private:
	boost::unordered_map<int, M_RechangeCFGData> mMapData;
};

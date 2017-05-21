#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_GiftCFGData
{
	//����ID
	int mGiftId;
	//�������
	int mCoin;
	//�Ƿ���ʾ
	int misShow;
	//���(������)
	float mPercent;
	//����VIP�ȼ�
	int mVip;
	//���ŵĶ���
	std::string mAction;
	//��Ʒ����������
	std::string mTextIcon;
};

class M_GiftCFG
{
public:
private:
	static std::auto_ptr<M_GiftCFG> msSingleton;
public:
	int GetCount();
	const M_GiftCFGData* GetData(int GiftId);
	boost::unordered_map<int, M_GiftCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_GiftCFG* GetSingleton();
private:
	boost::unordered_map<int, M_GiftCFGData> mMapData;
};

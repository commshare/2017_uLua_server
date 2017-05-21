#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_FishRoomCFGData
{
	//����id
	int mRoomID;
	//������
	std::string mRoomName;
	//����ͼƬ
	std::string mRoomImage;
	//��������
	std::string mArmatureName;
	//����·��
	std::string mArmaturePath;
	//�������
	int mGoldCondition;
	//vip����
	int mVipCondition;
	//��ȯ����
	int mTicketCondition;
	//�ȼ�����
	int mLevelCondition;
	//��ͱ���
	int mMinRate;
	//�����
	int mMaxRate;
	//�л����ʵ�λ
	int mStepRate;
	//������
	int mTableCount;
	//�Ƿ񿪷�
	bool mIsOpen;
	//����ϵ��
	int mPowerParam;
	//������������
	int mBuyPowerCost;
	//��������
	int mMissileCost;
	//��������
	bool mOpenProtect;
	//�ܻ�ȡ����
	bool mCanGetExp;
	//��鱶��
	bool mCheckOpenRate;
	//��ѵ���
	bool mFreeItem;
};

class M_FishRoomCFG
{
public:
private:
	static std::auto_ptr<M_FishRoomCFG> msSingleton;
public:
	int GetCount();
	const M_FishRoomCFGData* GetData(int RoomID);
	boost::unordered_map<int, M_FishRoomCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_FishRoomCFG* GetSingleton();
private:
	boost::unordered_map<int, M_FishRoomCFGData> mMapData;
};

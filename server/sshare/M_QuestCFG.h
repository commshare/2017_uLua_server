#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_QuestCFGData
{
	//����ID
	int mID;
	//����
	std::string mName;
	//����
	std::string mDesc;
	//����ICON1
	std::string mIcon1;
	//����ICON2
	std::string mIcon2;
	//�߿�
	std::string mFrame;
	//��ʼ��
	bool mDefault;
	//����
	int mClass;
	//����
	int mType;
	//�����������
	int mCompleteType;
	//��ɼ���
	int mCompleteCount;
	//�������
	int mCompleteParam;
	//��������id
	int mNextQuestID;
	//�Ƿ�������
	bool mIsSaveCount;
	//������ƷID
	std::vector<int> mAwardItemIDs;
	//������Ʒ����
	std::vector<int> mAwardItemCounts;
	//�����Ƿ�����(�����ۼ�)
	bool mIsSet;
	//�Ƿ���ǰ��
	int mGoTo;
};

class M_QuestCFG
{
public:
private:
	static std::auto_ptr<M_QuestCFG> msSingleton;
public:
	int GetCount();
	const M_QuestCFGData* GetData(int ID);
	boost::unordered_map<int, M_QuestCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_QuestCFG* GetSingleton();
private:
	boost::unordered_map<int, M_QuestCFGData> mMapData;
};

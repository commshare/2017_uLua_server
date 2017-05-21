#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_GameCFGData
{
	//key
	int mID;
	//��Ϸ����
	std::string mGameName;
	//��Ϸ·��
	std::string mGamePrefix;
	//���µ�ַ
	std::string mUpdateUrl;
	//�Ƿ񿪷�
	bool mIsOpen;
	//��Ϸ��С
	std::string mGameSize;
	//zip�汾
	std::string mZipVersion;
	//��������
	std::string mAnimationName;
	//ͼƬ����
	std::string mPictureName;
	//�Ƿ���ʾ
	bool mIsShow;
	//��ʾ���
	int mShowIndex;
	//������Ҫ��
	int mEnterGold;
	//����VIP
	int mEnterVIP;
};

class M_GameCFG
{
public:
private:
	static std::auto_ptr<M_GameCFG> msSingleton;
public:
	int GetCount();
	const M_GameCFGData* GetData(int ID);
	boost::unordered_map<int, M_GameCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_GameCFG* GetSingleton();
private:
	boost::unordered_map<int, M_GameCFGData> mMapData;
};

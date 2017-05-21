#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_ThirdPluginCFGData
{
	//������
	std::string mChannelID;
	//ƽ̨
	std::string mPlatform;
	//�ű�·��
	std::string mLuaFilePath;
	//��ע
	std::string mRemark;
};

class M_ThirdPluginCFG
{
public:
private:
	static std::auto_ptr<M_ThirdPluginCFG> msSingleton;
public:
	int GetCount();
	const M_ThirdPluginCFGData* GetData(std::string ChannelID);
	boost::unordered_map<std::string, M_ThirdPluginCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_ThirdPluginCFG* GetSingleton();
private:
	boost::unordered_map<std::string, M_ThirdPluginCFGData> mMapData;
};

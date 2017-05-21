#pragma once
#include <boost/unordered_map.hpp>
#include <vector>
struct M_RecordCFGData
{
	//ͳ��ID
	int mRecordID;
	//��¼����
	std::string mRecordName;
	//��¼��Ϣ�б�
	std::vector<std::string> mRecordInfoList;
};

class M_RecordCFG
{
public:
private:
	static std::auto_ptr<M_RecordCFG> msSingleton;
public:
	int GetCount();
	const M_RecordCFGData* GetData(int RecordID);
	boost::unordered_map<int, M_RecordCFGData>& GetMapData();
	void Reload();
	void Reload(const std::string& path);
	void Load(const std::string& path);
	void Load();
	static M_RecordCFG* GetSingleton();
private:
	boost::unordered_map<int, M_RecordCFGData> mMapData;
};

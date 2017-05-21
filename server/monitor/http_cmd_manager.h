#pragma once
#include "enable_singleton.h"
#include "enable_queue.h"

/*
		����ͨ��http������������
*/
class HttpCmdManager : public enable_singleton<HttpCmdManager>
{
	enum
	{
		// �������
		max_count = 1000,

		// ÿ֡��������
		process_count_each_frame = 20,
	};
public:
	bool addCommand(const std::string& cmd);

	// ����������Ϣ
	void heartbeat(double elapsed);
private:
	fast_safe_queue<std::string> m_cmdList;
};



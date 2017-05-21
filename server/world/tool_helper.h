#pragma once

class ToolHelper
{
public:
	static bool parseTime(const std::string* strStart, const std::string* strEnd, 
		time_t* outStartTime, time_t* outEndTime, bool emtpyValid = true);

	static bool parseTime(const std::string* strTime, time_t* outTime, bool emtpyValid = true);

	// ����ʱ���ж��Ƿ�ͬһ���
	static bool isSameActivity(time_t oldStartTime, time_t oldEndTime, time_t newStartTime, time_t newEndTime);

	// �������ӵļ��ܵ�
	static int getAddSkillPoint(time_t startT, time_t curT, int interval);
};

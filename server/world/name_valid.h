#pragma once
#include <string>

// ���ƵĺϷ����ж�
class NameValid
{
public:
	/*
			str�Ƿ�Ϸ����������Ϊutf-8
			errorRet	�Ƿ�ʱ�ķ���ֵ��
			�ɹ�����e_rmt_success
	*/
	static int isValid(const std::string& str, int errorRet);
};


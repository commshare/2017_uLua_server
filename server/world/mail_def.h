#pragma once
#include "gift_def.h"

struct stMail
{
	// ������
	int32_t m_senderId;
	// �ʼ�ID
	std::string m_mailId;
	// ����ʱ��
	time_t m_time;
	// ����
	std::string m_title;
	// ������
	std::string m_sender;
	// ����
	std::string m_content;
	// �Ƿ�����ȡ����
	bool m_isRecvive;
	// �����б�
	std::vector<stGift> m_items;
};

#pragma once
#include "game_sys_def.h"

class game_player;

// ������
class SafeDepositBoxMgr : public enable_obj_pool<SafeDepositBoxMgr>, public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_safe_deposit_box);

	MAKE_GET_OWNER(game_player);

	virtual void init_sys_object();	

	/*
			��������
			ֻ�е�����Ϊ��ʱ���������ã�����Ϊ�޸�����
			����ֵ����ֵ e_msg_result_def����
	*/
	int setPassword(const std::string& pwd1, const std::string& pwd2);

	/*
			������
			����ֵ����ֵ e_msg_result_def����
	*/
	int depositGold(GOLD_TYPE gold, const std::string& pwd);

	/*
			ȡ�����
			����ֵ����ֵ e_msg_result_def����
	*/
	int drawGold(GOLD_TYPE gold, const std::string& pwd);

	/*
			���ñ���������
			oldPwd		������
			pwd1		�����������1
			pwd2		�����������2
			����ֵ����ֵ e_msg_result_def����
	*/
	int resetPassword(const std::string& phoneCode, const std::string& pwd1, const std::string& pwd2);

		/*
			��֤����������
			oldPwd		������
			pwd1		�����������1
			pwd2		�����������2
			����ֵ����ֵ e_msg_result_def����
	*/
	int checkPassword(const std::string& pwd);

	/*
			�޸ı���������
			oldPwd		������
			pwd1		�����������1
			pwd2		�����������2
			����ֵ����ֵ e_msg_result_def����
	*/
	int modifyPassword(const std::string& oldPwd, const std::string& pwd1, const std::string& pwd2);

	/*
			�����������Ƿ�Ϊ��
	*/
	bool isPasswordEmpty();
private:
	int _checkOp(const std::string& pwd);

	int _setPassword(const std::string& pwd1, const std::string& pwd2);
public:
	// ����������
	GStringFieldPtr m_password;

	// ����Ľ������
	Tfield<GOLD_TYPE>::TFieldPtr m_gold;
};


#pragma once
#include "game_sys_def.h"
struct stUserBindInfo;

// �ֻ���ϵͳ
class MobilePhoneBindingSys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_mobile_phone_binding);

	MobilePhoneBindingSys();

	virtual void sys_update(double delta);

	virtual void sys_exit();

	/*
			�����ֻ���
	*/
	int reqBindPhone(game_player* player, const std::string& phone, time_t curTime);

	/*
			�����ֻ�������֤
	*/
	int reqVerifyCode(game_player* player, const std::string& code, time_t curTime);

	//��������֤��
	int reqReliveVerify(game_player* player);
	//�������ֻ�
	int reqRelivePhone(game_player* player, const std::string& code);

	/*
			��ȡ�޸ı������������֤��
	*/
	int getSafeBoxSecurityCode(game_player* player, time_t curTime);

	/*
			������֤��������
	*/
	int reqVerifySafeBoxSecurityCode(game_player* player, const std::string& code);

#ifdef _DEBUG
	std::string getCode(int playerId);
#endif
private:
	// ������֤��
	//void _sendCode();

	void _sendphone(game_player* player);

	void _send(stUserBindInfo& userInfo);

	bool _isBindPhone(game_player* player, const std::string& phone);

	//�Ѿ��󶨹�5���˺�
	bool _bindAccountLimit(const std::string& phone);

	// ����6λ���������֤��
	std::string _genIdentifyingCode();
private:
	// �Ƿ������߳�
	//bool m_run;
	// ������֤�������
	//fast_safe_queue<stUserBindInfo> m_sendQue;
	// �����߳�
	//boost::thread m_work;

	ENABLE_MAP<int, stUserBindInfo> m_user;

	ENABLE_MAP<int, stUserBindInfo> m_safeBoxUser;

	// һ�����󶨴���
	int m_maxBindCount;
	// ��֤�����Ч��
	int m_expiryDate;
};

// �������Ϣ
struct stUserBindInfo
{
	// ��֤��
	std::string m_idCode;

	// ��֤������ʱ��
	time_t m_genTime;

	// ������
	int m_retCode;

	// �ֻ���
	std::string m_phone;

	int m_codeType;
};


#pragma once
#include "game_sys_def.h"
#include "mail_def.h"

class game_player;

// �ʼ�ϵͳ
class MailSys : public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_mail);

	/*
			����ҷ����ʼ�
			title   �ʼ�����
			sender  ����������
			content �ı�����
			senderId	������ID
			durationDay		�ʼ���Ч����, 0��ʾû��ʱ������
			items   ���ʼ���������Ϣ�����룬�����ÿա�
			mailId ����һ���ʼ�ID
			����ֵ�μ� e_msg_result_def����
	*/
	int sendMail(const std::string& title, const std::string& sender, const std::string& content, int senderId, int toPlayerId, int durationDay, std::vector<stGift>* items = NULL, std::string *mailId = NULL
		,int needCoin = 0);
	
	/*
			��ȡ�ʼ�����������
			player ���
			mailId �ʼ�ID
			resItems   ����Ҫ��������ȡ�ĵ��ߣ������������
			����ֵ�μ� e_msg_result_def����
	*/
	int receiveGift(game_player* player, const std::string& mailId, std::vector<stGift>* resGifts = NULL);
	
	/*
			ɾ��ĳ���ʼ�
			����ֵ�μ� e_msg_result_def����
	*/
	int removeMail(game_player* player, const std::string& mailId);
	
	/*
			��ȡ����ʼ�
			t   ��ʱ�� > t���ʼ�
			Last �������һ���ʼ��ķ���ʱ��
			res �����ʼ����
			����ֵ�μ� e_msg_result_def����
	*/
	int getMail(game_player* player, std::vector<stMail>& res, time_t t, time_t* Last = NULL);

	/*
			����һ���ʼ�
			��mailResult���ؽ��
	*/
	int buildMail(const std::string& title, const std::string& sender, const std::string& content, int senderId, int toPlayerId, int durationDay, mongo::BSONObj& mailResult, 
		std::vector<stGift>* items = NULL, std::string *mailId = NULL,int needCoin = 0);

	/*
			���������ʼ�
	*/
	int sendMail(std::vector<mongo::BSONObj>& mailList);

	/*
			��������
			player		������
			����ֵ�μ� e_msg_result_def����
	*/
	int sendGift(game_player* player, const std::string& title, int toPlayerId, int durationDay, std::vector<stGift>& gifts, std::string *mailId = NULL);
};


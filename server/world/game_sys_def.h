#pragma once
#include <enable_smart_ptr.h>
#include <game_sys_base.h>

#include <game_object.h>
#include <game_object_field.h>
#include <game_object_map.h>
#include <game_object_array.h>

enum e_game_sys_type
{
	e_gst_none = 0,
	e_gst_recharge,			//��ֵ	
	e_gst_chat,				//����
	e_gst_mail,             //�ʼ�
	e_gst_dial_lottery,     //ת�̳齱
	e_gst_rank,             //����
	e_gst_exchange,         //�һ�
	e_gst_bag,				//����
	e_gst_shop,				//�̳�
	e_gst_friend,			//����
	e_gst_online_reward,	//���߽���
	e_gst_safe_deposit_box,	//������
	e_gst_id_generator,	    //id������
	e_gst_benefits_sys,		//�ȼý�
	e_gst_pump,				//ͳ��ϵͳ
	e_gst_notice,			//����
	e_gst_mobile_phone_binding, //�ֻ���
	e_gst_player_log,           //�����־
	e_gst_gm,                   //��̨ϵͳ
	e_gst_daily_box_lottery,    //ÿ�ձ���齱
	e_gst_operation_activity,   //�
	e_gst_speaker,			    //С����
	e_gst_robots,					//������
	e_gst_quest,				//����ɾ�
	e_gst_star_lottery,			//���ǳ齱
	e_gst_order_sys,			//����ϵͳ
};

class game_player;
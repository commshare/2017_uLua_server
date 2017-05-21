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
	e_gst_vip,			//vip
	e_gst_sign,			//ǩ��
	e_gst_bag,			//����
	e_gst_battle,		//ս��
	e_gst_hero,			//Ӣ��
	e_gst_lottery,		//�齱
	e_gst_mail,			//�ʼ�
	e_gst_quest,		//����
	e_gst_shop,			//�̵�
	e_gst_snatch,		//����
	e_gst_arena,		//������
	e_gst_expedition,   //Զ��

	e_gst_count
};

class game_player;
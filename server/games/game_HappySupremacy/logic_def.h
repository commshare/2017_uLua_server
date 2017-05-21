#pragma once

#include <enable_smart_ptr.h>
#include <enable_object_pool.h>
#include <enable_hashmap.h>

#include <game_object.h>
#include <game_object_field.h>
#include <game_object_map.h>
#include <game_object_array.h>


class logic_room;
class logic_player;
class logic_lobby;

typedef boost::shared_ptr<logic_room> LRoomPtr;
typedef boost::shared_ptr<logic_player> LPlayerPtr;

typedef std::map<uint16_t, LRoomPtr> LROOM_MAP;
typedef std::map<uint32_t, LPlayerPtr> LPLAYER_MAP;

#define SAFE_DELETE(v) if(v != nullptr){delete v; v = nullptr;}

//0������:1��˳�ǣ�2������,3:˳���ţ��ǣ�,4:�����ţ��ǣ�,5:˳���ţ��ţ����ţ�
static const int MAX_BET_COUNT = 6;//Ѻע������
//ÿ�˷�2����
const int EVERYONE_CARDCOUNT=2;
//��������Ϊ8
const int SENDCARD_COUNT=8;
//�Ƶ�����Ϊ32
const int CARD_MAX_COUNT =32;

#ifndef _DEBUG
#define NDEBUG
#endif
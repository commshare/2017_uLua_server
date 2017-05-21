// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� GAME_HAPPYSUPREMACY_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// GAME_FISHLORD_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#pragma once

#ifdef GAME_HAPPYSUPREMACY_EXPORTS
#define GAME_HAPPYSUPREMACY_API __declspec(dllexport)
#else
#define GAME_HAPPYSUPREMACY_API __declspec(dllimport)
#endif

#include "game_engine.h"
#include "net/packet_manager.h"

extern "C" {

	GAME_HAPPYSUPREMACY_API void* get_game_engine();

	GAME_HAPPYSUPREMACY_API void* get_packet_mgr();
}
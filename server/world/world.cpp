// world.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "world_server.h"

int _tmain(int argc, _TCHAR* argv[])
{
	world_server::instance().s_init(argc, argv);

	return 0;
}


// gate.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "gate_server.h"

int _tmain(int argc, _TCHAR* argv[])
{
	gate_server::instance().s_init(argc, argv);
	return 0;
}


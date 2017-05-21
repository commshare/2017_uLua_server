#pragma once
#ifdef CLIENT
#include "CocosHead.h"
#else
#include "logic_pos.h"
#endif

#include <list>
#include "BaseGenerator.h"
#include "FishCommonHead.h"

class BaseRoute;
//��������
class GeneratorMgr
{
public:
	GeneratorMgr();
	virtual ~GeneratorMgr();

	//������
	virtual void createFish(int fishID, int fishCfgID, RoutePtr baseRoute) = 0;

	static BaseGenerator* buildGenerator(int generatorID, int routeID, GeneratorMgr* generatorMgr);
	static void deleteGenerator(BaseGenerator* generator);
};
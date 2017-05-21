#pragma once
#include "BaseGenerator.h"

struct Fish_GeneratorCFGData;

//��������
class CircleGenerator : public BaseGenerator
{
public:
	CircleGenerator(const Fish_GeneratorCFGData* generatorCFGdata, GeneratorMgr* generatorMgr);
	virtual ~CircleGenerator();
protected:
	virtual void update(float dt);
protected:
	int mRadius;

	int mFishCfgID;
	//ÿȦ������
	int mCircleFishCount;

	int mRedFishIndex;
	int mRedFishID;

	int mRouteID;
	Vec2 mSpeed;
};
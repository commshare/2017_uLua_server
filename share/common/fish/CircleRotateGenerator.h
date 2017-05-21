#pragma once
#include "BaseGenerator.h"

struct Fish_GeneratorCFGData;

//��������
class CircleRotateGenerator : public BaseGenerator
{
public:
	CircleRotateGenerator(const Fish_GeneratorCFGData* generatorCFGdata, GeneratorMgr* generatorMgr);
	virtual ~CircleRotateGenerator();
protected:
	virtual void update(float dt);
protected:
	int mRadius;

	int mFishCfgID;
	//ÿȦ������
	int mCircleFishCount;

	int mRedFishIndex;
	int mRedFishID;

	float mRotation;
	float mRotateTime;
	float mMoveSpeed;
};
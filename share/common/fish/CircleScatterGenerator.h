#pragma once
#include "BaseGenerator.h"

struct Fish_GeneratorCFGData;

//��������
class CircleScatterGenerator : public BaseGenerator
{
public:
	CircleScatterGenerator(const Fish_GeneratorCFGData* generatorCFGdata, GeneratorMgr* generatorMgr);
	virtual ~CircleScatterGenerator();
protected:
	virtual void update(float dt);
protected:
	int mRadius;

	int mFishCfgID;
	//ÿȦ������
	int mCircleFishCount;

	int mRedFishIndex;
	int mRedFishID;
	//�ƶ��ٶ�
	float mMoveSpeed;
};
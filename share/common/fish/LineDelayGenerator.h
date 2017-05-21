#pragma once
#include "BaseGenerator.h"

struct Fish_GeneratorCFGData;

//��������
class LineDelayGenerator : public BaseGenerator
{
public:
	LineDelayGenerator(const Fish_GeneratorCFGData* generatorCFGdata, GeneratorMgr* generatorMgr);
	virtual ~LineDelayGenerator();
protected:
	virtual void update(float dt);
protected:
	float mElapsed;

	Vec2 mStartPosition;
	Vec2 mEndPosition;

	int mBlockCount;
	int mFishCfgID;
	//ÿ��������
	int mLineFishCount;

	Vec2 mSpeed;

	float mDelayTime;
	float mMoveTime;
	float mWaitTime;
};
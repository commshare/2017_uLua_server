#pragma once
#ifdef CLIENT
#include "CocosHead.h"
#else
#include "logic_pos.h"
#endif
#include "FishCommonHead.h"
#include "enable_random.h"

struct RoutePoint
{
	float mSpeed;			//�ٶ�
	float mRatotion;		//�Ƕ�
	float mGradient;		//����ʱ��
	float mDuration;		//����ʱ��
};

enum RouteType
{
	RouteType_Base = 1,
	RouteType_Advanced,
	RouteType_Rotate,
	RouteType_Special,
	RouteType_Offset,
};

//·����
class BaseRoute
{
public:
	BaseRoute(const Vec2& pos, const Vec2& speed);
	virtual ~BaseRoute();

	void updateTime(float dt);
	void setSimTime(float simTime);

	const Vec2& getPosition() const;
	float getRotation() const;
	bool isEnd() const;
	//�Լ��ж�λ���Ƿ����
	virtual bool canAutoEnd();	

	float getLifeTime();
	void setLifeTime(float lifeTime);

	//��ʼ������
	void pushRouteParam(int param);
	void pushRouteParam(const Vec2& pos);
	const std::vector<int32_t>& getRouteParam();
	float getElapsedTime();
	void setElapsedTime(float elapsedTime);
protected:
	BaseRoute();
	virtual void update(float dt);
protected:
	bool mIsEnd;
	Vec2 mPosition;
	Vec2 mSpeed;
	float mRotation;

	float mLifeTime;
	float mSimTime;		//ģ��ʱ��

	std::vector<int32_t> mRouteParam;
	float mElapsedTime;
};

struct RouteData;
class AdvancedRoute : public BaseRoute
{
public:
	AdvancedRoute(const RouteData* routeData);
	virtual ~AdvancedRoute();

	float getCurSpeed();
	float getDuration();
	virtual bool canAutoEnd();	
protected:
	virtual void update(float dt);
	void setRoutePoint(unsigned int pointIndex);
protected:
	//Ŀǰ�ٶ�
	float mCurSpeed;
	float mCurRotation;
	//���ٶ�
	float mAccSpeed;
	float mAccRotation;

	//����ʱ��
	float mGradientTime;
	//����ʱ��
	float mDuration;

	unsigned int mPointIndex;
	const RouteData* mRouteData;
};

class CustomRoute : public BaseRoute
{
public:
	CustomRoute();
	virtual ~CustomRoute();

	void init(const Vec2& pos, float rotation, float speed);
	void addRoutePoint(const RoutePoint& routePoint);

	void setRoutePoint(unsigned int pointIndex);

	float getCurSpeed();
	float getDuration();
	virtual bool canAutoEnd();
protected:
	virtual void update(float dt);
	void getNextRoutePoint();
protected:
	//Ŀǰ�ٶ�
	float mCurSpeed;
	float mCurRotation;
	//���ٶ�
	float mAccSpeed;
	float mAccRotation;

	//����ʱ��
	float mGradientTime;
	//����ʱ��
	float mDuration;

	int mPointIndex;
	std::vector<RoutePoint> mRoutePoints;
};

class OffsetRoute : public BaseRoute
{
public:
	OffsetRoute(const RouteData* routeData, const Vec2& initOffset, int randOffset, int randSeed);
	virtual ~OffsetRoute();

	virtual bool canAutoEnd();
protected:
	virtual void update(float dt);
	void resetRandOffset();
	void setState(int state);
private:
	AdvancedRoute* mRoute;

	Vec2 mCurOffset;
	Vec2 mNextOffset;
	//Vec2 mDirection;
	int mOffset;

	float mMoveDistance;
	float mDistance;
	//����ʱ��
	float mAccTime;
	int mState;

	enable_random<boost::rand48> m_random;
};
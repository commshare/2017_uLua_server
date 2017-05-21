#pragma once
#include "Route.h"

//·����������
struct RouteData
{
public:
	RouteData();
	~RouteData();

	void clearUp();

	int getRouteID() const;
	void setRouteID(int routeID);

	void setStartPos(float posX, float posY);
	void setStartPosX(float posX);
	void setStartPosY(float posY);
	float getStartPosX() const;
	float getStartPosY() const;

	unsigned int getRoutePointSize() const;
	const RoutePoint& getRoutePoint(unsigned int index) const;
	void addRoutePoint(RoutePoint& routePoint);
	void updateRoutePoint(unsigned int index, RoutePoint& routePoint);

	void setLifeTime(float lifeTime);
	float getLifeTime() const;
protected:
	int mRouteID;

	//��ʼλ��
	float mStartPosX;	
	float mStartPosY;

	//·����
	std::vector<RoutePoint> mRoutePoints;

	float mLifeTime;

	static RoutePoint msEmptyRoutePoint;
};
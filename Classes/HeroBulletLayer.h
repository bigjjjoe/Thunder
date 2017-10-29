#pragma once
#ifndef __HeroBulletLayer_H__
#define __HeroBulletLayer_H__
#include "cocos2d.h"
#include "BulletStyle.h"
#include "HeroBulletOne.h"
#include "HeroBulletTwo.h"
#include "HeroBulletThree.h"
USING_NS_CC;
//定义子弹类型编号
enum BULLET_TAG{
	One_Bullet=1,
	Two_Bullet=2,
	Three_Bullet=3,
};
class HeroBulletLayer : public cocos2d::Layer
{
public:
	HeroBulletLayer(Node* heroPlane);
	virtual bool init();

	//根据英雄飞机创建子弹
	static HeroBulletLayer* create(Node* heroPlane);


	//改变子弹
	bool changeBullet(int bulletNumber);
public:

	Node* heroPlane;//传入的英雄飞机
	BulletStyle *mBulletStyle;//子弹类型
	int bulletNumber;//当前子弹编号
};
#endif 
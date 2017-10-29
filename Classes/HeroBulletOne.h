
#pragma once
#ifndef __HeroBulletOne_H__
#define __HeroBulletOne_H__
#include "cocos2d.h"
#include "BulletStyle.h"
USING_NS_CC;
class HeroBulletOne : public BulletStyle {
public:
	virtual  void shootBullet(float dt);
};
#endif 
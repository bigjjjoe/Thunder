
#ifndef __GameMain_H__
#define __GameMain_H__
#include "BackLayerDown.h"
#include "BackLayerUp.h"
#include "HeroBulletLayer.h"
#include "cocos2d.h"

USING_NS_CC;

class GameMain : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void changeBullet(float dt);
	void update(float dt);
	CREATE_FUNC(GameMain);

	void enemyBuild1(float dt);//跟随
	void enemyBuild2(float dt);//并飞
	void enemyBuild3(float dt);//
	void enemyBuild4(float dt);//
	void enemyRemove(Node* pNode);
private:
	bool isHeroPlaneControl;//飞机是否被控制着
	float mDeltaX;//英雄飞机随手指移动时的X偏移量
	float mDeltaY;//英雄飞机随手指移动时的Y偏移量
	Sprite *mHeroPlane;//英雄飞机

	//HeroBulletLayer *mHeroBulletLayer;
	int number;

};

#endif // __GameMain_H__
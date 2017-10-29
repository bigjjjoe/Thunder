
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

	void enemyBuild1(float dt);//����
	void enemyBuild2(float dt);//����
	void enemyBuild3(float dt);//
	void enemyBuild4(float dt);//
	void enemyRemove(Node* pNode);
private:
	bool isHeroPlaneControl;//�ɻ��Ƿ񱻿�����
	float mDeltaX;//Ӣ�۷ɻ�����ָ�ƶ�ʱ��Xƫ����
	float mDeltaY;//Ӣ�۷ɻ�����ָ�ƶ�ʱ��Yƫ����
	Sprite *mHeroPlane;//Ӣ�۷ɻ�

	//HeroBulletLayer *mHeroBulletLayer;
	int number;

};

#endif // __GameMain_H__
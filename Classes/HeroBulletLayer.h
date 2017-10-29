#pragma once
#ifndef __HeroBulletLayer_H__
#define __HeroBulletLayer_H__
#include "cocos2d.h"
#include "BulletStyle.h"
#include "HeroBulletOne.h"
#include "HeroBulletTwo.h"
#include "HeroBulletThree.h"
USING_NS_CC;
//�����ӵ����ͱ��
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

	//����Ӣ�۷ɻ������ӵ�
	static HeroBulletLayer* create(Node* heroPlane);


	//�ı��ӵ�
	bool changeBullet(int bulletNumber);
public:

	Node* heroPlane;//�����Ӣ�۷ɻ�
	BulletStyle *mBulletStyle;//�ӵ�����
	int bulletNumber;//��ǰ�ӵ����
};
#endif 
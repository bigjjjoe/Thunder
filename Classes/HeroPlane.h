#pragma once
#ifndef __HeroPlane_H__
#define __HeroPlane_H__
#include "cocos2d.h"
USING_NS_CC;
class HeroPlane :public cocos2d::Layer{
private:
	HeroPlane();
public:
	/**
	*��õ���Ӣ�۷ɻ��ķ���
	*@return Ӣ�۷ɻ���
	*/
	static HeroPlane* getInstance();
	virtual bool init();
	/**
	*ȡ�õ�ǰӢ�۷ɻ��еľ���
	*@return �ɻ��о��飬ʵ�ʵĲ�������
	*/
	Sprite* getPlane();
        /**
	*�����ĸ��ֱ�Ϊ��������ʱ���¼�
	*/
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchEened(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_even);

public:
	unsigned int planeHp;//Ӣ�۷ɻ�����ֵ
	unsigned int planeScore;//Ӣ�۷ɻ�����ֵ
	unsigned int planeBulletNum;//Ӣ�۷ɻ��ӵ�����
        unsigned int planeAttack;//Ӣ�۷ɻ�����ֵ
        unsigned int planeDefend;//Ӣ�۷ɻ�����ֵ
private:
	static HeroPlane* sharePlane;//Ӣ�۷ɻ���̬����
	bool isHeroPlaneControl;//�ɻ��Ƿ񱻿�����
	float mDeltaX;//Ӣ�۷ɻ�����ָ�ƶ�ʱ��Xƫ����
	float mDeltaY;//Ӣ�۷ɻ�����ָ�ƶ�ʱ��Yƫ����
	Sprite* plane;//Ӣ�۷ɻ�

};
#endif 
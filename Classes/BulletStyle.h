#pragma once
#ifndef __BulletStyle_H__
#define __BulletStyle_H__
#include "cocos2d.h"
USING_NS_CC;

class BulletStyle : public cocos2d::Layer{
public:
	~BulletStyle();
	/**
	* �Ƴ����еĶ���
	*/
	void removeAllObject();
	/**
	*�Ƴ�������Ļ���ӷ�Χ���ӵ�������ײ����ӵ����
	*@param pNode Ҫɾ�����ӵ�
	*/
	void removeBullet(Node* pNode);
	/**
	*���ݴ���ķɻ����ӵ����淢��
	*@param planeΪ����ɻ�����ΪӢ�۷ɻ���л� 
	*/
	virtual void createBullet(Node* plane);
	/**
	*�����ӵ��������н����ӵ�����Ⱦ���ӵ��ķ��ж�����Ĭ��Ϊ���ӵ� 
	*@param dt�ӵ������ʱ��
	*/
	virtual void shootBullet(float dt){}
	
protected:
	//�ӵ�����
	  Vector <Sprite *> vecBullet;
	 //������Ⱦ�ڵ�
	  SpriteBatchNode* bulletBatchNode;
	 //����ķɻ�
	  Node* plane;
};
#endif 
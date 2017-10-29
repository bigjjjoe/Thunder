#include "HeroBulletOne.h"

void HeroBulletOne::shootBullet(float dt) {
		Size winSize = Director::getInstance()->getWinSize();
		auto PlanePos = plane->getPosition();
		//�ӻ����д����ӵ�
		auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
		//�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
		bulletBatchNode->addChild(spritebullet);
		//�������õ��ӵ���ӵ�����
		vecBullet.pushBack(spritebullet);

		Point bulletPos = (Point(PlanePos.x,
			PlanePos.y + plane->getContentSize().height / 2 + 20));
		spritebullet->setPosition(bulletPos);
		spritebullet->setScale(0.8f);

	    float flyVelocity = 500;//�����ٶȣ������Լ����ƣ�ÿ�����ߵ�����
		float flyLen = winSize.height - PlanePos.y;
		float realFlyDuration = flyLen / flyVelocity;//ʵ�ʷ��е�ʱ��

		//�ӵ����еľ����ʱ�䣬�ӷɻ�����ʼ���е���Ļ����
		auto actionMove = MoveTo::create(realFlyDuration,
			Point(bulletPos.x, winSize.height));

		//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(HeroBulletOne::removeBullet, this));

		//�ӵ���ʼ�ܶ�
		Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
		spritebullet->runAction(sequence);


	}

//void HeroBulletOne::createBullet(Node* plane) {
//	    this->plane = plane;
//	  	//����BatchNode�ڵ�
//		bulletBatchNode = SpriteBatchNode::create("bullet1.png");
//		this->addChild(bulletBatchNode);
//		//ÿ��0.2S����һ�η����ӵ�����
//		schedule(schedule_selector(HeroBulletOne::shootBullet), 0.2f);
//	}




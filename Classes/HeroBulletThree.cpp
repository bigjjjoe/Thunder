#include "HeroBulletThree.h"

void HeroBulletThree::shootBullet(float dt) {
		Size winSize = Director::getInstance()->getWinSize();
		auto PlanePos = plane->getPosition();
		double angle = M_PI * 80 / 180;//���D�ĽǶ�
		//�ӻ����д����ӵ�
		auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
		auto spritebullet1 = Sprite::createWithTexture(bulletBatchNode->getTexture());
		spritebullet1->setRotation(-angle);
		auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode->getTexture());
		spritebullet2->setRotation(angle);
		//�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
		bulletBatchNode->addChild(spritebullet);
		bulletBatchNode->addChild(spritebullet1);
		bulletBatchNode->addChild(spritebullet2);
		//�������õ��ӵ���ӵ�����
		vecBullet.pushBack(spritebullet);
		vecBullet.pushBack(spritebullet1);
		vecBullet.pushBack(spritebullet2);

		Point bulletPos = (Point(PlanePos.x,
			PlanePos.y + plane->getContentSize().height / 2 + 20));


		Point bulletPos1 = (Point(PlanePos.x - plane->getContentSize().width / 4-10,
			PlanePos.y + plane->getContentSize().height / 2+10 ));

		Point bulletPos2 = (Point(PlanePos.x + plane->getContentSize().width / 4+10,
			PlanePos.y + plane->getContentSize().height / 2+10));

		spritebullet->setPosition(bulletPos);
		spritebullet->setScale(0.8f);

		spritebullet1->setPosition(bulletPos1);
		spritebullet1->setScale(0.8f);

		spritebullet2->setPosition(bulletPos2);
		spritebullet2->setScale(0.8f);


	    float flyVelocity = 500;//�����ٶȣ������Լ����ƣ�ÿ�����ߵ�����

		float flyLen = winSize.height - PlanePos.y;
		float flyLen1 = PlanePos.x / cos(angle);//���նȁ���
		float flyLen2 = (winSize.width - PlanePos.x) / cos(angle);

		float realFlyDuration = flyLen / flyVelocity;//ʵ�ʷ��е�ʱ��
		float realFlyDuration1 = flyLen1 / flyVelocity;//ʵ�ʷ��е�ʱ��
		float realFlyDuration2 = flyLen2 / flyVelocity;//ʵ�ʷ��е�ʱ��

		//�ӵ����еľ����ʱ�䣬�ӷɻ�����ʼ���е���Ļ����
		auto actionMove = MoveTo::create(realFlyDuration,
			Point(bulletPos.x, winSize.height));

		auto actionMove1 = MoveTo::create(realFlyDuration1,
			Point(0, PlanePos.x*tan(angle) + PlanePos.y));

		auto actionMove2 = MoveTo::create(realFlyDuration2,
			Point(winSize.width, (winSize.width - PlanePos.x)*tan(angle) + PlanePos.y));

		//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(HeroBulletThree::removeBullet, this));

		//�ӵ���ʼ�ܶ�
		Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
		spritebullet->runAction(sequence);

		Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
		spritebullet1->runAction(sequence1);

		Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
		spritebullet2->runAction(sequence2);


	}






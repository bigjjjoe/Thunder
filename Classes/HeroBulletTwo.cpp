
#include "HeroBulletTwo.h"

void HeroBulletTwo::shootBullet(float dt) {
		Size winSize = Director::getInstance()->getWinSize();
		auto PlanePos = plane->getPosition();
		//�ӻ����д����ӵ�
		auto spritebullet1 = Sprite::createWithTexture(bulletBatchNode->getTexture());
		auto spritebullet2 = Sprite::createWithTexture(bulletBatchNode->getTexture());


		//�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
		bulletBatchNode->addChild(spritebullet1);
		bulletBatchNode->addChild(spritebullet2);
		//�������õ��ӵ���ӵ�����
		vecBullet.pushBack(spritebullet1);
		vecBullet.pushBack(spritebullet2);

		Point bulletPos1 = (Point(PlanePos.x - plane->getContentSize().width / 4,
			PlanePos.y + plane->getContentSize().height / 2+10 ));

		Point bulletPos2 = (Point(PlanePos.x + plane->getContentSize().width / 4,
			PlanePos.y + plane->getContentSize().height / 2+10));

		spritebullet1->setPosition(bulletPos1);
		spritebullet1->setScale(0.8f);

		spritebullet2->setPosition(bulletPos2);
		spritebullet2->setScale(0.8f);

	    float flyVelocity = 500;//�����ٶȣ������Լ����ƣ�ÿ�����ߵ�����
		float flyLen = winSize.height - PlanePos.y;
		float realFlyDuration = flyLen / flyVelocity;//ʵ�ʷ��е�ʱ��


		//�ӵ����еľ����ʱ�䣬�ӷɻ�����ʼ���е���Ļ����
		auto actionMove1 = MoveTo::create(realFlyDuration,
			Point(bulletPos1.x, winSize.height));

		auto actionMove2 = MoveTo::create(realFlyDuration,
			Point(bulletPos2.x, winSize.height));

		//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
		auto actionDone = CallFuncN::create(
			CC_CALLBACK_1(HeroBulletTwo::removeBullet, this));

		//�ӵ���ʼ�ܶ�
		Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
		spritebullet1->runAction(sequence1);

		Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
		spritebullet2->runAction(sequence2);


	}






#include "GameMain.h"
#include"HeroPlane.h"
USING_NS_CC;
Scene* GameMain::createScene()
{
	auto scene = Scene::create();
	auto layer = GameMain::create();
	scene->addChild(layer);
	return scene;
}

bool GameMain::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	//���ǵ���ͼ��
	this->addChild(BackLayerUp::create());
	//���ǰ���ͼ��
	this->addChild(BackLayerDown::create());


	HeroPlane *heroPlane = HeroPlane::getInstance();
	this->addChild(heroPlane);



	scheduleUpdate();
	//ÿ��0.5S����һ��
	schedule(schedule_selector(GameMain::enemyBuild1), 0.5f);
	//ÿ��3S����һ��
	schedule(schedule_selector(GameMain::enemyBuild2), 3.0f);
	//ÿ��0.5S����һ��
	schedule(schedule_selector(GameMain::enemyBuild3), 0.5f);

	//ÿ��0.5����һ��
	schedule(schedule_selector(GameMain::enemyBuild4), 0.5f);
	return true;
}



void GameMain::update(float dt) {
	//auto *mEnemyPlane = getChildByTag(200);
	//Vector <Sprite *> mVecHeroBullet = mHeroBulletLayer->GetBullet();
	//for (int i = 0; i<mVecHeroBullet.size();i++){
	//	if (mEnemyPlane->boundingBox().intersectsRect(mVecHeroBullet.at(i)->boundingBox())){
	//		mHeroBulletLayer->removeBullet(mVecHeroBullet.at(i));
	//	}

	//}

}
//void GameMain::changeBullet(float dt) {
//	if (number == 1) {
//		mHeroBulletLayer->changeBullet(2);
//		number = 2;
//	}
//	else if (number == 2) {
//		mHeroBulletLayer->changeBullet(3);
//		number = 3;
//	}
//	else if (number == 3)
//	{
//		mHeroBulletLayer->changeBullet(1);
//		number = 1;
//	}
//
//}

void GameMain::enemyBuild1(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto spritePlane = Sprite::create("air3.png");
	spritePlane->setRotation(90);
	spritePlane->setPosition(Vec2(0, 400));
	spritePlane->setScale(0.25);
	this->addChild(spritePlane);

	//���ñ��������߲���
	ccBezierConfig tr0;
	tr0.endPosition = Vec2(0, 10);//�յ�
	tr0.controlPoint_1 = Vec2(250, 300);//���Ƶ�1
	tr0.controlPoint_2 = Vec2(180, 150);//���Ƶ�2


	ActionInterval* bezierForward = BezierTo::create(3.f, tr0);//�������еı���������
	ActionInterval *forwardBy = RotateBy::create(3.f, 180);     // �ڶ����������������������˳ʱ�룬������ʱ�� 
	Spawn* spawn = Spawn::create(bezierForward, forwardBy, NULL);//�����ϳɶ���

																 //�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(GameMain::enemyRemove, this));

	//��������
	Sequence* sequence = Sequence::create(spawn, actionDone, NULL);
	spritePlane->runAction(sequence);

}
void GameMain::enemyBuild2(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//���ɾ���
	auto spritePlane1 = Sprite::create("air4.png");
	auto spritePlane2 = Sprite::create("air4.png");
	auto spritePlane3 = Sprite::create("air4.png");
	//�õ������͸�
	float height = spritePlane1->getContentSize().height;
	float width = spritePlane1->getContentSize().width;

	//��ת�ĽǶ�
	spritePlane1->setRotation(180);
	spritePlane2->setRotation(180);
	spritePlane3->setRotation(180);

	//��������
	//spritePlane1->setScale(0.3);
	//spritePlane2->setScale(0.3);
	//spritePlane3->setScale(0.3);

	//����λ��
	spritePlane1->setPosition(Vec2(width, winSize.height + height));
	spritePlane2->setPosition(Vec2(winSize.width / 2, winSize.height - height));
	spritePlane3->setPosition(Vec2(winSize.width - width, winSize.height + height));


	//���м��뾫��
	this->addChild(spritePlane1);
	this->addChild(spritePlane2);
	this->addChild(spritePlane3);

	//�������ʱ��
	float flyVelocity = 200;//�����ٶȣ������Լ����ƣ�ÿ�����ߵ�����
	float flyLen = winSize.height;
	float realFlyDuration = flyLen / flyVelocity;//ʵ�ʷ��е�ʱ��

												 //�ӵ����еľ����ʱ�䣬�ӷɻ�����ʼ���е���Ļ�ײ�
	auto actionMove1 = MoveBy::create(realFlyDuration, Point(0, -winSize.height - height));
	auto actionMove2 = MoveBy::create(realFlyDuration, Point(0, -winSize.height - height));
	auto actionMove3 = MoveBy::create(realFlyDuration, Point(0, -winSize.height - height));

	////�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(GameMain::enemyRemove, this));

	//��������
	Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
	Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
	Sequence* sequence3 = Sequence::create(actionMove3, actionDone, NULL);

	//�ɻ���ʼ�ܶ�
	spritePlane1->runAction(sequence1);
	spritePlane2->runAction(sequence2);
	spritePlane3->runAction(sequence3);

}
void GameMain::enemyBuild3(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto spritePlane = Sprite::create("air2.png");
	//�õ������͸�
	float height = spritePlane->getContentSize().height;
	float width = spritePlane->getContentSize().width;
	//���õл�λ�����Ͻ�

	spritePlane->setPosition(Vec2(winSize.width + width / 2, winSize.height + height / 2));
	spritePlane->setScale(0.25);
	this->addChild(spritePlane);
	

}
void GameMain::enemyBuild4(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//������ߵл�
	auto spritePlane1 = Sprite::create("air5.png");
	auto spritePlane2 = Sprite::create("air5.png");
	auto spritePlane3 = Sprite::create("air5.png");
	//���ɱߵл�
	auto spritePlane4 = Sprite::create("air5.png");
	auto spritePlane5 = Sprite::create("air5.png");
	auto spritePlane6 = Sprite::create("air5.png");

	//��ת�ĽǶ�
	spritePlane1->setRotation(90);
	spritePlane2->setRotation(90);
	spritePlane3->setRotation(90);

	spritePlane4->setRotation(-90);
	spritePlane5->setRotation(-90);
	spritePlane6->setRotation(-90);

	//��������
	//spritePlane1->setScale(0.3);
	//spritePlane2->setScale(0.3);
	//   spritePlane3->setScale(0.3);


	//�õ������͸�
	float height = spritePlane1->getContentSize().height;
	float width = spritePlane1->getContentSize().width;

	//���õл�λ��
	spritePlane1->setPosition(Vec2(-width / 2, winSize.height - height / 2 - 10));
	spritePlane2->setPosition(Vec2(-width / 2, spritePlane1->getPosition().y - 2 * height - 10));
	spritePlane3->setPosition(Vec2(-width / 2, spritePlane2->getPosition().y - 2 * height - 10));

	spritePlane4->setPosition(Vec2(winSize.width + width / 2, spritePlane1->getPosition().y - height - 10));
	spritePlane5->setPosition(Vec2(winSize.width + width / 2, spritePlane4->getPosition().y - 2 * height - 10));
	spritePlane6->setPosition(Vec2(winSize.width + width / 2, spritePlane5->getPosition().y - 2 * height - 10));


	//���м��뾫��
	this->addChild(spritePlane1);
	this->addChild(spritePlane2);
	this->addChild(spritePlane3);
	this->addChild(spritePlane4);
	this->addChild(spritePlane5);


	//�������ʱ��
	float flyVelocity = 200;//�����ٶȣ������Լ����ƣ�ÿ�����ߵ�����
	float flyLen = winSize.width + width;
	float realFlyDuration = flyLen / flyVelocity;//ʵ�ʷ��е�ʱ��


												 //�ӵ����еľ����ʱ�䣬�ӷɻ�����ʼ���е���Ļ�ײ�
	auto actionMove1 = MoveBy::create(realFlyDuration, Point(flyLen, 0));
	auto actionMove2 = MoveBy::create(realFlyDuration, Point(-flyLen, 0));

	//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(GameMain::enemyRemove, this));
	//��������
	Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
	Sequence* sequence2 = Sequence::create(actionMove1->clone(), actionDone, NULL);
	Sequence* sequence3 = Sequence::create(actionMove1->clone(), actionDone, NULL);
	Sequence* sequence4 = Sequence::create(actionMove2, actionDone, NULL);
	Sequence* sequence5 = Sequence::create(actionMove2->clone(), actionDone, NULL);
	//�ɻ���ʼ�ܶ�
	spritePlane1->runAction(sequence1);
	spritePlane2->runAction(sequence2);
	spritePlane3->runAction(sequence3);
	spritePlane4->runAction(sequence4);
	spritePlane5->runAction(sequence5);


}

void GameMain::enemyRemove(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* plane = (Sprite*)pNode;
	this->removeChild(plane, true);
}



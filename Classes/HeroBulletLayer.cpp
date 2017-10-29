#include "HeroBulletLayer.h"
HeroBulletLayer::HeroBulletLayer(Node* heroPlane) {
	this->heroPlane = heroPlane;
	mBulletStyle = NULL;
	bulletNumber = 1;
}
/**
*�����ӵ��ľ�̬����
*@param heroPlaneΪӢ�۷ɻ�
*/
HeroBulletLayer* HeroBulletLayer::create(Node* heroPlane){
	HeroBulletLayer* pRet = new HeroBulletLayer(heroPlane);
	if (pRet&&pRet->init()){
		pRet->autorelease();
		return pRet;
	}
	else{
		delete pRet;
		pRet = NULL;
		return NULL;
	}

}
bool HeroBulletLayer::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());

		
		mBulletStyle = new HeroBulletOne();
		mBulletStyle->autorelease();
		mBulletStyle->createBullet(heroPlane);
		this->addChild(mBulletStyle);
		bRet = true;
	} while (0);
	return bRet;
}
/**
*�û���ķ��������ӵ�������ʼ���ӵ����˶����˶�����¼�
*/
//void HeroBulletLayer::shootBullet(float dt) {
	//Size winSize = Director::getInstance()->getWinSize();
	//auto PlanePos = heroPlane->getPosition();
	////�ӻ����д����ӵ�
	//auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	////�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
	//bulletBatchNode->addChild(spritebullet);
	////�������õ��ӵ���ӵ�����
	//vecBullet.pushBack(spritebullet);

	//Point bulletPos = (Point(PlanePos.x,
	//	PlanePos.y + heroPlane->getContentSize().height / 2 + 20));
	//spritebullet->setPosition(bulletPos);
	//spritebullet->setScale(0.8f);


	//float flyLen = winSize.height - PlanePos.y;
	//float realFlyDuration = flyLen / FlYVElOCITY;//ʵ�ʷ��е�ʱ��

	////�ӵ����еľ����ʱ�䣬�ӷɻ�����ʼ���е���Ļ����
	//auto actionMove = MoveTo::create(realFlyDuration,
	//	Point(bulletPos.x, winSize.height));

	////�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	//auto actionDone = CallFuncN::create(
	//	CC_CALLBACK_1(HeroBulletLayer::removeBullet, this));

	////�ӵ���ʼ�ܶ�
	//Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	//spritebullet->runAction(sequence);

	//�����ӵ�

	//Size winSize = Director::getInstance()->getWinSize();
	//auto PlanePos = heroPlane->getPosition();


	//�ӻ����д����ӵ�
	//Sprite spritebullet[2];
	//spritebullet[0] = Sprite::createWithTexture(bulletBatchNode->getTexture());
	////�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
	//bulletBatchNode->addChild(spritebullet);
	////�������õ��ӵ���ӵ�����
	//vecBullet.pushBack(spritebullet);


	//Point bulletPos = (Point(PlanePos.x,
	//	PlanePos.y + heroPlane->getContentSize().height / 2 + 20));
	//spritebullet->setPosition(bulletPos);
	//spritebullet->setScale(0.8f);


	//float flyLen = winSize.height - PlanePos.y;
	//float realFlyDuration = flyLen / FlYVElOCITY;//ʵ�ʷ��е�ʱ��

	////�ӵ����еľ����ʱ�䣬�ӷɻ�����ʼ���е���Ļ����
	//auto actionMove = MoveTo::create(realFlyDuration,
	//	Point(bulletPos.x, winSize.height));

	////�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	//auto actionDone = CallFuncN::create(
	//	CC_CALLBACK_1(HeroBulletLayer::removeBullet, this));

	////�ӵ���ʼ�ܶ�
	//Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	//spritebullet->runAction(sequence);
//}

/**
 * �Ƴ��ӵ������ӵ����������Ƴ���ͬʱҲ��SpriteBatchNode���Ƴ�
 */
//void HeroBulletLayer::removeBullet(Node* pNode) {
//	if (NULL == pNode) {
//		return;
//	}
//	Sprite* bullet = (Sprite*)pNode;
//	this->bulletBatchNode->removeChild(bullet, true);
//	vecBullet.eraseObject(bullet);
//}
/**
*�����ӵ��б�������л�����ײ���
*/
//Vector <Sprite *>& HeroBulletLayer::GetBullet(){
//	return vecBullet;
//}
bool HeroBulletLayer::changeBullet(int number){


	switch (number)
	{
	case 1:
		if (bulletNumber != 1){
			this->removeChild(mBulletStyle, true);
		mBulletStyle = new HeroBulletOne();
		bulletNumber = 1;
		mBulletStyle->createBullet(heroPlane);
		mBulletStyle->autorelease();
		this->addChild(mBulletStyle);
		}
		break;
	case 2:
		if (bulletNumber != 2){
			this->removeChild(mBulletStyle, true);
			mBulletStyle = new HeroBulletTwo();
			bulletNumber = 2;
			mBulletStyle->createBullet(heroPlane);
			mBulletStyle->autorelease();
			this->addChild(mBulletStyle);
		}
		break;
	case 3:
		if (bulletNumber != 3){
			this->removeChild(mBulletStyle, true);
			mBulletStyle = new HeroBulletThree();
			bulletNumber = 3;
			mBulletStyle->createBullet(heroPlane);
			mBulletStyle->autorelease();
			this->addChild(mBulletStyle);
		}
		break;
	default:
		break;
	}

return false;
}

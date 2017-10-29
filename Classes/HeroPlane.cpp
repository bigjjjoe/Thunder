#include"HeroPlane.h"
USING_NS_CC;
HeroPlane* HeroPlane::sharePlane = NULL;//ע�⣬��̬������д����
HeroPlane::HeroPlane(){
	plane = NULL;
	planeHp=10000;//Ӣ�۷ɻ�����ֵ
	planeScore=0;//Ӣ�۷ɻ�����ֵ
	planeBulletNum=1;//Ӣ�۷ɻ��ӵ�����,Ĭ�ϳ�ʼ��Ϊ��һ��
	isHeroPlaneControl = false;
    planeAttack=100;//Ӣ�۷ɻ�����ֵ
    planeDefend=100;//Ӣ�۷ɻ�����ֵ

}
//ȡ��Ӣ�۷ɻ��ķ�����ֻ��ͨ���������
HeroPlane* HeroPlane::getInstance()
{
	if (NULL == sharePlane){
		sharePlane = new HeroPlane();
		sharePlane->init();
		sharePlane->autorelease();
	}
	return sharePlane;
}
bool HeroPlane::init(){

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("heroplane.plist", "heroplane.png");//����ȫ����Դ

	plane = Sprite::createWithSpriteFrameName("plane1.png");//���ɷɻ�
	
	plane->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 5));
	this->addChild(plane, 0, 1);

	Blink *blink = Blink::create(3,8);//��˸����
	Animation* animation = Animation::create();
	animation->setDelayPerUnit(0.1f);
	animation->addSpriteFrame(frameCache->getSpriteFrameByName("plane1.png"));
	animation->addSpriteFrame(frameCache->getSpriteFrameByName("plane2.png"));
	Animate* animate = Animate::create(animation);//֡����

	plane->runAction(blink);//ִ����˸����
	plane->runAction(RepeatForever::create(animate));// ִ��֡����

	//���������¼����÷ɻ�������ָ�ƶ�
	auto listen = EventListenerTouchOneByOne::create();
	listen->onTouchBegan = CC_CALLBACK_2(HeroPlane::onTouchBegan, this);
	listen->onTouchMoved = CC_CALLBACK_2(HeroPlane::onTouchMoved, this);
	listen->onTouchEnded = CC_CALLBACK_2(HeroPlane::onTouchEened, this);
	listen->onTouchCancelled = CC_CALLBACK_2(HeroPlane::onTouchCancelled, this);
	listen->setSwallowTouches(false);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listen, this);

	return true;
}
Sprite* HeroPlane::getPlane(){
	if (NULL == plane)
		return NULL;
	return plane;
}
bool  HeroPlane::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){

	Point mHeroPos = plane->getPosition();
	Point mBeganPos = touch->getLocationInView();
	mBeganPos = Director::getInstance()->convertToGL(mBeganPos);

	//�жϵ�ǰ��ָ���������Ƿ���Ӣ�۷ɻ�������,���Ҽ���ɻ�Ҫ�ƶ�ʱ��ƫ����
	if (mBeganPos.x > mHeroPos.x - plane->getContentSize().width / 2 && mBeganPos.x<mHeroPos.x + plane->getContentSize().width / 2 &&
		mBeganPos.y>mHeroPos.y - plane->getContentSize().height / 2 && mBeganPos.y < mHeroPos.y + plane->getContentSize().height / 2){
		isHeroPlaneControl = true;
		//Ӌ��ƫ����
		mDeltaX = mBeganPos.x - mHeroPos.x;
		mDeltaY = mBeganPos.y - mHeroPos.y;

	}

	return true;
}
void HeroPlane::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	if (isHeroPlaneControl){
		Point mMovedPos = touch->getLocationInView();
		mMovedPos = Director::getInstance()->convertToGL(mMovedPos);

		Size visibleSize = Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();
		float x = mMovedPos.x - mDeltaX;//ӛ�Üpȥƫ����
		float y = mMovedPos.y - mDeltaY;

		if (x <= plane->getContentSize().width / 2 + origin.x)//x������Ļ��߽�
			x = plane->getContentSize().width / 2 + origin.x;
		else if (x >= visibleSize.width - plane->getContentSize().width / 2)//x������Ļ�ұ߽�
			x = visibleSize.width - plane->getContentSize().width / 2;

		if (y <= plane->getContentSize().height / 2 + origin.y)//y������Ļ�±߽�
			y = plane->getContentSize().height / 2 + origin.y;
		else if (y >= visibleSize.height - plane->getContentSize().height / 2)//x������Ļ�ϱ߽�
			y = visibleSize.height - plane->getContentSize().height / 2;

		//�ɻ�������ָ�ƶ�
		plane->setPosition(Vec2(x, y));
	}
}
void HeroPlane::onTouchEened(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	isHeroPlaneControl = false;
}
void  HeroPlane::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_even){
	isHeroPlaneControl = false;
}
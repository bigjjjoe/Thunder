
#include "BulletStyle.h"
BulletStyle::~BulletStyle(){
	//removeAllObject();
}
/**
* �Ƴ����еĶ���
*/
void BulletStyle::removeAllObject(){
	bulletBatchNode->removeAllChildren();
	vecBullet.clear();
	this->removeAllChildren();
	
}
/**
* �Ƴ��ӵ������ӵ����������Ƴ���ͬʱҲ��SpriteBatchNode���Ƴ�
*/
void BulletStyle::removeBullet(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;
	bulletBatchNode->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}
/**
*���ݴ���ķɻ����ӵ����淢��
*@param planeΪ����ɻ�����ΪӢ�۷ɻ���л�
*/
void BulletStyle::createBullet(Node* plane){
	this->plane = plane;
	//����BatchNode�ڵ�
	bulletBatchNode = SpriteBatchNode::create("bullet1.png");
	this->addChild(bulletBatchNode);
	//ÿ��0.2S����һ�η����ӵ�����
	schedule(schedule_selector(BulletStyle::shootBullet), 0.2f);//ע�⣬�@���{������ģ���

}
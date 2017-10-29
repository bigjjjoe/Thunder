#ifndef __BackLayerUp_H__
#define __BackLayerUp_H__

#include "cocos2d.h"
#define MAP_1_Tag   1       // 宏定义两个Map的Tag  
#define MAP_2_Tag   2 
class BackLayerUp : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(BackLayerUp);
private:
	void update(float time);
	virtual void onExit();
};

#endif // __BackLayerUp_H__

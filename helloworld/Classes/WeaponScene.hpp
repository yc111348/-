//
//  WeaponScene.hpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/2.
//

#ifndef WeaponScene_hpp
#define WeaponScene_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>
USING_NS_CC;

class WeaponScene: public Layer
{
public:
    
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(WeaponScene);
    MenuItemSprite* createMenuItem2Img(const std::string imgA,const std::string imgB);
    void onMenuCloseCallback(cocos2d::Ref *sender);
    void menuGoToChooseScene(cocos2d::Ref * Sender);
    
    cocos2d::Sprite* nike1;
    cocos2d::Sprite* nike2;
    Size size;
};



#endif /* WeaponScene_hpp */

//
//  ChooseScene.hpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/1.
//

#ifndef ChooseScene_hpp
#define ChooseScene_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>
#include "ui/CocosGUI.h"
USING_NS_CC;

class ChooseScene: public Layer
{
protected:
    cocos2d::ui::Button* _pauseButton;
    
public:
    
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(ChooseScene);
    MenuItemSprite* createMenuItem2Img(const std::string imgA,const std::string imgB);
    void onMenuCloseCallback(cocos2d::Ref *sender);
    void menuGoToWeapon(cocos2d::Ref * Sender);
    void menuGoToCharacter(cocos2d::Ref * Sender);
};

#endif /* ChooseScene_hpp */

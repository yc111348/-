//
//  LoginScene.hpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/5/31.
//

#ifndef LoginScene_hpp
#define LoginScene_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>
#include "ui/CocosGUI.h"
USING_NS_CC;

class LoginScene: public Layer
{
protected:
    cocos2d::ui::Button* _pauseButton;
public:
    
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(LoginScene);
    MenuItemSprite* createMenuItem2Img(const std::string imgA,const std::string imgB);
    void onMenuCloseCallback(cocos2d::Ref *sender);
    void menuGoToHelloworld(cocos2d::Ref * Sender);
};

#endif /* LoginScene_hpp */

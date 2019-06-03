//
//  CharacterScene.hpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/2.
//

#ifndef CharacterScene_hpp
#define CharacterScene_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>
USING_NS_CC;

class CharacterScene: public Layer
{
public:
    
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(CharacterScene);
    void onMenuCloseCallback(cocos2d::Ref *sender);
    void menuGoToChooseScene(cocos2d::Ref * Sender);
    void rolemove1();
    void rolemove2();
};



#endif /* CharacterScene_hpp */

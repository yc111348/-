//
//  EndGameScene.hpp
//  elloworld
//
//  Created by 董震宇 on 2019/6/14.
//

#ifndef EndGameScene_hpp
#define EndGameScene_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "ui/CocosGUI.h"

USING_NS_CC;


class EndGameScene: public Layer
{
    
public:
    
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(EndGameScene);
    
    
    cocos2d::ui::Button* _pauseButton;

    void menuGoToChooseScene(cocos2d::Ref * Sender);
    void menuGoToHeroScene(cocos2d::Ref * Sender);
};
#endif /* EndGameScene_hpp */

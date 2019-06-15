//
//  RankScene.hpp
//  elloworld
//
//  Created by 董震宇 on 2019/6/15.
//

#ifndef RankScene_hpp
#define RankScene_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "ui/CocosGUI.h"

USING_NS_CC;


class RankScene: public Layer
{
    
public:
    
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(RankScene);
    
    
    cocos2d::ui::Button* _pauseButton;
    
    void ranklist(int a[]);
    int SCORE = UserDefault::getInstance()->getIntegerForKey("score");
    int temp;


};


#endif /* RankScene_hpp */

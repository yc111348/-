//
//  hero.hpp
//  yc
//
//  Created by mac on 2019/6/10.
//

#ifndef hero_hpp
#define hero_hpp

#include "ProgressView.hpp"
#include <stdio.h>
#include "cocos2d.h"

class Hero:public cocos2d::Scene
{
    
    std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
    cocos2d::TMXTiledMap* map;
public:
    int before;
    int s_before;
    cocos2d::Animation* animation1;
    cocos2d::Animation* animation2;
    cocos2d::Animation* animation3;
    cocos2d::Animation* animation4;
    cocos2d::Animation* s_animation1;
    cocos2d::Animation* s_animation2;
    cocos2d::Animation* s_animation3;
    cocos2d::Animation* s_animation4;
    cocos2d::Vector <cocos2d::SpriteFrame*> animFrames1;
    cocos2d::Vector <cocos2d::SpriteFrame*> animFrames2;
    cocos2d::Vector <cocos2d::SpriteFrame*> animFrames3;
    cocos2d::Vector <cocos2d::SpriteFrame*> animFrames4;
    cocos2d::Vector <cocos2d::SpriteFrame*> s_animFrames1;
    cocos2d::Vector <cocos2d::SpriteFrame*> s_animFrames2;
    cocos2d::Vector <cocos2d::SpriteFrame*> s_animFrames3;
    cocos2d::Vector <cocos2d::SpriteFrame*> s_animFrames4;
    void update(float delta) override;
    static cocos2d::Scene* createScene();
    virtual bool init();
    cocos2d::Sprite *hero;
    cocos2d::Point heropos;
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(Hero);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
    void keyPressedDuration(cocos2d::EventKeyboard::KeyCode code);
    void dirchange(int dir);
    //------------------------------------------------------------------//
    ProgressView *m_pProgressView;  //血条
    
    //------------------------------------------------------------------//
    bool touch(Touch * touch,Event *event);//鼠标点击
    float point_x,point_y;//点击位置
    float hero_x,hero_y;//英雄实时位置
    //--------------r子弹--------//
    void display();
    cocos2d::Point viewpos;
    cocos2d::Point positiontrans(cocos2d::Point pos);
    bool couldgo(int direction);
};

#endif /* hero_hpp */

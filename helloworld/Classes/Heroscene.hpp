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
    cocos2d::Vector <cocos2d::SpriteFrame*> animFrames1;
    cocos2d::Vector <cocos2d::SpriteFrame*> animFrames2;
    cocos2d::Vector <cocos2d::SpriteFrame*> animFrames3;
    cocos2d::Vector <cocos2d::SpriteFrame*> animFrames4;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy_animFrames1;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy_animFrames2;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy_animFrames3;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy_animFrames4;
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
    ProgressView *m_pProgressView;
    ProgressView *enemy_pProgressView;//血条
    
    //------------------------------------------------------------------//
    bool touch(Touch * touch,Event *event);//鼠标点击
    float point_x,point_y;//点击位置
    float hero_x,hero_y;//英雄实时位置
    //--------------r子弹--------//
    int bullet2inhero=0;
    void display();
    cocos2d::Point viewpos;
    cocos2d::Point positiontrans(cocos2d::Point pos);
    bool couldgo(int direction);
    int isbullet=0;
    void bulletgo();
    cocos2d::Sprite* bullet;
    cocos2d::Sprite* bullet2;
    int bullet2inair=0;
    void couldbulletgo();
    void couldbullet2go();
    int bulletinwall=0;
    int bullet2inwall=0;
    int bulletinenemy=0;
    int time=0;
    
    
    //enemy
    int enemyacktime=300;
    int enemyblood=100;
    float enemy_x;
    float enemy_y;
    cocos2d::Sprite* enemy;
    void enemycoming();
    int enemytime=0;
    int enemylive=0;
    void enemymove();
    int enemymovetime=0;
    bool canenemygo(int direction);
    float lenthfromhero[4]={0,0,0,0};
    int enemydirection=0;
    void getenemydirection(int enemycode);
    void getlenth(int direction);
    void enemyattack();
    
    void enemyforup();
    
    //结束
    //碰撞检测
    void popif(int whobeatwho);
    void popgo(int whogodie);
    void gotodie(int who);
    //结束
    
    //道具刷新
    int itemtime = 300;
    void itemtimecoming();
    cocos2d::Sprite*  item1;
    cocos2d::Sprite*  item2;
    cocos2d::Sprite*  item3;
    cocos2d::Sprite*  item4;
    cocos2d::Sprite*  item5;
    cocos2d::Sprite*  item6;
    cocos2d::Sprite*  item7;
    cocos2d::Sprite*  item8;
    cocos2d::Sprite*  item9;
    cocos2d::Sprite*  item10;
    int isitemlive[11]={0,0,0,0,0,0,0,0,0,0,0};
    cocos2d::Point getitemcreatpos();
    void itempop();
    //结束
    //英雄属性
    float hero_speed=5;
    int hero_shecheng=200;
    int hero_blood=0;
    //结束
    
    
protected:
    //-----------积分榜----------//
    cocos2d::Label * ranklist;
    cocos2d::Label * scorettf;
    int score;
};

#endif /* hero_hpp */

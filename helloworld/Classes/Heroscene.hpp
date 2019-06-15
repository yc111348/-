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
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy2_animFrames1;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy2_animFrames2;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy2_animFrames3;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy2_animFrames4;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy3_animFrames1;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy3_animFrames2;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy3_animFrames3;
    cocos2d::Vector <cocos2d::SpriteFrame*> enemy3_animFrames4;
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
    ProgressView *enemy2_pProgressView;//血条
    ProgressView *enemy3_pProgressView;//血条
    
    //------------------------------------------------------------------//
    bool touch(Touch * touch,Event *event);//鼠标点击
    float point_x,point_y;//点击位置
    float hero_x,hero_y;//英雄实时位置
    //--------------r子弹--------//
    
    void display();
    cocos2d::Point viewpos;
    cocos2d::Point positiontrans(cocos2d::Point pos);
    bool couldgo(int direction);
    int isbullet=0;
    void bulletgo();
    cocos2d::Sprite* bullet;
    cocos2d::Sprite* bullet2;
    cocos2d::Sprite* bullet3;
    cocos2d::Sprite* bullet4;
    int bullet2inair=0;
    int bullet3inair=0;
    int bullet4inair=0;
    void couldbulletgo();
    void couldbullet2go();
    void couldbullet3go();
    void couldbullet4go();
    int bulletinwall=0;
    int bullet2inwall=0;
    int bullet3inwall=0;
    int bullet4inwall=0;
    int bulletinenemy=0;
    int bulletinenemy2=0;
    int bulletinenemy3=0;
    int bullet2inhero=0;
    int bullet3inhero=0;
    int bullet4inhero=0;
    int time=0;
    
    
    //enemy
    int enemy_shecheng=300;
    int enemyacktime=300;
    int enemyblood=100;
    float enemy_x;
    float enemy_y;
    cocos2d::Sprite* enemy;
    void enemycoming();
    int enemytime=2;
    int enemylive=0;
    void enemymove();
    int enemymovetime=0;
    bool canenemygo(int direction);
    float lenthfromhero[4]={0,0,0,0};
    int enemydirection=0;
    void getenemydirection(int enemycode);
    void getlenth(int direction);
    void enemyattack();
    int enemy_speed = 20 ;
    int enemy_shesu = 110;
    int enemy_gongjili=0;
    cocos2d::Point getenemypos();
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
    int weaponnum=0;
    float hero_speed=0;
    int hero_shecheng=0;
    int hero_blood=0;
    //结束
    
    
    //----------死亡界面----------//
    cocos2d::Label * deadttf;
    bool ifendgame = 0;
    
protected:
    //-----------积分榜----------//
    cocos2d::Label * ranklist;
    cocos2d::Label * scorettf;
    int score;
    //结束
    
    
    
    
    //enemy2
    int enemy2_shecheng=300;
    int enemy2acktime=300;
    int enemy2blood=100;
    float enemy2_x;
    float enemy2_y;
    cocos2d::Sprite* enemy2;
    void enemy2coming();
    int enemy2time=2;
    int enemy2live=0;
    void enemy2move();
    int enemy2movetime=0;
    bool canenemy2go(int direction);
    float lenthfromhero2[4]={0,0,0,0};
    int enemy2direction=0;
    void getenemy2direction(int enemy2code);
    void getlenth2(int direction);
    void enemy2attack();
    int enemy2_speed = 20 ;
    int enemy2_shesu = 110;
    int enemy2_gongjili=0;
    void enemy2forup();
    
    //结束
    
    //enemy3
    int enemy3_shecheng=300;
    int enemy3acktime=300;
    int enemy3blood=100;
    float enemy3_x;
    float enemy3_y;
    cocos2d::Sprite* enemy3;
    void enemy3coming();
    int enemy3time=2;
    int enemy3live=0;
    void enemy3move();
    int enemy3movetime=0;
    bool canenemy3go(int direction);
    float lenthfromhero3[4]={0,0,0,0};
    int enemy3direction=0;
    void getenemy3direction(int enemy3code);
    void getlenth3(int direction);
    void enemy3attack();
    int enemy3_speed = 20 ;
    int enemy3_shesu = 110;
    int enemy3_gongjili=0;
    void enemy3forup();
    
    
    //end
    
    
};

#endif /* hero_hpp */

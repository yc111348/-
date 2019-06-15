//
//  hero.cpp
//  yc
//
//  Created by mac on 2019/6/10.
//

#include "Heroscene.hpp"
#include "SimpleAudioEngine.h"
#include "EndGameScene.hpp"

USING_NS_CC;
bool Hero::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
    if(keys[keyCode]) {
        return true;
    } else {
        return false;
    }
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
Scene* Hero::createScene()
{
    return Hero::create();
}

// Print useful error message instead of segfaulting when files are not there.

// on "init" you need to initialize your instance
bool Hero::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    map = TMXTiledMap::create("mapres/map.tmx");
    addChild(map,1);
    auto mapgo = map->getLayer("move");
    mapgo->setVisible(false);
    weaponnum = UserDefault::getInstance()->getIntegerForKey("weapon");
    if(weaponnum==1)
    {
        bullet = Sprite::create("item/greenball.png");
    }
    if(weaponnum==2)
    {
        bullet = Sprite::create("item/fireball.png");
    }
    bullet2 = Sprite::create("item/bullet2.png");
    bullet3 = Sprite::create("item/bullet4.png");
    bullet4 = Sprite::create("item/bullet3.png");
    addChild(bullet,4);
    addChild(bullet2,4);
    addChild(bullet3,4);
    addChild(bullet4,4);
    bullet->setVisible(false);
    bullet2->setVisible(false);
    bullet3->setVisible(false);
    bullet4->setVisible(false);
    bullet->setPosition(50,50);
    bullet2->setPosition(50,50);
    bullet3->setPosition(50,50);
    bullet4->setPosition(50,50);
    bullet3->setScale(0.7,0.7);
    bullet4->setScale(0.5,0.5);
    if(weaponnum==2)
    {
        bullet->setScale(0.3,0.3);
    }
    
    //    获取地图属性
    //    auto mapProperties = map->getProperties();
    //    //地图名字本身的属性
    //    auto str=mapProperties["type"].asString();
    //    log("属性是%s",str.c_str());
    //
    //    //获取图层属性
    //    auto scenelayer=map->getLayer("scene");
    //    //先找到图层
    //    auto layerp=scenelayer->getProperties();
    //    //找到图层的属性
    //    log("属性是%s",layerp["type"].asString().c_str());
    //    //找到对应的属性，用数组的方式输出
    //
    //
    //    //获取对象属性
    //    auto obje = map->getObjectGroup("ob");
    //    //获取对象组
    //    auto obj=obje->getObject("juxing1");
    //    //修改颜色
    //    auto color=obje->getObject("juxing1");
    //    auto colorx=color["x"].asFloat();
    //    auto colory=color["y"].asFloat();
    //    auto colorw=color["width"].asInt()/8;
    //    auto colorh=color["height"].asInt()/8;
    //
    //    for(int x=colorx;x<colorx+colorw;x++)
    //    {
    //        for(int y=colory;y<colorh+colory;y++)
    //        {
    ////            auto sprite=scenelayer->getTileAt(Vec2(map->getMapSize().width-x,map->getMapSize().height-y));
    //            auto sprite=scenelayer->getTileAt(Vec2(x=colorx,colory));
    //            sprite->setColor(Color3B(255,0,0));
    //        }
    //    }
    
    
    //武器属性
    if(weaponnum==1)
    {
        hero_speed=3;
        hero_shecheng=250;
        hero_blood=0;
    }
    if(weaponnum==2)
    {
        hero_speed=5;
        hero_shecheng=200;
        hero_blood=0;
    }
    
    //结束
    
    
    
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    int heronum = UserDefault::getInstance()->getIntegerForKey("hero");  //
    
    //1.读取素材文件
    SpriteFrameCache* cache3 = SpriteFrameCache::getInstance();
    cache3->addSpriteFramesWithFile("hero1/waklleft1.plist"); //从plist中加载图片信息
    SpriteFrameCache* cache2 = SpriteFrameCache::getInstance();
    cache2->addSpriteFramesWithFile("hero1/walkback1.plist"); //从plist中加载图片信息
    SpriteFrameCache* cache1 = SpriteFrameCache::getInstance();
    cache1->addSpriteFramesWithFile("hero1/walkfront1.plist"); //从plist中加载图片信息
    SpriteFrameCache* cache4 = SpriteFrameCache::getInstance();
    cache4->addSpriteFramesWithFile("hero1/walkright1.plist"); //从plist中加载图片信息
    SpriteFrameCache* s_cache3 = SpriteFrameCache::getInstance();
    s_cache3->addSpriteFramesWithFile("hero1/standleft1.plist"); //从plist中加载图片信息
    SpriteFrameCache* s_cache2 = SpriteFrameCache::getInstance();
    s_cache2->addSpriteFramesWithFile("hero1/standback1.plist"); //从plist中加载图片信息
    SpriteFrameCache* s_cache1 = SpriteFrameCache::getInstance();
    s_cache1->addSpriteFramesWithFile("hero1/standfront1.plist"); //从plist中加载图片信息
    SpriteFrameCache* s_cache4 = SpriteFrameCache::getInstance();
    s_cache4->addSpriteFramesWithFile("hero1/standright1.plist"); //从plist中加载图片信息
    SpriteFrameCache* enemy_cache3 = SpriteFrameCache::getInstance();
    enemy_cache3->addSpriteFramesWithFile("A monster/monsterwalkleft.plist"); //从plist中加载图片信息
    SpriteFrameCache* enemy_cache2 = SpriteFrameCache::getInstance();
    enemy_cache2->addSpriteFramesWithFile("A monster/monsterwalkfront.plist"); //从plist中加载图片信息
    SpriteFrameCache* enemy_cache1 = SpriteFrameCache::getInstance();
    enemy_cache1->addSpriteFramesWithFile("A monster/monsterwalkback.plist"); //从plist中加载图片信息
    SpriteFrameCache* enemy_cache4 = SpriteFrameCache::getInstance();
    enemy_cache4->addSpriteFramesWithFile("A monster/monsterwalkright.plist"); //从plist中加载图片信息
    
    
    //怪物2素材
    SpriteFrameCache* enemy2_cache3 = SpriteFrameCache::getInstance();
    enemy2_cache3->addSpriteFramesWithFile("monster2/mon1walkleft.plist"); //从plist中加载图片信息
    SpriteFrameCache* enemy2_cache2 = SpriteFrameCache::getInstance();
    enemy2_cache2->addSpriteFramesWithFile("monster2/mon1walkfront.plist"); //从plist中加载图片信息
    SpriteFrameCache* enemy2_cache1 = SpriteFrameCache::getInstance();
    enemy2_cache1->addSpriteFramesWithFile("monster2/mon1walkback.plist"); //从plist中加载图片信息
    SpriteFrameCache* enemy2_cache4 = SpriteFrameCache::getInstance();
    enemy2_cache4->addSpriteFramesWithFile("monster2/mon1walkright.plist"); //从plist中加载图片信息
    //结束
    
    //角色2的素材
    
    SpriteFrameCache* cache7 = SpriteFrameCache::getInstance();
    cache7->addSpriteFramesWithFile("hero2/walkleft2.plist"); //从plist中加载图片信息
    SpriteFrameCache* cache6 = SpriteFrameCache::getInstance();
    cache6->addSpriteFramesWithFile("hero2/walkback2.plist"); //从plist中加载图片信息
    SpriteFrameCache* cache5 = SpriteFrameCache::getInstance();
    cache5->addSpriteFramesWithFile("hero2/walkfront2.plist"); //从plist中加载图片信息
    SpriteFrameCache* cache8 = SpriteFrameCache::getInstance();
    cache8->addSpriteFramesWithFile("hero2/walkright2.plist"); //从plist中加载图片信息
    
    SpriteFrameCache* s_cache7 = SpriteFrameCache::getInstance();
    s_cache7->addSpriteFramesWithFile("hero2/standleft2.plist"); //从plist中加载图片信息
    SpriteFrameCache* s_cache6 = SpriteFrameCache::getInstance();
    s_cache6->addSpriteFramesWithFile("hero2/standback2.plist"); //从plist中加载图片信息
    SpriteFrameCache* s_cache5 = SpriteFrameCache::getInstance();
    s_cache5->addSpriteFramesWithFile("hero2/standfront2.plist"); //从plist中加载图片信息
    SpriteFrameCache* s_cache8 = SpriteFrameCache::getInstance();
    s_cache8->addSpriteFramesWithFile("hero2/standright2.plist"); //从plist中加载图片信息
    //结束
    
    
    //怪物3素材
    SpriteFrameCache* enemy3_cache3 = SpriteFrameCache::getInstance();
    enemy3_cache3->addSpriteFramesWithFile("monster3/mon2walkleft.plist"); //从plist中加载图片信息
    SpriteFrameCache* enemy3_cache2 = SpriteFrameCache::getInstance();
    enemy3_cache2->addSpriteFramesWithFile("monster3/mon2walkfront.plist"); //从plist中加载图片信息
    SpriteFrameCache* enemy3_cache1 = SpriteFrameCache::getInstance();
    enemy3_cache1->addSpriteFramesWithFile("monster3/mon2walkback.plist"); //从plist中加载图片信息
    SpriteFrameCache* enemy3_cache4 = SpriteFrameCache::getInstance();
    enemy3_cache4->addSpriteFramesWithFile("monster3/mon2walkright.plist"); //从plist中加载图片信息
    //结束
    
    //2.创建逐帧数组
    //front
    if(heronum==1)
    {
        char str1[100] = {0};
        for (int i = 1231; i<1240; i++)
        {
            sprintf(str1, "%d.png", i);
            SpriteFrame* pFrame1 = cache1->getSpriteFrameByName(str1);
            animFrames1.pushBack(pFrame1);
        }
        //back
        char str2[100] = {0};
        for (int i = 1131; i<1140; i++)
        {
            sprintf(str2, "%d.png", i);
            SpriteFrame* pFrame2 = cache2->getSpriteFrameByName(str2);
            animFrames2.pushBack(pFrame2);
        }
        //left
        char str3[100] = {0};
        for (int i = 1331; i<1340; i++)
        {
            sprintf(str3, "%d.png", i);
            SpriteFrame* pFrame3 = cache3->getSpriteFrameByName(str3);
            animFrames3.pushBack(pFrame3);
        }
        //right
        char str4[100] = {0};
        for (int i = 1431; i<1440; i++)
        {
            sprintf(str4, "%d.png", i);
            SpriteFrame* pFrame4 = cache4->getSpriteFrameByName(str4);
            animFrames4.pushBack(pFrame4);
        }
        char s_str1[100] = {0};
        for (int i = 1211; i<1219; i++)
        {
            sprintf(s_str1, "%d.png", i);
            SpriteFrame* s_pFrame1 = s_cache1->getSpriteFrameByName(s_str1);
            s_animFrames1.pushBack(s_pFrame1);
        }
        char s_str2[100] = {0};
        for (int i = 1111; i<1119; i++)
        {
            sprintf(s_str2, "%d.png", i);
            SpriteFrame* s_pFrame2 = s_cache2->getSpriteFrameByName(s_str2);
            s_animFrames2.pushBack(s_pFrame2);
        }
        char s_str3[100] = {0};
        for (int i = 1311; i<1319; i++)
        {
            sprintf(s_str3, "%d.png", i);
            SpriteFrame* s_pFrame3 = s_cache3->getSpriteFrameByName(s_str3);
            s_animFrames3.pushBack(s_pFrame3);
        }
        char s_str4[100] = {0};
        for (int i = 1411; i<1419; i++)
        {
            sprintf(s_str4, "%d.png", i);
            SpriteFrame* s_pFrame4 = s_cache4->getSpriteFrameByName(s_str4);
            s_animFrames4.pushBack(s_pFrame4);
        }
    }
    if(heronum==2)
    {
        char str1[100] = {0};
        for (int i = 2231; i<2240; i++)
        {
            sprintf(str1, "%d.png", i);
            SpriteFrame* pFrame1 = cache5->getSpriteFrameByName(str1);
            animFrames1.pushBack(pFrame1);
        }
        //back
        char str2[100] = {0};
        for (int i = 2131; i<2140; i++)
        {
            sprintf(str2, "%d.png", i);
            SpriteFrame* pFrame2 = cache6->getSpriteFrameByName(str2);
            animFrames2.pushBack(pFrame2);
        }
        //left
        char str3[100] = {0};
        for (int i = 2331; i<2340; i++)
        {
            sprintf(str3, "%d.png", i);
            SpriteFrame* pFrame3 = cache7->getSpriteFrameByName(str3);
            animFrames3.pushBack(pFrame3);
        }
        //right
        char str4[100] = {0};
        for (int i = 2431; i<2440; i++)
        {
            sprintf(str4, "%d.png", i);
            SpriteFrame* pFrame4 = cache8->getSpriteFrameByName(str4);
            animFrames4.pushBack(pFrame4);
        }
        char s_str1[100] = {0};
        for (int i = 2211; i<2219; i++)
        {
            sprintf(s_str1, "%d.png", i);
            SpriteFrame* s_pFrame1 = s_cache5->getSpriteFrameByName(s_str1);
            s_animFrames1.pushBack(s_pFrame1);
        }
        char s_str2[100] = {0};
        for (int i = 2111; i<2119; i++)
        {
            sprintf(s_str2, "%d.png", i);
            SpriteFrame* s_pFrame2 = s_cache6->getSpriteFrameByName(s_str2);
            s_animFrames2.pushBack(s_pFrame2);
        }
        char s_str3[100] = {0};
        for (int i = 2311; i<2319; i++)
        {
            sprintf(s_str3, "%d.png", i);
            SpriteFrame* s_pFrame3 = s_cache7->getSpriteFrameByName(s_str3);
            s_animFrames3.pushBack(s_pFrame3);
        }
        char s_str4[100] = {0};
        for (int i = 2411; i<2419; i++)
        {
            sprintf(s_str4, "%d.png", i);
            SpriteFrame* s_pFrame4 = s_cache8->getSpriteFrameByName(s_str4);
            s_animFrames4.pushBack(s_pFrame4);
        }
    }
    
    char enemy_str1[100] = {0};
    for (int i = 4001; i<4009; i++)
    {
        sprintf(enemy_str1, "%d.png", i);
        SpriteFrame* enemy_pFrame1 = enemy_cache1->getSpriteFrameByName(enemy_str1);
        enemy_animFrames1.pushBack(enemy_pFrame1);
    }
    
    char enemy_str2[100] = {0};
    for (int i = 1001; i<1009; i++)
    {
        sprintf(enemy_str2, "%d.png", i);
        SpriteFrame* enemy_pFrame2 = enemy_cache2->getSpriteFrameByName(enemy_str2);
        enemy_animFrames2.pushBack(enemy_pFrame2);
    }
    char enemy_str3[100] = {0};
    for (int i = 3001; i<3009; i++)
    {
        sprintf(enemy_str3, "%d.png", i);
        SpriteFrame* enemy_pFrame3 = enemy_cache3->getSpriteFrameByName(enemy_str3);
        enemy_animFrames3.pushBack(enemy_pFrame3);
    }
    char enemy_str4[100] = {0};
    for (int i = 2001; i<2009; i++)
    {
        sprintf(enemy_str4, "%d.png", i);
        SpriteFrame* enemy_pFrame4 = enemy_cache4->getSpriteFrameByName(enemy_str4);
        enemy_animFrames4.pushBack(enemy_pFrame4);
    }
    
    
    
    //怪物2
    
    
    char enemy2_str1[100] = {0};
    for (int i = 14001; i<14009; i++)
    {
        sprintf(enemy2_str1, "%d.png", i);
        SpriteFrame* enemy2_pFrame1 = enemy2_cache1->getSpriteFrameByName(enemy2_str1);
        enemy2_animFrames1.pushBack(enemy2_pFrame1);
    }
    
    char enemy2_str2[100] = {0};
    for (int i = 11001; i<11009; i++)
    {
        sprintf(enemy2_str2, "%d.png", i);
        SpriteFrame* enemy2_pFrame2 = enemy2_cache2->getSpriteFrameByName(enemy2_str2);
        enemy2_animFrames2.pushBack(enemy2_pFrame2);
    }
    char enemy2_str3[100] = {0};
    for (int i = 13001; i<13009; i++)
    {
        sprintf(enemy2_str3, "%d.png", i);
        SpriteFrame* enemy2_pFrame3 = enemy2_cache3->getSpriteFrameByName(enemy2_str3);
        enemy2_animFrames3.pushBack(enemy2_pFrame3);
    }
    char enemy2_str4[100] = {0};
    for (int i = 12001; i<12009; i++)
    {
        sprintf(enemy2_str4, "%d.png", i);
        SpriteFrame* enemy2_pFrame4 = enemy2_cache4->getSpriteFrameByName(enemy2_str4);
        enemy2_animFrames4.pushBack(enemy2_pFrame4);
    }
    
    
    
    
    //结束
    
    
    
    //怪物3
    
    
    char enemy3_str1[100] = {0};
    for (int i = 24001; i<24009; i++)
    {
        sprintf(enemy3_str1, "%d.png", i);
        SpriteFrame* enemy3_pFrame1 = enemy3_cache1->getSpriteFrameByName(enemy3_str1);
        enemy3_animFrames1.pushBack(enemy3_pFrame1);
    }
    
    char enemy3_str2[100] = {0};
    for (int i = 21001; i<21009; i++)
    {
        sprintf(enemy3_str2, "%d.png", i);
        SpriteFrame* enemy3_pFrame2 = enemy3_cache2->getSpriteFrameByName(enemy3_str2);
        enemy3_animFrames2.pushBack(enemy3_pFrame2);
    }
    char enemy3_str3[100] = {0};
    for (int i = 23001; i<23009; i++)
    {
        sprintf(enemy3_str3, "%d.png", i);
        SpriteFrame* enemy3_pFrame3 = enemy3_cache3->getSpriteFrameByName(enemy3_str3);
        enemy3_animFrames3.pushBack(enemy3_pFrame3);
    }
    char enemy3_str4[100] = {0};
    for (int i = 22001; i<22009; i++)
    {
        sprintf(enemy3_str4, "%d.png", i);
        SpriteFrame* enemy3_pFrame4 = enemy3_cache4->getSpriteFrameByName(enemy3_str4);
        enemy3_animFrames4.pushBack(enemy3_pFrame4);
    }
    
    
    
    
    //结束
    
    
    
    
    
    
    //3.设置起始帧
    if(heronum==1)
    {
        hero = Sprite::createWithSpriteFrameName("1231.png");
    }
    if(heronum==2)
    {
        hero = Sprite::createWithSpriteFrameName("2231.png");
    }
    addChild(hero,2);
    hero->setPosition(500,500);
    auto s_animation1 = Animation::createWithSpriteFrames(s_animFrames1, 0.3);
    hero->runAction(RepeatForever::create(Animate::create(s_animation1))); //测试动画
    
    //--------------------加入用户昵称------------------//
    std::string name = UserDefault::getInstance()->getStringForKey("Username");
    auto username = Label::createWithTTF(name,"fonts/chicken.ttf" , 20);
    username -> setColor(Color3B(0,0,0));
    username ->  setPosition(hero_x+315,hero_y+450);
    hero -> addChild(username,100);
    //--------------------结      束-------------------//
    
    
    //4.执行动画
//        s_animation1 = Animation::createWithSpriteFrames(s_animFrames1, 0.3);
//        hero->runAction(RepeatForever::create(Animate::create(s_animation1))); //测试动画
    //    animation1 = Animation::createWithSpriteFrames(animFrames1, 0.3);
    //    hero->runAction(RepeatForever::create(Animate::create(animation1))); //测试动画
    //    animation2 = Animation::createWithSpriteFrames(animFrames2, 0.3);
    //    hero->runAction(RepeatForever::create(Animate::create(animation2))); //测试动画
    
    
    
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){
        keys[keyCode] = true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event){
        keys[keyCode] = false;
    };
    
    
    this->scheduleUpdate();
    
    
    //道具
//    auto shoes = Sprite::create("shoes.png");
//    addChild(shoes,3);
//    shoes->setScale(0.5);
//    shoes->setPosition(visibleSize.width/2,visibleSize.height/2);
    
    //结束
    
    
    
    
    
    
    
    //结束
    
    //血条消失术
    m_pProgressView = new ProgressView();
    m_pProgressView->setScale(1,0.5);
    m_pProgressView->setPosition(hero_x+315,hero_y+430);
    m_pProgressView->setBackgroundTexture("item/noblood.png");
    m_pProgressView->setForegroundTexture("item/heroblood.png");
    m_pProgressView->setTotalProgress(100.0f);
    m_pProgressView->setCurrentProgress(100.0f);
    hero -> addChild(m_pProgressView,1);
    hero_blood=100;
    
    
    
    //结束
    //子弹发射术
        auto listenermouse = EventListenerTouchOneByOne::create();//
        listenermouse->onTouchBegan = CC_CALLBACK_2(Hero::touch,this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listenermouse, this);
    //结束
    

    
    auto listeners = EventListenerTouchOneByOne::create();
    listeners->onTouchBegan = [=](Touch *t, Event *e){
        return true;
    };
    
    
    //-------------------实时积分------------------//
    ranklist = Label::createWithTTF("积分:", "fonts/chicken.ttf", 40);
    ranklist -> setColor(Color3B(255,69,0));
    addChild(ranklist,10);
    
    scorettf = Label::createWithTTF("0", "fonts/chicken.ttf", 40);
    scorettf -> setColor(Color3B(255,69,0));
    addChild(scorettf,10);
    //-------------------结  束-------------------//
    
    //-------------------死亡文字------------------//
    deadttf = Label::createWithTTF("游戏结束!", "fonts/chicken.ttf", 70);
    deadttf -> setColor(Color3B(255,69,0));
    deadttf -> setVisible(false);
    addChild(deadttf,10);
    
    //-------------------结   束------------------//
    
    
    return true;
}


void Hero::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
void Hero::update(float delta)
{
    enemyforup();
    enemy2forup();
    enemy3forup();
    time+=1;
    if( (!bulletinwall)&&(isbullet) )
    {
        couldbulletgo();
    }
    heropos= hero->getPosition();
    hero_x = hero->getPositionX();
    hero_y = hero->getPositionY();
    Node::update(delta);
    auto leftArrow = EventKeyboard::KeyCode::KEY_A, rightArrow = EventKeyboard::KeyCode::KEY_D,upArrow = EventKeyboard::KeyCode::KEY_W,downArrow = EventKeyboard::KeyCode::KEY_S;
    if(isKeyPressed(leftArrow))
    {
        keyPressedDuration(leftArrow);
    }
    else if(isKeyPressed(rightArrow))
    {
        keyPressedDuration(rightArrow);
    }
    else if(isKeyPressed(upArrow))
    {
        keyPressedDuration(upArrow);
    }
    else if(isKeyPressed(downArrow))
    {
        keyPressedDuration(downArrow);
    }
    if((!isKeyPressed(leftArrow))&&(!isKeyPressed(rightArrow))&&(!isKeyPressed(upArrow))&&(!isKeyPressed(downArrow)))
    {
        if(before==1)
        {
            hero->stopAllActions();
            auto s_animation1 = Animation::createWithSpriteFrames(s_animFrames1, 0.3);
            hero->runAction(RepeatForever::create(Animate::create(s_animation1))); //测试动画
        }
        if(before==2)
        {
            hero->stopAllActions();
            auto s_animation2 = Animation::createWithSpriteFrames(s_animFrames2, 0.3);
            hero->runAction(RepeatForever::create(Animate::create(s_animation2))); //测试动画
        }
        if(before==3)
        {
            hero->stopAllActions();
            auto s_animation3 = Animation::createWithSpriteFrames(s_animFrames3, 0.3);
            hero->runAction(RepeatForever::create(Animate::create(s_animation3))); //测试动画
        }
        if(before==4)
        {
            hero->stopAllActions();
            auto s_animation4 = Animation::createWithSpriteFrames(s_animFrames4, 0.3);
            hero->runAction(RepeatForever::create(Animate::create(s_animation4))); //测试动画
        }
        before=-1;
    }
    auto vsize = Director::getInstance()->getVisibleSize();
    auto mapTN=map->getMapSize();
    auto tiledSize = map->getTileSize();
    auto mapsize = Size(mapTN.width*tiledSize.width,mapTN.height*tiledSize.height);
    auto hpos=hero->getPosition();
    auto x = MAX(hpos.x,vsize.width/2);
    auto y = MAX(hpos.y,vsize.height/2);
    x = MIN(x,mapsize.width-vsize.width/2);
    y = MIN(y,mapsize.height-vsize.height/2);
    auto destpos=Vec2(x,y);
    auto centerpos = Vec2(vsize.width/2,vsize.height/2);
    viewpos = centerpos - destpos;
    this -> setPosition(viewpos);
    
    popif(1);
    popif(2);
    popif(3);
    popif(4);
    popif(5);
    popif(6);
    
    if(time==itemtime)
    {
        itemtimecoming();
        itemtime+=300;
    }
    itempop();
    
    
    //----------排行榜位置-------------//
    ranklist -> setPosition(-viewpos.x+100,-viewpos.y+700);
    scorettf -> setPosition(-viewpos.x+200,-viewpos.y+700);
    scorettf -> setString(__String::createWithFormat("%i",score)->getCString());
    //----------结     束-------------//
    //----------死亡  文字-------------//
    deadttf -> setPosition(-viewpos.x+500, -viewpos.y+400);
    if(ifendgame == 1)
    {
        auto * listenerEndGame = EventListenerTouchOneByOne::create();
        listenerEndGame->onTouchBegan = [this](Touch * touch,Event * event)
        {
          Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5, EndGameScene::createScene()));
            return false;
        };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerEndGame,this);
        this->unscheduleUpdate();
    }
    //----------结     束-------------//
}

void Hero::keyPressedDuration(EventKeyboard::KeyCode code)
{
    float offsetX = 0, offsetY = 0;
    switch (code)
    {
        case EventKeyboard::KeyCode::KEY_A:
            dirchange(3);
            if(couldgo(3))
            {
                offsetX = -hero_speed;
            }
            break;
        case EventKeyboard::KeyCode::KEY_W:
            dirchange(2);
            if(couldgo(2))
            {
                offsetY = hero_speed;
            }
            break;
        case EventKeyboard::KeyCode::KEY_S:
            dirchange(1);
            if(couldgo(1))
            {
                offsetY = -hero_speed;
            }
            break;
        case EventKeyboard::KeyCode::KEY_D:
            dirchange(4);
            if(couldgo(4))
            {
                offsetX = hero_speed;
            }
            break;
        default:
            offsetY = offsetX = 0;
            break;
    }
    auto moveTo = MoveTo::create(0.01, Vec2(hero->getPositionX() + offsetX, hero->getPositionY() + offsetY));
    hero->runAction(moveTo);
}
bool Hero::touch(Touch * touch,Event *event)
{
    if(isbullet==0 && !ifendgame)
    {
        auto visiblesize = Director::getInstance()->getVisibleSize();
        Point pt = touch->getLocation();
        pt = Director::getInstance()->convertToGL(pt);
        pt.x = pt.x - viewpos.x;
        pt.y = pt.y + viewpos.y;
        point_x = pt.x;
        point_y = pt.y;
        float deltx,delty;
        deltx = point_x - hero_x;
        delty = visiblesize.height - point_y - hero_y;
        float delta = sqrt(deltx*deltx + delty*delty);
        float ex = deltx/delta;
        float ey = delty/delta;
        bullet->setPosition(hero_x, hero_y);
        bullet->setVisible(true);
        auto fire = MoveBy::create(0.3,Vec2(hero_shecheng*ex,hero_shecheng*ey));
        isbullet=1;
        auto callbackfunc = [=]()
        {
            isbullet=0;
            bullet->setVisible(false);
            bullet->setPosition(50,50);
        };
        auto callFunc=CallFunc::create(callbackfunc);
        auto actions = Sequence::create(fire,DelayTime::create(0.15),callFunc,NULL);
        bullet->runAction(actions);
    }
    return true;
}


void Hero::dirchange(int dir)
{
    if(dir!=before)
    {
        before=dir;
        if(dir==1)
        {
            hero->stopAllActions();
            auto animation1 = Animation::createWithSpriteFrames(animFrames1, 0.15);
            hero->runAction(RepeatForever::create(Animate::create(animation1))); //测试动画
        }
        if(dir==2)
        {
            hero->stopAllActions();
            auto animation2 = Animation::createWithSpriteFrames(animFrames2, 0.15);
            hero->runAction(RepeatForever::create(Animate::create(animation2))); //测试动画
        }
        if(dir==3)
        {
            hero->stopAllActions();
            auto animation3 = Animation::createWithSpriteFrames(animFrames3, 0.15);
            hero->runAction(RepeatForever::create(Animate::create(animation3))); //测试动画
        }
        if(dir==4)
        {
            hero->stopAllActions();
            auto animation4 = Animation::createWithSpriteFrames(animFrames4, 0.15);
            hero->runAction(RepeatForever::create(Animate::create(animation4))); //测试动画
        }
    }
}

Point Hero::positiontrans(cocos2d::Point pos)
{
    auto mapTiledNum = map->getMapSize();
    auto tiledSize = map->getTileSize();
    float x = pos.x/tiledSize.width;
    float y=(2880-pos.y)/tiledSize.height;
    if(x>0)
    {
        x-=1;
    }
    if(y>0)
    {
        y-=0;
    }
    return Point(x,y);
}

bool Hero::couldgo(int direction)
{
    Point temp=Point(0,0);
    Point herotemp=Point(0,0);
    if(direction==1)
    {
        temp=Point(1,1);
    }
    if(direction==2)
    {
        temp=Point(1,-1);
    }
    if(direction==3)
    {
        temp=Point(0,0);
    }
    if(direction==4)
    {
        temp=Point(2,0);
    }
    auto maplayer = map->getLayer("move");
    Point pos=positiontrans(heropos);
    int tiledID =  maplayer -> getTileGIDAt(pos+temp);
    if(tiledID==0)
    {
        return true;
    }
    if(tiledID!=0)
    {
        return false;
    }
    else
    {
        return true;
    }
}


void Hero::couldbulletgo()
{
    Point pos=positiontrans(bullet->getPosition());
    int tiledID =  map->getLayer("move")-> getTileGIDAt(pos);
    if(tiledID)
    {
        bulletinwall=1;
        bullet->stopAllActions();
        bulletinenemy=0;
        auto callbackfunc = [=]()
        {
            
            isbullet=0;
            bullet->setVisible(false); bullet->setPosition(Director::getInstance()->getVisibleSize().width/2,Director::getInstance()->getVisibleSize().height/2);
            isbullet=0;
            bulletinwall=0;
        };
        
        auto callFunc=CallFunc::create(callbackfunc);
        auto actions = Sequence::create(DelayTime::create(0.15),callFunc,NULL);
        bullet->runAction(actions);
    }
}

void Hero::enemycoming()
{
    enemy= Sprite::createWithSpriteFrameName("1001.png");
    addChild(enemy,2);
    enemy->setPosition(getenemypos());
    auto enemy_animation1 = Animation::createWithSpriteFrames(enemy_animFrames1, 0.3);
    enemy->runAction(RepeatForever::create(Animate::create(enemy_animation1))); //测试动画
    enemylive=1;
    enemyblood=100;
    if(enemy_speed<=30)
    {
        enemy_speed+=2;
    }
    if(enemy_shesu>=50)
    {
        enemy_shesu-=10;
    }
    if(enemy_gongjili<=50)
    {
        enemy_gongjili+=5;
    }
    if(enemy_shecheng<=600)
    {
        enemy_shecheng+=30;
    }
    enemy_x = enemy->getPositionX();
    enemy_y=enemy->getPositionY();
    enemy_pProgressView = new ProgressView();
    enemy_pProgressView->setScale(1,0.5);
    enemy_pProgressView->setPosition(330,450);
    enemy_pProgressView->setBackgroundTexture("item/noblood.png");
    enemy_pProgressView->setForegroundTexture("item/fullblood.png");
    enemy_pProgressView->setTotalProgress(100.0f);
    enemy_pProgressView->setCurrentProgress(100.0f);
    enemy -> addChild(enemy_pProgressView,5);
}

void Hero::enemymove()
{
    getenemydirection(1);
    int i = enemydirection;
    for(;;)
    {
        if(canenemygo(i))
        {
            break;
        }
        i = random(1, 4);
    }
    switch (i)
    {
        case 1:
        {
            enemy->stopAllActions();
            auto enemy_animation1 = Animation::createWithSpriteFrames(enemy_animFrames1, 0.3);
            enemy->runAction(RepeatForever::create(Animate::create(enemy_animation1))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(0,-enemy_speed));
            enemy->runAction(moveby);
            break;
        }
        case 2:
        {
            enemy->stopAllActions();
            auto enemy_animation2 = Animation::createWithSpriteFrames(enemy_animFrames2, 0.3);
            enemy->runAction(RepeatForever::create(Animate::create(enemy_animation2))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(0,enemy_speed));
            enemy->runAction(moveby);
            break;
        }
        case 3:
        {
            enemy->stopAllActions();
            auto enemy_animation3 = Animation::createWithSpriteFrames(enemy_animFrames3, 0.3);
            enemy->runAction(RepeatForever::create(Animate::create(enemy_animation3))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(-enemy_speed,0));
            enemy->runAction(moveby);
            break;
        }
        case 4:
        {
            enemy->stopAllActions();
            auto enemy_animation4 = Animation::createWithSpriteFrames(enemy_animFrames4, 0.3);
            enemy->runAction(RepeatForever::create(Animate::create(enemy_animation4))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(enemy_speed,0));
            enemy->runAction(moveby);
            break;
        }
    }
}


bool Hero::canenemygo(int direction)
{
    Point temp=Point(0,0);
    Point enemytemp=Point(0,0);
    if(direction==1)
    {
        temp=Point(1,1);
    }
    if(direction==2)
    {
        temp=Point(1,-3);
    }
    if(direction==3)
    {
        temp=Point(0,-2);
    }
    if(direction==4)
    {
        temp=Point(3,0);
    }
    auto maplayer = map->getLayer("move");
    Point pos=positiontrans(enemy->getPosition());
    int tiledID =  maplayer -> getTileGIDAt(pos+temp);
    
//    if(    ( (enemy->getPositionX ()) < (enemy2->getPositionX()   )  )
//       &&  ( (enemy2->getPositionX()) < (enemy->getPositionX ()+60)  )
//       &&  ( (enemy->getPositionY()) < (enemy2->getPositionY ()   )  )
//       &&  ( (enemy2->getPositionY())< (enemy->getPositionY  ()+80)  ) )
//    {
//        tiledID = 1 ;
//    }
    
    if(tiledID==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Hero::popif(int whobeatwho)
{
    if(whobeatwho==1)
    {
        if( (!bullet2inhero)&&(bullet2inair) )
        {
            if(((hero->getPositionX()-20) < (bullet2->getPositionX())) &&  ( (bullet2->getPositionX())< (hero->getPositionX()+60)  )  &&((hero->getPositionY()) < (bullet2->getPositionY())) &&  ( (bullet2->getPositionY())< (hero->getPositionY()+80)  ) )
            {
                popgo(1);
            }
        }
    }
    if(whobeatwho==2)
    {
        if( (!bulletinenemy)&&enemylive&&isbullet)
        {
            if(((enemy->getPositionX()-20) < (bullet->getPositionX())) &&  ( (bullet->getPositionX())< (enemy->getPositionX()+85)  )  &&((enemy->getPositionY()) < (bullet->getPositionY())) &&  ( (bullet->getPositionY())< (enemy->getPositionY()+128)  )   )
            {
                popgo(2);
            }
        }
    }
    if(whobeatwho==3)
    {
        if( (!bullet3inhero)&&(bullet3inair) )
        {
            if(((hero->getPositionX()-20) < (bullet3->getPositionX())) &&  ( (bullet3->getPositionX())< (hero->getPositionX()+60)  )  &&((hero->getPositionY()) < (bullet3->getPositionY())) &&  ( (bullet3->getPositionY())< (hero->getPositionY()+80)  ) )
            {
                popgo(3);
            }
        }
    }
    if(whobeatwho==4)
    {
        if( (!bulletinenemy)&&enemy2live&&isbullet)
        {
            if(((enemy2->getPositionX()-20) < (bullet->getPositionX())) &&  ( (bullet->getPositionX())< (enemy2->getPositionX()+85)  )  &&((enemy2->getPositionY()) < (bullet->getPositionY())) &&  ( (bullet->getPositionY())< (enemy2->getPositionY()+128)  )   )
            {
                popgo(4);
            }
        }
    }
    if(whobeatwho==5)
    {
        if( (!bullet4inhero)&&(bullet4inair) )
        {
            if(((hero->getPositionX()-20) < (bullet4->getPositionX())) &&  ( (bullet4->getPositionX())< (hero->getPositionX()+60)  )  &&((hero->getPositionY()) < (bullet4->getPositionY())) &&  ( (bullet4->getPositionY())< (hero->getPositionY()+80)  ) )
            {
                popgo(5);
            }
        }
    }
    if(whobeatwho==6)
    {
        if( (!bulletinenemy)&&enemy3live&&isbullet)
        {
            if(((enemy3->getPositionX()-20) < (bullet->getPositionX())) &&  ( (bullet->getPositionX())< (enemy3->getPositionX()+85)  )  &&((enemy3->getPositionY()) < (bullet->getPositionY())) &&  ( (bullet->getPositionY())< (enemy3->getPositionY()+128)  )   )
            {
                popgo(6);
            }
        }
    }
}

void Hero::popgo(int whogodie)
{
    if(whogodie==1)
    {
        hero_blood-=enemy_gongjili;
        bullet2inhero=1;
        bullet2->stopAllActions();
        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()-enemy_gongjili);
        auto callbackfunc = [=]()
        {
            
            bullet2inair=0;
            bullet2->setVisible(false); bullet2->setPosition(50,50);
            bullet2inhero=0;
        };
        auto callFunc= CallFunc::create(callbackfunc);
        auto actions = Sequence::create(DelayTime::create(0.15),callFunc,NULL);
        bullet2->runAction(actions);
        if(hero_blood<=0)
        {
            gotodie(1);
        }
    }
    if(whogodie==2)
    {
        enemyblood-=10;
        bulletinenemy=1;
        bullet->stopAllActions();
        enemy_pProgressView->setCurrentProgress(enemy_pProgressView->getCurrentProgress()-10);//更改血量
        score += 10;
        auto callbackfunc = [=]()
        {
            isbullet=0;
            bullet->setVisible(false);
            bullet->setPosition(50,50);
            bulletinenemy=0;
        };
        auto callFunc=CallFunc::create(callbackfunc);
        auto actions = Sequence::create(DelayTime::create(0.15),callFunc,NULL);
        bullet->runAction(actions);
        if(enemyblood<=0)
        {
            score += 50;
            gotodie(2);
        }
       
    }
    if(whogodie==3)
    {
        hero_blood-=enemy2_gongjili;
        bullet3inhero=1;
        bullet3->stopAllActions();
        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()-enemy2_gongjili);
        auto callbackfunc = [=]()
        {
            
            bullet3inair=0;
            bullet3->setVisible(false);
            bullet3->setPosition(50,50);
            bullet3inhero=0;
        };
        auto callFunc= CallFunc::create(callbackfunc);
        auto actions = Sequence::create(DelayTime::create(0.15),callFunc,NULL);
        bullet3->runAction(actions);
        if(hero_blood<=0)
        {
            gotodie(1);
        }
    }
    if(whogodie==4)
    {
        enemy2blood-=10;
        bulletinenemy=1;
        bullet->stopAllActions();
        enemy2_pProgressView->setCurrentProgress(enemy2_pProgressView->getCurrentProgress()-10);//更改血量
        score += 10;
        auto callbackfunc = [=]()
        {
            
            isbullet=0;
            bullet->setVisible(false);
            bullet->setPosition(50,50);
            bulletinenemy=0;
        };
        auto callFunc=CallFunc::create(callbackfunc);
        auto actions = Sequence::create(DelayTime::create(0.15),callFunc,NULL);
        bullet->runAction(actions);
        if(enemy2blood<=0)
        {
            score += 50;
            gotodie(3);
        }
    }
    if(whogodie==5)
    {
        hero_blood-=enemy3_gongjili;
        bullet4inhero=1;
        bullet4->stopAllActions();
        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()-enemy3_gongjili);
        auto callbackfunc = [=]()
        {
            bullet4inair=0;
            bullet4->setVisible(false);
            bullet4->setPosition(50,50);
            bullet4inhero=0;
        };
        auto callFunc= CallFunc::create(callbackfunc);
        auto actions = Sequence::create(DelayTime::create(0.15),callFunc,NULL);
        bullet4->runAction(actions);
        if(hero_blood<=0)
        {
            gotodie(1);
        }
    }
    if(whogodie==6)
    {
        enemy3blood-=10;
        bulletinenemy=1;
        bullet->stopAllActions();
        enemy3_pProgressView->setCurrentProgress(enemy3_pProgressView->getCurrentProgress()-10);//更改血量
        score += 10;
        auto callbackfunc = [=]()
        {
            isbullet=0;
            bullet->setVisible(false);
            bullet->setPosition(50,50);
            bulletinenemy=0;
        };
        auto callFunc=CallFunc::create(callbackfunc);
        auto actions = Sequence::create(DelayTime::create(0.15),callFunc,NULL);
        bullet->runAction(actions);
        if(enemy3blood<=0)
        {
            score += 50;
            gotodie(4);
        }
    }
}

void Hero::gotodie(int who)
{
    if(who==1)
    {
        UserDefault::getInstance()->setIntegerForKey("score", score);
        auto callbackfunc1 = [=]()
        {
            deadttf -> setVisible(true);
        };
        auto callbackfunc2 = [=]()
        {
            deadttf -> setVisible(false);
        };
        auto callbackfunc3 = [=]()
        {
            ifendgame = 1;
        };
        hero->stopAllActions();
        auto callfunc3=CallFunc::create(callbackfunc3);
        auto callFunc1=CallFunc::create(callbackfunc1);
        auto callFunc2=CallFunc::create(callbackfunc2);
        auto actions = Sequence::create(callFunc1,DelayTime::create(0.2),callFunc2,DelayTime::create(0.2),callFunc1,DelayTime::create(0.2),callFunc2,DelayTime::create(0.2),callFunc1,callfunc3,NULL);
        deadttf->runAction(actions);
  
    }
    if(who==2)
    {
        enemylive = 0;
        auto callbackfunc1 = [=]()
        {
            enemy->setVisible(false);
        };
        auto callbackfunc2 = [=]()
        {
            enemy->setVisible(true);
        };
        auto callbackfunc3 = [=]()
        {
            bullet2->setVisible(false);
            bullet2->setPosition(50,50);
            enemy->setPosition(250,250);
            enemy->removeFromParent();
        };
        enemy->stopAllActions();
        auto callFunc1=CallFunc::create(callbackfunc1);
        auto callFunc2=CallFunc::create(callbackfunc2);
        auto callFunc3=CallFunc::create(callbackfunc3);
        auto actions = Sequence::create(callFunc1,DelayTime::create(0.2),callFunc2,DelayTime::create(0.2),callFunc1,DelayTime::create(0.2),callFunc2,DelayTime::create(0.2),callFunc1,callFunc3,NULL);
        enemy->runAction(actions);
        enemytime = time + 300;
    }
    if(who==3)
    {
        enemy2live = 0;
        auto callbackfunc1 = [=]()
        {
            enemy2->setVisible(false);
        };
        auto callbackfunc2 = [=]()
        {
            enemy2->setVisible(true);
        };
        auto callbackfunc3 = [=]()
        {
            bullet3->setVisible(false);
            bullet3->setPosition(50,50);
            enemy2->setPosition(250,250);
            enemy2->removeFromParent();
        };
        enemy2->stopAllActions();
        auto callFunc1=CallFunc::create(callbackfunc1);
        auto callFunc2=CallFunc::create(callbackfunc2);
        auto callFunc3=CallFunc::create(callbackfunc3);
        auto actions = Sequence::create(callFunc1,DelayTime::create(0.2),callFunc2,DelayTime::create(0.2),callFunc1,DelayTime::create(0.2),callFunc2,DelayTime::create(0.2),callFunc1,callFunc3,NULL);
        enemy2->runAction(actions);
        enemy2time = time + 300;
    }
    if(who==4)
    {
        enemy3live = 0;
        auto callbackfunc1 = [=]()
        {
            enemy3->setVisible(false);
        };
        auto callbackfunc2 = [=]()
        {
            enemy3->setVisible(true);
        };
        auto callbackfunc3 = [=]()
        {
            bullet4->setVisible(false);
            bullet4->setPosition(50,50);
            enemy3->setPosition(250,250);
            enemy3->removeFromParent();
        };
        enemy3->stopAllActions();
        auto callFunc1=CallFunc::create(callbackfunc1);
        auto callFunc2=CallFunc::create(callbackfunc2);
        auto callFunc3=CallFunc::create(callbackfunc3);
        auto actions = Sequence::create(callFunc1,DelayTime::create(0.2),callFunc2,DelayTime::create(0.2),callFunc1,DelayTime::create(0.2),callFunc2,DelayTime::create(0.2),callFunc1,callFunc3,NULL);
        enemy3->runAction(actions);
        enemy3time = time + 300;
    }
}


void Hero::getenemydirection(int enemycode)
{
    if(enemycode==1)
    {
        if((enemy_x-hero_x)>=0)
        {
            if((enemy_y-hero_y)>=0)
            {
                if((enemy_y-hero_y)>=(enemy_x-hero_x))
                {
                    enemydirection=1;
                }
                else
                {
                    enemydirection=3;
                }
            }
            if((enemy_y-hero_y)<0)
            {
                if((hero_y-enemy_y)>=(enemy_x-hero_x))
                {
                    enemydirection=2;
                }
                else
                {
                    enemydirection=3;
                }
            }
        }
        if((enemy_x-hero_x)<0)
        {
            if((enemy_y-hero_y)>0)
            {
                if((hero_x-enemy_x)>=(enemy_y-hero_y))
                {
                    enemydirection=4;
                }
                else
                {
                    enemydirection=1;
                }
            }
            if((enemy_y-hero_y)<0)
            {
                if((hero_x-enemy_x)>=(hero_y-enemy_y))
                {
                    enemydirection=4;
                }
                else
                {
                    enemydirection=2;
                }
            }
        }
    }
}



void Hero::enemyattack()
{
    bullet2->setVisible(true);
    float deltx,delty;
    deltx = enemy_x - hero_x;
    delty = enemy_y - hero_y;
    float delta = sqrt(deltx*deltx + delty*delty);
    float ex = deltx/delta;
    float ey = delty/delta;
    int n = enemy_shecheng;//shecheng
    bullet2->setPosition(enemy_x, enemy_y);
    bullet2->setVisible(true);
    bullet2inair=1;
    auto fire = MoveBy::create(0.3,Vec2(-n*ex,-n*ey));
    auto callbackfunc = [=]()
    {
        bullet2->setVisible(false);
        bullet2->setPosition(50,50);
        bullet2inair=0;
    };
    auto callFunc=CallFunc::create(callbackfunc);
    auto actions = Sequence::create(fire,DelayTime::create(0.15),callFunc,NULL);
    bullet2->runAction(actions);
}



void Hero::itemtimecoming()
{
    for(int i=1;i<11;i++)
    {
        if(isitemlive[i]==0)
        {
            if(i==1)
            {
                auto pos = getitemcreatpos();
                int ran = random(1, 10);
                log(" %d  is    %f   %f",i,pos.x,pos.y);
                if(ran<4)
                {
                    isitemlive[i]=1;
                    item1 = Sprite::create("item/shoes.png");
                    item1->setPosition(pos);
                    addChild(item1,5);
                    item1->setScale(0.5,0.5);
                }
                else if(ran<8)
                {
                    isitemlive[i]=2;
                    item1 = Sprite::create("item/healthpotion.png");
                    item1->setPosition(pos);
                    addChild(item1,5);
                    item1->setScale(0.2,0.2);
                }
                else if(ran<11)
                {
                    isitemlive[i]=3;
                    item1 = Sprite::create("item/attackboost.png");
                    item1->setPosition(pos);
                    addChild(item1,5);
                    item1->setScale(0.5,0.5);
                }
                break;
            }
            if(i==2)
            {
                auto pos = getitemcreatpos();
                int ran = random(1, 10);
                log(" %d  is    %f   %f",i,pos.x,pos.y);
                if(ran<4)
                {
                    isitemlive[i]=1;
                    item2 = Sprite::create("item/shoes.png");
                    item2->setPosition(pos);
                    addChild(item2,5);
                    item2->setScale(0.5,0.5);
                }
                else if(ran<8)
                {
                    isitemlive[i]=2;
                    item2 = Sprite::create("item/healthpotion.png");
                    item2->setPosition(pos);
                    addChild(item2,5);
                    item2->setScale(0.2,0.2);
                }
                else if(ran<11)
                {
                    isitemlive[i]=3;
                    item2 = Sprite::create("item/attackboost.png");
                    item2->setPosition(pos);
                    addChild(item2,5);
                    item2->setScale(0.5,0.5);
                }
                break;
            }
            if(i==3)
            {
                auto pos = getitemcreatpos();
                int ran = random(1, 10);
                log(" %d  is    %f   %f",i,pos.x,pos.y);
                if(ran<4)
                {
                    isitemlive[i]=1;
                    item3 = Sprite::create("item/shoes.png");
                    item3->setPosition(pos);
                    addChild(item3,5);
                    item3->setScale(0.5,0.5);
                }
                else if(ran<8)
                {
                    isitemlive[i]=2;
                    item3 = Sprite::create("item/healthpotion.png");
                    item3->setPosition(pos);
                    addChild(item3,5);
                    item3->setScale(0.2,0.2);
                }
                else if(ran<11)
                {
                    isitemlive[i]=3;
                    item3 = Sprite::create("item/attackboost.png");
                    item3->setPosition(pos);
                    addChild(item3,5);
                    item3->setScale(0.5,0.5);
                }
                break;
            }
            if(i==4)
            {
                auto pos = getitemcreatpos();
                int ran = random(1, 10);
                log(" %d  is    %f   %f",i,pos.x,pos.y);
                if(ran<4)
                {
                    isitemlive[i]=1;
                    item4 = Sprite::create("item/shoes.png");
                    item4->setPosition(pos);
                    addChild(item4,5);
                    item4->setScale(0.5,0.5);
                }
                else if(ran<8)
                {
                    isitemlive[i]=2;
                    item4 = Sprite::create("item/healthpotion.png");
                    item4->setPosition(pos);
                    addChild(item4,5);
                    item4->setScale(0.2,0.2);
                }
                else if(ran<11)
                {
                    isitemlive[i]=3;
                    item4 = Sprite::create("item/attackboost.png");
                    item4->setPosition(pos);
                    addChild(item4,5);
                    item4->setScale(0.5,0.5);
                }
                break;
            }
            if(i==5)
            {
                auto pos = getitemcreatpos();
                int ran = random(1, 10);
                log(" %d  is    %f   %f",i,pos.x,pos.y);
                if(ran<4)
                {
                    isitemlive[i]=1;
                    item5 = Sprite::create("item/shoes.png");
                    item5->setPosition(pos);
                    addChild(item5,5);
                    item5->setScale(0.5,0.5);
                }
                else if(ran<8)
                {
                    isitemlive[i]=2;
                    item5 = Sprite::create("item/healthpotion.png");
                    item5->setPosition(pos);
                    addChild(item5,5);
                    item5->setScale(0.2,0.2);
                }
                else if(ran<11)
                {
                    isitemlive[i]=3;
                    item5 = Sprite::create("item/attackboost.png");
                    item5->setPosition(pos);
                    addChild(item5,5);
                    item5->setScale(0.5,0.5);
                }
                break;
            }
            if(i==6)
            {
                auto pos = getitemcreatpos();
                int ran = random(1, 10);
                log(" %d  is    %f   %f",i,pos.x,pos.y);
                if(ran<4)
                {
                    isitemlive[i]=1;
                    item6 = Sprite::create("item/shoes.png");
                    item6->setPosition(pos);
                    addChild(item6,5);
                    item6->setScale(0.5,0.5);
                }
                else if(ran<8)
                {
                    isitemlive[i]=2;
                    item6 = Sprite::create("item/healthpotion.png");
                    item6->setPosition(pos);
                    addChild(item6,5);
                    item6->setScale(0.2,0.2);
                }
                else if(ran<11)
                {
                    isitemlive[i]=3;
                    item6 = Sprite::create("item/attackboost.png");
                    item6->setPosition(pos);
                    addChild(item6,5);
                    item6->setScale(0.5,0.5);
                }
                break;
            }
            if(i==7)
            {
                auto pos = getitemcreatpos();
                int ran = random(1, 10);
                log(" %d  is    %f   %f",i,pos.x,pos.y);
                if(ran<4)
                {
                    isitemlive[i]=1;
                    item7 = Sprite::create("item/shoes.png");
                    item7->setPosition(pos);
                    addChild(item7,5);
                    item7->setScale(0.5,0.5);
                }
                else if(ran<8)
                {
                    isitemlive[i]=2;
                    item7 = Sprite::create("item/healthpotion.png");
                    item7->setPosition(pos);
                    addChild(item7,5);
                    item7->setScale(0.2,0.2);
                }
                else if(ran<11)
                {
                    isitemlive[i]=3;
                    item7 = Sprite::create("item/attackboost.png");
                    item7->setPosition(pos);
                    addChild(item7,5);
                    item7->setScale(0.5,0.5);
                }
                break;
            }
            if(i==8)
            {
                auto pos = getitemcreatpos();
                int ran = random(1, 10);
                log(" %d  is    %f   %f",i,pos.x,pos.y);
                if(ran<4)
                {
                    isitemlive[i]=1;
                    item8 = Sprite::create("item/shoes.png");
                    item8->setPosition(pos);
                    addChild(item8,5);
                    item8->setScale(0.5,0.5);
                }
                else if(ran<8)
                {
                    isitemlive[i]=2;
                    item8 = Sprite::create("item/healthpotion.png");
                    item8->setPosition(pos);
                    addChild(item8,5);
                    item8->setScale(0.2,0.2);
                }
                else if(ran<11)
                {
                    isitemlive[i]=3;
                    item8 = Sprite::create("item/attackboost.png");
                    item8->setPosition(pos);
                    addChild(item8,5);
                    item8->setScale(0.5,0.5);
                }
                break;
            }
            if(i==9)
            {
                auto pos = getitemcreatpos();
                int ran = random(1, 10);
                log(" %d  is    %f   %f",i,pos.x,pos.y);
                if(ran<4)
                {
                    isitemlive[i]=1;
                    item9 = Sprite::create("item/shoes.png");
                    item9->setPosition(pos);
                    addChild(item9,5);
                    item9->setScale(0.5,0.5);
                }
                else if(ran<8)
                {
                    isitemlive[i]=2;
                    item9 = Sprite::create("item/healthpotion.png");
                    item9->setPosition(pos);
                    addChild(item9,5);
                    item9->setScale(0.2,0.2);
                }
                else if(ran<11)
                {
                    isitemlive[i]=3;
                    item9 = Sprite::create("item/attackboost.png");
                    item9->setPosition(pos);
                    addChild(item9,5);
                    item9->setScale(0.5,0.5);
                }
                break;
            }
            if(i==10)
            {
                auto pos = getitemcreatpos();
                int ran = random(1, 10);
                log(" %d  is    %f   %f",i,pos.x,pos.y);
                if(ran<4)
                {
                    isitemlive[i]=1;
                    item10 = Sprite::create("item/shoes.png");
                    item10->setPosition(pos);
                    addChild(item10,5);
                    item10->setScale(0.5,0.5);
                }
                else if(ran<8)
                {
                    isitemlive[i]=2;
                    item10 = Sprite::create("item/healthpotion.png");
                    item10->setPosition(pos);
                    addChild(item10,5);
                    item10->setScale(0.2,0.2);
                }
                else if(ran<11)
                {
                    isitemlive[i]=3;
                    item10 = Sprite::create("item/attackboost.png");
                    item10->setPosition(pos);
                    addChild(item10,5);
                    item10->setScale(0.5,0.5);
                }
                break;
            }
        }
    }
}



Point Hero::getitemcreatpos()
{
    float x=0,y=0;
    for(;;)
    {
        x=random(350 , 3500);
        y=random(350 , 2500);
        Point pos=positiontrans(Point(x+30,y+30));
        if(  !(map->getLayer("move")-> getTileGIDAt(Point(pos.x,pos.y)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x+1,pos.y)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x,pos.y+1)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x-1,pos.y)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x,pos.y-1)))
           )
        {
            break;
        }
    }
    return Point(x,y);
}


void Hero::itempop()
{
    for(int i=1;i<11;i++)
    {
        if(isitemlive[i])
        {
            if(i==1)
            {
                if( ( ( hero_x < item1->getPosition().x+50 ) && ( hero_x+90 > item1->getPosition().x+50 )
                   && ( hero_y < item1->getPosition().y+35 ) && ( hero_y+90 > item1->getPosition().y+35 )
                   ) )
                {
                    item1->removeFromParent();
                    if(isitemlive[i]==1&&hero_speed<=10)
                    {
                        hero_speed+=0.5;
                    }
                    if(isitemlive[i]==2&&hero_blood<100)
                    {
                        int n=100-hero_blood;
                        if(n>30)
                        {
                            n = 30;
                        }
                        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()+n);
                        hero_blood+=n;
                    }
                    if(isitemlive[i]==3)
                    {
                        if(hero_shecheng<400)
                        {
                            hero_shecheng+=15;
                        };
                    }
                    isitemlive[i]=0;
                }
            }
            if(i==2)
            {
                if(( hero_x < item2->getPosition().x+50 ) && ( hero_x+90 > item2->getPosition().x+50 )
                   && ( hero_y < item2->getPosition().y+35 ) && ( hero_y+90 > item2->getPosition().y+35 )
                   )
                {
                    item2->removeFromParent();
                    if(isitemlive[i]==1&&hero_speed<=10)
                    {
                        hero_speed+=0.5;
                    }
                    if(isitemlive[i]==2&&hero_blood<100)
                    {
                        int n=100-hero_blood;
                        if(n>30)
                        {
                            n = 30;
                        }
                        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()+n);
                        hero_blood+=n;
                    }
                    if(isitemlive[i]==3)
                    {
                        if(hero_shecheng<400)
                        {
                            hero_shecheng+=15;
                        };
                    }
                    isitemlive[i]=0;
                }
            }
            if(i==3)
            {
                if(( hero_x < item3->getPosition().x+50 ) && ( hero_x+90 > item3->getPosition().x+50 )
                   && ( hero_y < item3->getPosition().y+35 ) && ( hero_y+90 > item3->getPosition().y+35 )
                   )
                {
                    item3->removeFromParent();
                    if(isitemlive[i]==1&&hero_speed<=10)
                    {
                        hero_speed+=0.5;
                    }
                    if(isitemlive[i]==2&&hero_blood<100)
                    {
                        int n=100-hero_blood;
                        if(n>30)
                        {
                            n = 30;
                        }
                        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()+n);
                        hero_blood+=n;
                    }
                    if(isitemlive[i]==3)
                    {
                        if(hero_shecheng<400)
                        {
                            hero_shecheng+=15;
                        };
                    }
                    isitemlive[i]=0;
                }
            }
            if(i==4)
            {
                if(( hero_x < item4->getPosition().x+50 ) && ( hero_x+90 > item4->getPosition().x+50 )
                   && ( hero_y < item4->getPosition().y+35 ) && ( hero_y+90 > item4->getPosition().y+35 )
                   )
                {
                    item4->removeFromParent();
                    if(isitemlive[i]==1&&hero_speed<=10)
                    {
                        hero_speed+=0.5;
                    }
                    if(isitemlive[i]==2&&hero_blood<100)
                    {
                        int n=100-hero_blood;
                        if(n>30)
                        {
                            n = 30;
                        }
                        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()+n);
                        hero_blood+=n;
                    }
                    if(isitemlive[i]==3)
                    {
                        if(hero_shecheng<400)
                        {
                            hero_shecheng+=15;
                        };
                    }
                    isitemlive[i]=0;
                }
            }
            if(i==5)
            {
                if(( hero_x < item5->getPosition().x+50 ) && ( hero_x+90 > item5->getPosition().x+50 )
                   && ( hero_y < item5->getPosition().y+35 ) && ( hero_y+90 > item5->getPosition().y+35 )
                   )
                {
                    item5->removeFromParent();
                    if(isitemlive[i]==1&&hero_speed<=10)
                    {
                        hero_speed+=0.5;
                    }
                    if(isitemlive[i]==2&&hero_blood<100)
                    {
                        int n=100-hero_blood;
                        if(n>30)
                        {
                            n = 30;
                        }
                        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()+n);
                        hero_blood+=n;
                    }
                    if(isitemlive[i]==3)
                    {
                        if(hero_shecheng<400)
                        {
                            hero_shecheng+=15;
                        };
                    }
                    isitemlive[i]=0;
                }
            }
            if(i==6)
            {
                if(( hero_x < item6->getPosition().x+50 ) && ( hero_x+90 > item6->getPosition().x+50 )
                   && ( hero_y < item6->getPosition().y+35 ) && ( hero_y+90 > item6->getPosition().y+35 )
                   )
                {
                    item6->removeFromParent();
                    if(isitemlive[i]==1&&hero_speed<=10)
                    {
                        hero_speed+=0.5;
                    }
                    if(isitemlive[i]==2&&hero_blood<100)
                    {
                        int n=100-hero_blood;
                        if(n>30)
                        {
                            n = 30;
                        }
                        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()+n);
                        hero_blood+=n;
                    }
                    if(isitemlive[i]==3)
                    {
                        if(hero_shecheng<400)
                        {
                            hero_shecheng+=15;
                        };
                    }
                    isitemlive[i]=0;
                }
            }
            if(i==7)
            {
                if(( hero_x < item7->getPosition().x+50 ) && ( hero_x+90 > item7->getPosition().x+50 )
                   && ( hero_y < item7->getPosition().y+35 ) && ( hero_y+90 > item7->getPosition().y+35 )
                   )
                {
                    item7->removeFromParent();
                    if(isitemlive[i]==1&&hero_speed<=10)
                    {
                        hero_speed+=0.5;
                    }
                    if(isitemlive[i]==2&&hero_blood<100)
                    {
                        int n=100-hero_blood;
                        if(n>30)
                        {
                            n = 30;
                        }
                        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()+n);
                        hero_blood+=n;
                    }
                    if(isitemlive[i]==3)
                    {
                        if(hero_shecheng<400)
                        {
                            hero_shecheng+=15;
                        };
                    }
                    isitemlive[i]=0;
                }
            }
            if(i==8)
            {
                if(( hero_x < item8->getPosition().x+50 ) && ( hero_x+90 > item8->getPosition().x+50 )
                   && ( hero_y < item8->getPosition().y+35 ) && ( hero_y+90 > item8->getPosition().y+35 )
                   )
                {
                    item8->removeFromParent();
                    if(isitemlive[i]==1&&hero_speed<=10)
                    {
                        hero_speed+=0.5;
                    }
                    if(isitemlive[i]==2&&hero_blood<100)
                    {
                        int n=100-hero_blood;
                        if(n>30)
                        {
                            n = 30;
                        }
                        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()+n);
                        hero_blood+=n;
                    }
                    if(isitemlive[i]==3)
                    {
                        if(hero_shecheng<400)
                        {
                            hero_shecheng+=15;
                        };
                    }
                    isitemlive[i]=0;
                }
            }
            if(i==9)
            {
                if(( hero_x < item9->getPosition().x+50 ) && ( hero_x+90 > item9->getPosition().x+50 )
                   && ( hero_y < item9->getPosition().y+35 ) && ( hero_y+90 > item9->getPosition().y+35 )
                   )
                {
                    item9->removeFromParent();
                    if(isitemlive[i]==1&&hero_speed<=10)
                    {
                        hero_speed+=0.5;
                    }
                    if(isitemlive[i]==2&&hero_blood<100)
                    {
                        int n=100-hero_blood;
                        if(n>30)
                        {
                            n = 30;
                        }
                        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()+n);
                        hero_blood+=n;
                    }
                    if(isitemlive[i]==3)
                    {
                        if(hero_shecheng<400)
                        {
                            hero_shecheng+=15;
                        };
                    }
                    isitemlive[i]=0;
                }
            }
            if(i==10)
            {
                if(( hero_x < item10->getPosition().x+50 ) && ( hero_x+90 > item10->getPosition().x+50 )
                   && ( hero_y < item10->getPosition().y+35 ) && ( hero_y+90 > item10->getPosition().y+35 )
                   )
                {
                    item10->removeFromParent();
                    if(isitemlive[i]==1&&hero_speed<=10)
                    {
                        hero_speed+=0.5;
                    }
                    if(isitemlive[i]==2&&hero_blood<100)
                    {
                        int n=100-hero_blood;
                        if(n>30)
                        {
                            n = 30;
                        }
                        m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()+n);
                        hero_blood+=n;
                    }
                    if(isitemlive[i]==3)
                    {
                        if(hero_shecheng<400)
                        {
                            hero_shecheng+=15;
                        };
                    }
                    isitemlive[i]=0;
                }
            }
        }
    }
}



void Hero::enemyforup()
{
    if(time==enemytime&&!enemylive)
    {
        enemycoming();
        enemymovetime=enemytime;
        enemyacktime=enemytime;
    }
    if(enemylive)
    {
        enemy_x = enemy->getPositionX();
        enemy_y = enemy->getPositionY();
        if(time==enemymovetime)
        {
            enemymove();
            enemymovetime+=18;
        }
        if(time==enemyacktime)
        {
            enemyattack();
            enemyacktime+=enemy_shesu;
        }
    }
    if( (bullet2inair) &&(!bullet2inwall) )
    {
        couldbullet2go();
    }
}


void Hero::couldbullet2go()
{
    Point pos=positiontrans(bullet2->getPosition());
    int tiledID = map->getLayer("move")->getTileGIDAt(pos);
    if(tiledID)
    {
        bullet2inwall=1;
        bullet2->stopAllActions();
        auto callbackfunc = [=]()
        {
            bullet2inair=0;
            bullet2->setVisible(false);
            bullet2->setPosition(50,50);
            bullet2inwall=0;
        };
        auto callFunc=CallFunc::create(callbackfunc);
        auto actions=Sequence::create(DelayTime::create(0.15),callFunc,NULL);
        bullet2->runAction(actions);
    }
}



Point Hero::getenemypos()
{
    float x=0,y=0;
    for(;;)
    {
        x = random(500 , 3200);
        y = random(500 , 2000);
        Point pos = positiontrans(Point(x+30,y+30));
        if(  !(map->getLayer("move")-> getTileGIDAt(Point(pos.x,pos.y)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x+3,pos.y)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x,pos.y+3)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x-3,pos.y)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x,pos.y-3)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x+2,pos.y)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x,pos.y+2)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x-2,pos.y)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x,pos.y-2)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x+1,pos.y)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x,pos.y+1)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x-1,pos.y)))
           &&!(map->getLayer("move")-> getTileGIDAt(Point(pos.x,pos.y-1)))
           )
        {
            break;
        }
    }
    return Point(x,y);
}



void Hero::enemy2coming()
{
    enemy2= Sprite::createWithSpriteFrameName("11001.png");
    addChild(enemy2,2);
    enemy2->setPosition(getenemypos());
    auto enemy2_animation1 = Animation::createWithSpriteFrames(enemy2_animFrames1, 0.3);
    enemy2->runAction(RepeatForever::create(Animate::create(enemy2_animation1))); //测试动画
    enemy2live=1;
    enemy2blood=100;
    if(enemy2_speed<=30)
    {
        enemy2_speed+=2;
    }
    if(enemy2_shesu>=50)
    {
        enemy2_shesu-=10;
    }
    if(enemy2_gongjili<=50)
    {
        enemy2_gongjili+=5;
    }
    if(enemy2_shecheng<=600)
    {
        enemy2_shecheng+=30;
    }
    enemy2_x=enemy2->getPositionX();
    enemy2_y=enemy2->getPositionY();
    enemy2_pProgressView = new ProgressView();
    enemy2_pProgressView->setScale(1,0.5);
    enemy2_pProgressView->setPosition(330,450);
    enemy2_pProgressView->setBackgroundTexture("item/noblood.png");
    enemy2_pProgressView->setForegroundTexture("item/fullblood.png");
    enemy2_pProgressView->setTotalProgress(100.0f);
    enemy2_pProgressView->setCurrentProgress(100.0f);
    enemy2->addChild(enemy2_pProgressView,5);
}


void Hero::enemy2forup()
{
    if(time==enemy2time&&!enemy2live)
    {
        enemy2coming();
        enemy2movetime=enemy2time;
        enemy2acktime=enemy2time;
    }
    if(enemy2live)
    {
        enemy2_x = enemy2->getPositionX();
        enemy2_y = enemy2->getPositionY();
        if(time==enemy2movetime)
        {
            enemy2move();
            enemy2movetime+=18;
        }
        if(time==enemy2acktime+15)
        {
            enemy2attack();
            enemy2acktime+=enemy2_shesu;
        }
    }
    if( (bullet3inair) &&(!bullet3inwall) )
    {
        couldbullet3go();
    }
}

void Hero::enemy2move()
{
    getenemy2direction(1);
    int i = enemy2direction;
    for(;;)
    {
        if(canenemy2go(i))
        {
            break;
        }
        i = random(1, 4);
    }
    switch (i)
    {
        case 1:
        {
            enemy2->stopAllActions();
            auto enemy2_animation1 = Animation::createWithSpriteFrames(enemy2_animFrames1, 0.3);
            enemy2->runAction(RepeatForever::create(Animate::create(enemy2_animation1))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(0,-enemy2_speed));
            enemy2->runAction(moveby);
            break;
        }
        case 2:
        {
            enemy2->stopAllActions();
            auto enemy2_animation2 = Animation::createWithSpriteFrames(enemy2_animFrames2, 0.3);
            enemy2->runAction(RepeatForever::create(Animate::create(enemy2_animation2))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(0,enemy2_speed));
            enemy2->runAction(moveby);
            break;
        }
        case 3:
        {
            enemy2->stopAllActions();
            auto enemy2_animation3 = Animation::createWithSpriteFrames(enemy2_animFrames3, 0.3);
            enemy2->runAction(RepeatForever::create(Animate::create(enemy2_animation3))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(-enemy2_speed,0));
            enemy2->runAction(moveby);
            break;
        }
        case 4:
        {
            enemy2->stopAllActions();
            auto enemy2_animation4 = Animation::createWithSpriteFrames(enemy2_animFrames4, 0.3);
            enemy2->runAction(RepeatForever::create(Animate::create(enemy2_animation4))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(enemy2_speed,0));
            enemy2->runAction(moveby);
            break;
        }
    }
}



void Hero::enemy2attack()
{
    bullet3->setVisible(true);
    float deltx,delty;
    deltx = enemy2_x - hero_x;
    delty = enemy2_y - hero_y;
    float delta = sqrt(deltx*deltx + delty*delty);
    float ex = deltx/delta;
    float ey = delty/delta;
    int n = enemy2_shecheng;//shecheng
    bullet3->setPosition(enemy2_x, enemy2_y);
    bullet3->setVisible(true);
    bullet3inair=1;
    auto fire = MoveBy::create(0.3,Vec2(-n*ex,-n*ey));
    auto callbackfunc = [=]()
    {
        bullet3->setVisible(false);
        bullet3->setPosition(50,50);
        bullet3inair=0;
    };
    auto callFunc=CallFunc::create(callbackfunc);
    auto actions = Sequence::create(fire,DelayTime::create(0.15),callFunc,NULL);
    bullet3->runAction(actions);
}


void Hero::couldbullet3go()
{
    Point pos=positiontrans(bullet3->getPosition());
    int tiledID = map->getLayer("move")->getTileGIDAt(pos);
    if(tiledID)
    {
        bullet3inwall=1;
        bullet3->stopAllActions();
        auto callbackfunc = [=]()
        {
            bullet3inair=0;
            bullet3->setVisible(false);
            bullet3->setPosition(50,50);
            bullet3inwall=0;
        };
        auto callFunc=CallFunc::create(callbackfunc);
        auto actions=Sequence::create(DelayTime::create(0.15),callFunc,NULL);
        bullet3->runAction(actions);
    }
}


bool Hero::canenemy2go(int direction)
{
    Point temp=Point(0,0);
    Point enemy2temp=Point(0,0);
    if(direction==1)
    {
        temp=Point(1,1);
    }
    if(direction==2)
    {
        temp=Point(1,-3);
    }
    if(direction==3)
    {
        temp=Point(0,-2);
    }
    if(direction==4)
    {
        temp=Point(3,0);
    }
    auto maplayer = map->getLayer("move");
    Point pos=positiontrans(enemy2->getPosition());
    int tiledID =  maplayer -> getTileGIDAt(pos+temp);
//    if(    ( (enemy2->getPositionX ()) < (enemy3->getPositionX ()   )  )
//       &&  ( (enemy3->getPositionX() ) < (enemy2->getPositionX ()+60)  )
//       &&  ( (enemy2->getPositionY() ) < (enemy3->getPositionY ()   )  )
//       &&  ( (enemy3->getPositionY() ) < (enemy2->getPositionY ()+80)  ) )
//    {
//        tiledID = 1 ;
//    }
    if(tiledID==0)
    {
        return true;
    }
    else if(tiledID!=0)
    {
        return false;
    }
}


void Hero::getenemy2direction(int enemy2code)
{
    if(enemy2code==1)
    {
        if((enemy2_x-hero_x)>=0)
        {
            if((enemy2_y-hero_y)>=0)
            {
                if((enemy2_y-hero_y)>=(enemy2_x-hero_x))
                {
                    enemy2direction=1;
                }
                else
                {
                    enemy2direction=3;
                }
            }
            if((enemy2_y-hero_y)<0)
            {
                if((hero_y-enemy2_y)>=(enemy2_x-hero_x))
                {
                    enemy2direction=2;
                }
                else
                {
                    enemy2direction=3;
                }
            }
        }
        if((enemy2_x-hero_x)<0)
        {
            if((enemy2_y-hero_y)>0)
            {
                if((hero_x-enemy2_x)>=(enemy2_y-hero_y))
                {
                    enemy2direction=4;
                }
                else
                {
                    enemy2direction=1;
                }
            }
            if((enemy2_y-hero_y)<0)
            {
                if((hero_x-enemy2_x)>=(hero_y-enemy2_y))
                {
                    enemy2direction=4;
                }
                else
                {
                    enemy2direction=2;
                }
            }
        }
    }
}


//enemy3





void Hero::enemy3coming()
{
    enemy3= Sprite::createWithSpriteFrameName("11001.png");
    addChild(enemy3,2);
    enemy3->setPosition(getenemypos());
    auto enemy3_animation1 = Animation::createWithSpriteFrames(enemy3_animFrames1, 0.3);
    enemy3->runAction(RepeatForever::create(Animate::create(enemy3_animation1))); //测试动画
    enemy3live=1;
    enemy3blood=100;
    if(enemy3_speed<=30)
    {
        enemy3_speed+=2;
    }
    if(enemy3_shesu>=50)
    {
        enemy3_shesu-=10;
    }
    if(enemy3_gongjili<=50)
    {
        enemy3_gongjili+=5;
    }
    if(enemy3_shecheng<=600)
    {
        enemy3_shecheng+=30;
    }
    enemy3_x=enemy3->getPositionX();
    enemy3_y=enemy3->getPositionY();
    enemy3_pProgressView = new ProgressView();
    enemy3_pProgressView->setScale(1,0.5);
    enemy3_pProgressView->setPosition(330,450);
    enemy3_pProgressView->setBackgroundTexture("item/noblood.png");
    enemy3_pProgressView->setForegroundTexture("item/fullblood.png");
    enemy3_pProgressView->setTotalProgress(100.0f);
    enemy3_pProgressView->setCurrentProgress(100.0f);
    enemy3->addChild(enemy3_pProgressView,5);
}


void Hero::enemy3forup()
{
    if(time==enemy3time&&!enemy3live)
    {
        enemy3coming();
        enemy3movetime=enemy3time;
        enemy3acktime=enemy3time;
    }
    if(enemy3live)
    {
        enemy3_x = enemy3->getPositionX();
        enemy3_y = enemy3->getPositionY();
        if(time==enemy3movetime)
        {
            enemy3move();
            enemy3movetime+=18;
        }
        if(time==enemy3acktime+30)
        {
            enemy3attack();
            enemy3acktime+=enemy3_shesu;
        }
    }
    if( (bullet4inair) &&(!bullet4inwall) )
    {
        couldbullet4go();
    }
}

void Hero::enemy3move()
{
    getenemy3direction(1);
    int i = enemy3direction;
    for(;;)
    {
        if(canenemy3go(i))
        {
            break;
        }
        i = random(1, 4);
    }
    switch (i)
    {
        case 1:
        {
            enemy3->stopAllActions();
            auto enemy3_animation1 = Animation::createWithSpriteFrames(enemy3_animFrames1, 0.3);
            enemy3->runAction(RepeatForever::create(Animate::create(enemy3_animation1))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(0,-enemy3_speed));
            enemy3->runAction(moveby);
            break;
        }
        case 2:
        {
            enemy3->stopAllActions();
            auto enemy3_animation2 = Animation::createWithSpriteFrames(enemy3_animFrames2, 0.3);
            enemy3->runAction(RepeatForever::create(Animate::create(enemy3_animation2))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(0,enemy3_speed));
            enemy3->runAction(moveby);
            break;
        }
        case 3:
        {
            enemy3->stopAllActions();
            auto enemy3_animation3 = Animation::createWithSpriteFrames(enemy3_animFrames3, 0.3);
            enemy3->runAction(RepeatForever::create(Animate::create(enemy3_animation3))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(-enemy3_speed,0));
            enemy3->runAction(moveby);
            break;
        }
        case 4:
        {
            enemy3->stopAllActions();
            auto enemy3_animation4 = Animation::createWithSpriteFrames(enemy3_animFrames4, 0.3);
            enemy3->runAction(RepeatForever::create(Animate::create(enemy3_animation4))); //测试动画
            auto moveby=MoveBy::create(0.3,Point(enemy3_speed,0));
            enemy3->runAction(moveby);
            break;
        }
    }
}



void Hero::enemy3attack()
{
    bullet4->setVisible(true);
    float deltx,delty;
    deltx = enemy3_x - hero_x;
    delty = enemy3_y - hero_y;
    float delta = sqrt(deltx*deltx + delty*delty);
    float ex = deltx/delta;
    float ey = delty/delta;
    int n = enemy3_shecheng;//shecheng
    bullet4->setPosition(enemy3_x, enemy3_y);
    bullet4->setVisible(true);
    bullet4inair=1;
    auto fire = MoveBy::create(0.3,Vec2(-n*ex,-n*ey));
    auto callbackfunc = [=]()
    {
        bullet4->setVisible(false);
        bullet4->setPosition(50,50);
        bullet4inair=0;
    };
    auto callFunc=CallFunc::create(callbackfunc);
    auto actions = Sequence::create(fire,DelayTime::create(0.15),callFunc,NULL);
    bullet4->runAction(actions);
}


void Hero::couldbullet4go()
{
    Point pos=positiontrans(bullet4->getPosition());
    int tiledID = map->getLayer("move")->getTileGIDAt(pos);
    if(tiledID)
    {
        bullet4inwall=1;
        bullet4->stopAllActions();
        auto callbackfunc = [=]()
        {
            bullet4inair=0;
            bullet4->setVisible(false);
            bullet4->setPosition(50,50);
            bullet4inwall=0;
        };
        auto callFunc=CallFunc::create(callbackfunc);
        auto actions=Sequence::create(DelayTime::create(0.15),callFunc,NULL);
        bullet4->runAction(actions);
    }
}


bool Hero::canenemy3go(int direction)
{
    Point temp=Point(0,0);
    Point enemy3temp=Point(0,0);
    if(direction==1)
    {
        temp=Point(1,1);
    }
    if(direction==2)
    {
        temp=Point(1,-3);
    }
    if(direction==3)
    {
        temp=Point(0,-2);
    }
    if(direction==4)
    {
        temp=Point(3,0);
    }
    auto maplayer = map->getLayer("move");
    Point pos=positiontrans(enemy3->getPosition());
    int tiledID =  maplayer -> getTileGIDAt(pos+temp);
//    if(    ( (enemy3->getPositionX ()) < (enemy->getPositionX ()   )  )
//       &&  ( (enemy->getPositionX() ) < (enemy3->getPositionX ()+60)  )
//       &&  ( (enemy3->getPositionY() ) < (enemy->getPositionY ()   )  )
//       &&  ( (enemy->getPositionY() ) < (enemy3->getPositionY ()+80)  ) )
//    {
//        tiledID = 1 ;
//    }
    if(tiledID==0)
    {
        return true;
    }
    else if(tiledID!=0)
    {
        return false;
    }
}


void Hero::getenemy3direction(int enemy3code)
{
    if(enemy3code==1)
    {
        if((enemy3_x-hero_x)>=0)
        {
            if((enemy3_y-hero_y)>=0)
            {
                if((enemy3_y-hero_y)>=(enemy3_x-hero_x))
                {
                    enemy3direction=1;
                }
                else
                {
                    enemy3direction=3;
                }
            }
            if((enemy3_y-hero_y)<0)
            {
                if((hero_y-enemy3_y)>=(enemy3_x-hero_x))
                {
                    enemy3direction=2;
                }
                else
                {
                    enemy3direction=3;
                }
            }
        }
        if((enemy3_x-hero_x)<0)
        {
            if((enemy3_y-hero_y)>0)
            {
                if((hero_x-enemy3_x)>=(enemy3_y-hero_y))
                {
                    enemy3direction=4;
                }
                else
                {
                    enemy3direction=1;
                }
            }
            if((enemy3_y-hero_y)<0)
            {
                if((hero_x-enemy3_x)>=(hero_y-enemy3_y))
                {
                    enemy3direction=4;
                }
                else
                {
                    enemy3direction=2;
                }
            }
        }
    }
}



//end


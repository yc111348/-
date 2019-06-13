//
//  hero.cpp
//  yc
//
//  Created by mac on 2019/6/10.
//

#include "Heroscene.hpp"
#include "SimpleAudioEngine.h"


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
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // 3. add your codes below...
    map = TMXTiledMap::create("mapres/map.tmx");
    addChild(map,1);
    auto mapgo = map->getLayer("move");
    mapgo->setVisible(false);
    
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
    
    //2.创建逐帧数组
    //front
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
        SpriteFrame* s_pFrame3 = cache3->getSpriteFrameByName(s_str3);
        s_animFrames3.pushBack(s_pFrame3);
    }
    char s_str4[100] = {0};
    for (int i = 1411; i<1419; i++)
    {
        sprintf(s_str4, "%d.png", i);
        SpriteFrame* s_pFrame4 = s_cache4->getSpriteFrameByName(s_str4);
        s_animFrames4.pushBack(s_pFrame4);
    }
    
    //3.设置起始帧
    hero = Sprite::createWithSpriteFrameName("1231.png");
    addChild(hero,2);
    hero->setPosition(500,500);
    s_animation1 = Animation::createWithSpriteFrames(s_animFrames1, 0.3);
    hero->runAction(RepeatForever::create(Animate::create(s_animation1))); //测试动画
    
    
    
    
    //4.执行动画
    //    s_animation1 = Animation::createWithSpriteFrames(s_animFrames1, 0.3);
    //    hero->runAction(RepeatForever::create(Animate::create(s_animation1))); //测试动画
    //    animation1 = Animation::createWithSpriteFrames(animFrames1, 0.3);
    //    hero->runAction(RepeatForever::create(Animate::create(animation1))); //测试动画
    //    animation2 = Animation::createWithSpriteFrames(animFrames2, 0.3);
    //    hero->runAction(RepeatForever::create(Animate::create(animation2))); //测试动画
    
    
    
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){
        keys[keyCode] = true;
        log("%d pressed",keyCode);
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event){
        keys[keyCode] = false;
        log("key release");
    };
    
    
    this->scheduleUpdate();
    

    
    //血条消失术
    m_pProgressView = new ProgressView();
    m_pProgressView->setScale(0.5);
    m_pProgressView->setPosition(hero_x+315,hero_y+430);
    m_pProgressView->setBackgroundTexture("noblood.png");
    m_pProgressView->setForegroundTexture("fullblood.png");
    m_pProgressView->setTotalProgress(100.0f);
    m_pProgressView->setCurrentProgress(100.0f);
    hero -> addChild(m_pProgressView);
    //结束
    //子弹发射术
    
    auto listenermouse = EventListenerTouchOneByOne::create();//
    listenermouse->onTouchBegan = CC_CALLBACK_2(Hero::touch,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listenermouse, this);
    //结束
    
    //测试移动镜头跟随
    
    //    auto vsize = Director::getInstance()->getVisibleSize();
    //    auto mapTN=map->getMapSize();
    //    auto tiledSize = map->getTileSize();
    //    auto mapsize = Size(mapTN.width*tiledSize.width,mapTN.height*tiledSize.height);
    //    auto hpos=hero->getPosition();
    //    auto x = MAX(hpos.x,vsize.width/2);
    //    auto y = MAX(hpos.y,vsize.height/2);
    //    x = MIN(x,mapsize.width-vsize.width/2);
    //    y = MIN(y,mapsize.height-vsize.height/2);
    //    auto destpos=Vec2(x,y);
    //    auto centerpos = Vec2(vsize.width/2,vsize.height/2);
    //    auto viewpos = centerpos - destpos;
    //    this -> setPosition(viewpos);
    
    
    
    
    //结束
    //    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    //    if (label == nullptr)
    //    {
    //        problemLoading("'fonts/Marker Felt.ttf'");
    //    }
    //    else
    //    {
    //        // position the label on the center of the screen
    //        label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                                origin.y + visibleSize.height - label->getContentSize().height));
    //
    //        // add the label as a child to this layer
    //        this->addChild(label, 1);
    //    }
    
    // add "HelloWorld" splash screen"
    //    auto sprite = Sprite::create("HelloWorld.png");
    //    if (sprite == nullptr)
    //    {
    //        problemLoading("'HelloWorld.png'");
    //    }
    //    else
    //    {
    //        // position the sprite on the center of the screen
    //        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //
    //        // add the sprite as a child to this layer
    //        this->addChild(sprite, 0);
    //    }
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
            s_animation1 = Animation::createWithSpriteFrames(s_animFrames1, 0.3);
            hero->runAction(RepeatForever::create(Animate::create(s_animation1))); //测试动画
        }
        if(before==2)
        {
            hero->stopAllActions();
            s_animation2 = Animation::createWithSpriteFrames(s_animFrames2, 0.3);
            hero->runAction(RepeatForever::create(Animate::create(s_animation2))); //测试动画
        }
        if(before==3)
        {
            hero->stopAllActions();
            s_animation3 = Animation::createWithSpriteFrames(s_animFrames3, 0.3);
            hero->runAction(RepeatForever::create(Animate::create(s_animation3))); //测试动画
        }
        if(before==4)
        {
            hero->stopAllActions();
            s_animation4 = Animation::createWithSpriteFrames(s_animFrames4, 0.3);
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
}

void Hero::keyPressedDuration(EventKeyboard::KeyCode code)
{
    int offsetX = 0, offsetY = 0;
    switch (code)
    {
        case EventKeyboard::KeyCode::KEY_A:
            dirchange(3);
            if(couldgo(3))
            {
                offsetX = -5;
            }
            break;
        case EventKeyboard::KeyCode::KEY_W:
            dirchange(2);
            if(couldgo(2))
            {
                offsetY = 5;
            }
            break;
        case EventKeyboard::KeyCode::KEY_S:
            dirchange(1);
            if(couldgo(1))
            {
                offsetY = -5;
            }
            break;
        case EventKeyboard::KeyCode::KEY_D:
            dirchange(4);
            if(couldgo(4))
            {
                offsetX = 5;
            }
            break;
        default:
            offsetY = offsetX = 0;
            break;
    }
    // 0.3s代表着动作从开始到结束所用的时间，从而显得不会那么机械。
    auto moveTo = MoveTo::create(0.01, Vec2(hero->getPositionX() + offsetX, hero->getPositionY() + offsetY));
    hero->runAction(moveTo);
}
bool Hero::touch(Touch * touch,Event *event)
{
    auto bullet = Sprite::create("redball.png");
    auto visiblesize = Director::getInstance()->getVisibleSize();
    Point pt = touch->getLocation();
    pt = Director::getInstance()->convertToGL(pt);
    log("view is %f   %f",viewpos.x,viewpos.y);
    pt.x = pt.x - viewpos.x;
    pt.y = pt.y + viewpos.y;
    log("Click");
    point_x = pt.x;
    point_y = pt.y;
    log("%f,%f",point_x,point_y);
    float deltx,delty;
    deltx = point_x - hero_x;
    delty = visiblesize.height - point_y - hero_y;
    float delta = sqrt(deltx*deltx + delty*delty);
    float ex = deltx/delta;
    float ey = delty/delta;
    int n = 300;//shecheng
    bullet->setPosition(hero_x, hero_y);
    addChild(bullet,4);
    auto fire = MoveBy::create(0.3,Vec2(n*ex,n*ey));
    auto callbackfunc = [=]()
    {
        log("111");
        removeChild(bullet);
    };
    auto callFunc=CallFunc::create(callbackfunc);
    auto actions = Sequence::create(fire,DelayTime::create(0.4),callFunc,NULL);
    bullet->runAction(actions);
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
            animation1 = Animation::createWithSpriteFrames(animFrames1, 0.15);
            hero->runAction(RepeatForever::create(Animate::create(animation1))); //测试动画
        }
        if(dir==2)
        {
            hero->stopAllActions();
            animation2 = Animation::createWithSpriteFrames(animFrames2, 0.15);
            hero->runAction(RepeatForever::create(Animate::create(animation2))); //测试动画
        }
        if(dir==3)
        {
            hero->stopAllActions();
            animation3 = Animation::createWithSpriteFrames(animFrames3, 0.15);
            hero->runAction(RepeatForever::create(Animate::create(animation3))); //测试动画
        }
        if(dir==4)
        {
            log("按了按了");
            hero->stopAllActions();
            animation4 = Animation::createWithSpriteFrames(animFrames4, 0.15);
            hero->runAction(RepeatForever::create(Animate::create(animation4))); //测试动画
        }
    }
}

Point Hero::positiontrans(cocos2d::Point pos)
{
    auto mapTiledNum = map->getMapSize();
    auto tiledSize = map->getTileSize();
    int x = pos.x/tiledSize.width;
    log("tiledSize=%f",tiledSize.width);
    int y=(2880-pos.y)/tiledSize.height;
    log("x=%d   y=%d",x,y);
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
        temp=Point(-1,0);
    }
    if(direction==4)
    {
        temp=Point(2,0);
    }
    auto maplayer = map->getLayer("move");
    Point pos=positiontrans(heropos);
    int tiledID =  maplayer -> getTileGIDAt(pos+temp);
    log("ID is %d",tiledID);
    if(tiledID==0)
    {
        return true;
    }
    if(tiledID!=0)
    {
        return false;
    }
}


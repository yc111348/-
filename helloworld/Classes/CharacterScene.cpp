//
//  CharacterScene.cpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/2.
//

#include "CharacterScene.hpp"
#include "ChooseScene.hpp"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"

USING_NS_CC;

Scene* CharacterScene::createScene()
{
    Scene* scene = Scene::create();
    CharacterScene * layer = CharacterScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool CharacterScene::init()
{
    //背景图片
    Size size = Director::getInstance()->getVisibleSize();
    Sprite  *background = Sprite::create("background.png");
    background->setPosition(size.width*4/7,size.height/2);
    addChild(background,0);
    
    
    //返回上一层按钮
    auto * ReturnItem = MenuItemImage::create("returnR.png","returnR2.png",this,menu_selector(CharacterScene::menuGoToChooseScene));
    ReturnItem->setPosition(size.width*8/9+30,size.height*8/9+10);
    auto * MenuToChoose = Menu::create(ReturnItem, NULL);
    MenuToChoose->setPosition(Point::ZERO);
    this->addChild(MenuToChoose,1);
    
    //按钮"我选好了！"
    auto * OkItem = MenuItemImage::create("yes.png","no.png",this,menu_selector(CharacterScene::menuGoToChooseScene));
    OkItem->setPosition(size.width*4/7, size.height*1/7);
    auto * MenuOkToChoose = Menu::create(OkItem, NULL);
    MenuOkToChoose->setPosition(Point::ZERO);
    this->addChild(MenuOkToChoose,1);
    auto * ConfirmTTF = Label::createWithTTF("我选好啦！", "fonts/chicken.ttf", 18);
    ConfirmTTF -> setPosition(size.width*4/7+6, size.height*1/7);
    addChild(ConfirmTTF,2);
    
    
    
    //"请选择角色！"
    auto *hint = Label::createWithTTF("请选择你的角色","fonts/chicken.ttf", 24);
    hint -> setPosition(size.width*4/7, size.height*6/7);
    hint -> setColor(Color3B(54,54,54));
    addChild(hint,1);
    
    //角色选择
    auto * BaseMap1 = Sprite::create("W_C_BG.png");
    auto * BaseMap2 = Sprite::create("W_C_BG.png");
    BaseMap1 -> setPosition(size.width*2/7, size.height/2);
    BaseMap2 -> setPosition(size.width*6/7, size.height/2);
    addChild(BaseMap1,1);
    addChild(BaseMap2,1);
    
    rolemove1();
    rolemove2();
    
    return true;
}


void CharacterScene::rolemove1()
{
    //1.读取素材文件
    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("role.plist"); //从plist中加载图片信息
    
    //2.创建逐帧数组
    Vector <SpriteFrame*> animFrames1;
    char str1[100] = {0};
    for (int i = 40000; i<40009; i++)
    {
        sprintf(str1, "%d.png", i);
        SpriteFrame* pFrame = cache->getSpriteFrameByName(str1);
        animFrames1.pushBack(pFrame);
    }
    
    //3.设置起始帧
    Size s = Director::getInstance()->getVisibleSize();
    Sprite* sprite1 = Sprite::createWithSpriteFrameName("40000.png");
    sprite1->setScale(2);
    sprite1->setPosition(Point(s.width *1/3-10, s.height *1/2-15));
    addChild(sprite1,3);
    
    //4.执行动画
    Animation* animation1 = Animation::createWithSpriteFrames(animFrames1, 0.3);
    sprite1->runAction(RepeatForever::create(Animate::create(animation1)));
}

void CharacterScene::rolemove2()
{
    SpriteFrameCache* cache2 = SpriteFrameCache::getInstance();
    cache2->addSpriteFramesWithFile("role2.plist");
    Vector <SpriteFrame*> animFrames2;
    char str2[100] = {0};
    for (int i = 0; i < 8; i++)
    {
        sprintf(str2, "%d.png", i);
        SpriteFrame* pFrame2 = cache2->getSpriteFrameByName(str2);
        animFrames2.pushBack(pFrame2);
    }
    Size s = Director::getInstance()->getVisibleSize();
    Sprite* sprite2 = Sprite::createWithSpriteFrameName("0.png");
    sprite2->setScale(2);
    sprite2->setPosition(Point(s.width *6/7+10, s.height *1/2-20));
    addChild(sprite2,3);
    Animation* animation2 = Animation::createWithSpriteFrames(animFrames2, 0.3);
    sprite2->runAction(RepeatForever::create(Animate::create(animation2)));
}





void CharacterScene::menuGoToChooseScene(Ref* Sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    Director::getInstance()->replaceScene(TransitionMoveInR::create(1.0f,ChooseScene::createScene()));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}



void CharacterScene::onMenuCloseCallback(Ref *sender)
{
    Director::getInstance()->end();
}

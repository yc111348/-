//
//  SingleConnectChoose.cpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/3.
//
#include "TeamScene.hpp"
#include "ChooseScene.hpp"
#include "SingleConnectChoose.hpp"
#include "cocos2d.h"


USING_NS_CC;

Scene* SingleConnectChooseScene::createScene()
{
    Scene* scene = Scene::create();
    SingleConnectChooseScene * layer = SingleConnectChooseScene::create();
    scene -> addChild(layer);
    
    return scene;
}

bool SingleConnectChooseScene::init()
{
    
    //背景图片
    Size size = Director::getInstance()->getVisibleSize();
    Sprite  *background = Sprite::create("UIres/background.png");
    background->setPosition(size.width/2,size.height/2);
    addChild(background,0);
    
    //返回上一层按钮
    auto * ReturnItem = MenuItemImage::create("UIres/returnL.png","UIres/returnL2.png",this,menu_selector(SingleConnectChooseScene::menuGoToChooseScene));
    ReturnItem->setPosition(size.width/7-60,size.height*8/9+20);
    auto * MenuToChoose = Menu::create(ReturnItem, NULL);
    MenuToChoose->setPosition(Point::ZERO);
    this->addChild(MenuToChoose,1);
    
    //GUI添加
    auto *choosebg1 = Sprite::create("UIres/ChooseGUI.png");
    choosebg1 -> setPosition(size.width*1/4, size.height/2);
    addChild(choosebg1,1);
    
    auto *choosebg2 = Sprite::create("UIres/ChooseGUI.png");
    choosebg2 -> setPosition(size.width*3/4, size.height/2);
    addChild(choosebg2,1);
    
    auto *WRM = Label::createWithTTF("选择游戏模式！","fonts/chicken.ttf", 50);
    WRM -> setPosition(size.width/2, size.height*6/7);
    WRM -> setColor(Color3B(54,54,54));
    addChild(WRM,1);
    
    //单机模式
    auto single = cocos2d::ui::Button::create("UIres/single.png");
    single -> setScale(0.5);
    single -> cocos2d::Node::setPosition(size.width*1/4, size.height/2);
    addChild(single,2);
    auto *singlettf = Label::createWithTTF("单人模式", "fonts/chicken.ttf", 44);
    singlettf -> setPosition(size.width*1/4,size.height/3-20);
    addChild(singlettf,2);
    single -> addClickEventListener([this](Ref * ref)
                                     {
                                         Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(1.0f,Hero::createScene()));
                                     });
    
    //联机模式
    auto connect = cocos2d::ui::Button::create("UIres/connect.png");
    connect -> setScale(0.4);
    connect -> cocos2d::Node::setPosition(size.width*3/4, size.height/2);
    addChild(connect,2);
    auto *connectttf = Label::createWithTTF("联机模式", "fonts/chicken.ttf",44);
    connectttf -> setPosition(size.width*3/4, size.height/3-20);
    addChild(connectttf,2);
    
    connect -> addClickEventListener([this](Ref * ref)
                                     {
                                         Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(1.0f,TeamScene::createScene()));
                                     });
    
    return true;
}


void SingleConnectChooseScene::menuGoToChooseScene(Ref* Sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(1.0f,ChooseScene::createScene()));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

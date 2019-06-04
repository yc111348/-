//
//  ChooseScene.cpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/1.
//
#include "popOUT.hpp"
#include "ChooseScene.hpp"
#include "HelloWorldScene.h"
#include "WeaponScene.hpp"
#include "CharacterScene.hpp"
#include "SingleConnectChoose.hpp"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::ui;


Scene* ChooseScene::createScene()
{
    Scene* scene = Scene::create();
    ChooseScene * layer = ChooseScene::create();
    scene->addChild(layer);
    
    return scene;
}

MenuItemSprite* ChooseScene::createMenuItem2Img(const std::string imgA, const std::string imgB)
{
    
    /**              normalSprite                         */
    //分别创建两张图片的精灵
    auto imgASprite_1=Sprite::create(imgA);
    auto imgBSprite_1=Sprite::create(imgB);
    
    //把图片A加到图片B上
    imgASprite_1->setPosition(imgBSprite_1->getContentSize()/2);
    imgBSprite_1->addChild(imgASprite_1);
    
    
    /**              selectedSprite                         */
    //分别用两个精灵的精灵帧创建出一模一样的精灵，只是内存地址不一样
    auto imgASprite_2=Sprite::createWithSpriteFrame(imgASprite_1->getSpriteFrame());
    auto imgBSprite_2=Sprite::createWithSpriteFrame(imgBSprite_1->getSpriteFrame());
    
    //把A精灵加到B精灵身上
    imgASprite_2->setPosition(imgBSprite_2->getContentSize()/2);
    imgBSprite_2->addChild(imgASprite_2);
    
    //把选择的精灵缩小0.9
    imgBSprite_2->setScale(0.9);
    imgBSprite_2->setPosition(imgBSprite_2->getContentSize()*0.05);
    
    return MenuItemSprite::create(imgBSprite_1, imgBSprite_2);
}


void ChooseScene::onMenuCloseCallback(Ref *sender)
{
    Director::getInstance()->end();
}


bool ChooseScene::init()
{
    //背景图片
    Size size = Director::getInstance()->getVisibleSize();
    Sprite  *background = Sprite::create("UIres/background.png");
    background->setPosition(size.width*4/7,size.height/2);
    addChild(background,0);


    //退出按钮
    _pauseButton = ui::Button::create("UIres/close1.png");
    _pauseButton -> cocos2d::Node::setPosition(size.width+8,15);
    addChild(_pauseButton,1);
    
    _pauseButton -> addClickEventListener([this](Ref* ref)
                                          {
                                              this -> unscheduleUpdate();
                                              auto popupbox = PopupBox::create();
                                              
                                              popupbox -> registerCallback([this,popupbox](){
                                                  popupbox -> removeFromParent();
                                                  this ->scheduleUpdate();
                                              },[](){
                                                  Director::getInstance()->end();
                                              });
                                              this -> addChild(popupbox,100);
                                          });
    
    
    //GUI添加
    auto *choosebg1 = Sprite::create("UIres/ChooseGUI.png");
    choosebg1 -> setPosition(size.width*2/7, size.height/2);
    addChild(choosebg1,1);
    
    auto *choosebg2 = Sprite::create("UIres/ChooseGUI.png");
    choosebg2 -> setPosition(size.width*6/7, size.height/2);
    addChild(choosebg2,1);
    
    auto *WRM = Label::createWithTTF("战斗准备！","fonts/chicken.ttf", 24);
    WRM -> setPosition(size.width*4/7, size.height*6/7);
    WRM -> setColor(Color3B(54,54,54));
    addChild(WRM,1);
    
    
    //武器界面准备
    auto *weaponttf = Label::createWithTTF("选择武器","fonts/chicken.ttf", 16);
    weaponttf -> setPosition(size.width*6/7, size.height*5/7);
    addChild(weaponttf,2);

    
    //跳转选择武器界面
    auto * WeaponItem = MenuItemImage::create("UIres/weapon.png","UIres/weapon2.png",this,menu_selector(ChooseScene::menuGoToWeapon));
    WeaponItem->setPosition(size.width*6/7,size.height/2-20);
    auto * MenuToWeapon = Menu::create(WeaponItem, NULL);
    MenuToWeapon->setPosition(Point::ZERO);
    this->addChild(MenuToWeapon,3);
    
    
    
    //人物界面准备
    auto *characterttf = Label::createWithTTF("选择人物","fonts/chicken.ttf", 16);
    characterttf -> setPosition(size.width*2/7, size.height*5/7);
    addChild(characterttf,2);

    
    //跳转选择人物界面
    auto * CharacterItem = MenuItemImage::create("UIres/character.png","UIres/character2.png",this,menu_selector(ChooseScene::menuGoToCharacter));
    CharacterItem->setPosition(size.width*2/7,size.height/2-20);
    auto * MenuToCharacter = Menu::create(CharacterItem, NULL);
    MenuToCharacter->setPosition(Point::ZERO);
    this->addChild(MenuToCharacter,3);
    
    
    //选择单机/联机模式准备
    auto *next = Label::createWithTTF("NEXT！","fonts/chicken.ttf", 20);
    next-> setPosition(size.width*4/7+5, size.height*1/9);
    addChild(next,3);
//    auto *nextbg = createMenuItem2Img("okbuttom.png","okbuttom.png");
//    nextbg -> setPosition(size.width*4/7,size.height*1/9);
//    auto nextItem = Menu::create(nextbg,NULL);
//    nextItem -> setPosition(Point::ZERO);
//    addChild(nextItem,2);
    auto nextItem = Button::create("UIres/okbuttom.png");
    nextItem -> cocos2d::Node::setPosition(size.width*4/7, size.height*1/9);
    addChild(nextItem,2);
    
    nextItem -> addClickEventListener([this](Ref* ref)
                                      {
                                          Director::getInstance()->replaceScene( TransitionProgressRadialCCW::create(1.0f,SingleConnectChooseScene::createScene()));
                                      });

    
    return true;
}


void ChooseScene::menuGoToWeapon(Ref* Sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    Director::getInstance()->replaceScene(TransitionMoveInR::create(1.0f,WeaponScene::createScene()));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}


void ChooseScene::menuGoToCharacter(Ref* Sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    Director::getInstance()->replaceScene(TransitionMoveInL::create(1.0f,CharacterScene::createScene()));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

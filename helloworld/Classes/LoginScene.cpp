//
//  LoginScene.cpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/5/31.
//

#include "HelloWorldScene.h"
#include "ChooseScene.hpp"
#include "SimpleAudioEngine.h"
#include "LoginScene.hpp"
#include "popOUT.hpp"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::ui;
using namespace cocos2d::extension;

Scene* LoginScene::createScene()
{
    Scene* scene = Scene::create();
    LoginScene * layer = LoginScene::create();
    scene->addChild(layer);
    
    return scene;
}

MenuItemSprite* LoginScene::createMenuItem2Img(const std::string imgA, const std::string imgB)
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



bool LoginScene::init()
{
    //背景图片
    Size size = Director::getInstance()->getVisibleSize();
    Sprite  *background = Sprite::create("UIres/background.png");
    background->setPosition(size.width/2,size.height/2);
    addChild(background,0);
    
    //输入框
    auto inputbox = Sprite::create("UIres/LoginGUI.png");
    inputbox->setPosition(size.width/2,size.height/2);
    addChild(inputbox,1);
    
    //输入框控件
    auto editBox = EditBox::create(Size(inputbox->getContentSize().width,inputbox->getContentSize().height*0.7),cocos2d::ui::Scale9Sprite::create());
    editBox -> setPosition(ccp(size.width*2/3, 150));
    editBox -> setMaxLength(16);//最多输入八个字符
    editBox -> setText("请输入昵称");
    editBox -> setFont("fonts/chicken.ttf", 25);
    editBox -> setFontColor(Color3B(255,255,255));
    addChild(editBox,2);
    
    auto signup = Label::createWithTTF("Sign up","fonts/chicken.ttf", 18);
    signup -> setPosition(size.width/2,size.height*11/13);
    addChild(signup,3);
    
    auto hint1 = Label::createWithTTF("Please entet your name ","fonts/chicken.ttf", 28);
    auto hint2 = Label::createWithTTF(" Within 16 characters ","fonts/chicken.ttf", 28);
    hint1 -> setPosition(size.width/2,size.height*2/3);
    hint2 -> setPosition(size.width/2,size.height*2/3-30);
    hint1 -> setColor(Color3B(142, 229, 238));
    hint2 -> setColor(Color3B(142, 229, 238));
    addChild(hint1,3);
    addChild(hint2,3);
    
   // OK按钮
    
    auto * OkButtom = MenuItemImage::create("UIres/okbuttom.png","UIres/okbuttom1.png",this,menu_selector(LoginScene::menuGoToHelloworld));
    OkButtom->setPosition(size.width/2,size.height*4/13);
    auto * MenuToOk = Menu::create(OkButtom, NULL);
    MenuToOk->setPosition(Point::ZERO);
    this->addChild(MenuToOk,3);
    auto OK = Label::createWithTTF("OK","fonts/chicken.ttf", 43);
    OK -> setPosition(size.width/2,size.height*4/13);
    addChild(OK,4);
//    auto *OkButtom = createMenuItem2Img("okbuttom.png","okbuttom.png");
//    OkButtom -> setCallback([&,editBox](Ref*obj)
//    {
//        log("%s",editBox -> getText());
//    });
//
//    auto menu = Menu::create(OkButtom,NULL);
//    menu -> setPosition(Point::ZERO);
//    addChild(menu,3);
//    auto *smallOkButtom = Sprite::create("okbuttom.png");
//    smallOkButtom -> setScale(0.9);
//    smallOkButtom -> setPosition(OkButtom->getContentSize()/2);
//    addChild(smallOkButtom,3);
//    auto * listenerOkbuttom = EventListenerTouchOneByOne::create();
//    listenerOkbuttom->onTouchBegan = [OkButtom](Touch * touch,Event * event)
//    {
//        if(OkButtom->getBoundingBox().containsPoint(touch->getLocation()))
//        {
//
//            Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5, ChooseScene::createScene()));
//        }
//
//        return false;
//    };
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerOkbuttom, OkButtom);
    

    
    //音乐暂停/播放
    //Pause
    auto MusicItemOff = createMenuItem2Img("UIres/MusicOff1.png","UIres/MusicOff1.png");
    MusicItemOff -> setPosition(size.width*1/10, size.height*11/12);
    auto menuMusicOff = Menu::create(MusicItemOff,NULL);
    menuMusicOff -> setPosition(Point::ZERO);
    addChild(menuMusicOff,4);
    auto *listennerMusicItemOff = EventListenerTouchOneByOne::create();
    listennerMusicItemOff->onTouchBegan = [MusicItemOff](Touch * touch,Event * event)
    {
        if(MusicItemOff->getBoundingBox().containsPoint(touch->getLocation()))
        {
            CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
        }
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listennerMusicItemOff, MusicItemOff);

    //Resume
    auto MusicItemOn = createMenuItem2Img("UIres/MusicOn1.png","UIres/MusicOn1.png");
    MusicItemOn -> setPosition(size.width*9/10, size.height*11/12);
    auto menuMusicOn = Menu::create(MusicItemOn,NULL);
    menuMusicOn -> setPosition(Point::ZERO);
    addChild(menuMusicOn,4);
    auto *listennerMusicItemOn = EventListenerTouchOneByOne::create();
    listennerMusicItemOn->onTouchBegan = [MusicItemOn](Touch * touch,Event * event)
    {
        if(MusicItemOn->getBoundingBox().containsPoint(touch->getLocation()))
        {
            CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
        }
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listennerMusicItemOn, MusicItemOn);
    
    
    //退出
    _pauseButton = ui::Button::create("UIres/close1.png");
    _pauseButton -> cocos2d::Node::setPosition(size.width-40,40);
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
    return true;
}


void LoginScene::onMenuCloseCallback(Ref *sender)
{
    Director::getInstance()->end();
}



void LoginScene::menuGoToHelloworld(Ref* Sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.4f,ChooseScene::createScene()));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

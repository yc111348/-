//
//  EndGameScene.cpp
//  elloworld
//
//  Created by 董震宇 on 2019/6/14.
//

#include "EndGameScene.hpp"
#include "ChooseScene.hpp"
#include "RankScene.hpp"
#include "Heroscene.hpp"
#include "popOUT.hpp"

Scene* EndGameScene::createScene()
{
    Scene* scene = Scene::create();
    EndGameScene * layer = EndGameScene::create();
    scene -> addChild(layer);
    
    return scene;
}


bool EndGameScene::init()
{
    //背景图片
    Size size = Director::getInstance()->getVisibleSize();
    Sprite  *background = Sprite::create("UIres/background.png");
    background->setPosition(size.width/2,size.height/2);
    addChild(background,0);
    
    auto ground = Sprite::create("UIres/endgamebg.png");
    ground -> setPosition(size.width/2, size.height/2);
    ground -> setScale(0.45,0.25);
    addChild(ground,1);
    
    auto hint = Label::createWithTTF("你这么蔡连AI都打不过?", "fonts/chicken.ttf", 48);
    auto hint2 = Label::createWithTTF("快来多练练吧!", "fonts/chicken.ttf", 48);
    hint -> setPosition(size.width/2, size.height*2/3);
    hint2 -> setPosition(size.width/2, size.height*2/3 - 80);
    hint -> setColor(Color3B(0,0,0));
    hint2 -> setColor(Color3B(0,0,0));
    addChild(hint,2);
    addChild(hint2,2);
    
    auto continueButton = ui::Button::create("UIres/yes.png");
    auto returnButton = ui::Button::create("UIres/no.png");
    auto rankButton = ui::Button::create("UIres/mid.png");
    rankButton -> setScale(0.6, 0.6);
    auto yesttf = Label::createWithTTF("重新开始", "fonts/chicken.ttf", 35);
    auto nottf = Label::createWithTTF("返回菜单", "fonts/chicken.ttf", 35);
    auto rankttf = Label::createWithTTF("查看排行", "fonts/chicken.ttf", 35);
    
    yesttf -> setPosition(continueButton->getPositionX()+100, continueButton->getPositionY()+40);
    nottf -> setPosition(returnButton->getPositionX()+100, returnButton->getPositionY()+40);
    rankttf -> setPosition(size.width/2, size.height/3);
    
    continueButton -> cocos2d::Node::setPosition(Vec2(size.width/3-50,size.height/3));
    returnButton -> cocos2d::Node::setPosition(Vec2(size.width*2/3+50,size.height/3));
    rankButton -> cocos2d::Node::setPosition(Vec2(size.width/2,size.height/3));
    
    continueButton -> addChild(yesttf);
    returnButton -> addChild(nottf);
    addChild(rankttf,4);
    
    this -> addChild(continueButton,3);
    this -> addChild(returnButton,3);
    this -> addChild(rankButton,3);
    
    
    continueButton -> addClickEventListener([this](Ref* ref)
                                            {
                                                Director::getInstance()->replaceScene(Hero::createScene());
                                            });
    returnButton -> addClickEventListener([this](Ref* ref)
                                          {
                                              Director::getInstance()->replaceScene(ChooseScene::createScene());
                                          });
    rankButton -> addClickEventListener([this](Ref* ref)
                                        {
                                            Director::getInstance()->replaceScene(RankScene::createScene());
                                        });
    
    
    //退出按钮
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




void EndGameScene::menuGoToChooseScene(Ref* Sender)
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

void EndGameScene::menuGoToHeroScene(Ref* Sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(1.0f,Hero::createScene()));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

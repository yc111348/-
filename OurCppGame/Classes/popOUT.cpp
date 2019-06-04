//
//  popOUT.cpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/3.
//

#include "popOUT.hpp"
#include "ui/CocosGUI.h"



PopupBox::PopupBox()
{
    
}

PopupBox::~PopupBox()
{
    
}

bool PopupBox::init()
{
    if(Layer::init() == false)
    {
        return false;
    }
    
    auto size = Director::getInstance()->getVisibleSize();
    
    auto background = LayerColor::create(Color4B(0,0,0,200));
    auto box = ui::Scale9Sprite::create("popupBG.png");
    auto continueButtom = ui::Button::create("yes.png");
    auto endGameButtom = ui::Button::create("no.png");
    auto title = Label::createWithTTF("你确认退出游戏吗？", "fonts/chicken.ttf", 24);
    auto yesttf = Label::createWithTTF("继续游戏", "fonts/chicken.ttf", 16);
    auto nottf = Label::createWithTTF("确认退出", "fonts/chicken.ttf", 16);
    box -> setContentSize(Size(300,200));
    box -> setPosition(size.width/2+30, size.height/2);
    
    yesttf -> setPosition(continueButtom->getPositionX()+50, continueButtom->getPositionY()+20);
    nottf -> setPosition(endGameButtom->getPositionX()+50, endGameButtom->getPositionY()+20);
    
    continueButtom -> cocos2d::Node::setPosition(Vec2(size.width/3+30,size.height/3));
    endGameButtom -> cocos2d::Node::setPosition(Vec2(size.width*2/3+30,size.height/3));
    
    title -> setPosition(size.width/2-50,size.height*2/3-60);
    title -> setColor(Color3B(219,112,147));
    
    
    
    continueButtom -> addChild(yesttf);
    endGameButtom -> addChild(nottf);
    box -> addChild(title);
    this -> addChild(box,100);
    this -> addChild(continueButtom,101);
    this -> addChild(endGameButtom,101);
    
    continueButtom -> addClickEventListener([this](Ref* ref)
                                            {
                                                if(_continueCallback != nullptr)
                                                {
                                                    _continueCallback();
                                                }
                                            });
    
    endGameButtom -> addClickEventListener([this](Ref* ref)
                                           {
                                               if(_endGameCallback != nullptr)
                                               {
                                                   _endGameCallback();
                                               }
                                           });
    
    auto listener = EventListenerTouchOneByOne::create();
    listener -> onTouchBegan=[](Touch* touch,Event* event)
    {
        return true;
    };
    listener -> setSwallowTouches(true);
    
    background -> getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, background);
    
    
    
    return true;
}

void PopupBox::registerCallback(std::function<void ()> continueCallback, std::function<void ()> endGameCallback)
{
    _continueCallback = continueCallback;
    _endGameCallback = endGameCallback;
}

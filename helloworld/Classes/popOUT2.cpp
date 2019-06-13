//
//  popOUT2.cpp
//  elloworld
//
//  Created by 董震宇 on 2019/6/13.
//

#include "popOUT2.hpp"
#include "ui/CocosGUI.h"



Popup2::Popup2()
{
    
}

Popup2::~Popup2()
{
    
}

bool Popup2::init()
{
    if(Layer::init() == false)
    {
        return false;
    }
    
    auto size = Director::getInstance()->getVisibleSize();
    
    auto background = LayerColor::create(Color4B(0,0,0,200));
    auto box = ui::Scale9Sprite::create("UIres/popupBG.png");
    auto continueButtom = ui::Button::create("UIres/yes.png");
    auto title = Label::createWithTTF("你还没有选择角色/武器!!", "fonts/chicken.ttf", 48);
    auto yesttf = Label::createWithTTF("好了好了我知道了", "fonts/chicken.ttf", 35);
    box -> setContentSize(Size(700,470));
    box -> setPosition(size.width/2, size.height/2);
    
    yesttf -> setPosition(size.width/2,size.height/3);
    
    continueButtom -> cocos2d::Node::setScale(2, 1);
    continueButtom -> cocos2d::Node::setPosition(Vec2(size.width/2,size.height/3));
    
    title -> setPosition(size.width/2-160,size.height*2/3-200);
    title -> setColor(Color3B(219,112,147));
    
    
    
    this -> addChild(yesttf,102);
    box -> addChild(title);
    this -> addChild(box,100);
    this -> addChild(continueButtom,101);
    
    continueButtom -> addClickEventListener([this](Ref* ref)
                                            {
                                                if(_continueCallback != nullptr)
                                                {
                                                    _continueCallback();
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

void Popup2::registerCallback(std::function<void ()> continueCallback, std::function<void ()> endGameCallback)
{
    _continueCallback = continueCallback;
}

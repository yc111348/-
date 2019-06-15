//
//  TeamScene.cpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/3.
//

#include "TeamScene.hpp"
#include "SingleConnectChoose.hpp"

USING_NS_CC;

Scene* TeamScene::createScene()
{
    Scene* scene = Scene::create();
    TeamScene * layer = TeamScene::create();
    scene -> addChild(layer);
    
    return scene;
}


bool TeamScene::init()
{
    //背景图片
    Size size = Director::getInstance()->getVisibleSize();
    Sprite  *background = Sprite::create("UIres/background.png");
    background->setPosition(size.width/2,size.height/2);
    addChild(background,0);
    
    //返回上一层按钮
    auto * ReturnItem = MenuItemImage::create("UIres/returnL.png","UIres/returnL2.png",this,menu_selector(TeamScene::menuGoToSCCScene));
    ReturnItem->setPosition(size.width/7-60,size.height*8/9+20);
    auto * MenuToChoose = Menu::create(ReturnItem, NULL);
    MenuToChoose->setPosition(Point::ZERO);
    this->addChild(MenuToChoose,1);
    
    
    
    auto hint = Label::createWithTTF("暂未开发敬请期待！", "fonts/chicken.ttf", 60);
    hint -> setPosition(Vec2(size.width/2,size.height*9/11));
    hint -> setColor(Color3B(54,54,54));
    addChild(hint,3);
    
    auto hint2 = Label::createWithTTF("可以赞助我们哦~", "fonts/chicken.ttf", 60);
    hint2 -> setPosition(Vec2(size.width/2,size.height*9/11 - 120));
    hint2 -> setColor(Color3B(54,54,54));
    addChild(hint2,3);
    
    auto pay = Sprite::create("UIres/pay.png");
    pay -> setPosition(Vec2(size.width/2,size.height/6));
    pay -> setScale(0.35, 0.35);
    addChild(pay,3);
    
    
    return true;
}




void TeamScene::menuGoToSCCScene(Ref* Sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(1.0f,SingleConnectChooseScene::createScene()));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

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
    Sprite  *background = Sprite::create("background.png");
    background->setPosition(size.width*4/7,size.height/2);
    addChild(background,0);
    
    //返回上一层按钮
    auto * ReturnItem = MenuItemImage::create("returnL.png","returnL2.png",this,menu_selector(TeamScene::menuGoToSCCScene));
    ReturnItem->setPosition(size.width/7,size.height*8/9+10);
    auto * MenuToChoose = Menu::create(ReturnItem, NULL);
    MenuToChoose->setPosition(Point::ZERO);
    this->addChild(MenuToChoose,1);
    
    
    
    
    
    
    
    
    
    
    
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

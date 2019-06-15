//
//  WeaponScene.cpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/2.
//

#include "WeaponScene.hpp"
#include "ChooseScene.hpp"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;


Scene* WeaponScene::createScene()
{
    Scene* scene = Scene::create();
    WeaponScene * layer = WeaponScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool WeaponScene::init()
{
    //背景图片
    size = Director::getInstance()->getVisibleSize();
    Sprite  *background = Sprite::create("UIres/background.png");
    background->setPosition(size.width/2,size.height/2);
    addChild(background,0);
    
    
    //返回上一层按钮
    auto * ReturnItem = MenuItemImage::create("UIres/returnL.png","UIres/returnL2.png",this,menu_selector(WeaponScene::menuGoToChooseScene));
    ReturnItem->setPosition(size.width/7-60,size.height*8/9+20);
    auto * MenuToChoose = Menu::create(ReturnItem, NULL);
    MenuToChoose->setPosition(Point::ZERO);
    this->addChild(MenuToChoose,1);
    //按钮"我选好了！"
    auto * OkItem = MenuItemImage::create("UIres/yes.png","UIres/no.png",this,menu_selector(WeaponScene::menuGoToChooseScene));
    OkItem->setPosition(size.width/2, size.height*1/7);
    auto * MenuOkToChoose = Menu::create(OkItem, NULL);
    MenuOkToChoose->setPosition(Point::ZERO);
    this->addChild(MenuOkToChoose,1);
    auto * ConfirmTTF = Label::createWithTTF("我选好啦！", "fonts/chicken.ttf", 40);
    ConfirmTTF -> setPosition(size.width/2+6, size.height*1/7);
    addChild(ConfirmTTF,2);


    
    //"请选择武器！"
    auto *hint = Label::createWithTTF("请选择你的武器","fonts/chicken.ttf", 50);
    hint -> setPosition(size.width/2, size.height*6/7);
    hint -> setColor(Color3B(54,54,54));
    addChild(hint,1);
    
    //武器选择
    auto * BaseMap1 = Sprite::create("UIres/W_C_BG.png");
    auto * BaseMap2 = Sprite::create("UIres/W_C_BG.png");
    BaseMap1 -> setPosition(size.width*1/4, size.height/2);
    BaseMap2 -> setPosition(size.width*3/4, size.height/2);
    addChild(BaseMap1,1);
    addChild(BaseMap2,1);
    auto HeavenFire = Sprite::create("UIres/HeavenFire.png");
    auto fifth = Sprite::create("UIres/5th.png");
    HeavenFire -> setPosition(BaseMap1->getContentSize()/2);
    fifth -> setPosition(BaseMap2->getContentSize()/2);
    BaseMap1 -> addChild(HeavenFire);
    BaseMap2 -> addChild(fifth);
    
    auto introduce1 = Label::createWithTTF("天火圣裁", "fonts/chicken.ttf", 50);
    introduce1 -> setPosition(Vec2(size.width/4,size.height*2/3-10));
    addChild(introduce1,3);
    auto introduce2 = Label::createWithTTF("5th圣遗物", "fonts/chicken.ttf", 50);
    introduce2 -> setPosition(Vec2(size.width*3/4,size.height*2/3-10));
    addChild(introduce2,3);
    
    auto introduce3 = Label::createWithTTF("攻速快，射程远", "fonts/chicken.ttf", 24);
    introduce3 -> setPosition(Vec2(size.width/4,size.height*1/3+60));
    addChild(introduce3,5);
    auto introduce4 = Label::createWithTTF("射程近，使人物加速", "fonts/chicken.ttf", 24);
    introduce4 -> setPosition(Vec2(size.width*3/4,size.height*1/3+60));
    addChild(introduce4,5);

    //选择按钮
    auto selectbutton = ui::Button::create("UIres/selectbutton2.png");
    selectbutton -> cocos2d::Node::setPosition(size.width/4, size.height/3);
    selectbutton -> setScale(0.25);
    addChild(selectbutton,3);
    auto selectbutton2 = ui::Button::create("UIres/selectbutton2.png");
    selectbutton2 -> cocos2d::Node::setPosition(size.width*3/4, size.height/3);
    selectbutton2 -> setScale(0.25);
    addChild(selectbutton2,3);
    nike1 = Sprite::create("UIres/selectbutton.png");
    nike1 -> cocos2d::Node::setPosition(size.width/4, size.height/3);
    nike1 -> setScale(0.25);
    nike1 -> setVisible(false);
    addChild(nike1,4);
    nike2 = Sprite::create("UIres/selectbutton.png");
    nike2 -> cocos2d::Node::setPosition(size.width*3/4, size.height/3);
    nike2 -> setScale(0.25);
    addChild(nike2,4);
    nike2->setVisible(false);
    selectbutton -> addClickEventListener([this](Ref * ref)
                                          {
                                              nike1 -> setVisible(true);
                                              nike2 -> setVisible(false);
                                              UserDefault::getInstance()->setIntegerForKey("weapon",1);
                                          });
    selectbutton2 -> addClickEventListener([this](Ref * ref)
                                           {
                                               nike2 -> setVisible(true);
                                               nike1 -> setVisible(false);
                                               UserDefault::getInstance()->setIntegerForKey("weapon",2);
                                           });
    
    int weaponnum = UserDefault::getInstance()->getIntegerForKey("weapon");
    if(weaponnum == 1)
    {
        nike1 -> setVisible(true);
    }
    if(weaponnum == 2)
    {
        nike2 -> setVisible(true);
    }

    
    
    
    
    
    return true;
}





void WeaponScene::menuGoToChooseScene(Ref* Sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    Director::getInstance()->replaceScene(TransitionMoveInL::create(1.0f,ChooseScene::createScene()));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}



MenuItemSprite* WeaponScene::createMenuItem2Img(const std::string imgA, const std::string imgB)
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

void WeaponScene::onMenuCloseCallback(Ref *sender)
{
    Director::getInstance()->end();
}

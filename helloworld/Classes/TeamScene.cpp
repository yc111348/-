//
//  TeamScene.cpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/3.
//

#include "TeamScene.hpp"
#include "SingleConnectChoose.hpp"
#include "ui/CocosGUI.cpp"

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
    background->setPosition(size.width*4/7,size.height/2);
    addChild(background,0);
    
    //底图
    auto back = Sprite::create("UIres/GUI.png");
    back -> setPosition(size.width*4/7,size.height/2);
    addChild(back,1);
    
    //返回上一层按钮/关闭按钮
    auto buttonx = ui::Button::create("UIres/ButtonX.png");
    buttonx -> cocos2d::Node::setPosition(size.width*5/7+30, size.height*3/4);
    buttonx -> cocos2d::Node::setScale(0.4);
    buttonx -> addClickEventListener([this](Ref * ref){
        Director::getInstance()->replaceScene(TransitionSplitRows::create(1.0f,SingleConnectChooseScene::createScene()));
    });
    addChild(buttonx,2);
    
    //创建房间/加入游戏
    auto plank1 = ui::Button::create("UIres/plank.png");
    auto plank2 = ui::Button::create("UIres/plank.png");
    plank1 -> setScale(0.25);
    plank2 -> setScale(0.25);
    plank1 -> cocos2d::Node::setPosition(size.width*4/7, size.height*4/7);
    plank2 -> cocos2d::Node::setPosition(size.width*4/7, size.height*2/7);
    addChild(plank1,2);
    addChild(plank2,2);
    

    //文本
    auto title = Label::createWithTTF("请选择","fonts/chicken.ttf", 24);
    auto makeRoom = Label::createWithTTF("创建房间", "fonts/chicken.ttf", 16);
    auto joinRoom = Label::createWithTTF("加入房间", "fonts/chicken.ttf", 16);
    title -> setPosition(size.width*4/7, size.height*3/4+30);
    makeRoom -> setPosition(size.width*4/7, size.height*4/7);
    joinRoom -> setPosition(size.width*4/7, size.height*2/7);
    addChild(title,3);
    addChild(makeRoom,3);
    addChild(joinRoom,3);

    

    
    return true;
}






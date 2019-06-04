#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "LoginScene.hpp"
#include "popOUT.hpp"
#include "ui/CocosGUI.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    initUI();
    
    return true;
}


void HelloWorld::initUI()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //退出（加确认）
    _pauseButton = ui::Button::create("close1.png");
    _pauseButton -> cocos2d::Node::setPosition(visibleSize.width+8,15);
    addChild(_pauseButton,1);

    _pauseButton -> addClickEventListener([this](Ref* ref)
                                          {
                                              this -> unscheduleUpdate();
                                              auto popupbox = PopupBox::create();

                                              popupbox -> registerCallback([this,popupbox](){
                                                  CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.wav",false);
                                                  popupbox -> removeFromParent();
                                                  this ->scheduleUpdate();
                                                  
                                              },[](){
                                                  Director::getInstance()->end();
                                              });
                                              this -> addChild(popupbox,100);
                                          });
    
    
    //主界面图片
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        this->addChild(sprite, 0);
    }
    
    
    //背景音乐
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.wav",true);
    
    
    
    //游戏标题
    auto label = Label::createWithTTF("求你别出BUG啦！", "fonts/chicken.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/chicken.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width*6/11,
                                origin.y + visibleSize.height*6/7 - label->getContentSize().height));
        
        // add the label as a child to this layer
        this->addChild(label, 1);
    }
    
    
    //"点击进入游戏"
    auto Entergame = Label::createWithTTF("点击此处进入游戏", "fonts/chicken.ttf", 12);
    if (Entergame == nullptr)
    {
        problemLoading("'fonts/chicken.ttf'");
    }
    else
    {
        Entergame->setPosition(Vec2(visibleSize.width * 4/7,
                                    visibleSize.height * 1/3));
        
        this->addChild(Entergame, 1);
    }
    
    
    //创建侦听，切换场景
    auto * listenerEnterGame = EventListenerTouchOneByOne::create();
    listenerEnterGame->onTouchBegan = [Entergame](Touch * touch,Event * event)
    {
        if(Entergame->getBoundingBox().containsPoint(touch->getLocation()))
        {
            Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5, LoginScene::createScene()));
        }
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerEnterGame, Entergame);

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
    CocosDenshion::SimpleAudioEngine::getInstance()->end();

}

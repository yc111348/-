//
//  RankScene.cpp
//  elloworld
//
//  Created by 董震宇 on 2019/6/15.
//

#include "RankScene.hpp"
#include "ChooseScene.hpp"
#include "popOUT.hpp"

Scene* RankScene::createScene()
{
    Scene* scene = Scene::create();
    RankScene * layer = RankScene::create();
    scene -> addChild(layer);
    
    return scene;
}


bool RankScene::init()
{
    //背景图片
    Size size = Director::getInstance()->getVisibleSize();
    Sprite  *background = Sprite::create("UIres/background.png");
    background->setPosition(size.width/2,size.height/2);
    addChild(background,0);
    
    //底图
    auto rankbg = Sprite::create("UIres/rank.png");
    rankbg -> setPosition(size.width/2, size.height/2);
    rankbg -> setScale(0.28, 0.28);
    addChild(rankbg,1);
    
    auto rankttf = Label::createWithTTF("RankList", "fonts/chicken.ttf", 48);
    rankttf -> setPosition(size.width/2,size.height*4/5+50);
    addChild(rankttf,2);
    
    auto ReturnButton = ui::Button::create("UIres/Iconback.png");
    ReturnButton -> setScale(0.3);
    ReturnButton -> setPosition(Vec2(280,50));
    addChild(ReturnButton,2);
    
    ReturnButton -> addClickEventListener([this](Ref* ref)
                                            {
                                    Director::getInstance()->replaceScene(ChooseScene::createScene());
                                            });
    
    //-----------第1名
    int first = UserDefault::getInstance()->getIntegerForKey("1test");
    int second = UserDefault::getInstance()->getIntegerForKey("2test");
    int third = UserDefault::getInstance()->getIntegerForKey("3test");                                                                                                                                                   
    int fourth = UserDefault::getInstance()->getIntegerForKey("4test");
    int fifth = UserDefault::getInstance()->getIntegerForKey("5test");
    int a[6] = {first,second,third,fourth,fifth,SCORE};
    ranklist(a);
    UserDefault::getInstance()->setIntegerForKey("score", 0);
    first = a[5];
    second = a[4];
    third = a[3];
    fourth = a[2];
    fifth = a[1];
    UserDefault::getInstance()->setIntegerForKey("1test", first);
    UserDefault::getInstance()->setIntegerForKey("2test", second);
    UserDefault::getInstance()->setIntegerForKey("3test", third);
    UserDefault::getInstance()->setIntegerForKey("4test", fourth);
    UserDefault::getInstance()->setIntegerForKey("5test", fifth);
    
    
    std::string s1 = std::to_string(first);
    auto firstlabel = Label::create();
    firstlabel -> setString(s1);
    firstlabel -> setSystemFontSize(48);
    firstlabel -> setColor(Color3B(0,0,0));
    firstlabel -> setPosition(Vec2(size.width/2,510));
    addChild(firstlabel,100);
    //-----------第2名
    std::string s2 = std::to_string(second);
    auto secondlabel = Label::create();
    secondlabel -> setString(s2);
    secondlabel -> setSystemFontSize(48);
    secondlabel -> setColor(Color3B(0,0,0));
    secondlabel -> setPosition(Vec2(size.width/2,440));
    addChild(secondlabel,100);
    //-----------第3名
    std::string s3 = std::to_string(third);
    auto thirdlabel = Label::create();
    thirdlabel -> setString(s3);
    thirdlabel -> setSystemFontSize(48);
    thirdlabel -> setColor(Color3B(0,0,0));
    thirdlabel -> setPosition(Vec2(size.width/2,370));
    addChild(thirdlabel,100);
    //-----------第4名
    std::string s4 = std::to_string(fourth);
    auto fourthlabel = Label::create();
    fourthlabel -> setString(s4);
    fourthlabel -> setSystemFontSize(48);
    fourthlabel -> setColor(Color3B(0,0,0));
    fourthlabel -> setPosition(Vec2(size.width/2,300));
    addChild(fourthlabel,100);
    //-----------第5名
    std::string s5 = std::to_string(fifth);
    auto fifthlabel = Label::create();
    fifthlabel -> setString(s5);
    fifthlabel -> setSystemFontSize(48);
    fifthlabel -> setColor(Color3B(0,0,0));
    fifthlabel -> setPosition(Vec2(size.width/2,230));
    addChild(fifthlabel,100);
    
    
    return true;
}

void RankScene::ranklist(int a[])
{
   for (int i = 0; i < 5; i++)
   {
       for (int j = 0; j < 5 - i; j++)
       {
           if (a[j] > a[j + 1])
           {
               temp = a[j];
               a[j] = a[j + 1];
               a[j + 1] = temp;
           }
       }
   }
}

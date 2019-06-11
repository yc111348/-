//
//  SingleConnectChoose.hpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/3.
//

#ifndef SingleConnectChoose_hpp
#define SingleConnectChoose_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Heroscene.hpp"

USING_NS_CC;

class SingleConnectChooseScene: public Layer
{
    
public:
    
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(SingleConnectChooseScene);

    void menuGoToChooseScene(cocos2d::Ref * Sender);
};

#endif /* SingleConnectChoose_hpp */

//
//  TeamScene.hpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/3.
//

#ifndef TeamScene_hpp
#define TeamScene_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class TeamScene: public Layer
{
    
public:
    
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(TeamScene);
    
};

#endif /* TeamScene_hpp */

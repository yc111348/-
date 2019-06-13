//
//  popOUT2.hpp
//  elloworld
//
//  Created by 董震宇 on 2019/6/13.
//

#ifndef popOUT2_hpp
#define popOUT2_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;


class Popup2:public Layer
{
public:
    Popup2();
    virtual ~Popup2();
    
    CREATE_FUNC(Popup2);
    
    virtual bool init();
    
    virtual void registerCallback(std::function<void()> continueCallback,std::function<void()> endGameCallback);
    
    
protected:
    std::function<void()> _continueCallback;
    
    
};

#endif /* popOUT2_hpp */

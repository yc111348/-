//
//  popOUT.hpp
//  OurCppGame
//
//  Created by 董震宇 on 2019/6/3.
//

#ifndef popOUT_hpp
#define popOUT_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;


class PopupBox:public Layer
{
public:
    PopupBox();
    virtual ~PopupBox();
    
    CREATE_FUNC(PopupBox);
    
    virtual bool init();
    
    virtual void registerCallback(std::function<void()> continueCallback,std::function<void()> endGameCallback);
    
    
protected:
    std::function<void()> _continueCallback;
    std::function<void()> _endGameCallback;
    
    
};

#endif /* popOUT_hpp */

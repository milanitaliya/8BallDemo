//
//  CCmacro.h
//  demo
//
//  Created by Milan Italiya on 17/02/21.
//
//

#ifndef demo_Config_h
#define demo_Config_h



#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;
 
#define PTM_RATIO 32.0

#define OutOfScreen Vec2(5000,5000)
// random macros utilizing arc4random()

//Get The Ipad Screen Height & Width
 #define IPAD_WIDTH         Director::getInstance()->getWinSize().width    //Screen width
#define IPAD_HEIGHT        Director::getInstance()->getWinSize().height   //Screen height

#define IPAD_VISIBLE_WIDTH         Director::getInstance()->getVisibleSize().width  //Screen width
#define IPAD_VISIBLE_HEIGHT        Director::getInstance()->getVisibleSize().height   //Screen height

#define IPAD_ORG_WIDTH  (IPAD_WIDTH < IPAD_HEIGHT ? 768 : 1024)

#define IPAD_ORG_HEIGHT (IPAD_WIDTH > IPAD_HEIGHT ? 768 : 1024)

#define x_scale    (IPAD_WIDTH / IPAD_ORG_WIDTH)
#define y_scale   (IPAD_HEIGHT / IPAD_ORG_HEIGHT)
#define av_scale   ((x_scale+y_scale)/2)

#endif

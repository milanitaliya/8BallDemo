//
//  CCmacro.h
//  demo
//
//  Created by milan italiya on 27/01/15.
//
//

#ifndef demo_Config_h
#define demo_Config_h



#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;
#define zipPassword ""
#define PackageName "com.app.name"
 #define AppName "App Name"

 #define MoreAppLink "https://play.google.com"
 #define RateAppLink "https://play.google.com/store/apps/details?id=com.app.name"

 
#define IAP_REMOVEADS "com.app.name.removeads"

#define TAP_SOUND "btn_click.mp3"

#define IsAdmobEnable 1
#define IsChartboostEnable 1
#define IsUnityAdsEnable 1


#define PTM_RATIO 32.0

#define OutOfScreen Vec2(5000,5000)
// random macros utilizing arc4random()
#define RAND_UINT_MAX        0xFFFFFFFF
#define RAND_INT_MAX        0x7FFFFFFF

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



// RAND_UINT() positive unsigned integer from 0 to RAND_UINT_MAX
// RAND_INT() positive integer from 0 to RAND_INT_MAX
// RAND_INT_VAL(a,b) integer on the interval [a,b] (includes a and b)
#define RAND_UINT()                arc4random()
#define RAND_INT()                ((int)(arc4random() & 0x7FFFFFFF))
#define RAND_INT_VAL(a,b)        ((arc4random() % ((b)-(a)+1)) + (a))

// RAND_FLOAT() float between 0 and 1 (including 0 and 1)
// RAND_FLOAT_VAL(a,b) float between a and b (including a and b)
#define RAND_FLOAT()            (((float)arc4random()) / RAND_UINT_MAX)
#define RAND_FLOAT_VAL(a,b)        (((((float)arc4random()) * ((b)-(a))) / RAND_UINT_MAX) + (a))

// note: Random doubles will contain more precision than floats, but will NOT utilize the
//        full precision of the double. They are still limited to the 32-bit precision of arc4random
// RAND_DOUBLE() double between 0 and 1 (including 0 and 1)
// RAND_DOUBLE_VAL(a,b) double between a and b (including a and b)
#define RAND_DOUBLE()            (((double)arc4random()) / RAND_UINT_MAX)
#define RAND_DOUBLE_VAL(a,b)    (((((double)arc4random()) * ((b)-(a))) / RAND_UINT_MAX) + (a))

// RAND_BOOL() a random boolean (0 or 1)
// RAND_DIRECTION() -1 or +1 (usage: int steps = 10*RAND_DIRECTION();  will get you -10 or 10)
#define RAND_BOOL()                (arc4random() & 1)
#define RAND_DIRECTION()        (RAND_BOOL() ? 1 : -1)




#endif

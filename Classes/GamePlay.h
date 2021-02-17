//
//  GamePlay.h
//  Demo-mobile
//
//  Created by Milan Italiya on 17/02/21.
//

#ifndef GamePlay_hpp
#define GamePlay_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "GLES-Render.h"

using namespace cocos2d;
class GamePlay : public cocos2d::Layer
{
public:
    virtual bool init();
    
    static cocos2d::Scene* createScene();
    Point location,locationBegan;
    
    
    float _prevAngle,scale,speedOfBall=10;
    bool isBallMoving;
    
    b2World* m_World;
    void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags);
    b2Body* createBall(string spriteName,bool isHero,Vec2 pos);
    
    Sprite *imageArrow;
    b2Body *bodyHero;

    void initPhysics();
    
    void update(float dt);

    void onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    
    virtual bool onTouchBegan(Touch*, Event*);
    virtual void onTouchMoved(Touch*, Event*);
    virtual void onTouchEnded(Touch*, Event*);
    virtual void onTouchCancelled(Touch*, Event*);

    CREATE_FUNC(GamePlay);
};

#endif /* GamePlay_hpp */

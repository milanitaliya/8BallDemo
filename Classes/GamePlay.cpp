//
//  GamePlay.cpp
//  Demo-mobile
//
//  Created by Milan Italiya on 17/02/21.
//

#include "AllHeader.h"

USING_NS_CC;

Scene* GamePlay::createScene()
{
        // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
        // 'layer' is an autorelease object
    GamePlay *layer = GamePlay::create();
    
        // add layer as a child to scene
    scene->addChild(layer);
    
        // return the scene
    return scene;
}

    // on "init" you need to initialize your instance
bool GamePlay::init()
{
        //////////////////////////////
        // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    auto touchesListinor=EventListenerTouchOneByOne::create();
    touchesListinor->onTouchBegan=CC_CALLBACK_2(GamePlay::onTouchBegan, this);
    touchesListinor->onTouchMoved=CC_CALLBACK_2(GamePlay::onTouchMoved, this);
    touchesListinor->onTouchEnded=CC_CALLBACK_2(GamePlay::onTouchEnded, this);
    touchesListinor->onTouchCancelled=CC_CALLBACK_2(GamePlay::onTouchCancelled, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchesListinor, this);
    
    
    auto keybackListinor=EventListenerKeyboard::create();
    keybackListinor->onKeyReleased=CC_CALLBACK_2(GamePlay::onKeyReleased,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keybackListinor, this);
    
    initPhysics();
    LayerColor *color = LayerColor::create(Color4B(Color3B(83,84,74)), IPAD_WIDTH, IPAD_HEIGHT);
    this->addChild(color);
    
    createBall("circle_blue.png",false,Vec2(843*x_scale,474*y_scale));
    createBall("circle_blue.png",false,Vec2(843*x_scale,429*y_scale));
    createBall("circle_blue.png",false,Vec2(843*x_scale,383*y_scale));
    createBall("circle_blue.png",false,Vec2(843*x_scale,338*y_scale));
    createBall("circle_blue.png",false,Vec2(843*x_scale,293*y_scale));
    createBall("circle_blue.png",false,Vec2(802*x_scale,450*y_scale));
    createBall("circle_blue.png",false,Vec2(802*x_scale,405*y_scale));
    createBall("circle_blue.png",false,Vec2(802*x_scale,359*y_scale));
    createBall("circle_blue.png",false,Vec2(802*x_scale,314*y_scale));
    createBall("circle_blue.png",false,Vec2(761*x_scale,426*y_scale));
    createBall("circle_blue.png",false,Vec2(761*x_scale,380*y_scale));
    createBall("circle_blue.png",false,Vec2(761*x_scale,335*y_scale));
    createBall("circle_blue.png",false,Vec2(721*x_scale,403*y_scale));
    createBall("circle_blue.png",false,Vec2(721*x_scale,358*y_scale));
    createBall("circle_blue.png",false,Vec2(681*x_scale,381*y_scale));

    bodyHero=createBall("circle_red.png",true,Vec2(200*x_scale,384*y_scale));

    

    scheduleUpdate();
    
    return true;
}
void GamePlay::initPhysics()
{
    b2Vec2 gravity;
    gravity.Set(0.0f,0);
    m_World = new b2World(gravity);
    
    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    auto groundBody = m_World->CreateBody(&groundBodyDef);

    b2EdgeShape groundBox;
    
    // bottom
    groundBox.Set(b2Vec2(0,0), b2Vec2(IPAD_VISIBLE_WIDTH/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
    groundBox.Set(b2Vec2(IPAD_VISIBLE_WIDTH/PTM_RATIO,0), b2Vec2(IPAD_VISIBLE_WIDTH/PTM_RATIO,IPAD_VISIBLE_HEIGHT/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    groundBox.Set(b2Vec2(IPAD_VISIBLE_WIDTH/PTM_RATIO,IPAD_VISIBLE_HEIGHT/PTM_RATIO),b2Vec2(0,IPAD_VISIBLE_HEIGHT/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    groundBox.Set(b2Vec2(0,IPAD_VISIBLE_HEIGHT/PTM_RATIO),b2Vec2(0,0));
    groundBody->CreateFixture(&groundBox,0);

   // groundBody->SetBullet(false);
    groundBody->GetFixtureList()->SetRestitution(1);
    

   // m_World->SetContinuousPhysics(true);
 
    b2Draw *m_debugDraw = new  GLESDebugDraw(PTM_RATIO);
    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    flags += b2Draw::e_aabbBit;
    flags += b2Draw::e_pairBit;
    flags += b2Draw::e_centerOfMassBit;
    m_debugDraw->SetFlags(flags);
    m_World->SetDebugDraw(m_debugDraw);
 }
void GamePlay::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    Layer::draw(renderer, transform, flags);
    Director* director = Director::getInstance();
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION );
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    m_World->DrawDebugData();
    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}
b2Body* GamePlay::createBall(string spriteName,bool isHero,Vec2 pos)
{
    
    auto sp=Sprite::create(spriteName.c_str());
    sp->setPosition(pos);
    sp->setScale(y_scale);
    this->addChild(sp);
    if(isHero)
        sp->setTag(10);

    b2CircleShape circle;
    circle.m_radius = (sp->getContentSize().width*y_scale/2)/PTM_RATIO;

    b2FixtureDef ballShapeDef;
    ballShapeDef.shape = &circle;
    ballShapeDef.density = 20;
    ballShapeDef.friction = 100;
    ballShapeDef.restitution = 0.2f;
    
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody;
    myBodyDef.position.Set(pos.x/PTM_RATIO,pos.y/PTM_RATIO);
    myBodyDef.userData=sp;
    myBodyDef.angle = 0;

    b2Body* ballBody = m_World->CreateBody(&myBodyDef);
    ballBody->SetAngularDamping(1);
    ballBody->SetLinearDamping(1);
    ballBody->SetBullet(false);
    ballBody->CreateFixture(&ballShapeDef);
       
    return ballBody;
}


void GamePlay::update(float dt)
{
    int velosityIterations = 8;
    int positionIterations = 3;
    
    m_World->Step(dt, velosityIterations, positionIterations);
    
    if(this->getChildByTag(5000))
        return ;
    
    for (auto b = m_World->GetBodyList(); b; b= b->GetNext())
    {
        if (b->GetUserData() != NULL)
        {
            Sprite *sp = (Sprite*) b->GetUserData();
            sp->setPosition(Point(b->GetPosition().x*PTM_RATIO, b->GetPosition().y*PTM_RATIO));
            sp->setRotation(-1* CC_RADIANS_TO_DEGREES(b->GetAngle()));
        }
    }
 
}
 bool GamePlay::onTouchBegan(Touch* touch, Event* event)
{
    if(this->getChildByTag(5000))
        return true;
    locationBegan=touch->getLocationInView();
    locationBegan=Director::getInstance()->convertToGL(location);
    locationBegan=this->convertToNodeSpace(location);
    
    if(!imageArrow && bodyHero->IsAwake()==false)
    {
        imageArrow=Sprite::create("starting_path.png");
        imageArrow->setPosition(this->getChildByTag(10)->getPosition());
        imageArrow->setAnchorPoint(Vec2(0.5,0));
        imageArrow->setScale(y_scale);
        this->addChild(imageArrow);

        auto diff = imageArrow->getPosition() - locationBegan;
        _prevAngle = atan2(diff.x, diff.y) * (180 / 3.14);
        imageArrow->setRotation(-180+_prevAngle);
    }
 
    return true;
}
void GamePlay::onTouchMoved(Touch *touch, Event *pEvent)
{
    if(this->getChildByTag(5000))
        return ;
    location=touch->getLocationInView();
    location=Director::getInstance()->convertToGL(location);
    location=this->convertToNodeSpace(location);
    
    if(imageArrow)
    {
        auto diff =imageArrow->getPosition().getDistance(location);

        auto diff1 = imageArrow->getPosition() - location;
        _prevAngle = atan2(diff1.x, diff1.y) * (180 / 3.14);
        imageArrow->setRotation(-180+_prevAngle);

        scale=abs((imageArrow->getContentSize().height+diff)/imageArrow->getContentSize().height);
            imageArrow->setScaleY(scale*y_scale);
    }
    
}
void GamePlay::onTouchEnded(Touch *touch, Event *pEvent)
{
    if(this->getChildByTag(5000))
        return ;
    location=touch->getLocationInView();
    location=Director::getInstance()->convertToGL(location);
    location=this->convertToNodeSpace(location);
    
    
    if(imageArrow )
    {
       
        speedOfBall=1000;
        float x = speedOfBall *imageArrow->getScaleY() * sin(CC_DEGREES_TO_RADIANS(imageArrow->getRotation()));
        float y = speedOfBall*imageArrow->getScaleY()* cos(CC_DEGREES_TO_RADIANS(imageArrow->getRotation()));
        bodyHero->ApplyLinearImpulseToCenter(b2Vec2(x,y), true);
 
        isBallMoving=true;
        imageArrow->removeFromParent();
        imageArrow=NULL;

    }

    
        // CCLOG("=====================================");
    CCLOG("Vec2(%2.0f,%2.0f)",location.x,location.y);
    
}
void GamePlay::onTouchCancelled(Touch *touch, Event *pEvent)
{
    if(this->getChildByTag(5000))
        return ;
    location=touch->getLocationInView();
    location=Director::getInstance()->convertToGL(location);
    location=this->convertToNodeSpace(location);
    
    CCLOG("Vec2(%2.0f,%2.0f)",location.x,location.y);
    
}
void GamePlay::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    if(EventKeyboard::KeyCode::KEY_ESCAPE==keyCode)
    {
    }
    
}
void GamePlay::TouchOn()
{
    _eventDispatcher->setEnabled(true);
}
void GamePlay::TouchOff()
{
    _eventDispatcher->setEnabled(false);
    
}

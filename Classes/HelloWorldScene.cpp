#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    CkConfig config;
    CkInit(&config);
    
    bank = CkBank::newBank("sound.ckb");
    sound = CkSound::newBankSound(bank, "main");
    se_ball_appear = CkSound::newBankSound(bank, "se_ball_appear");
    
    auto startButton = ui::Button::create("sprite9.png");
    startButton->setScale9Enabled(true);
    startButton->setContentSize(cocos2d::Size(100, 100));
    startButton->setPosition(Vec2(visibleSize.width * 0.2, visibleSize.height * 0.2));
    startButton->setTitleText("start");
    startButton->setTitleColor(Color3B::BLACK);
    startButton->setTitleFontSize(20);
    this->addChild(startButton, 2);

    startButton->addTouchEventListener([this](Ref* pSender, ui::Widget::TouchEventType type){
        if (type == ui::Widget::TouchEventType::ENDED) {
            sound->play();
        }
        return;
    });

    auto stopButton = ui::Button::create("sprite9.png");
    stopButton->setScale9Enabled(true);
    stopButton->setContentSize(cocos2d::Size(100, 100));
    stopButton->setPosition(Vec2(visibleSize.width * 0.4, visibleSize.height * 0.2));
    stopButton->setTitleText("stop");
    stopButton->setTitleColor(Color3B::BLACK);
    stopButton->setTitleFontSize(20);
    this->addChild(stopButton, 2);
    
    stopButton->addTouchEventListener([this](Ref* pSender, ui::Widget::TouchEventType type){
        if (type == ui::Widget::TouchEventType::ENDED) {
            sound->stop();
        }
        return;
    });
    

    
    return true;
}
#include "GameScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene *GameScreen::createScene()
{

    auto scene = Scene::create();

    auto layer = GameScreen::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool GameScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto pauseItem = MenuItemImage::create("Pause_Button.png", "Pause_Button(Click).png", CC_CALLBACK_1(GameScreen::GoToPauseScene, this));
    pauseItem->setPosition(Point(pauseItem->getContentSize().width - (pauseItem->getContentSize().width / 2) + origin.x, visibleSize.height - pauseItem->getContentSize().height + (pauseItem->getContentSize().width / 2) + origin.y));

    auto menuTitle = MenuItemImage::create("Play_Level.png", "Play_Level.png");
    float rx = visibleSize.width / menuTitle->getContentSize().width;
    float ry = visibleSize.height / menuTitle->getContentSize().height;

    menuTitle->setScaleX(rx);
    menuTitle->setScaleY(ry);

    menuTitle->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));

    auto menu = Menu::create(pauseItem, menuTitle, NULL);

    // menu->alignItemsVerticallyWithPadding(visibleSize.height/4);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);

    mySprite = Sprite::create("rose.png");

    mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));

    this->addChild(mySprite);

    // auto action = MoveBy::create(3, Point(100, 50));

    // auto action = MoveTo::create(3, Point(100, 0));

    // auto action = JumpBy::create(3, Point(100, 0), 50, 3);

    // auto action = JumpTo::create(3, Point(100, 30), 50, 6);

    // auto action = Sequence::create(MoveBy::create(5, Point(100, 0)), NULL);

    auto action = MoveBy::create(5, Point(100, 0));

    mySprite->runAction(EaseBounceIn::create(action));

    // mySprite->runAction(action);

    return true;
}

void GameScreen::GoToPauseScene(cocos2d::Ref *pSender)
{
    auto scene = PauseMenu::createScene();

    Director::getInstance()->pushScene(scene);
}

void GameScreen::GoToGameOverScene(cocos2d::Ref *pSender)
{
    auto scene = GameOver::createScene();

    Director::getInstance()->replaceScene(scene);
}

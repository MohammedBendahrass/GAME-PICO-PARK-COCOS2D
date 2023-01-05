#include "MainMenuScene.h"
#include "GameScene.h"
#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>

USING_NS_CC;

Scene *MainMenu::createScene()
{

    auto scene = Scene::create();

    auto layer = MainMenu::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto menuTitle = MenuItemImage::create("poster.png", "poster.png");

    auto playItem = MenuItemImage::create("Play_Button.png", "Play_Button(Click).png",
                                          CC_CALLBACK_1(MainMenu::GoToGameScene, this));

    auto menu = Menu::create(menuTitle, playItem, NULL);

    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);

    this->addChild(menu);

    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.25);

    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("picopark.mp3");

    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("picopark.mp3");

    return true;
}

void MainMenu::GoToGameScene(Ref *pSender)
{
    auto scene = GameScreen::createScene();

    Director::getInstance()->replaceScene(scene);
}

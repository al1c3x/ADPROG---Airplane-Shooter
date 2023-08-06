#include "GameScene.h"
#include "BGObject.h"
#include "AirplanePlayer.h"
#include "AirplaneSupport.h"
#include "EnemyAirplane.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "EmptyGameObject.h"
#include "EnemySwarmHandler.h"
#include "ProjectileSwarmHandler.h"
#include "ProjectileObject.h"
#include "HUDScreen.h"
#include "PhysicsManager.h"

GameScene::GameScene() :AScene("GameScene")
{

}

GameScene::~GameScene()
{
}

void GameScene::onLoadResources()
{
}

void GameScene::onLoadObjects()
{
    BGObject* bgObject = new BGObject("BGObject");
    this->registerObject(bgObject);

    AirplanePlayer* planeObject = new AirplanePlayer("PlaneObject");
    this->registerObject(planeObject);


    AirplaneSupport* support1 = new AirplaneSupport("AirSupport_1");
    planeObject->attachChild(support1);
    support1->setPosition(50, 100);

    AirplaneSupport* support2 = new AirplaneSupport("AirSupport_2");
    planeObject->attachChild(support2);
    support2->setPosition(-50, 100);

    HUDScreen* hudScreen = new HUDScreen("HUDScreen");
    this->registerObject(hudScreen);

    //create N enemies via object pooling
    srand(time(NULL));
    EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
    EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(10, "SwarmHandler");
    enemiesManager->attachComponent(swarmHandler);
    this->registerObject(enemiesManager);


    ProjectileSwarmHandler* projectileswarmHandler = new ProjectileSwarmHandler(50, "ProjectileSwarmHandler");
    planeObject->attachComponent(projectileswarmHandler);

    PhysicsManager::initialize("physics", planeObject);

}

void GameScene::onUnloadObjects()
{
    GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
    ObjectPoolHolder::getInstance()->unregisterObjectPool(enemyPool);
    AScene::onUnloadObjects();

    GameObjectPool* projectilePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG);
    ObjectPoolHolder::getInstance()->unregisterObjectPool(projectilePool);
    AScene::onUnloadObjects();

    PhysicsManager::getInstance()->clean();
    
}


void GameScene::onUnloadResources()
{
}
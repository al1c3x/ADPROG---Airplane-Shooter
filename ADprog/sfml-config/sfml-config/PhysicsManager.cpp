#include "PhysicsManager.h"
#include "ObjectPoolHolder.h"
#include "GameObjectManager.h"
#include "SamplePopupScreen.h"
#include <iostream>

PhysicsManager* PhysicsManager::sharedInstance = NULL;

void PhysicsManager::initialize(string name, AGameObject* parent){

    PhysicsManager* Physics = new PhysicsManager(name);
    parent->attachComponent(Physics);
}

void PhysicsManager::destroy(){
}

PhysicsManager* PhysicsManager::getInstance(){

    if (sharedInstance == NULL)
    {
        sharedInstance = new PhysicsManager("PhysicsManager");
    }
    return sharedInstance;
}

PhysicsManager::~PhysicsManager(){
}

void PhysicsManager::trackObject(Collider* object){

    trackedObjects.push_back(object);
}

void PhysicsManager::trackProjectiles(Collider* projectiles){

    trackedProjectiles.push_back(projectiles);
}
void PhysicsManager::trackEnemies(Collider* enemies){

    trackedEnemies.push_back(enemies);
}
void PhysicsManager::trackPlayer(Collider* player) {

    trackedPlayer.push_back(player);
}


void PhysicsManager::untrackObject(Collider* object){

    forCleaningObjects.push_back(object);
    delete object;
    trackedObjects.erase(std::remove(trackedObjects.begin(), trackedObjects.end(), object), trackedObjects.end());
    trackedObjects.shrink_to_fit();
}

void PhysicsManager::perform()
{
    for (unsigned int i= 0; i < sharedInstance->trackedPlayer.size(); i++)
    {
        for (unsigned int j = 0; j < sharedInstance->trackedEnemies.size(); j++) {
            if (sharedInstance->trackedPlayer[i]->willCollide(sharedInstance->trackedEnemies[j]))
            {
                SamplePopupScreen* gameover = new SamplePopupScreen("gameover");
                GameObjectManager::getInstance()->addObject(gameover);

            }
        }
        
     
    }


    for (unsigned int i = 0; i < sharedInstance->trackedProjectiles.size(); i++){
        for (unsigned int j = 0; j < sharedInstance->trackedEnemies.size(); j++){

            if (sharedInstance->trackedProjectiles[i]->willCollide(sharedInstance->trackedEnemies[j])){
                ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG)->releasePoolable
                ((APoolable*)sharedInstance->trackedProjectiles[i]->getOwner());

                ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG)->releasePoolable
                ((APoolable*)sharedInstance->trackedEnemies[j]->getOwner());
                
            }
        }
    }
    trackedProjectiles.clear();
    trackedEnemies.clear();
}

void PhysicsManager::clean()
{
    cleanUpObjects();
}

void PhysicsManager::cleanUpObjects()
{
    sharedInstance->trackedEnemies.clear();
    sharedInstance->trackedProjectiles.clear();
    sharedInstance->trackedObjects.clear();
}
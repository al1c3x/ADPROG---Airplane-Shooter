#include "ProjectileSwarmHandler.h"
#include "EnemySwarmHandler.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "EnemyAirplane.h"
#include "ProjectileObject.h"
#include "PlayerInputController.h"
#include "AirplanePlayer.h"


ProjectileSwarmHandler::ProjectileSwarmHandler(int numProjectiles, string name) : AComponent(name, Script)
{
	GameObjectPool* ProjectilePool = new GameObjectPool(ObjectPoolHolder::PROJECTILE_POOL_TAG, new ProjectileObject("Projectile"), numProjectiles, NULL);
	ProjectilePool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(ProjectilePool);
}

ProjectileSwarmHandler::~ProjectileSwarmHandler()
{

}

void ProjectileSwarmHandler::perform()
{
	AirplanePlayer* airplane = (AirplanePlayer*)this->owner;
	PlayerInputController* BulletFire = (PlayerInputController*)airplane->findComponentByName("MyPlayerInput");

	if (BulletFire->isSpace()) {
		GameObjectPool* projectilePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG);
		this->timer += this->deltaTime.asSeconds();

		if (this->timer > SPAWN_INTERVAL) {
			this->timer = 0.0f;
			projectilePool->requestPoolable();
		}
	}
}
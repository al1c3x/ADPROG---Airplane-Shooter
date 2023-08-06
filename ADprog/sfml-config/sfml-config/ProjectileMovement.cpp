#include "ProjectileMovement.h"
#include "EnemyBehavior.h"
#include "AGameObject.h"
#include <iostream>
#include "Game.h";
#include "ObjectPoolHolder.h"


ProjectileMovement::ProjectileMovement(string name) : AComponent(name, Script)
{
	this->reset();
}

void ProjectileMovement::perform()
{
	this->timer += this->deltaTime.asSeconds();
	sf::Transformable* transformable = this->getOwner()->getTransformable();

	if (this->timer > this->forwardDuration) {
		
		this->timer = 0.0f;
	}

	if (this->movementType == Forward) {
		transformable->move(0, this->deltaTime.asSeconds() * -SPEED);
	}

	
	if (transformable->getPosition().y < 0) {
		ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG)->releasePoolable((APoolable*)this->getOwner());
	}
}




void ProjectileMovement::delayTimer(float delay)
{
	this->delay += delay;
}

void ProjectileMovement::reset()
{
	this->movementType = Forward;
	this->timer = 0.0f;
}
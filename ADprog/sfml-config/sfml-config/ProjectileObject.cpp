#include "ProjectileObject.h"
#include "EnemyAirplane.h"
#include "TextureManager.h"
#include "Game.h"
#include "ProjectileMovement.h"
#include <iostream>
#include "GameObjectManager.h"
#include "Renderer.h"
#include "PhysicsManager.h"
#include "Collider.h"

ProjectileObject::ProjectileObject(string name) : APoolable(name)
{

}

void ProjectileObject::initialize()
{
	
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("Projectile"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();

	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);


	Renderer* renderer = new Renderer("Bullet");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	ProjectileMovement* movement = new ProjectileMovement("ProjectileMovement");
	this->attachComponent(movement);
	movement->delayTimer(0.5f);

	Collider* collision = new Collider("ProjectileCollider", sprite);
	this->attachComponent(collision);

	PhysicsManager::getInstance()->trackProjectiles(collision);

}

void ProjectileObject::onRelease()
{
	ProjectileMovement* movement = (ProjectileMovement*)this->findComponentByName("ProjectileMovement");
	movement->reset();
	sf::Vector2f PlanePos = GameObjectManager::getInstance()->findObjectByName("PlaneObject")->getTransformable()->getPosition();
	this->setPosition(PlanePos.x, PlanePos.y);
}

void ProjectileObject::onActivate()
{
	
	ProjectileMovement* movement = (ProjectileMovement*)this->findComponentByName("ProjectileMovement");
	movement->reset();
	sf::Vector2f PlanePos = GameObjectManager::getInstance()->findObjectByName("PlaneObject")->getTransformable()->getPosition();
	this->setPosition(PlanePos.x, PlanePos.y);

}

APoolable* ProjectileObject::clone()
{
	APoolable* copyObj = new ProjectileObject(this->name);
	return copyObj;
}
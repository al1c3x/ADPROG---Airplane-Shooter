#include "PlayerMovement.h"
#include "AGameObject.h"
#include "PlayerInputController.h"
#include <iostream>

PlayerMovement::PlayerMovement(string name) : AComponent(name, Script)
{

}

PlayerMovement::~PlayerMovement()
{
	AComponent::~AComponent();
}

void PlayerMovement::perform()
{
	PlayerInputController* inputController = (PlayerInputController*)this->getOwner()->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* playerTransformable = this->getOwner()->getTransformable();
	if (playerTransformable == NULL || inputController == NULL) {
		cout << "One or more of the needed dependencies are missing!\n";
		return;
	}

	sf::Vector2f offset(0.0f, 0.0f);
	if (inputController->isUp()) {
		offset.y -= this->SPEED_MULTIPLIER;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}
	else if (inputController->isDown()) {
		offset.y += this->SPEED_MULTIPLIER;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}

	else if (inputController->isRight()) {
		offset.x += this->SPEED_MULTIPLIER;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}
	else if (inputController->isLeft()) {
		offset.x -= this->SPEED_MULTIPLIER;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}
}
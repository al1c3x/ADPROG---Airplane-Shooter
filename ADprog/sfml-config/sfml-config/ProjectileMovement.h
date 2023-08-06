
#pragma once
#include "AComponent.h"
class ProjectileMovement : public AComponent
{

public:
	enum ProjectileMovementType { Delay = 0, Forward = 1 };

	ProjectileMovement(string name);
	void perform();
	void delayTimer(float delay);
	void reset();

private:
	const float SPEED = 100.0f;
	ProjectileMovementType movementType = Forward;
	float timer = 0.0f;
	float delay = 0.0f;
	float forwardDuration = 0.0f;
};


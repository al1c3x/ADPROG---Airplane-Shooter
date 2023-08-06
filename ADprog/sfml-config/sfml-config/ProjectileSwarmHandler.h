#pragma once
#include "AComponent.h"
//class handling N enemy airplanes. communicates with object pool
class ProjectileSwarmHandler : public AComponent
{
public:
	ProjectileSwarmHandler(int numProjectiles, string name);
	~ProjectileSwarmHandler();
	void perform();

private:
	const float SPAWN_INTERVAL = 1.0f;
	float timer = 0.0f;
};
#pragma once
#include "AComponent.h"
#include "AGameObject.h"
#include <unordered_map>
#include <vector>
#include "Collider.h"

typedef std::vector<Collider*> CollisionList;

class PhysicsManager : public AComponent
{
public:
	static void initialize(string name, AGameObject* parent);
	static void destroy();
	static PhysicsManager* getInstance();
	~PhysicsManager();

	void trackObject(Collider* object);
	void trackEnemies(Collider* enemy);
	void trackPlayer(Collider* player);
	void trackProjectiles(Collider* projectiles);
	void untrackObject(Collider* object);
	void perform();
	void clean();
private:
	PhysicsManager(string name) : AComponent(name, Script) {};
	PhysicsManager(PhysicsManager const&) : AComponent(name, Script) {};             // copy constructor is private
	PhysicsManager& operator=(PhysicsManager const&) {};  // assignment operator is private
	static PhysicsManager* sharedInstance;

	CollisionList trackedPlayer;
	CollisionList trackedObjects;
	CollisionList forCleaningObjects;
	CollisionList trackedEnemies;
	CollisionList trackedProjectiles;

	void cleanUpObjects();

};

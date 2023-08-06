

#include "APoolable.h"
#include <iostream>

using namespace std;



class ProjectileObject : public APoolable
{
public:
	ProjectileObject(string name);
	void initialize();
	void onRelease();
	void onActivate();
	APoolable* clone();

private:
	int counter = 0;
};




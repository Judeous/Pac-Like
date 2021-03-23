#include "DazedBehavior.h"
#include "Minion.h"

void DazedBehavior::update(Agent* owner, float deltaTime)
{
	timeSinceSpawn += deltaTime;
	int randInt = rand();
	if (timeSinceSpawn >= spawnedTimer)
		owner->addBehavior();
	owner->setVelocity(owner->getForward() / 2);
}

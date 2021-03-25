#include "DazedBehavior.h"
#include "Minion.h"

DazedBehavior::DazedBehavior(float timer)
{
	spawnedTimer = timer;
}

void DazedBehavior::update(Agent* owner, float deltaTime)
{
	timeSinceSpawn += deltaTime;
	int randInt = rand();
	if (timeSinceSpawn >= spawnedTimer)
		setEnabled(false);
}

MathLibrary::Vector2 DazedBehavior::calculateForce(Agent* agent)
{
	return (agent->getForward() / 2);
}

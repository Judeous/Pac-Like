#include "DazedBehavior.h"
#include "Minion.h"

DazedBehavior::DazedBehavior(float timer)
{
	m_direction = MathLibrary::Vector2(cos(rand()), sin(rand())).getNormalized();
	spawnedTimer = timer;
}

void DazedBehavior::update(Agent* owner, float deltaTime)
{
	owner->applyForce(m_direction / 2);

	timeSinceSpawn += deltaTime;
	if (timeSinceSpawn >= spawnedTimer)
		setEnabled(false);
}
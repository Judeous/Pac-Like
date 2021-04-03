#include "DazedBehavior.h"
#include "Minion.h"

DazedBehavior::DazedBehavior(float timer)
{
	m_direction = MathLibrary::Vector2(cos(rand()), sin(rand())).getNormalized();
	m_spawnedTimer = timer;
}

void DazedBehavior::update(Agent* owner, float deltaTime)
{
	owner->applyForce(m_direction * owner->getMaxSpeed()/5);

	m_timeSinceSpawn += deltaTime;
	if (m_timeSinceSpawn >= m_spawnedTimer)
		setEnabled(false);
}
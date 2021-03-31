#include "OrbitBehavior.h"
#include "Character.h"

OrbitBehavior::OrbitBehavior(Character* target, float forceScale)
{
	setTarget(target);
	setForceScale(forceScale);
}

MathLibrary::Vector2 OrbitBehavior::calculateForce(Agent* agent)
{
	//Calculate current Distance and get the maximum and minimum distances
	MathLibrary::Vector2 toTarget = m_target->getWorldPosition() - agent->getWorldPosition();
	float currentDistance = toTarget.getMagnitude();
	float minDistance = getForceScale() * 128;
	float maxDistance = getForceScale() * 416;

	MathLibrary::Vector2 direction = MathLibrary::Vector2();

	//If too close
	if (currentDistance < minDistance)
	{
		//Create a Vector facing away from the target
		direction = (agent->getWorldPosition() - m_target->getWorldPosition()).getNormalized();
	}
	//If too far
	else if (currentDistance > maxDistance)
	{
		//Create a Vector facing the target
		direction = (m_target->getWorldPosition() - agent->getWorldPosition()).getNormalized();
	}
	else
	{
		//Create a Vector facing to the side
		direction = MathLibrary::Vector2(toTarget.y, -1 * toTarget.x);
	}
	return direction * agent->getMaxSpeed();
}

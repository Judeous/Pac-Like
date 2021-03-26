#include "ShieldBehavior.h"
#include "Character.h"
#include "Game.h"

MathLibrary::Vector2 ShieldBehavior::calculateForce(Agent* agent)
{
	MathLibrary::Vector2 direction = MathLibrary::Vector2();
	if (m_defended->getTarget())
	{
		//Get Vector from defended to blocked
		MathLibrary::Vector2 defToBlocked = m_defended->getTarget()->getWorldPosition() - m_defended->getWorldPosition();

		//Shrink that Vector's Magnitude by 3/4
		defToBlocked = defToBlocked / 4;

		//Get direction Vector pointing from Agent to that Vector
		MathLibrary::Vector2 direction = (defToBlocked - agent->getWorldPosition()).getNormalized();

		//Return direction Vector scaled by the agent's speed
	}
	else
	{
		MathLibrary::Vector2 direction = (m_defended->getWorldPosition() + m_defended->getForward()).getNormalized();
	}
	return direction * agent->getMaxSpeed();
}

void ShieldBehavior::setTarget(Character* defended)
{
	m_defended = defended;
	m_defended->setDefended(true);
}
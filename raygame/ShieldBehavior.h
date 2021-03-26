#pragma once
#include "SteeringBehavior.h"

class Character;

class ShieldBehavior : public SteeringBehavior
{
public:
	ShieldBehavior(Character* defended) { setTarget(defended); }
	MathLibrary::Vector2 calculateForce(Agent* agent);
	
	void setTarget(Character* defended);
private:
	Character* m_defended;
};
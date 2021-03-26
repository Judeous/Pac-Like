#pragma once
#include "SteeringBehavior.h"

class Character;

class LimitedEvadeBehavior : public SteeringBehavior
{
public:
	LimitedEvadeBehavior(Character* target, float forceScale = 5);

	MathLibrary::Vector2 calculateForce(Agent* agent) override;
};
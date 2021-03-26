#pragma once
#include "SteeringBehavior.h"
class OrbitBehavior : public SteeringBehavior
{
public:
	OrbitBehavior(Character* target, float forceScale = 1);
	MathLibrary::Vector2 calculateForce(Agent* agent) override;
	void setTarget(Character* target) { m_target = target; }

private:
	float angle;
	Character* m_target;
};
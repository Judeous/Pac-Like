#pragma once
#include "SteeringBehavior.h"

class Agent;

class DazedBehavior : public SteeringBehavior
{
public:
	DazedBehavior(float timer);
	void update(Agent* owner, float deltaTime) override;
	virtual MathLibrary::Vector2 calculateForce(Agent* agent) override;

private:
	float spawnedTimer = 2.0f;
	float timeSinceSpawn = 0;
};
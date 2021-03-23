#pragma once
#include "SteeringBehavior.h"
#include <Vector2.h>

class Agent;

class DazedBehavior : public SteeringBehavior
{
public:
	void update(Agent* owner, float deltaTime) override;

private:
	float spawnedTimer = 3.0f;
	float timeSinceSpawn = 0;
};
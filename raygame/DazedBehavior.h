#pragma once
#include "Behavior.h"

class Agent;

class DazedBehavior : public Behavior
{
public:
	DazedBehavior(float timer);
	void update(Agent* owner, float deltaTime) override;

private:
	MathLibrary::Vector2 m_direction;
	float m_spawnedTimer = 2.0f;
	float m_timeSinceSpawn = 0;
};
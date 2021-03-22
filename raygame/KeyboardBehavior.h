#pragma once
#include "Behavior.h"

class KeyboardBehavior : public Behavior
{
public:
	/// <param name="speed">The speed to move when a direction is pressed</param>
	KeyboardBehavior(float speed):m_speedIncrement(speed) {};
	virtual ~KeyboardBehavior() {};

	virtual void update(Agent* owner, float deltaTime) override;

private:
	float m_speedIncrement;
};


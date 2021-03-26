#pragma once
#include "Agent.h"

class Character;

class Projectile : public Agent
{
public:
	Projectile(Character* target, float speed, int damage);
	void update(float deltaTime) override;
	void onCollision(Actor* other) override;

private:
	Character* m_target;
	float m_speed;
	int m_damage;
};
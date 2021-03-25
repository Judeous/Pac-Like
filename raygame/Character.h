#pragma once
#include "Agent.h"
class Character : public Agent
{
public:
    Character();
    Character(float x, float y, float speed, int health);
    void update(float deltaTime) override;

    int takeDamage(int damage) { return m_health -= damage; }
    int dealDamage(int damage, Character target) { return target.takeDamage(damage); }

    virtual void setTarget(Character* target);
protected:
    float m_attackCoolDown = 1;
    float m_timeSinceAttack = 0;
    int m_health = 5;
};
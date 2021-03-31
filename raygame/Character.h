#pragma once
#include "Agent.h"
class Character : public Agent
{
public:
    Character();
    Character(float x, float y, float speed, int health, float collRadius, int color = (int)0xFFFF00FF);
    void update(float deltaTime) override;

    int takeDamage(int damage) { return m_health -= damage; }
    int dealDamage(int damage, Character* target) { return target->takeDamage(damage); }
    int getHealth() { return m_health; }

    virtual void setTarget(Character* target) { m_target = target; m_target->setTargeted(true); }
    virtual Character* getTarget() { return m_target; }

    bool getDefended() { return m_defended; }
    void setDefended(bool value) { m_defended = value; }

    bool getTargeted() { return m_targeted; }
    void setTargeted(bool value) { m_targeted = value; }
protected:
    Character* m_target = nullptr;
    float m_attackCoolDown = 1;
    float m_timeSinceAttack = 0;
    int m_health = 5;
    bool m_defended = false;
    bool m_targeted = false;
};
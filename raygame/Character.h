#pragma once
#include "Agent.h"
class Character : public Agent
{
public:
    Character(float x, float y, float speed, int health);

protected:
    int m_health = 3;
};
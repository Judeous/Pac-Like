#pragma once
#include "Character.h"

class SteeringBehavior;

class Summoner : public Character
{
public:
	Summoner(float x, float y);
	void update(float deltaTime) override;
private:
	void summon();
};
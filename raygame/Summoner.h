#pragma once
#include "Character.h"

class SteeringBehavior;
class Maze;

class Summoner : public Character
{
public:
	Summoner(float x, float y, float speed, Maze* maze);
	void start() override;
	void update(float deltaTime) override;
private:
	void summon();
private:
	Maze* m_maze;
};
#include "Character.h"
#include "Agent.h"
#include"Maze.h"

Character::Character()
	: Agent(0, 0, Maze::TILE_SIZE, 0, 0, (int)0x00009900)
{ }

Character::Character(float x, float y, float speed, int health)
	: Agent(x, y, Maze::TILE_SIZE / 2.5f, speed, speed, (int)0x00009900)
{
	m_health = health;
}

void Character::update(float deltaTime)
{
	m_timeSinceAttack -= deltaTime;
	Agent::update(deltaTime);
}

void Character::setTarget(Character* target)
{
	
}

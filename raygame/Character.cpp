#include "Character.h"
#include "Agent.h"
#include"Maze.h"

Character::Character(float x, float y, float speed, int health)
	: Agent(x, y, Maze::TILE_SIZE / 2.5f, speed, speed, (int)0x00009900)
{
	m_health = health;
}

#include "Character.h"
#include "Agent.h"
#include "Maze.h"
#include "SeekPathBehavior.h"

Character::Character()
	: Agent(0, 0, Maze::TILE_SIZE, 0, 0, 0x00FFFFFF)
{ }

Character::Character(float x, float y, float speed, int health, float collRadius = Maze::TILE_SIZE / 2.5f, int color)
	: Agent(x, y, collRadius, speed, speed, color)
{
	m_health = health;
}

void Character::update(float deltaTime)
{
	m_timeSinceAttack += deltaTime;
	Agent::update(deltaTime);
}

void Character::setTarget(Character* target)
{
	m_target = target;

	std::vector<Behavior*> behaviors = getBehaviors();
	for (int i = 0; i < getBehaviors().size(); i++)
	{
		SeekPathBehavior* seekPath = dynamic_cast<SeekPathBehavior*>(behaviors[i]);
		if (seekPath)
			seekPath->setTarget(target);
	}

	m_target->setTargeted(true);
}

#include "Summoner.h"
#include "Minion.h"
#include "Game.h"
//#include "ShieldBehavior.h"
#include "SeekPathBehavior.h"
#include "OrbitBehavior.h"

Summoner::Summoner(float x, float y, float speed, Maze* maze)
	: Character(x, y, speed, m_health, 32 / 2.0f)
{
	m_maze = maze;
	m_attackCoolDown = 3;
}

void Summoner::start()
{
	Summoner* enemy = Game::getInstance()->getCurrentScene()->getEnemySummoner(this);
	if (enemy)
		setTarget(enemy);
	else
		m_target = nullptr;

	OrbitBehavior* orbit = new OrbitBehavior(m_target);
	addBehavior(orbit);
}

void Summoner::update(float deltaTime)
{
	Character::update(deltaTime);
	if (m_timeSinceAttack >= m_attackCoolDown)
	{
		summon();
		m_timeSinceAttack = 0;
	}
}

void Summoner::summon()
{
	//Create Minions
	Minion* warriorMinion = new Minion(getWorldPosition().x, getWorldPosition().y, 250.0f, this, m_maze);
	Minion* warriorMinion2 = new Minion(getWorldPosition().x, getWorldPosition().y, 250.0f, this, m_maze);
	Minion* warriorMinion3 = new Minion(getWorldPosition().x, getWorldPosition().y, 250.0f, this, m_maze);

	//Add Minions to the current Scene
	Game::getInstance()->getCurrentScene()->addActor(warriorMinion);
	Game::getInstance()->getCurrentScene()->addActor(warriorMinion2);
	Game::getInstance()->getCurrentScene()->addActor(warriorMinion3);
}
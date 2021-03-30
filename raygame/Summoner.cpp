#include "Summoner.h"
#include "Minion.h"
#include "Game.h"
#include "DazedBehavior.h"
#include "ShieldBehavior.h"
#include "SeekBehavior.h"
#include "OrbitBehavior.h"

Summoner::Summoner(float x, float y) : Character(x, y, getMaxSpeed(), m_health, 32 / 2.0f)
{
	Summoner* enemy = Game::getInstance()->getCurrentScene()->getEnemySummoner(this);
	if (enemy)
		m_target = enemy;
	else
		m_target = nullptr;
}

void Summoner::update(float deltaTime)
{
	if (m_timeSinceAttack >= m_attackCoolDown)
		summon();
	Character::update(deltaTime);
}

void Summoner::summon()
{
	//Create Minions
	Minion* defenderMinion = new Minion(getWorldPosition().x, getWorldPosition().y, this);
	Minion* warriorMinion = new Minion(getWorldPosition().x, getWorldPosition().y, this);
	Minion* casterMinion = new Minion(getWorldPosition().x, getWorldPosition().y, this);

	//Create Behaviors for the Minions
	DazedBehavior* dazed = new DazedBehavior(3);
	ShieldBehavior* shield = new ShieldBehavior(this);
	SeekBehavior* seek = new SeekBehavior();
	OrbitBehavior* orbit = new OrbitBehavior(m_target);
	
	//Give the Minions the Behaviors
	defenderMinion->addBehavior(dazed);
	defenderMinion->addBehavior(shield);
	warriorMinion->addBehavior(dazed);
	warriorMinion->addBehavior(seek);
	casterMinion->addBehavior(dazed);
	casterMinion->addBehavior(orbit);
	
	//Add Minions to the current Scene
	Game::getInstance()->getCurrentScene()->addActor(defenderMinion);
	Game::getInstance()->getCurrentScene()->addActor(warriorMinion);
	Game::getInstance()->getCurrentScene()->addActor(casterMinion);
}
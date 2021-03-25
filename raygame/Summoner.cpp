#include "Summoner.h"
#include "Minion.h"
#include "DazedBehavior.h"
#include "Game.h"

Summoner::Summoner(float x, float y)
	: Character(x, y, getMaxSpeed(), m_health)
{
    m_enemySummoner = Game::getInstance()->getCurrentScene()->getEnemySummoner(this);
}

void Summoner::update(float deltaTime)
{
	if (m_timeSinceAttack >= m_attackCoolDown)
		summon();
	Character::update(deltaTime);
}

void Summoner::setTarget(Character* target)
{
	m_enemySummoner = dynamic_cast<Summoner*>(target);
}

void Summoner::summon()
{
	Minion* minion = new Minion(getWorldPosition().x, getWorldPosition().y, this);
	DazedBehavior* dazed = new DazedBehavior(3);
	minion->addBehavior(dazed);
}
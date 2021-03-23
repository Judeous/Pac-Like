#pragma once
#include "Character.h"
#include <vector>

class Summoner;

class Minion : public Character
{
public:

private:
	Summoner* m_masterSummoner;
	Summoner* m_enemySummoner;
	std::vector<Minion> m_allyMinions;
	std::vector<Minion> m_enemyMinions;
};
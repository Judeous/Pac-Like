#pragma once
#include "Character.h"
#include <vector>

class Summoner;

class Minion : public Character
{
public:
	Minion(float x, float y, Summoner* master);

	void update(float deltaTime);
	void setTarget(Character* target) override;
	Summoner* getMaster() { return m_masterSummoner; }

private:
	/// <summary>
	/// Gets the teams of every Character currently in the Scene
	/// </summary>
	void getTeams();

	/// <summary>
	/// Checks the team of a new Minion, and adds it to the respective list
	/// </summary>
	/// <param name="minion">The Minion to check</param>
	void pushTeam(Minion* minion);

	/// <summary>
	/// Gives the Minions in the current Scene the team this Minion is on
	/// </summary>
	void giveTeam();
private:
	Character* m_currentTarget;
	Summoner* m_masterSummoner;
	Summoner* m_enemySummoner;
	std::vector<Minion*> m_allyMinions;
	std::vector<Minion*> m_enemyMinions;
};
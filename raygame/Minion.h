#pragma once
#include "Character.h"
#include <vector>

class Maze;
class Summoner;

class Minion : public Character
{
public:
	Minion(float x, float y, float speed, Summoner* master, Maze* maze);
	void start() override;
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

	/// <summary>
	/// Checks to see if there are any duplicates in the team vectors
	/// </summary>
	void checkTeamMembers();

	/// <summary>
	/// Finds a target in m_enemyMinions to target
	/// </summary>
	/// <returns>Whether or not a target was found</returns>
	bool findTarget();
private:
	Summoner* m_masterSummoner;
	Summoner* m_enemySummoner;
	std::vector<Minion*> m_allyMinions;
	std::vector<Minion*> m_enemyMinions;
	Maze* m_maze;
};
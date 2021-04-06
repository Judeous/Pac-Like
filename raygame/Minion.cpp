#include "Minion.h"
#include "Game.h"
#include "Summoner.h"
#include <Vector2.h>
#include "DazedBehavior.h"
#include "SeekPathBehavior.h"

Minion::Minion(float x, float y, float speed, Summoner* master, Maze* maze)
    : Character(x, y, speed, m_health, 32 / 3.0f)
{
    m_masterSummoner = master;
    m_maze = maze;
}

void Minion::start()
{
    //Get a random direction for DazedBehavior
    setForward(MathLibrary::Vector2(sin(rand()), cos(rand())).getNormalized());

    //Create Behaviors
    SeekPathBehavior* seekPath = new SeekPathBehavior(m_maze);
    DazedBehavior* dazed = new DazedBehavior(3);

    //Add behaviors
    addBehavior(dazed);
    //addBehavior(seekPath);

    //Assign Team variables
    //Give the Already existing Minions your team
    giveTeam();
    //Get the already existing Minions' teams
    getTeams();

    //Check for duplicates
    //checkTeamMembers();

    //Find a target
    findTarget();
}

void Minion::getTeams()
{
    //Get access to the Summoners in the current scene
    std::vector<Summoner*> summoners = Game::getInstance()->getCurrentScene()->getSummoners();
    //Check the team of the current Summoner, and assign accordingly
    for (int i = 0; i < summoners.size(); i++)
    {
        if (summoners[i] != getMaster())
            m_enemySummoner = summoners[i];
    }

    //Get access to the Minions in the current scene
    std::vector<Minion*> minions = Game::getInstance()->getCurrentScene()->getMinions();
    //Check the team of the current Minion, and assign accordingly
    for (int i = 0; i < minions.size(); i++)
    {
        //If the minion's master is the same as this one and is not this
        if (minions[i]->getMaster() == getMaster() && minions[i] != this)
            m_allyMinions.push_back(minions[i]);
        //Otherwise if the minion's master is this one's enemy summoner
        else if (minions[i]->getMaster() == m_enemySummoner)
            m_enemyMinions.push_back(minions[i]);
    }
}

void Minion::pushTeam(Minion* minion)
{
    if (minion->getMaster() == getMaster())
        m_allyMinions.push_back(minion);
    else if (minion->getMaster() == m_enemySummoner)
        m_enemyMinions.push_back(minion);
}

void Minion::giveTeam()
{
    //Get access to the Minions in the current scene
    std::vector<Minion*> minions = Game::getInstance()->getCurrentScene()->getMinions();

    for (int i = 0; i < minions.size(); i++)
    {
        if (minions[i] != this)
            minions[i]->pushTeam(this);
    }
}

void Minion::checkTeamMembers()
{
    //For every Minion
    for (int i = 0; i < m_allyMinions.size(); i++)
    {
        //Also for every Minion but in reverse
        for (int j = m_allyMinions.size(); j > 0; j--)
        {
            //If the minions in the j and i position are the same but the indexes aren't the same
            if (m_allyMinions[i] == m_allyMinions[j] && j != i)
            {
                std::vector<Minion*> tempMinions;
                //For every Minion
                for (int k = 0; k < m_allyMinions.size(); k++)
                {
                    //If the Minion at k's index is the same as the Minion at i's index
                    if (m_allyMinions[k] == m_allyMinions[i])
                        //Add the Minion to the new Array
                        tempMinions.push_back(m_allyMinions[k]);
                }
                m_allyMinions = tempMinions;
            }
        }
    }
}

bool Minion::findTarget()
{
    //If enemies exist
    if (!m_enemyMinions.empty())
    {
        //For every enemy Minion
        for (int i = 0; i < m_enemyMinions.size(); i++)
        {
            //If the current Minion isn't targeted
            if (!m_enemyMinions[i]->getTargeted())
            {
                setTarget(m_enemyMinions[i]);
                return true;
            }
        }
    }
    //Otherwise if the enemy Summoner isn't null
    else if (m_enemySummoner)
    {
        setTarget(m_enemySummoner);
        return true;
    }
    return false;
}
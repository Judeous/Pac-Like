#include "Minion.h"
#include "Game.h"
#include "Summoner.h"
#include <Vector2.h>
#include "DazedBehavior.h"

Minion::Minion(float x, float y, float speed, Summoner* master) : Character(x, y, speed, m_health, 32 / 3.0f)
{
    m_masterSummoner = master;
}

void Minion::start()
{
    //Get a random direction for DazedBehavior
    setForward(MathLibrary::Vector2(sin(rand()), cos(rand())).getNormalized());

    //Create a DazedBehavior
    DazedBehavior* dazed = new DazedBehavior(3);
    addBehavior(dazed);

    //Assign Team variables
    getTeams();
    giveTeam();

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
        if (minions[i]->getMaster() == getMaster())
            m_allyMinions.push_back(minions[i]);
        else
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
        minions[i]->pushTeam(this);
    }
}

bool Minion::findTarget()
{
    //If no enemies exist
    if (!m_enemyMinions.empty())
    {
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
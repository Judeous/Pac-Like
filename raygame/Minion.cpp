#include "Minion.h"
#include "Game.h"
#include "Summoner.h"
#include <Vector2.h>

Minion::Minion(float x, float y, Summoner* master) : Character(x, y, getMaxSpeed(), m_health)
{
    m_masterSummoner = master;
    //Get a random direction for DazedBehavior
    setForward(MathLibrary::Vector2(sin(rand()), cos(rand())).getNormalized());
    //Assign Team variables
    getTeams();
    giveTeam();
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

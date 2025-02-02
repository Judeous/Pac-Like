#pragma once
#include <vector>
#include "Character.h"

class Minion;
class Summoner;

class Scene
{
public:
    Scene();

    /// <returns>If this scene is the current active scene in the game.</returns>
    bool getStarted() { return m_started; }

    /// <returns>The scenes matrix that represents the world transform.</returns>
    MathLibrary::Matrix3* getWorld();

    /// <returns>m_actors</returns>
    std::vector<Actor*> getActors() { return m_actors; }

    /// <returns>All Actors that are Characters</returns>
    std::vector<Character*> getCharacters();
    
    /// <returns>All Actors that are Minions</returns>
    std::vector<Minion*> getMinions();

    /// <returns>All Actors that are Summoners</returns>
    std::vector<Summoner*> getSummoners();

    /// <returns>The passed in Summoner's enemy</returns>
    Summoner* getEnemySummoner(Summoner* currentSummoner);

    /// <summary>
    /// Adds the given actor to the array of actors so that the scene may call its update and drawGraph functions.
    /// </summary>
    /// <param name="actor">The actor to add to the scene.</param>
    void addActor(Actor* actor);

    /// <summary>
    /// Removes the actor at the given index. DOES NOT DELETE THE ACTOR!!!
    /// </summary>
    /// <param name="index">The index the actor is in the scene's array.</param>
    /// <returns>False if the index given is out of bounds.</returns>
    bool removeActor(int index);

    /// <summary>
    /// Removes the actor given if it's in the array. DOES NOT DELETE THE ACTOR!!!
    /// </summary>
    /// <param name="actor">The actor to look for in the scene's array.</param>
    /// <returns>False if the actor is a nullptr or isn't in the array.</returns>
    bool removeActor(Actor* actor);

    virtual void start();

    /// <summary>
    /// Checks if any actor has collided in scene. Calls the actors onCollision function if so.
    /// </summary>
    virtual void checkCollision();

    virtual void update(float deltaTime);

    virtual void draw();

    virtual void debug();

    virtual void end();

private:
    std::vector<Actor*> m_actors;
    MathLibrary::Matrix3* m_world;

    bool m_started = false;
};


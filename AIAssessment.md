AI Assessment
-------------

### Character
Inherits Agent
- Character()
  - calls Actor's constructor, passing in hardcoded values to make a default Character
- Character(float x, float y, float speed, int health)
  - also calls Actor's constructor, but passes in the parameters instead of hardcoded values
- void update(float deltaTime) overload
  - decrements member variable timeSinceAttack, then calls Agent's update
- int takeDamage(int damage)
  - returns damage subtracted from member variable health
- int dealDamage(int damage, Character* target)
  - returns a call for dealDamage through target, passing in damage
- void getHealth()
  - returns member variable health
- void setTarget(Character* target)
  - sets member variable target to passed in target
- Character* getTarget()
  - returns member variable target
- bool getDefended()
  - returns member variable defended
- void setDefended(bool value)
  - sets member variable defended to passed in value

### Minion
Inherits Character
- Minion(float x, float y, Summoner* master)
  - calls Character's constructor, passing in x and y as well as hardcoded values
  - sets member variable master to be passed in master
  - calls setForward, passing in normalized rand calls to get a random direction
  - calls getTeams and giveTeam
- Summoner* getMaser()
  - returns member variable masterSummoner
- void getTeams()
  - assigns the teams of every Character currently in the same Scene to the respective team member variable (allyMinions, enemyMinions, or enemySummoner)
- pushTeam(Minion* minion)
  - used when Minions are summoned after this Minion
  - checks the team of the passed in Minion and assigns accordingly
- giveTeam
  - used when created
  - tells the Minions already in the scene what team this Minion is on

### Summoner
Inherits Character
- Summoner(float x, float y)
  - calls Character's constructor, passing in x and y as well as hardcoded values
  - currently sets member variable target to nullptr
    - intended to set the member variable target to the enemy Summoner
- void update(float deltaTime) override
  - if member variable timeSinceAttack is greater than or equal to member variable attackCoolDown, calls summon
  - calls Character's update
- private void summon()
  - creates three Minions, setting their positions to be the current position
  - passes in itself so they set themselves to the respective team
  - creates behaviors for the Minions and gives them to them
    - DazedBehavior to all three, so they move forwards for three seconds before attacking enemy team (Should also look cool)
    - ShieldBehavior to one
    - SeekBehavior to one
    - OrbitBehavior to one
  - adds the new Minions to the current Scene

### DazedBehavior
Inherits Behavior
- DazedBehavior(float timer)
  - sets member variable direction to a normalized random direction
  - sets spawnedTimer to passed in timer
- void update(Agent* owner, float deltaTime) override
  - calls applyForce for owner, passing in member variable direction divided by two
    - this makes the owner move slowly forwards
  - adds deltaTime to timeSinceSpawn
  - if timeSinceSpawn is greater than spawnedTimer, then disable this Behavior

### LimitedEvadeBehavior
Inherits SteeringBehavior
- LimitedEvadeBehavior(Character* target, float forceScale = 5)
  - calls setForceScale passing in forceScale
    - Should call setTarget, but that does not appear to work
- MathLibrary::Vector2 calculateForce(Agent* agent) override
  - casts the passed in agent* as a Character*
  - if the character's target is too close
    - gets the target's position and velocity
    - creates a vector facing away from the target and returns it

### OrbitBehavior
Inherits SteeringBehavior
- OrbitBehavior(Character* target, float forceScale = 1)
  - calls setTarget, passing in target
  - calls setForceScale, passing in forceScale
- MathLibrary::Vector2 calculateForce(Agent* agent) override
  - calculates and stores current Distance from agent to member variable target
  - calculates and stores minimum and maximum desired distances from member variable target
  - if current distance is less than the minimum distance, creates and returns a Vector facing away from the target
  - if current distance is greater than the maximum distance, creates and returns a Vector facing towards the target
  - otherwise, turns the agent to the side and makes it move forwards
- void setTarget(Character* target)
  - sets member variable target to be passed in target

### ShieldBehavior
Inherits SteeringBehavior
- ShieldBehavior(Character* defended)
  - sets member variable defended to passed in defended
- MathLibrary::Vector2 calculateForce
  - if member variable defended has a target
    - gets and stores a vector from defended to the blocked dedToBlocked)
    - divides the vector's magnitude by four
    - sets direction to the direction from this agent to the defToBlocked vector
  - otherwise
    - sets direction to be angled towards the front of defended
  - returns direction
- void setTarget
  - sets defended to be the passed in defended, and calls defended's setDefended to set it true

### SteeringBehavior
Inherits Behavior
- virtual void update(Agent* owner, float deltaTime) override
  - calls applyForce for the owner, passing in a call for calculateForce (passing in the owner)
- pure virtual MathLibrary::Vector2 calculateForce(Agent* agent)
- float getForceScale()
  - returns member variable forceScale
    

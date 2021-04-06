Behavior Assessment Post-Mortem
-------------------------------
##### Actor types
- Character
  - I wanted this to be the base class for any other Actor types in this program. It worked for the most part; I just gave it a health int, targeted bool, defended bool, and a target with getters and setters, as well as timeSinceAttack and attackCoolDown floats.
  - Of course, since this was to be inherited by the Actor classes that would demonstrate behaviors, I made it inherit from Agent.
- Summoner
  - This was to be the sort of mothership of each team; what identified what team each Minion was on. It uses the cooldown inherited from Character to determine when to summon a wave of three Minions while orbiting the enemy Summoner. These seemed to function properly, so I moved on to the Minions
- Minion
  - These were to be the action part of the program; what made it make the people who saw it go "Woah", by displaying several different behaviors to target the enemy Minions and the enemy Summoner and to defend ally Minions or the ally Summoner itself.
  - If I had time, I would have been able to get the behaviors, but the pathfinding was what got to me; I (And several others) were unable to figure out what about the pathfinding was causing issues.

##### Behavior types
- OrbitBehavior
  - When I started this, I thought it would be the most difficult one to make. It turned out to be the only one that I made and tested the bugs out of. I wanted it to orbit the target while within a minimum and maximum range, which wasn't difficult to make; just a couple of if statements with a couple more float variables to match. The only issue I ran into while making this one was the final calculation; I had used the wrong variable when calculating the direction variable in the case that the target was within the desired range, which was an easy fix. Once that was fixed, it worked perfectly.
- ShieldBehavior
  - I wanted Characters with this to stand between the characters target and target's target. Of course, because I overscoped, I didn't get to test it out, so I don't know if it works, but I also don't know why it wouldn't work; it's a simple couple of calculations: Just get a vector from the target to the targets target, then divide the magnitude to get it down to however far you want the Character to stand from the target. 
- LimitedEvadeBehavior
  - I thought it was either this behavior or the DazedBehavior that would be the easiest to implement; I just wanted this one to evade up to a certain distance away from the target. Like the ShieldBehavior, I didn't get to test it, so I don't know if this works, but because of the simplicity of this one, I honestly see no way that this could be dysfunctional unless I used the wrong variable somewhere.
- DazedBehavior
  - This is the second of the two that I did get to test, but even then I didn't get to finish this one, because I was focused on trying to fix a single issue elsewhere for the majority of the time. I wanted Characters with this to move in one (Random) direction slowly for a certain amount of time then have the behavior disable itself. The issue seemed to be in the direction and speed, as well as having it disable itself. I wanted it to nullify all other behaviors and make itself the only behavoir affecting the movement of the Character, but I didn'/don't know how to do that. After the timer would finish, it'd allow the other behaviors to start affecting the Character again.
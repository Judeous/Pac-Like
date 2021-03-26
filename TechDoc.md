Technical Information
---------------------
Created using Visual Studio 2019
Language used is C++
Forked from vanPhelan/Pac-Like https://github.com/vanPhelan/Pac-Like

### AI Mechanics
- DazedBehavior
  - Moves the character forwards slowly for a specified amount of time
- LimitedEvadeBehavior
  - Moves the character away from the target up to a specified distance
- OrbitBehavior
  - If the character isn't within a minimum and maximum radius of the target, the character will move itself into that range
  - If the character is within the minimum and maximum range, the character will orbit the target 
    - The orbiting motion was made using a vector perpendicular to one going straight from the character to the target
- ShieldBehavior
  - If the target doesn't have a target, the character will stand in front of it's target
  - If the target has a target, the character will stand between the target and the target's target
    - This distance is 1/4th of the way between the two, closer to the character's target
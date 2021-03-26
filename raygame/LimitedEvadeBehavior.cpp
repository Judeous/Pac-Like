#include "LimitedEvadeBehavior.h"
#include "Character.h"

LimitedEvadeBehavior::LimitedEvadeBehavior(Character* target, float forceScale)
{
    setForceScale(forceScale);

}

MathLibrary::Vector2 LimitedEvadeBehavior::calculateForce(Agent* agent)
{
    Character* character = dynamic_cast<Character*>(agent);

    //If target is too close
    if ((character->getTarget()->getWorldPosition() - character->getWorldPosition()).getMagnitude() <= getForceScale())
    {
        //Get the target's position and velocity
        MathLibrary::Vector2 targetPosition = character->getTarget()->getWorldPosition();
        MathLibrary::Vector2 targetVelocity = character->getTarget()->getVelocity();
        //Subtract the new variables from the owner's position to get a Vector facing away from the target
        MathLibrary::Vector2 direction = character->getWorldPosition() - targetPosition + targetVelocity;
        //Return the direction Vector scaled by the owner's max speed
        return direction * character->getMaxSpeed();
    }
    return MathLibrary::Vector2();
}

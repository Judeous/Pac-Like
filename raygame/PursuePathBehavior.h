#pragma once
#include "PathfindBehavior.h"

class PursuePathBehavior : public PathfindBehavior
{
public:
	PursuePathBehavior(Maze* maze) :PathfindBehavior(maze) {}

protected:
	virtual MathLibrary::Vector2 findDestination(Agent* owner) override;
};


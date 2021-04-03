#include "NodeGraph.h"
#include <raylib.h>

std::deque<NodeGraph::Node*> NodeGraph::findPath(Node* start, Node* end)
{
	// Find a path from start to end (The current implementation is obviously insufficient)
	std::deque<Node*> path;

	//Check if the start or the goal pointer is null
	if (!start || !end)
		//return an empty list
		return path;
	//end if statement

	//Create a node pointer that will act as an iterator for the graph
	Node* iterator = nullptr;
	//Create an open list
	std::deque<Node*> openList;
	//Create a closed list
	std::deque<Node*> closedList;

	//Add start to the open list
	openList.push_back(start);
	//Loop while the open list is not empty
	while (!openList.empty())
	{
		//Sort the items in the open list by the f score
		///BEGIN SORT
		//For every item in the list going from 0 up to the end
		for (int i = 0; i < openList.size(); i++)
			//For every item in the list going from i down to the beginning
			for (int j = openList.size() - 1; j > i; j--)
				//If the Node before j's fScore is greater than j's fScore
				if (openList[j - 1]->fScore > openList[j]->fScore)
				{
					//Swap j with the one before it
					//Create a temporary Node pointer in order to not lose the value
					Node* temp = openList[j - 1];
					//Set the backed up Node's value to be that of the rhs Node
					openList[j] = openList[j - 1];
					//Set the rhs Node's value to be lhs's previous value
					openList[j - 1] = temp;
				}
		///END SORT

		//Set the iterator to be the first item in the open list
		iterator = openList.front();

		//Check if the iterator is pointing to the goal node
		if (iterator == end)
			return std::deque<Node*>();

		//Pop the first item off the open list
		openList.pop_front();
		//Add the first item to the closed list
		closedList.push_front(iterator);

		//Loop through all of the edges for the iterator
		for (int i = 0; i < iterator->connections.size(); i++)
		{
			//Check if node at the end of the edge is in the closed list
			if (!contains(closedList, iterator->connections[i].target))
			{
				//Create a float and set it to be the g score of the iterator plus the cost of the edge
				float gScore = iterator->gScore + iterator->connections[i].cost;
				//Create a float and set it to be the h score of the node at the end of the edge
				float hScore = (iterator->connections[i].target->position - end->position).getMagnitude();
				//Create a float for the f score and set it to be the g score combined with the h score
				float fScore = gScore + hScore;

				//Check if the node at the end of the edge is in the open list
				if (!contains(openList, iterator->connections[i].target))
				{
					//Set the nodes g score to be the g score calculated earlier
					iterator->connections[i].target->gScore = gScore;
					//Set the nodes h score to be the h score calculated earlier
					iterator->connections[i].target->hScore = hScore;
					//Set the nodes f score to be the f score calculated earlier
					iterator->connections[i].target->fScore = fScore;
					//Set the nodes previous to be the iterator
					iterator->connections[i].target->previous = iterator;
					//Add the node to the open list
					openList.push_back(iterator->connections[i].target);
				}

				//Otherwise if the f score is less than the node at the end of the edge's f score...
				else if (fScore < iterator->connections[i].target->fScore)
				{
					//Set the nodes g score to be the g score calculated earlier
					iterator->connections[i].target->gScore = gScore;
					//Set the nodes h score to be the h score calculated earlier
					iterator->connections[i].target->hScore = hScore;
					//Set the nodes f score to be the f score calculated earlier
					iterator->connections[i].target->fScore = fScore;
					//Set its previous to be the current node
					iterator->connections[i].target->previous = iterator;
				}
			} //end if statement
		} //end loop
	} //end loop

	std::deque<Node*> newPath;
	while (iterator != start)
	{
		newPath.push_front(iterator);
		iterator = iterator->previous;
	}
	return newPath;
}

bool NodeGraph::contains(std::deque<Node*> list, Node* node)
{
	if (!node)
		return false;
	for (int i = 0; i < list.size(); i++)
		if (list[i] == node)
			return true;
	return false;
}

void NodeGraph::drawGraph(Node* start)
{
	std::deque<Node*>* drawnList = new std::deque<Node*>();
	drawConnectedNodes(start, drawnList);
	delete drawnList;
}

void NodeGraph::drawNode(Node* node, int color)
{
	static char buffer[10];
	sprintf_s(buffer, "%.0f", node->gScore);

	//Draw the circle for the outline
	DrawCircle((int)node->position.x, (int)node->position.y, 16, GetColor(color));
	//Draw the inner circle
	DrawCircle((int)node->position.x, (int)node->position.y, 14, BLACK);
	//Draw the text
	DrawText(buffer, (int)node->position.x, (int)node->position.y, 24, RAYWHITE);
}

void NodeGraph::drawConnectedNodes(Node* node, std::deque<Node*>* drawnList)
{
	//drawNode(node);
	drawnList->push_back(node);

	//For each Edge in this node's connections
	for (Edge e : node->connections) {
		//Draw the Edge
		DrawLine((int)node->position.x, (int)node->position.y, (int)e.target->position.x, (int)e.target->position.y, WHITE);
		//Draw the cost
		MathLibrary::Vector2 costPos = { (node->position.x + e.target->position.x) / 2, (node->position.y + e.target->position.y) / 2 };
		static char buffer[10];
		sprintf_s(buffer, "%.0f", e.cost);
		DrawText(buffer, (int)costPos.x, (int)costPos.y, 16, RAYWHITE);
		//Draw the target node
		if (std::find(drawnList->begin(), drawnList->end(), e.target) == drawnList->end()) {
			drawConnectedNodes(e.target, drawnList);
		}
	}
}

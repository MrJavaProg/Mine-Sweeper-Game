#include "Cell.h"



Cell::Cell()
{
	state = 0;
}


Cell::~Cell()
{
}

int Cell::getState()
{
	return state;
}

void Cell::setState(int state)
{
	this->state = state;
}


/*static float Cell::getEdge()
{
	return getEdge();
}*/
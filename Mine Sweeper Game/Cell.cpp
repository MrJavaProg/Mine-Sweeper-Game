#include "Cell.h"



Cell::Cell()
{
}


Cell::~Cell()
{
}

Cell::Cell(float xStart, float yStart)
{
	this->state = 0;
	setXStart(xStart);
	setYStart(yStart);
}

int Cell::getState()
{
	return state;
}

void Cell::setState(int state)
{
	this->state = state;
}
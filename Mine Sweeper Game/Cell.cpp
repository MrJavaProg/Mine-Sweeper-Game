#include "Cell.h"


Cell::Cell(float xStart, float yStart, int state)
{
	this->state = state;
	setXStart(xStart);
	setYStart(yStart);
}



Cell::~Cell() 
{
}
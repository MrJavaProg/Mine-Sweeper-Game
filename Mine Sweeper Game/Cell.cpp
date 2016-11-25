#include "Cell.h"



Cell::Cell()
{
}

Cell::Cell(int xStart, int yStart, int xEnd, int yEnd, int state)
{
	this->xStart = xStart;
	this->yStart = yStart;
	this->xEnd = xEnd;
	this->yEnd = yEnd;
	this->state = state;

}

int Cell::getXStart()
{
	return xStart;
}

int Cell::getYStart()
{
	return yStart;
}

int Cell::getXEnd()
{
	return xEnd;
}

int Cell::getYEnd()
{
	return yEnd;
}

int Cell::getState()
{
	return state;
}

void Cell::setXStart(int xStart)
{
	this->xStart = xStart;
}

void Cell::setYStart(int yStart)
{
	this->yStart = yStart;
}

void Cell::setXEnd(int xEnd)
{
	this->xEnd = xEnd;
}

void Cell::setYEnd(int yEnd)
{
	this->yEnd = yEnd;
}

void Cell::setState(int state)
{
	this->state = state;
}

Cell::~Cell() 
{
}
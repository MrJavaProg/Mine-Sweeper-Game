#include "Cell.h"

Cell::Cell() 
{
}


Cell::~Cell()
{
}


float Cell::edge = 25;

float Cell::getXStart()
{
	return xStart;
}

float Cell::getYStart()
{
	return yStart;
}

float Cell::getXEnd()
{
	return xEnd;
}

float Cell::getYEnd()
{
	return yEnd;
}

void Cell::setXStart(float xStart)
{
	this->xStart = xStart;
}

void Cell::setYStart(float yStart)
{
	this->yStart = yStart;
}

void Cell::setXEnd(float xEnd)
{
	this->xEnd = xEnd;
}

void Cell::setYEnd(float yEnd)
{
	this->yEnd = yEnd;
}


#include "CellAI.h"



void CellAI::setIsOpened(bool isOpened)
{
	this->isOpened = isOpened;
}

bool CellAI::getIsOpened()
{
	return isOpened;
}

void CellAI::setIsChecked(bool isChecked)
{
	this->isChecked = isChecked;
}

void CellAI::addMinePossibility(float minePossibility)
{
	this->minePossibility += minePossibility;
}

float CellAI::getMinePossibility()
{
	return minePossibility;
}

bool CellAI::getIsChecked()
{
	return isChecked;
}

CellAI::CellAI()
{
	minePossibility = 0;
	isChecked = false;
	isOpened = false;
}


CellAI::~CellAI()
{
}

#pragma once
#include "CellDrawing.h"

ref class Cell : public CellDrawing
{
	int xStart,
		yStart,
		xEnd,
		yEnd,
		state;
	
public:
	Cell();
	~Cell();
	Cell(int xStart, int yStart, int xEnd, int yEnd, int state);
	int getXStart();
	int getYStart();
	int getXEnd();
	int getYEnd();
	int getState();

	void setXStart(int xStart);
	void setYStart(int yStart);
	void setXEnd(int xEnd);
	void setYEnd(int yEnd);
	void setState(int state);
};


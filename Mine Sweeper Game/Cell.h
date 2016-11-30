#pragma once
#include "CellDrawing.h"

class Cell : CellDrawing
{
	int    state;

public:
	Cell();
	~Cell();
	Cell(float xStart, float yStart);
	int getState();
	void setState(int state);
};


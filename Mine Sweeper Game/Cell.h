#pragma once
#include "CellDrawing.h"

class Cell : public CellDrawing
{
	int    state;

public:
	//static float CellDrawing::edge;
	Cell();
	~Cell();
	int getState();
	void setState(int state);
	//static float getEdge();
};


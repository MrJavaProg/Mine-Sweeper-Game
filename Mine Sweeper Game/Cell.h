#pragma once
#include "CellDrawing.h"

ref class Cell : public CellDrawing
{
private:	
	int    state;
	
public:
	~Cell();
	Cell(float xStart, float yStart, int state);
	
	//int getState();

	//void setState(int state);
	
};


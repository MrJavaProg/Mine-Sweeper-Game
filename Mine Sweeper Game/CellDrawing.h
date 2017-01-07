#include "Cell.h"
#pragma once

class CellDrawing : public Cell
{
public:
	CellDrawing();
	~CellDrawing();
	void drawExplodedCell(System::Drawing::Graphics ^g);
	void drawUndefinedCell(System::Drawing::Graphics ^g);
	void drawFlaggedCell(System::Drawing::Graphics ^g);
	void drawEmptyCell(System::Drawing::Graphics ^g);
	void drawOpenedCell(System::Drawing::Graphics ^g, int nearbyMines);
	void drawPossibility(float possibility, System::Drawing::Graphics ^g);
};


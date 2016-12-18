#pragma once

#include "CellDrawing.h"

class GameCell : public CellDrawing
{
	int nearbyMines,
		state,
		extraState;

public:
	int getState();
	int getExtraState();

	void setNearbyMines(int nearbyMines);
	void setState(int state);
	void setExtraState(int extraState);
	void addNearbyMines();

	void redrawCell(System::Windows::Forms::Form ^ form);

	GameCell() : CellDrawing() {};
	~GameCell();
};


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

	static int mb_open,
		mb_flag,
		mb_undefined3;
	static enum state { empty = 0, mined = 1 };
	static enum extraState { unchecked = 0, opened = 2, flagged = 3, undefined = 4 };
};


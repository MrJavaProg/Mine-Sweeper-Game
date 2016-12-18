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
	void openCell(System::Windows::Forms::Form ^f, bool &started, int &mb, int &lifes, int &closedCells, bool &wasFirstClick);


	GameCell() : CellDrawing() {};
	~GameCell();

	static int mb_open,
		mb_flag,
		mb_undefined;
};


#include "CellDrawing.h"
#pragma once

enum state { empty = 0, mined = 1 };
enum extraState { unchecked = 0, opened = 2, flagged = 3, undefined = 4 };

class GameCell : public CellDrawing
{
	int nearbyMines,
		state,
		extraState;

public:
	int getState();
	int getExtraState();

	int getNearbyMines();
	void setState(int state);
	void setExtraState(int extraState);
	void addNearbyMines();

	void redrawCell(System::Drawing::Graphics ^g);

	GameCell();
	~GameCell();

	static int mb_open,
		mb_flag,
		mb_undefined;
	
};


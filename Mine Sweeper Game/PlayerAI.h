#pragma once
#include "Game.h"
#include "CellAI.h"

class PlayerAI
{
	Game *game;

	CellAI **field;
	int width,
		height,
		mines;

public:
	PlayerAI(int width, int height, float formWidth, float formHeight, int mines, int lifes, bool shownMines, Graphics ^g);
	PlayerAI();
	~PlayerAI();

	void openCellAI();
};


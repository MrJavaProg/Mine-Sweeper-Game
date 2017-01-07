#pragma once
#include "Game.h"
#include "CellAI.h"

class PlayerAI
{
	
	CellAI **fieldAI;
	int width,
		height,
		mines;
	bool wasFirstClickAI;

public:
	Game *game;
	PlayerAI(int width, int height, float formWidth, float formHeight, int mines, int lifes, bool shownMines, Graphics ^g);
	PlayerAI();
	~PlayerAI();

	//bool openCellAI(Graphics ^g);
	int getSurroundedCells(int x, int y);
	void resyncAIField(int x, int y, Graphics ^g);
	void doAction(bool &win, Graphics ^g);
	void setPossibilities(Graphics ^g);
	void checkPossibilities(Graphics ^g);//удалить!!!
};


#pragma once

#include "Player.h"


class Game
{
	Player player;
	GameCell **field;

	int	width,
		height,
		mines,
		lifes = 0,
		closedCells,
		time;
	bool wasFirstClick = false,
		timerEnabled = false;
	int flags;


public:
	Game();
	~Game();
	void saveGame();
	GameCell* loadGame();
	void writeRecord();
	void spawnMines();
	void showMines();
};


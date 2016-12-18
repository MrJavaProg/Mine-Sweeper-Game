#pragma once

#include "Player.h"
using namespace System::Windows::Forms;


class Game
{
	Player player;
	GameCell **field;

	int	width,
		height,
		closedCells;
	bool wasFirstClick,
		started,
		timerEnabled;
	int flags;


public:
	Game(int width, int height, int mines);
	~Game();
	void saveGame(bool &started);
	void loadGame(Form ^ f, bool & started);
	void spawnMines(int &curPosX, int &curPosY);
	void showMines(Form ^f);
	void createField(Form ^f);
	void showMines(Form ^f);
	void openCell(System::Windows::Forms::Form ^f, bool &started, int &mb, int &lifes, int &closedCells, bool &wasFirstClick);

};


#pragma once
#include "GameCell.h"
#include "Player.h"


class Game
{
	Player player;
	GameCell **field;

	int	width,
		height,
		closedCells,
		mines;
	bool wasFirstClick,
		started,
		timerEnabled;
	int flags;


public:
	Game(int width, int height, int mines);
	~Game();
	void saveGame(bool &started);
	void loadGame(System::Windows::Forms::Form ^ f, bool & started);
	void spawnMines(int &curPosX, int &curPosY);
	void createField(System::Windows::Forms::Form ^f);
	void showMines(System::Windows::Forms::Form ^f);
	void openCell(int &x, int &y, System::Windows::Forms::Form ^f, bool &started, int &mb, int &lifes, int &closedCells, bool &wasFirstClick);

};


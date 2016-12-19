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
		mines,
		lifes;
	int flags;


public:
	Game(int width, int height, int mines, int lifes);
	~Game();
	void saveGame(bool &started, bool &wasFirstClick);
	void loadGame(System::Windows::Forms::Form ^ f, bool & started, bool &wasFirstClick);
	void spawnMines(int &curPosX, int &curPosY);
	void createField(System::Windows::Forms::Form ^f);
	void showMines(System::Windows::Forms::Form ^f);
	void openCell(int x, int y, int &mb, System::Windows::Forms::Form ^f, bool &wasFirstClick, bool &started, bool &timerEnabled);

};


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
	float xStart,
		yStart,
		xEnd,
		yEnd;
	bool wasFirstClick,
		started,
		timerEnabled;


public:
	Game(int width, int height, int mines, int lifes, System::Windows::Forms::Form ^f);
	Game(System::Windows::Forms::Form ^f);
	~Game();
	void saveGame();
	void loadGame(System::Windows::Forms::Form ^ f);
	void spawnMines(int &curPosX, int &curPosY);
	void createField(System::Windows::Forms::Form ^f);
	void showMines(System::Windows::Forms::Form ^f);
	void openCell(int x, int y, int &mb, System::Windows::Forms::Form ^f);
	bool getTimerEnabled();
	int getWidth();
	int getHeight();
};


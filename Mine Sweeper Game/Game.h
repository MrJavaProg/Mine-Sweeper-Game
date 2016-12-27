#pragma once
#include "GameCell.h"
#include "Player.h"


class Game : public Player
{
	//Player player;
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
		timerEnabled,
		shownMines;


public:
	Game(int width, int height, int mines, int lifes, bool shownMines, System::Windows::Forms::Form ^f);
	Game(System::Windows::Forms::Form ^f);
	~Game();
	void saveGame();
	void loadGame(System::Windows::Forms::Form ^ f);
	void spawnMines(int &curPosX, int &curPosY);
	void createField(System::Windows::Forms::Form ^f);
	void setShownMines(bool shownMines);
	bool getShownMines();
	void showMines(System::Windows::Forms::Form ^f);
	bool openCell(int x, int y, int &mb, System::Windows::Forms::Form ^f);
	bool getTimerEnabled();
	int getWidth();
	int getHeight();
private:
	void autoOpen(int x, int y, System::Windows::Forms::Form ^f);
};


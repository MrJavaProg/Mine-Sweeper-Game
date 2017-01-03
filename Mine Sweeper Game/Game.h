#pragma once
#include "GameCell.h"
#include "Player.h"

using namespace System::Drawing;
class Game : public Player
{
	
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
	Game(int width, int height, float formWidth, float formHeight, int mines, int lifes, bool shownMines, Graphics ^g);
	Game(Graphics ^g);
	~Game();
	void saveGame();
	bool getShownMines();
	void showMines(Graphics ^g);
	bool getTimerEnabled();
	int getWidth();
	int getHeight();
	int getLifes();
	void redrawField(Graphics ^g);
	void removeGraphics(Graphics ^g, Color &color);
	bool openCell(int x, int y, int &mb, Graphics ^g);

private:
	void autoOpen(int x, int y, Graphics ^g);
	void loadGame(Graphics ^g);
	void spawnMines(int &curPosX, int &curPosY);
	void createField(Graphics ^g, float x, float y);

};


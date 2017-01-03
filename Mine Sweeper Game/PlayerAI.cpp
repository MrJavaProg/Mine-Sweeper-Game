#include "PlayerAI.h"




PlayerAI::PlayerAI(int width, int height, float formWidth, float formHeight, int mines, int lifes, bool shownMines, Graphics ^g)
{
	this->width = width;
	this->height = height;
	this->mines = mines;

	field = new CellAI*[width];
	for (int i = 0; i < width; i++) {
		field[i] = new CellAI[height];
	}

	game = new Game(width, height, formWidth, formHeight, mines, lifes, shownMines, g);
}

PlayerAI::PlayerAI()
{
}


PlayerAI::~PlayerAI()
{
}

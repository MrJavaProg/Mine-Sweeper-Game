#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::createField(int &width, int &height, System::Windows::Forms::Form ^f, bool &started) {
	float xStart,
		yStart;
	yStart = (f->Height / 2) - (height / 2)*Cell::edge;
	xStart = (f->Width / 2) - (width / 2)*Cell::edge;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			field[i][j].setXStart(xStart + i*Cell::edge);
			field[i][j].setYStart(yStart + j*Cell::edge);
			field[i][j].setXEnd(field[i][j].getXStart() + Cell::edge);
			field[i][j].setYEnd(field[i][j].getYStart() + Cell::edge);
			field[i][j].drawEmptyCell(f);
		}
	}
	started = true;
	wasFirstClick = false;
	flags = mines;
	showMines(field, width, height, f);
}

void Game::spawnMines(Cell **field, int &width, int &height, int mines, int &curPosX, int &curPosY) {
	int x,
		y;
	while (mines != 0) {
		x = rand() % (width - 1) + 0;
		y = rand() % (height - 1) + 0;
		if (x != curPosX && y != curPosY && field[x][y].getState() != state::mined) {
			field[x][y].setState(state::mined);
			if (x - 1 >= 0) {
				field[x - 1][y - 1].addNearbyMines();
			}
			if (y - 1 >= 0) {
				field[x][y - 1].addNearbyMines();
			}
			if (x + 1 <= width && y - 1 >= 0) {
				field[x + 1][y - 1].addNearbyMines();
			}
			if (x + 1 <= width) {
				field[x + 1][y].addNearbyMines();
			}
			if (x + 1 <= width && y + 1 <= height) {
				field[x + 1][y + 1].addNearbyMines();
			}
			if (y + 1 <= height) {
				field[x][y + 1].addNearbyMines();
			}
			if (x - 1 >= 0 && y + 1 <= height) {
				field[x - 1][y + 1].addNearbyMines();
			}
			if (x - 1 >= 0) {
				field[x - 1][y].addNearbyMines();
			}
			mines--;
		}
	}
}
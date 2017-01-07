#include "PlayerAI.h"




PlayerAI::PlayerAI(int width, int height, float formWidth, float formHeight, int mines, int lifes, bool shownMines, Graphics ^g)
{
	this->width = width;
	this->height = height;
	this->mines = mines;
	wasFirstClickAI = false;
	fieldAI = new CellAI*[width];
	for (int i = 0; i < width; i++) {
		fieldAI[i] = new CellAI[height];
	}

	game = new Game(width, height, formWidth, formHeight, mines, lifes, shownMines, g);
}

PlayerAI::PlayerAI()
{
}


PlayerAI::~PlayerAI()
{
	game->~Game();
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			fieldAI[i][j].~CellAI();
		}
	}
	delete[] fieldAI;
}

/*bool PlayerAI::openCellAI(Graphics ^g)
{
	if (wasFirstClickAI == false) {
		int x,
			y,
			cellX,
			cellY;

		cellX = rand() % (width - 1) + 0;
		cellY = rand() % (height - 1) + 0;
		x = cellX*GameCell::edge + (int)game->getXStart()-5;
		y = cellY*GameCell::edge + (int)game->getYStart() - 5;
		wasFirstClickAI = true;
		return game->openCell(x, y, GameCell::mb_open, g);
	}
	else {
		//
	}

	
}*/

int PlayerAI::getSurroundedCells(int x, int y)
{
	int surroundedCells = 0;
	if (x - 1 >= 0) {
		if (fieldAI[x-1][y].getIsOpened() == false) {
			surroundedCells++;
		}
	}

	if (x - 1 >= 0 && y-1>=0) {
		if (fieldAI[x-1][y-1].getIsOpened() == false) {
			surroundedCells++;
		}
	}

	if (y-1 >= 0) {
		if (fieldAI[x][y-1].getIsOpened() == false) {
			surroundedCells++;
		}
	}

	if (x + 1<width && y-1>=0) {
		if (fieldAI[x+1][y-1].getIsOpened() == false) {
			surroundedCells++;
		}
	}

	if (x + 1 <width) {
		if (fieldAI[x+1][y].getIsOpened() == false) {
			surroundedCells++;
		}
	}

	if (x + 1 <width && y+1<height) {
		if (fieldAI[x+1][y+1].getIsOpened() == false) {
			surroundedCells++;
		}
	}

	if (y + 1 < height) {
		if (fieldAI[x][y + 1].getIsOpened() == false) {
			surroundedCells++;
		}
	}

	if (y + 1 < height && x-1 >=0) {
		if (fieldAI[x-1][y + 1].getIsOpened() == false) {
			surroundedCells++;
		}
	}
	return surroundedCells;
}

void PlayerAI::resyncAIField(int x, int y, Graphics ^g)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (game->getExtraState(i, j) == extraState::opened) {
				fieldAI[i][j].setIsOpened(true);
				if (game->getNearbyMines(i, j) == 0) {
					fieldAI[i][j].setIsChecked(true);
				}
			}
		}
	}
	setPossibilities(g);
}

void PlayerAI::doAction(bool &win, Graphics ^ g)
{
	if (wasFirstClickAI == false) {
		int x,
			y,
			cellX,
			cellY;

		cellX = rand() % (width - 1) + 0;
		cellY = rand() % (height - 1) + 0;
		x = (cellX)*GameCell::edge + (int)game->getXStart();
		y = (cellY)*GameCell::edge + (int)game->getYStart();
		wasFirstClickAI = true; 
		win = game->openCell(x, y, GameCell::mb_open, g);;
		resyncAIField(cellX, cellY, g);
		checkPossibilities(g);
	}
	else {
		float minPosibility = 8,
			tmpPossibility;
		int curX, curY, x, y;
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				tmpPossibility = fieldAI[i][j].getMinePossibility();
				//if (game->getClosedCells() != )
				if (tmpPossibility > 0 && fieldAI[i][j].getIsOpened() == false && getSurroundedCells(i, j)>0) {
					if (tmpPossibility < minPosibility) {
						curX = i;
						curY = j;
						minPosibility = tmpPossibility;
					}
				}
			}
		}
		x = (curX)*GameCell::edge + (int)game->getXStart()+5;
		y = (curY)*GameCell::edge + (int)game->getYStart()+5;
		win = fieldAI[curX][curY].getIsOpened();
		win = game->openCell(x, y, GameCell::mb_open, g);
		resyncAIField(curX, curY, g);
		checkPossibilities(g);
	}
	
}

void PlayerAI::setPossibilities(Graphics ^g) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (fieldAI[i][j].getIsOpened() == true && fieldAI[i][j].getIsChecked() == false && game->getNearbyMines(i, j) != 0) {
				float minePossibility = (float)game->getNearbyMines(i, j) / (float)getSurroundedCells(i, j);
				if (i - 1 >= 0) {
					if (fieldAI[i - 1][j].getIsOpened() == false) {
						fieldAI[i - 1][j].addMinePossibility(minePossibility);
						//game->drawPossibility(i - 1, j, fieldAI[i - 1][j].getMinePossibility(), g);
					}
				}

				if (i - 1 >= 0 && j - 1 >= 0) {
					if (fieldAI[i - 1][j - 1].getIsOpened() == false) {
						fieldAI[i - 1][j - 1].addMinePossibility(minePossibility);
						//game->drawPossibility(i - 1, j - 1, fieldAI[i - 1][j - 1].getMinePossibility(), g);
					}
				}

				if (j - 1 >= 0) {
					if (fieldAI[i][j - 1].getIsOpened() == false) {
						fieldAI[i][j - 1].addMinePossibility(minePossibility);
						//game->drawPossibility(i, j - 1, fieldAI[i][j - 1].getMinePossibility(), g);
					}
				}

				if (i + 1 < width && j - 1 >= 0) {
					if (fieldAI[i + 1][j - 1].getIsOpened() == false) {
						fieldAI[i + 1][j - 1].addMinePossibility(minePossibility);
						//game->drawPossibility(i + 1, j - 1, fieldAI[i + 1][j - 1].getMinePossibility(), g);
					}
				}

				if (i + 1 < width) {
					if (fieldAI[i + 1][j].getIsOpened() == false) {
						fieldAI[i + 1][j].addMinePossibility(minePossibility);
						//game->drawPossibility(i + 1, j, fieldAI[i + 1][j].getMinePossibility(), g);
					}
				}

				if (i + 1 < width && j + 1 < height) {
					if (fieldAI[i + 1][j + 1].getIsOpened() == false) {
						fieldAI[i + 1][j + 1].addMinePossibility(minePossibility);
						//game->drawPossibility(i + 1, j + 1, fieldAI[i + 1][j + 1].getMinePossibility(), g);
					}
				}

				if (j + 1 < height) {
					if (fieldAI[i][j + 1].getIsOpened() == false) {
						fieldAI[i][j + 1].addMinePossibility(minePossibility);
						//game->drawPossibility(i, j + 1, fieldAI[i][j + 1].getMinePossibility(), g);
					}
				}

				if (i - 1 >= 0 && j + 1 < height) {
					if (fieldAI[i - 1][j + 1].getIsOpened() == false) {
						fieldAI[i - 1][j + 1].addMinePossibility(minePossibility);
						//game->drawPossibility(i - 1, j + 1, fieldAI[i - 1][j + 1].getMinePossibility(), g);
					}
				}
				//}
				fieldAI[i][j].setIsChecked(true);
			}
		}
	}

}

void PlayerAI::checkPossibilities(Graphics ^g) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			game->drawPossibility(i, j, fieldAI[i][j].getIsOpened(), g);
		}
	}
}
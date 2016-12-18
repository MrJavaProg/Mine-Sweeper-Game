#include "GameCell.h"

enum state { empty = 0, mined = 1 };
enum extraState { unchecked = 0, opened = 2, flagged = 3, undefined = 4 };

GameCell::GameCell()
{
	state = 0;
	nearbyMines = 0;
	extraState = 0;
}


GameCell::~GameCell()
{
}

int GameCell::getState()
{
	return state;
}

int GameCell::getExtraState()
{
	return extraState;
}

void GameCell::setState(int state)
{
	this->state = state;
}

void GameCell::setExtraState(int extraState)
{
	this->extraState = extraState;
}

void GameCell::setNearbyMines(int nearbyMines)
{
	this->nearbyMines = nearbyMines;
}

void GameCell::addNearbyMines()
{
	nearbyMines++;
}


void GameCell::redrawCell(System::Windows::Forms::Form ^ form)
{
	drawEmptyCell(form);
	if (extraState == 2) {
		if (state == 0) {
			drawOpenedCell(form);
		}
		else {
			drawExplodedCell(form);
		}
	}
	else {
		if (extraState == 0) {
			drawEmptyCell(form);
		}
		if (extraState == 3) {
			drawFlaggedCell(form);
		}
		if (extraState == 4) {
			drawFlaggedCell(form);
		}
	}
}

void openCell(System::Windows::Forms::Form ^f, bool &started, int &mb, int &lifes, int &closedCells, bool &wasFirstClick) {
	/*float xStart = field[0][0].getXStart(),
		xEnd = field[width - 1][height - 1].getXEnd(),
		yStart = field[0][0].getYStart(),
		yEnd = field[width - 1][height - 1].getYEnd();
	int curPosX,
		curPosY;

	if (started == true) {
		if (x > xStart && x<xEnd && y>yStart && y < yEnd) {
			curPosX = (int)((x - xStart) / Cell::edge);
			curPosY = (int)((y - yStart) / Cell::edge);*/

			if (mb == mb_open && getExtraState() != extraState::opened && field[curPosX][curPosY].getExtraState() != extraState::flagged && field[curPosX][curPosY].getExtraState() != extraState::undefined) {
				if (wasFirstClick == false) {
					spawnMines(field, width, height, mines, curPosX, curPosY);
					wasFirstClick = true;
				}

				if (field[curPosX][curPosY].getState() == state::empty) {
					field[curPosX][curPosY].drawOpenedCell(f);
					field[curPosX][curPosY].setExtraState(extraState::opened);
					closedCells--;
				}
				else {
					//if (field[curPosX][curPosY].getState()==state::mined)
					flags--;
					mines--;
					field[curPosX][curPosY].drawExplodedCell(f);
					field[curPosX][curPosY].setExtraState(extraState::opened);
					if (lifes == 0) {
						started = false;
					}
					else {
						lifes--;
					}
				}
			}

			if (mb == mb_flag && field[curPosX][curPosY].getExtraState() != extraState::opened && field[curPosX][curPosY].getExtraState() != extraState::undefined) {
				if (wasFirstClick == false) {
					spawnMines(field, width, height, mines, curPosX, curPosY);
					wasFirstClick = true;
				}
				if (field[curPosX][curPosY].getExtraState() == extraState::flagged) {
					field[curPosX][curPosY].drawEmptyCell(f);
					field[curPosX][curPosY].setExtraState(state::empty);
					flags++;
					if (field[curPosX][curPosY].getState() == state::mined) {
						mines++;
					}
				}
				else {
					if (flags > 0) {
						field[curPosX][curPosY].drawFlaggedCell(f);
						field[curPosX][curPosY].setExtraState(extraState::flagged);
						flags--;
						if (field[curPosX][curPosY].getState() == state::mined) {
							mines--;
						}
					}
				}
			}

			if (mb == mb_undefined && field[curPosX][curPosY].getExtraState() != extraState::opened && field[curPosX][curPosY].getExtraState() != extraState::flagged) {
				if (wasFirstClick == false) {
					spawnMines(field, width, height, mines, curPosX, curPosY);
					wasFirstClick = true;
				}
				if (field[curPosX][curPosY].getExtraState() == extraState::undefined) {
					field[curPosX][curPosY].drawEmptyCell(f);
					field[curPosX][curPosY].setExtraState(extraState::unchecked);
				}
				else {
					field[curPosX][curPosY].drawUndefinedCell(f);
					field[curPosX][curPosY].setExtraState(extraState::undefined);
				}
			}
		}
	}
}




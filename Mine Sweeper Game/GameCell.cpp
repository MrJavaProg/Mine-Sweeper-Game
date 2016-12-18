#include "GameCell.h"

enum state { empty = 0, mined = 1 };
enum extraState { unchecked = 0, opened = 2, flagged = 3, undefined = 4 };


static int mb_open = 1,
	mb_flag = 2,
	mb_undefined = 3;


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

void GameCell::openCell(System::Windows::Forms::Form ^f, bool &started, int &mb, int &lifes, int &closedCells, bool &wasFirstClick) {
	/**/
			if (mb == mb_open && getExtraState() != extraState::opened && getExtraState() != extraState::flagged && getExtraState() != extraState::undefined) {
				if (wasFirstClick == false) {
					spawnMines(field, width, height, mines, curPosX, curPosY);
					wasFirstClick = true;
				}

				if (getState() == state::empty) {
					drawOpenedCell(f);
					setExtraState(extraState::opened);
					closedCells--;
				}
				else {
					//if (field[curPosX][curPosY].getState()==state::mined)
					flags--;
					mines--;
					drawExplodedCell(f);
					setExtraState(extraState::opened);
					if (lifes == 0) {
						started = false;
					}
					else {
						lifes--;
					}
				}
			}

			if (mb == mb_flag && getExtraState() != extraState::opened && getExtraState() != extraState::undefined) {
				if (wasFirstClick == false) {
					spawnMines(field, width, height, mines, curPosX, curPosY);
					wasFirstClick = true;
				}
				if (getExtraState() == extraState::flagged) {
					drawEmptyCell(f);
					setExtraState(state::empty);
					flags++;
					if (getState() == state::mined) {
						mines++;
					}
				}
				else {
					if (flags > 0) {
						drawFlaggedCell(f);
						setExtraState(extraState::flagged);
						flags--;
						if (getState() == state::mined) {
							mines--;
						}
					}
				}
			}

			if (mb == mb_undefined && getExtraState() != extraState::opened && getExtraState() != extraState::flagged) {
				if (wasFirstClick == false) {
					spawnMines(field, width, height, mines, curPosX, curPosY);
					wasFirstClick = true;
				}
				if (getExtraState() == extraState::undefined) {
					drawEmptyCell(f);
					setExtraState(extraState::unchecked);
				}
				else {
					drawUndefinedCell(f);
					setExtraState(extraState::undefined);
				}
			}
		}
	}
}




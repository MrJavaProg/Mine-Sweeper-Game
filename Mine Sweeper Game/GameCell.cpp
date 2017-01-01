#include "GameCell.h"

int GameCell::mb_open = 1,
	GameCell::mb_flag = 2,
	GameCell::mb_undefined = 3;

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

int GameCell::getNearbyMines()
{
	return nearbyMines;
}

void GameCell::setState(int state)
{
	this->state = state;
}

void GameCell::setExtraState(int extraState)
{
	this->extraState = extraState;
}

void GameCell::addNearbyMines()
{
	nearbyMines++;
}


void GameCell::redrawCell(System::Drawing::Graphics ^g)
{
	if (extraState == extraState::unchecked) {
		drawEmptyCell(g);
	}
	if (extraState == opened) {
		if (state == state::empty) {
			drawOpenedCell(g, nearbyMines);
		}
		else {
			drawExplodedCell(g);
		}
	}
	if (extraState == extraState::flagged) {
		drawFlaggedCell(g);
	}
	if (extraState == extraState::undefined) {
		drawUndefinedCell(g);
	}

	
}





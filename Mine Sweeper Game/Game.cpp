#include <fstream>
#include "Game.h"


Game::Game(int width, int height, int mines)
{
	this->width = width;
	this->height = height;
	player.setMines(mines);
}

Game::~Game()
{
}

void Game::createField(Form ^f) {
	//GameCell **gField;   если что, проблема тут)
	float xStart,
		yStart;
	yStart = (f->Height / 2) - (height / 2)*Cell::edge;
	xStart = (f->Width / 2) - (width / 2)*Cell::edge;

	field = new GameCell*[width];

	for (int i = 0; i < width; i++) {
		field[i] = new GameCell[height];
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			field[i][j].setXStart(xStart + i*Cell::edge);
			field[i][j].setYStart(yStart + j*Cell::edge);
			field[i][j].setXEnd(field[i][j].getXStart() + Cell::edge);
			field[i][j].setYEnd(field[i][j].getYStart() + Cell::edge);
			field[i][j].redrawCell(f);
		}
	}
	wasFirstClick = false;
	flags = player.getMines();
	showMines(f);
}

void Game::spawnMines(int &curPosX, int &curPosY) {
	int x,
		y,
		mines = player.getMines();

	while (mines != 0) {
		x = rand() % (width - 1) + 0;
		y = rand() % (height - 1) + 0;
		if (x != curPosX && y != curPosY && field[x][y].getState() != GameCell::state::mined) {
			field[x][y].setState(GameCell::state::mined);
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

void Game::showMines(Form ^f) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (field[i][j].getState() == GameCell::state::mined && field[i][j].getExtraState() != GameCell::extraState::flagged) {
				field[i][j].redrawCell(f);
			}
		}
	}
}

void Game::saveGame(bool &started) {
	std::fstream save;
	int time = player.getTime(),
		mines = player.getMines(),
		lifes = player.getMines();

	save.open("Save.sav", std::ios::out | std::ios::trunc | std::ios::binary);
	save.write(reinterpret_cast<char*> (&started), sizeof(bool));
	save.write(reinterpret_cast<char*> (&wasFirstClick), sizeof(bool));
	save.write(reinterpret_cast<char*> (&time), sizeof(int));
	save.write(reinterpret_cast<char*> (&lifes), sizeof(int));
	save.write(reinterpret_cast<char*> (&mines), sizeof(int));
	save.write(reinterpret_cast<char*> (&flags), sizeof(int));
	save.write(reinterpret_cast<char*> (&closedCells), sizeof(int));
	save.write(reinterpret_cast<char*> (&width), sizeof(int));
	save.write(reinterpret_cast<char*> (&height), sizeof(int));
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			save.write(reinterpret_cast<char*> (&field[i][j]), sizeof(GameCell));
		}
	}
	save.close();
}


void Game::loadGame(Form ^f, bool &started) {
	std::fstream load;
	int time = player.getTime(),
		mines = player.getMines(),
		lifes = player.getMines();

	load.open("Save.sav", std::ios::in | std::ios::binary);
	load.read(reinterpret_cast<char*> (&started), sizeof(bool));
	load.read(reinterpret_cast<char*> (&wasFirstClick), sizeof(bool));
	load.read(reinterpret_cast<char*> (&time), sizeof(int));
	load.read(reinterpret_cast<char*> (&lifes), sizeof(int));
	load.read(reinterpret_cast<char*> (&mines), sizeof(int));
	load.read(reinterpret_cast<char*> (&flags), sizeof(int));
	load.read(reinterpret_cast<char*> (&closedCells), sizeof(int));
	load.read(reinterpret_cast<char*> (&width), sizeof(int));
	load.read(reinterpret_cast<char*> (&height), sizeof(int));

	field = new GameCell*[width];

	for (int i = 0; i < width; i++) {
		field[i] = new GameCell[height];
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			load.read(reinterpret_cast<char*> (&field[i][j]), sizeof(GameCell));
			field[i][j].redrawCell(f);
		}
	}
}

void Game::openCell(int System::Windows::Forms::Form ^f, bool &started, int &mb, int &lifes, int &closedCells, bool &wasFirstClick) {
	/**/
	if (mb == GameCell::mb_open && getExtraState() != extraState::opened && getExtraState() != extraState::flagged && getExtraState() != extraState::undefined) {
	if (wasFirstClick == false) {
	spawnMines(field, width, height, mines, curPosX, curPosY);
	wasFirstClick = true;
	}

	if (state == state::empty) {
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


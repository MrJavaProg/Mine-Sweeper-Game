#include <fstream>
#include "Game.h"

using namespace System::Drawing;

Game::Game(int width, int height, float formWidth, float formHeight, int mines, int lifes, bool shownMines, Graphics ^g)
{
	Player::setLifes(lifes);
	this->lifes = lifes;
	this->width = width;
	this->height = height;
	this->mines = mines;
	Player::setMines(mines);
	flags = mines;
	wasFirstClick = false;
	started = true;
	createField(g, formWidth, formHeight);
	Player::setHeight(height);
	Player::setWidth(width);
	this->shownMines = shownMines;
	closedCells = width*height;
}


Game::Game(Graphics ^g)
{
	loadGame(g);
	xStart = field[0][0].getXStart();
	yStart = field[0][0].getYStart();
	xEnd = field[width - 1][height - 1].getXEnd();
	yEnd = field[width - 1][height - 1].getYEnd();
}

Game::~Game()
{
}

void Game::createField(Graphics ^g, float formWidth, float formHeight) {
	yStart = (formHeight / 2) - (height / 2)*Cell::edge;
	xStart = (formWidth / 2) - (width / 2)*Cell::edge;

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
			field[i][j].redrawCell(g);
		}
	}
	
	xEnd = field[width - 1][height - 1].getXEnd(),
	yEnd = field[width - 1][height - 1].getYEnd();
}

bool Game::getShownMines()
{
	return shownMines;
}

void Game::spawnMines(int &curPosX, int &curPosY) {
	int x,
		y,
		mines = this->mines;

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

void Game::showMines(Graphics ^g) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (field[i][j].getState() == state::mined) {
				if (field[i][j].getExtraState() == extraState::flagged) {
					field[i][j].drawExplodedCell(g);
					field[i][j].drawFlaggedCell(g);
				}
				if (field[i][j].getExtraState() == extraState::undefined) {
					field[i][j].drawExplodedCell(g);
					field[i][j].drawUndefinedCell(g);
				}
				if (field[i][j].getExtraState() == extraState::unchecked) {
					field[i][j].drawExplodedCell(g);
				}
			}
		}
	}
}

void Game::saveGame() {
	std::fstream save;
	int time = Player::getTime(),
		mines = Player::getMines(),
		lifes = Player::getLifes();

	save.open("Save.sav", std::ios::out | std::ios::trunc | std::ios::binary);
	save.write(reinterpret_cast<char*>(&timerEnabled), sizeof(bool));
	save.write(reinterpret_cast<char*> (&this->shownMines), sizeof(bool));
	save.write(reinterpret_cast<char*> (&started), sizeof(bool));
	save.write(reinterpret_cast<char*> (&wasFirstClick), sizeof(bool));
	save.write(reinterpret_cast<char*> (&time), sizeof(int));
	save.write(reinterpret_cast<char*> (&lifes), sizeof(int));
	save.write(reinterpret_cast<char*> (&mines), sizeof(int));
	save.write(reinterpret_cast<char*> (&flags), sizeof(int));
	save.write(reinterpret_cast<char*> (&this->lifes), sizeof(int));
	save.write(reinterpret_cast<char*> (&this->mines), sizeof(int));
	save.write(reinterpret_cast<char*> (&this->flags), sizeof(int));
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


void Game::loadGame(Graphics ^g) {
	std::fstream load;
	load.open("Save.sav", std::ios::in | std::ios::binary);
	int time,
		mines,
		lifes = Player::getLifes();
		
		load.seekg(std::ios::end);
		if (load.tellg() > 0) {
			load.seekg(std::ios::beg);
			load.read(reinterpret_cast<char*>(&timerEnabled), sizeof(bool));
			load.read(reinterpret_cast<char*> (&this->shownMines), sizeof(bool));
			load.read(reinterpret_cast<char*> (&started), sizeof(bool));
			load.read(reinterpret_cast<char*> (&wasFirstClick), sizeof(bool));
			load.read(reinterpret_cast<char*> (&time), sizeof(int));
			load.read(reinterpret_cast<char*> (&lifes), sizeof(int));
			load.read(reinterpret_cast<char*> (&mines), sizeof(int));
			load.read(reinterpret_cast<char*> (&flags), sizeof(int));
			load.read(reinterpret_cast<char*> (&this->lifes), sizeof(int));
			load.read(reinterpret_cast<char*> (&this->mines), sizeof(int));
			load.read(reinterpret_cast<char*> (&this->flags), sizeof(int));
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
					field[i][j].redrawCell(g);
				}
			}
			Player::setLifes(lifes);
			Player::setMines(mines);
			Player::setTime(time);
			Player::setWidth(width);
			Player::setHeight(height);
		}
}

bool Game::openCell(int x, int y, int &mb, Graphics ^g) {
	int curPosX,
		curPosY;

		if (started == true) {
			if (x > xStart && x<xEnd && y>yStart && y < yEnd) {
				curPosX = (int)((x - xStart) / Cell::edge);
				curPosY = (int)((y - yStart) / Cell::edge);
			
				if (mb == GameCell::mb_open && field[curPosX][curPosY].getExtraState() != extraState::opened && field[curPosX][curPosY].getExtraState() != extraState::flagged && field[curPosX][curPosY].getExtraState() != extraState::undefined) {
					if (wasFirstClick == false) {
						spawnMines(curPosX, curPosY);
						wasFirstClick = true;
						timerEnabled = true;
				}
					showMines(g); //only for test
				if (field[curPosX][curPosY].getState() == state::empty) {
					if (field[curPosX][curPosY].getNearbyMines() == 0) {
						autoOpen(curPosX, curPosY, g);
					}
					else {
						field[curPosX][curPosY].setExtraState(extraState::opened);
						field[curPosX][curPosY].redrawCell(g);
						closedCells--;
					}
				}
				else {
					flags--;
					mines--;
					field[curPosX][curPosY].setExtraState(extraState::opened);
					field[curPosX][curPosY].redrawCell(g);
						if (lifes == 0) {
							started = false;
							timerEnabled = false;
							showMines(g);
							return false;
						}
						else {
							lifes--;
							closedCells--;
						}
				}	
			}
				if (mb == GameCell::mb_flag && field[curPosX][curPosY].getExtraState() != extraState::opened && field[curPosX][curPosY].getExtraState() != extraState::undefined) {
				if (wasFirstClick == false) {
					spawnMines(curPosX, curPosY);
					wasFirstClick = true;
					timerEnabled = true;
				}
				if (field[curPosX][curPosY].getExtraState() == extraState::flagged) {
					field[curPosX][curPosY].setExtraState(state::empty);
					field[curPosX][curPosY].redrawCell(g);
					flags++;
					if (field[curPosX][curPosY].getState() == state::mined) {
						mines++;
					}
				}
				else {
					if (flags > 0) {
						field[curPosX][curPosY].setExtraState(extraState::flagged);
						field[curPosX][curPosY].redrawCell(g);
						flags--;
						if (field[curPosX][curPosY].getState() == state::mined) {
							mines--;
						}
					}
				}
			}
				if (mb == GameCell::mb_undefined && field[curPosX][curPosY].getExtraState() != extraState::opened && field[curPosX][curPosY].getExtraState() != extraState::flagged) {
					if (wasFirstClick == false) {
						spawnMines(curPosX, curPosY);
						wasFirstClick = true;
						timerEnabled = true;
				}
				if (field[curPosX][curPosY].getExtraState() == extraState::undefined) {
					field[curPosX][curPosY].setExtraState(extraState::unchecked);
					field[curPosX][curPosY].redrawCell(g);
				}
				else {
					field[curPosX][curPosY].setExtraState(extraState::undefined);
					field[curPosX][curPosY].redrawCell(g);
				}
			}
		}
	}
	
		if (closedCells == mines) {
			timerEnabled = false;
			started = false;
			return true;
		}
		else { 
			return false; 
		}
}

bool Game::getTimerEnabled()
{
	return timerEnabled;
}

int Game::getWidth()
{
	return width;
}

int Game::getHeight()
{
	return height;
}


void Game::autoOpen(int x, int y, Graphics ^g) {
	if (x >= 0 && y >= 0 && x < width && y < height) {
		if (field[x][y].getNearbyMines() == 0 && field[x][y].getExtraState() != extraState::flagged && field[x][y].getExtraState() != extraState::opened && field[x][y].getExtraState() != extraState::undefined) {
			field[x][y].setExtraState(extraState::opened);
			field[x][y].redrawCell(g);
			closedCells--;
			if (x + 1 < width) {
				autoOpen(x + 1, y, g);
			}
			if (x + 1 < width && y - 1 >= 0) {
				autoOpen(x + 1, y - 1, g);
			}
			if (y - 1 >= 0) {
				autoOpen(x, y - 1, g);
			}
			if (x - 1 >= 0 && y - 1 >= 0) {
				autoOpen(x - 1, y - 1, g);
			}
			if (x - 1 >= 0) {
				autoOpen(x - 1, y, g);
			}
			if (x - 1 >= 0 && y + 1 < height) {
				autoOpen(x - 1, y + 1, g);
			}
			if (y + 1 < height) {
				autoOpen(x, y + 1, g);
			}
			if (x + 1 < width && y + 1 < height) {
				autoOpen(x + 1, y + 1, g);
			}
			return;
		}
		else {
			if (field[x][y].getNearbyMines() != 0 && field[x][y].getExtraState() != extraState::opened) {
				field[x][y].setExtraState(extraState::opened);
				field[x][y].redrawCell(g);
				closedCells--;
			}
		}
		return;
	}
}

int Game::getLifes() {
	return this->lifes;
}

void Game::redrawField(Graphics ^ g)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			field[i][j].redrawCell(g);
		}
	}
}

void Game::removeGraphics(Graphics ^g, Color &color) {
	g->FillRectangle(gcnew SolidBrush(Color::FromArgb(180, 180, 180)), xStart, yStart, xEnd-xStart, yEnd-yStart);
	g->DrawRectangle(gcnew Pen(Color::Black, 1), xStart, yStart, xEnd - xStart, yEnd - yStart);
}



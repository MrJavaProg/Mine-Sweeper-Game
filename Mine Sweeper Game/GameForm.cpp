#include <vector>

#include "GameForm.h"
#include <Windows.h>
#include <fstream>
#include <iostream>



using namespace MineSweeperGame;
using namespace System;

enum state {empty = 0, mined = 1, opened = 2, flagged = 3, undefined = 4};
/*Cell **field;
int	width,
	height,
	mines,
	quantity_of_mines = 0,
	quantity_of_cells_width = 0,
	quantity_of_cells_height = 0,
	mb_open = 1,
	mb_flag = 2,
	mb_undefined = 3,
	lifes = 20;*/



void createField(Cell **field, int &width, int &height, int &mines, System::Windows::Forms::Form ^f, bool &started) {
	float xStart,
		  yStart;
	yStart = (f->Height / 2) - (height / 2)*Cell::edge; 
	xStart = (f->Width / 2) - (width/2)*Cell::edge;
		
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			field[i][j].setXStart(xStart+i*Cell::edge);
			field[i][j].setYStart(yStart + j*Cell::edge);
			field[i][j].setXEnd(field[i][j].getXStart() + Cell::edge);
			field[i][j].setYEnd(field[i][j].getYStart() + Cell::edge);
			field[i][j].drawEmptyCell(f);
		}
	}
	started = true;
	wasFirstClick = false;
	flags = mines;
}

void spawnMines(Cell **field, int &width, int &height, int mines, int &curPosX, int &curPosY) {
	int x,
		y;
	while (mines != 0) {
		x = rand() % (width - 1) + 0;
		y = rand() % (height - 1) + 0;
		if (x != curPosX && y != curPosY && field[x][y].getState()!=state::mined) {
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

void showMines(Cell **field, int &width, int &height, Form ^f) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (field[i][j].getState() == state::mined && field[i][j].getExtraState() != state::flagged) {
				field[i][j].drawExplodedCell(f);
			}
		}
	}
}

void openCell(Cell **field, int x, int y, int &width, int &height, int &mines, System::Windows::Forms::Form ^f, bool &started, int &mb, int &lifes, int &closedCells) {
	float xStart = field[0][0].getXStart(),
		 xEnd = field[width - 1][height - 1].getXEnd(),
		 yStart = field[0][0].getYStart(),
		 yEnd = field[width - 1][height - 1].getYEnd();
	int curPosX,
		curPosY;

	if (started == true) {
		if (x > xStart && x<xEnd && y>yStart && y < yEnd) {
			curPosX = (int)((x - xStart) / Cell::edge);
			curPosY = (int)((y - yStart) / Cell::edge);

			if (mb==mb_open && field[curPosX][curPosY].getExtraState()!=state::opened && field[curPosX][curPosY].getExtraState() != state::flagged && field[curPosX][curPosY].getExtraState() != state::undefined) {
				if (wasFirstClick == false) {
					spawnMines(field, width, height, mines, curPosX, curPosY);
					wasFirstClick = true;
				}

				if (field[curPosX][curPosY].getState() == state::empty) {
					field[curPosX][curPosY].drawOpenedCell(f);
					field[curPosX][curPosY].setExtraState(state::opened);
					closedCells--;
				}
				else {
					if (field[curPosX][curPosY].getState()==state::mined)
					flags--;
					mines--;
					field[curPosX][curPosY].drawExplodedCell(f);
					field[curPosX][curPosY].setExtraState(state::opened);
					if (lifes == 0) {
						started = false;
					}
					else {
						lifes--;
					}
				}
			}

			if (mb==mb_flag && field[curPosX][curPosY].getExtraState()!=state::opened && field[curPosX][curPosY].getExtraState()!=state::undefined) {
				if (wasFirstClick == false) {
					spawnMines(field, width, height, mines, curPosX, curPosY);
					wasFirstClick = true;
				}
				if (field[curPosX][curPosY].getExtraState() == state::flagged) {
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
						field[curPosX][curPosY].setExtraState(state::flagged);
						flags--;
						if (field[curPosX][curPosY].getState() == state::mined) {
							mines--;
						}
					}
				}
			}
			
			if (mb == mb_undefined && field[curPosX][curPosY].getExtraState()!=state::opened && field[curPosX][curPosY].getExtraState()!=state::flagged) {
				if (wasFirstClick == false) {
					spawnMines(field, width, height, mines, curPosX, curPosY);
					wasFirstClick = true;
				}
				if (field[curPosX][curPosY].getExtraState() == state::undefined) {
					field[curPosX][curPosY].drawEmptyCell(f);
					field[curPosX][curPosY].setExtraState(state::empty);
				}
				else {
					field[curPosX][curPosY].drawUndefinedCell(f);
					field[curPosX][curPosY].setExtraState(state::undefined);
				}
			}	
		}	
	}
}

void clearField(Cell **field, int &width, int &height) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			field[i][j].~Cell();
		}
	}

	for (int i = 0; i < width; i++) {
		delete [] field[i];
	}
	delete field;
}

void saveGame(Cell **field, int &width, int &height, int &mines, int &lifes) {
	std::fstream save;
	save.open("Save.sav", std::ios::out | std::ios::trunc);
	//save.write("Save.sav", std::ios::out | std::ios::trunc | std::ios::binary);
	save.write(reinterpret_cast<char*> (&lifes), sizeof(int));	
	save.write(reinterpret_cast<char*> (&width), sizeof(int));
	save.write(reinterpret_cast<char*> (&height), sizeof(int));
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			save.write(reinterpret_cast<char*> (&field[i][j]), sizeof(Cell));
		}
	}
	save.close();
}

void loadGame(Cell **field, int &width, int &height, int &mines, int &lifes, System::Windows::Forms::Form ^f, bool started, int &closedCells) {
	std::fstream load;
	load.open("Save.sav", std::ios::in | std::ios::binary);
	load.read(reinterpret_cast<char*> (&lifes), sizeof(int));
	load.read(reinterpret_cast<char*> (&width), sizeof(int));
	load.read(reinterpret_cast<char*> (&height), sizeof(int));
	
	field = new Cell*[width];

	for (int i = 0; i < width; i++) {
		field[i] = new Cell[height];
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			load.read(reinterpret_cast<char*> (&field[i][j]), sizeof(Cell));
			field[i][j].redrawCell(f);
		}
	}
	closedCells = width*height;
	started = true;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GameForm ^gameForm = gcnew GameForm;
	Application::Run(gameForm);
	
	return 0;
}


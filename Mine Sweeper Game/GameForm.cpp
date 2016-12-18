#include "GameForm.h"
#include <Windows.h>




using namespace MineSweeperGame;
using namespace System;

enum state { empty = 0, mined = 1 };
enum extraState { unchecked = 0, opened = 2, flagged = 3, undefined = 4};

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
	showMines(field, width, height, f);
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
			if (field[i][j].getState() == state::mined && field[i][j].getExtraState() != extraState::flagged) {
				field[i][j].drawExplodedCell(f);
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

void saveGame(Cell **field, int &width, int &height, int &mines, int &lifes, int &flags, int &closedCells, int &time, bool &started, bool &wasFirstClick) {
	std::fstream save;
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
			save.write(reinterpret_cast<char*> (&field[i][j]), sizeof(Cell));
		}
	}
	save.close();
}

Cell** loadGame(int &width, int &height, int &mines, int &lifes, int &time, int &flags, System::Windows::Forms::Form ^f, bool &started, bool &wasFirstClick, int &closedCells) {
	Cell **field; 
	std::fstream load;
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
	return field;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GameForm ^gameForm = gcnew GameForm;
	Application::Run(gameForm);
	
	return 0;
}


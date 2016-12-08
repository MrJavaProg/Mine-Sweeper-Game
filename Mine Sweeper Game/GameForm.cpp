#include <vector>

#include "GameForm.h"
#include <Windows.h>


using namespace MineSweeperGame;
using namespace System;

enum state {empty = 0, mined = 1, opened = 2, flagged = 3, undefined = 4};
Cell **field;
int	width,
	height,
	mines,
	quantity_of_mines = 0,
	quantity_of_cells_width = 0,
	quantity_of_cells_height = 0,
	mb_open = 1,
	mb_flag = 2,
	mb_undefined = 3,
	lifes = 0;
bool minePass = false;



void createField(Cell **field, int &width, int &height, System::Windows::Forms::Form ^f, bool &started) {
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
}

void openCell(Cell **field, int x, int y, int &width, int &height, System::Windows::Forms::Form ^f, bool &started, int &mb, int &lifes) {
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

			if (mb==mb_open && field[curPosX][curPosY].getState()!=state::opened) {
				if (field[curPosX][curPosY].getState() == state::empty) {
					field[curPosX][curPosY].drawOpenedCell(f);
					field[curPosX][curPosY].setState(state::opened);
				}
				if (field[curPosX][curPosY].getState() == state::mined) {
					field[curPosX][curPosY].drawExplodedCell(f);
					if (lifes == 0) {
						started = false;
					}
					else {
						lifes--;
					}
				}
			}

			if (mb==mb_flag && field[curPosX][curPosY].getState()!=state::opened) {
				if (field[curPosX][curPosY].getState() == state::flagged) {
					field[curPosX][curPosY].drawEmptyCell(f);
					field[curPosX][curPosY].setState(state::empty);
				}
				else {
					field[curPosX][curPosY].drawFlaggedCell(f);
					field[curPosX][curPosY].setState(state::flagged);
				}
			}
			
			if (mb == mb_undefined && field[curPosX][curPosY].getState()!=state::opened && field[curPosX][curPosY].getState()!=state::flagged) {
				if (field[curPosX][curPosY].getState() == state::undefined) {
					field[curPosX][curPosY].drawEmptyCell(f);
					field[curPosX][curPosY].setState(state::undefined);
				}
				else {
					field[curPosX][curPosY].drawFlaggedCell(f);
					field[curPosX][curPosY].setState(state::undefined);
				}
			}
				
		}
		
	}
}



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GameForm ^gameForm = gcnew GameForm;
	Application::Run(gameForm);
	
	return 0;
}


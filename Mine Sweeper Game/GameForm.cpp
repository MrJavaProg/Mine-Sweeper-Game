#include <vector>

#include "GameForm.h"
#include <Windows.h>


using namespace MineSweeperGame;
using namespace System;

enum state {empty = 0, mined = 1, opened = 2, flagged = 3, undefined = 4};
extern Cell **field;
void createField(Cell **field, int &width, int &height, System::Windows::Forms::Form ^f, bool &started) {
	float xStart,
		  yStart;
	yStart = (f->Height / 2) - (height / 2)*Cell::edge; 
	xStart = (f->Width / 2) - (width/2)*Cell::edge;
		
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			field[i][j].setXStart(xStart+i*Cell::edge);
			field[i][j].setYStart(yStart + j*Cell::edge);
			field[i][j].drawEmptyCell(f);
		}
	}
	started = true;
}

void openCell(Cell **field, int x, int y, System::Windows::Forms::Form ^f, bool &started) {
	float xStart = field[0][0].getXStart(),
		 xEnd = field[width - 1][height - 1].getXEnd(),
		 yStart = field[0][0].getYStart(),
		 yEnd = field[width - 1][height - 1].getYEnd();
	int curPosX,
		curPosY;

	if (started == true) {
		if (x > xStart && x<xEnd && y>yStart && y < yEnd) {
			curPosX = (int)(x / xStart); //- (int)x%(int)xStart;
			curPosY = (int)(y / yStart); //-(int)y % (int)yStart;
			field[curPosX][curPosY].drawOpenedCell(f);
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


#include "GameForm.h"

#include <Windows.h>




using namespace MineSweeperGame;
//using namespace System;


/*void clearField(Cell **field, int &width, int &height) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			field[i][j].~Cell();
		}
	}
	
	for (int i = 0; i < width; i++) {
		delete [] field[i];
	}
	delete field;
}*/




int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GameForm ^gameForm = gcnew GameForm;
	Application::Run(gameForm);
	
	return 0;
}


#include "GameForm.h"
#include <Windows.h>
//#include "Cell.h"

using namespace MineSweeperGame;

extern int width,
		   height;

void createField(array< Cell^>^ field, int %width, int %height) {
	field = gcnew array< Cell^> (width) ;
	for (int i = 0; i < width; i++) {
		field[i] = gcnew Cell;
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
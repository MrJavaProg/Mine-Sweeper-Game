#include "GameForm.h"
#include <Windows.h>


using namespace MineSweeperGame;

void getRecords(RichTextBox ^rtb) {
		
}
	


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GameForm ^gameForm = gcnew GameForm;
	Application::Run(gameForm);

	return 0;
}


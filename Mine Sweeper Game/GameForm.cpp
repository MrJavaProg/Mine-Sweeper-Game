#include "GameForm.h"
#include <Windows.h>

using namespace MineSweeperGame;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew GameForm);
	return 0;
}

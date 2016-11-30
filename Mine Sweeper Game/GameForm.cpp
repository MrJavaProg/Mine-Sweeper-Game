#include "GameForm.h"
#include <Windows.h>


using namespace MineSweeperGame;

enum state {empty = 0, mined = 1, opened = 2, flagged = 3, undefined = 4};

extern int width,
		   height,
		   mines,
		   quantity_of_mines,
		   quantity_of_cells_width,
	       quantity_of_cells_height;

/*void createField(array <Cell ^>^ field, int &width, int &height, int &mines) {
	Cell ;
}*/


/*void setNearbyMines() {
	
}*/

/*void spawnMines() {

}*/




/*void createField(array< Cell^>^ field, int %width, int %height) {
	
	}
}*/

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GameForm ^gameForm = gcnew GameForm;
	Application::Run(gameForm);
	
	return 0;
}
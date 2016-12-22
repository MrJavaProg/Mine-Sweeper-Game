#include "GameForm.h"
#include <Windows.h>


using namespace MineSweeperGame;

void getRecords(RichTextBox ^rtb) {
	std::fstream records;
	records.open("Records.rec", std::ios::in);
	//System::String ^rec;
	char rec[100];
	int i=0;

	records.getline(rec, 100, '\n');
	while (rec[i] != '\0') {
		rtb->Text = rec[i].ToString();
		i++;
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


#pragma once
#include "Cell.h"

class CellDrawing : public Cell
{
public:
	CellDrawing();
	~CellDrawing();
	void drawExplodedCell(System::Windows::Forms::Form ^form);

protected:
	void drawEmptyCell(System::Windows::Forms::Form ^form);
	void drawOpenedCell(System::Windows::Forms::Form ^form, int nearbyMines);
	void drawUndefinedCell(System::Windows::Forms::Form ^form);
	void drawFlaggedCell(System::Windows::Forms::Form ^form);
};


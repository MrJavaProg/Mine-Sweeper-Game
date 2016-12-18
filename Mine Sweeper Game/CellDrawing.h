#pragma once
#include "Cell.h"

class CellDrawing : public Cell
{
public:
	CellDrawing() : Cell() {};
	~CellDrawing();

protected:
	void drawEmptyCell(System::Windows::Forms::Form ^form);
	void drawOpenedCell(System::Windows::Forms::Form ^form);
	void drawUndefinedCell(System::Windows::Forms::Form ^form);
	void drawFlaggedCell(System::Windows::Forms::Form ^form);
	void drawExplodedCell(System::Windows::Forms::Form ^form);
};


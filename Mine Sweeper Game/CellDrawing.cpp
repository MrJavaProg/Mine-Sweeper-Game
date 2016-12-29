#include "CellDrawing.h"

using namespace System::Drawing;

CellDrawing::CellDrawing()
{
	Cell();
}

CellDrawing::~CellDrawing()
{
}

void CellDrawing::drawEmptyCell(System::Windows::Forms::Form ^form)
{
	Graphics ^g = form->CreateGraphics();

	form->g->FillRectangle(gcnew SolidBrush(Color::FromArgb(180, 180, 180)), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew Pen(Color::Black, 1), xStart, yStart, edge, edge);
}

void CellDrawing::drawOpenedCell(System::Windows::Forms::Form ^form, int nearbyMines)
{
	Graphics ^g = form->CreateGraphics();

	g->FillRectangle(gcnew SolidBrush(Color::FromArgb(255, 255, 255)), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew Pen(Color::Black, 1), xStart, yStart, edge, edge);
	if (nearbyMines != 0) {
		g->DrawString(nearbyMines.ToString(), gcnew Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold), gcnew SolidBrush(Color::FromArgb(84, 4, 4)), xStart, yStart);
	}
}

void CellDrawing::drawUndefinedCell(System::Windows::Forms::Form ^ form)
{
	Graphics ^g = form->CreateGraphics();
	drawEmptyCell(form);
	g->DrawString("?", gcnew Font(FontFamily::GenericSansSerif, 18, FontStyle::Bold), gcnew SolidBrush(Color::FromArgb(84, 4, 4)), xStart, yStart - 4);
}

void CellDrawing::drawFlaggedCell(System::Windows::Forms::Form ^ form)
{
	Graphics ^g = form->CreateGraphics();
	Pen ^pen = gcnew Pen(Color::Black, 2);


	array <PointF> ^flag = { PointF(xStart + 3, yStart + edge - 1),
		PointF(xStart + 3, yStart + 3),
		PointF(xStart + edge - 3, yStart + 7),
		PointF(xStart + 3, yStart + 13) };
	drawEmptyCell(form);
	g->DrawPolygon(pen, flag);
	g->FillPolygon(gcnew SolidBrush(Color::Red), flag);
}

void CellDrawing::drawExplodedCell(System::Windows::Forms::Form ^ form)
{
	Graphics ^g = form->CreateGraphics();

	g->FillRectangle(gcnew SolidBrush(Color::Red), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew Pen(Color::Black, 1), xStart, yStart, edge, edge);
}


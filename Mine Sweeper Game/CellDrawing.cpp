#include "CellDrawing.h"

CellDrawing::CellDrawing()
{
}

CellDrawing::~CellDrawing()
{
}

void CellDrawing::drawEmptyCell(System::Drawing::Graphics ^g)
{
	g->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(180, 180, 180)), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Black, 1), xStart, yStart, edge, edge);
}

void CellDrawing::drawOpenedCell(System::Drawing::Graphics ^g, int nearbyMines)
{
	g->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(255, 255, 255)), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Black, 1), xStart, yStart, edge, edge);
	if (nearbyMines != 0) {
		g->DrawString(nearbyMines.ToString(), gcnew System::Drawing::Font(System::Drawing::FontFamily::GenericSansSerif, 14, System::Drawing::FontStyle::Bold), gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(84, 4, 4)), xStart, yStart);
	}
}

void CellDrawing::drawPossibility(float possibility, System::Drawing::Graphics ^g)
{
	g->DrawString(possibility.ToString(), gcnew System::Drawing::Font(System::Drawing::FontFamily::GenericSansSerif, 8, System::Drawing::FontStyle::Bold), gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(100, 40, 40)), xStart, yStart);
}

void CellDrawing::drawUndefinedCell(System::Drawing::Graphics ^g)
{
	g->DrawString("?", gcnew System::Drawing::Font(System::Drawing::FontFamily::GenericSansSerif, 18, System::Drawing::FontStyle::Bold), gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(3, 14, 97)), xStart, yStart - 4);
}

void CellDrawing::drawFlaggedCell(System::Drawing::Graphics ^g)
{
	System::Drawing::Pen ^pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black, 2);
	array <System::Drawing::PointF> ^flag = { System::Drawing::PointF(xStart + 3, yStart + edge - 1),
		System::Drawing::PointF(xStart + 3, yStart + 3),
		System::Drawing::PointF(xStart + edge - 3, yStart + 7),
		System::Drawing::PointF(xStart + 3, yStart + 13) };
	g->DrawPolygon(pen, flag);
	g->FillPolygon(gcnew System::Drawing::SolidBrush(System::Drawing::Color::DarkRed), flag);
}

void CellDrawing::drawExplodedCell(System::Drawing::Graphics ^g)
{
	g->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Black, 1), xStart, yStart, edge, edge);
}


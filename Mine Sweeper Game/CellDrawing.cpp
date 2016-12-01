#include "CellDrawing.h"

using namespace System::Drawing;

float CellDrawing::edge = 25;

CellDrawing::CellDrawing()
{
}


CellDrawing::~CellDrawing()
{
}

float CellDrawing::getXStart()
{
	return xStart;
}

float CellDrawing::getYStart()
{
	return yStart;
}

float CellDrawing::getXEnd()
{
	return xEnd;
}

float CellDrawing::getYEnd()
{
	return yEnd;
}

void CellDrawing::setNearbyMines(int nearbyMines)
{
	this->nearbyMines = nearbyMines;
}

void CellDrawing::setXStart(float xStart)
{
	this->xStart = xStart;
}

void CellDrawing::setYStart(float yStart)
{
	this->yStart = yStart;
}

void CellDrawing::setXEnd(float xEnd)
{
	this->xEnd = xEnd;
}

void CellDrawing::setYEnd(float yEnd)
{
	this->yEnd = yEnd;
}

void CellDrawing::addNearbyMines()
{
	nearbyMines++;
}

/*void CellDrawing::setEdge(float edge)
{
this->edge = edge;
}*/


void CellDrawing::drawEmptyCell(System::Windows::Forms::Form ^form)
{
	Graphics ^g = form->CreateGraphics();

	g->FillRectangle(gcnew SolidBrush(Color::FromArgb(180, 180, 180)), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew Pen(Color::Black, 1), xStart, yStart, edge, edge);
}

void CellDrawing::drawOpenedCell(System::Windows::Forms::Form ^form)
{
	Graphics ^g = form->CreateGraphics();

	g->FillRectangle(gcnew SolidBrush(Color::FromArgb(255, 255, 255)), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew Pen(Color::Black, 1), xStart, yStart, edge, edge);
	g->DrawString(nearbyMines.ToString(), gcnew Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold), gcnew SolidBrush(Color::FromArgb(84, 4, 4)), xStart, yStart - 4);
}

void CellDrawing::drawUndefinedCell(System::Windows::Forms::Form ^ form)
{
	Graphics ^g = form->CreateGraphics();

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
	/*flag = gcnew PointF()[4];
	flag[0] = flag0;
	flag[1] = flag1;
	flag[2] = flag2;
	flag[3] = flag3;*/


	//g->DrawPolygon()
	g->DrawPolygon(pen, flag);
	g->FillPolygon(gcnew SolidBrush(Color::Red), flag);
}

void CellDrawing::drawExplodedCell(System::Windows::Forms::Form ^ form)
{
	Graphics ^g = form->CreateGraphics();

	g->FillRectangle(gcnew SolidBrush(Color::Red), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew Pen(Color::Black, 1), xStart, yStart, edge, edge);
}


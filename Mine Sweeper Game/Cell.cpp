#include "Cell.h"


using namespace System::Drawing;

Cell::Cell()
{
	state = 0;
	nearbyMines = 0;
	extraState = 0;
	mined = false;
}


Cell::~Cell()
{
}

int Cell::getState()
{
	return state;
}

int Cell::getExtraState()
{
	return extraState;
}

void Cell::setState(int state)
{
	this->state = state;
}

void Cell::setExtraState(int extraState)
{
	this->extraState = extraState;
}

void Cell::setMined(bool mined)
{
	this->mined = mined;
}


float Cell::edge = 25;

float Cell::getXStart()
{
	return xStart;
}

float Cell::getYStart()
{
	return yStart;
}

float Cell::getXEnd()
{
	return xEnd;
}

float Cell::getYEnd()
{
	return yEnd;
}

bool Cell::getMined()
{
	return mined;
}

void Cell::setNearbyMines(int nearbyMines)
{
	this->nearbyMines = nearbyMines;
}

void Cell::setXStart(float xStart)
{
	this->xStart = xStart;
}

void Cell::setYStart(float yStart)
{
	this->yStart = yStart;
}

void Cell::setXEnd(float xEnd)
{
	this->xEnd = xEnd;
}

void Cell::setYEnd(float yEnd)
{
	this->yEnd = yEnd;
}

void Cell::addNearbyMines()
{
	nearbyMines++;
}

void Cell::drawEmptyCell(System::Windows::Forms::Form ^form)
{
	Graphics ^g = form->CreateGraphics();

	g->FillRectangle(gcnew SolidBrush(Color::FromArgb(180, 180, 180)), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew Pen(Color::Black, 1), xStart, yStart, edge, edge);
}

void Cell::drawOpenedCell(System::Windows::Forms::Form ^form)
{
	Graphics ^g = form->CreateGraphics();

	g->FillRectangle(gcnew SolidBrush(Color::FromArgb(255, 255, 255)), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew Pen(Color::Black, 1), xStart, yStart, edge, edge);
	if (nearbyMines != 0) {
		g->DrawString(nearbyMines.ToString(), gcnew Font(FontFamily::GenericSansSerif, 14, FontStyle::Bold), gcnew SolidBrush(Color::FromArgb(84, 4, 4)), xStart, yStart - 4);
	}
}

void Cell::drawUndefinedCell(System::Windows::Forms::Form ^ form)
{
	Graphics ^g = form->CreateGraphics();
	drawEmptyCell(form);
	g->DrawString("?", gcnew Font(FontFamily::GenericSansSerif, 18, FontStyle::Bold), gcnew SolidBrush(Color::FromArgb(84, 4, 4)), xStart, yStart - 4);
}

void Cell::drawFlaggedCell(System::Windows::Forms::Form ^ form)
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

void Cell::drawExplodedCell(System::Windows::Forms::Form ^ form)
{
	Graphics ^g = form->CreateGraphics();

	g->FillRectangle(gcnew SolidBrush(Color::Red), xStart, yStart, edge, edge);
	g->DrawRectangle(gcnew Pen(Color::Black, 1), xStart, yStart, edge, edge);
}

void Cell::redrawCell(System::Windows::Forms::Form ^ form)
{
	if (state != 2) {
		if (extraState == 3) {
			drawFlaggedCell(form);
		}
		else {
			if (extraState == 4) {
				drawUndefinedCell(form);
			}
		}
	}
	else {
		if (mined == true) {
			drawExplodedCell(form);
		}
		else {
			drawOpenedCell(form);
		}
	}
}

#pragma once
#include "CellDrawing.h"

class Cell
{
	
	float xStart,
		yStart,
		xEnd,
		yEnd;
	int nearbyMines,
		state,
		extraState;

public:
	static float edge;
	//static float CellDrawing::edge;
	Cell();
	~Cell();
	int getState();
	int getExtraState();
	float getXStart();
	float getYStart();
	float getXEnd();
	float getYEnd();
	//static float getEdge();

	void drawEmptyCell(System::Windows::Forms::Form ^form);
	void drawOpenedCell(System::Windows::Forms::Form ^form);
	void drawUndefinedCell(System::Windows::Forms::Form ^form);
	void drawFlaggedCell(System::Windows::Forms::Form ^form);
	void drawExplodedCell(System::Windows::Forms::Form ^form);

	void setNearbyMines(int nearbyMines);
	void setXStart(float xStart);
	void setYStart(float yStart);
	void setXEnd(float xEnd);
	void setYEnd(float yEnd);
	void setState(int state);
	void setExtraState(int extraState);

	void addNearbyMines();
};


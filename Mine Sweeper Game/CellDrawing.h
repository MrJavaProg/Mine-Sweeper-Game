#pragma once
class CellDrawing
{
	float xStart,
		yStart,
		xEnd,
		yEnd;
	int nearbyMines;
//	static float edge = 25;
	static float edge;

public:
	CellDrawing();
	~CellDrawing();
	float getXStart();
	float getYStart();
	float getXEnd();
	float getYEnd();
	static float getEdge(float edge);

	void drawEmptyCell(System::Windows::Forms::Form ^form);
	void drawOpenedCell(System::Windows::Forms::Form ^form);
	void drawUndefinedCell(System::Windows::Forms::Form ^form);
	void drawFlaggedCell(System::Windows::Forms::Form ^form);
	void drawExplodedCell(System::Windows::Forms::Form ^form);

protected:
	void setNearbyMines(int nearbyMines);
	void setXStart(float xStart);
	void setYStart(float yStart);
	void setXEnd(float xEnd);
	void setYEnd(float yEnd);
};


#pragma once
ref class CellDrawing 
{
	float xStart,
		yStart,
		xEnd,
		yEnd;
	static float edge = 25;

protected:
	
	void setXStart(float xStart);
	void setYStart(float yStart);
	void setXEnd(float xEnd);
	void setYEnd(float yEnd);
	//void setEdge(float edge);
	

public:
	float getXStart();
	float getYStart();
	float getXEnd();
	float getYEnd();
	static float getEdge(float edge);
	//float getEdge();

	



	void drawEmptyCell(System::Windows::Forms::Form ^form);
	void drawOpenedCell(System::Windows::Forms::Form ^form);
	void drawUndefinedCell(System::Windows::Forms::Form ^form);
	void drawFlaggedCell(System::Windows::Forms::Form ^form);
	void drawExplodedCell(System::Windows::Forms::Form ^form);
};


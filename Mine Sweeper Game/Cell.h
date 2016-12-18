#pragma once

class Cell
{
protected:
	float xStart,
		  yStart,
		  xEnd,
		  yEnd;

public:
	static float edge;
	Cell();
	~Cell();

	float getXStart();
	float getYStart();
	float getXEnd();
	float getYEnd();
	
	void setXStart(float xStart);
	void setYStart(float yStart);
	void setXEnd(float xEnd);
	void setYEnd(float yEnd);
	

	
};


#pragma once
class CellAI
{
	float minePossibility;
	bool isOpened,
		 isChecked;

public:
	void setIsOpened(bool isOpened);
	bool getIsOpened();
	void setIsChecked(bool isChecked);
	void addMinePossibility(float minePossibility);
	float getMinePossibility();
	bool getIsChecked();
	CellAI();
	~CellAI();
};


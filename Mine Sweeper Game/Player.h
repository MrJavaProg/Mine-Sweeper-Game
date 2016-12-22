#pragma once


class Player
{
	int time,
		mines,
		width,
		height,
		lifes;


public:
	Player();
	~Player();
	
	void setLifes(int lifes);
	void setMines(int mines);
	void setTime(int time);
	int getMines();
	int getTime();
	int getLifes();
	void writeDownRecord(System::String ^name, int &time);
	void setWidth(int width);
	void setHeight(int height);
};


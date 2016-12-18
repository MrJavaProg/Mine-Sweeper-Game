#pragma once

class Player
{
	char *name;
	int time,
		mines,
		lifes;


public:
	Player();
	~Player();
	
	void setName(char *name);
	char* getName();
	void setMines(int mines);
	void setTime(int time);
	int getMines();
	int getTime();

	//void writeRecord();
};


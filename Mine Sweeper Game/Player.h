#pragma once
#include "GameCell.h"

using namespace std;

class Player
{
	string name;
	int time,
		mines,
		lifes;


public:
	Player();
	~Player();
	
	void setName(string name);
	const char* getName();
	void setMines(int mines);
	void setTime(int time);
	int getMines();
	int getTime();

	void writeRecord();
};


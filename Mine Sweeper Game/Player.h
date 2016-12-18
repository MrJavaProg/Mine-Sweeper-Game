#pragma once
#include "GameCell.h"

using namespace std;

class Player
{
	string name;
	int time,
		mines;



public:
	void setName(string name);
	const char* getName();
	Player();
	~Player();
	
	
};


#include "Player.h"
#include <fstream>



void Player::setLifes(int lifes)
{
	this->lifes = lifes;
}

Player::Player()
{
}


Player::~Player()
{
}

void Player::setMines(int mines)
{
	this->mines = mines;
}

void Player::setTime(int time)
{
	this->time = time;
}

int Player::getMines()
{
	return mines;
}

int Player::getTime()
{
	return time;
}

int Player::getLifes()
{
	return lifes;
}

void Player::setWidth(int width)
{
	this->width = width;
}

void Player::setHeight(int height)
{
	this->height = height;
}

void Player::writeDownRecord(System::String ^name, int &time)
{
	std::fstream records;

	char *newRecord,
		 thisRecord[100],
		 *curVal,
		delim = '.';
	int width,
		height,
		mines;

	records.open("Records.rec", std::ios::in);
	records.getline(thisRecord, 100);
	while (thisRecord[0] != '\0') {
		curVal = strchr(thisRecord, delim) + 1;
		width = atoi(curVal);
		curVal = strchr(curVal, delim) + 1;
		height = atoi(curVal);
		curVal = strchr(curVal, delim) + 1;
		mines = atoi(curVal);
		curVal = strchr(curVal, delim) + 1;
		time = atoi(curVal);
		if (this->width)
		records.getline(thisRecord, 100);
	}
	records.close();

	records.open("Records.rec", std::ios::out);
	for (int i = 0; i < name->Length; i++) {
		records << static_cast<char> (name[i]);
	}
	records << delim << this->width << 'x' << delim << this->height << '-' << delim << this->mines << delim << time << '\n';
	records.close();
}


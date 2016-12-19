#include "Player.h"



void Player::setLifes(int lifes)
{
	this->lifes = lifes;
}

void Player::setName(char* name)
{
	this->name = name;
}

char* Player::getName()
{
	return name;
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



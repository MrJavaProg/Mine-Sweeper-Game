#include "Player.h"



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

void Player::writeDownRecord(char *name, char *fileName, int &time)
{
	this->name = name;
	this->time = time;
	std::fstream records;
	int line = 0,
		lines = 10;  //количество строк рекордов
	char record[100];
	bool isEmpty = true;
	int recTime;


	records.open(fileName, std::ios::in);
	records.getline(record, 100);
	while (record[0] != '\0' && line <= lines) {
		recTime = atoi(strchr(record, ',') + 1);
		isEmpty = false;
		if (time <= recTime) {
			break;
		}

		else {
			records.getline(record, 100);
			line++;
		}
	}
	if (line < 10) {
		createTemp(records, fileName, line, lines);
	}

	if (isEmpty == true) {
		char cTime[10];
		records.close();
		records.open(fileName, std::ios::out);
		records.write(name, strlen(name));
		records.write(",", 1);
		records << itoa(time, cTime, 10);
		records.write("\n", 1);
		records.close();
	}
}


void Player::createTemp(std::fstream &records, char *fileName, int &line, int &lines) {
	char tmpRecord[100],
		 *fileNameTmp;
	int fileNameLen = strlen(fileName);
	std::fstream tmp;

	fileNameTmp = new char[fileNameLen+2];
	for (int i = 0; i < fileNameLen; i++) {
		fileNameTmp[i] = fileName[i];
	}
	fileNameTmp[fileNameLen] = '~';
	fileNameTmp[fileNameLen + 1] = '\0';

	tmp.open(fileNameTmp, std::ios::out);
	records.seekg(std::ios::beg);
	records.getline(tmpRecord, 100);
	while (tmpRecord[0] != '\0') {
		tmp.write(tmpRecord, strlen(tmpRecord));
		tmp.write("\n", 1);
		records.getline(tmpRecord, 100);
	}
	records.close();
	tmp.close();
	rewriteRecords(fileName, fileNameTmp, line, lines);
}

void Player::rewriteRecords(char *fileName, char *fileNameTmp, int &line, int &lines)
{
	std::fstream records,
				 tmp;
	char record[100],
		cTime[50];

	tmp.open(fileNameTmp, std::ios::in);
	records.open(fileName, std::ios::out | std::ios::trunc);
	tmp.seekg(std::ios::beg);
	
	for (int i = 0; i < line; i++) {
		tmp.getline(record, 100);
		records.write(record, strlen(record));
		records.write("\n", 1);
	}

	records.write(name, strlen(name));
	records.write(",", 1);
	records << itoa(time, cTime, 10);
	records.write("\n", 1);
	line = lines-line-1;

	tmp.getline(record, 100);
	while (record[0] != '\0' && line > 0) {
		records.write(record, strlen(record));
		records.write("\n", 1);
		line--;
		tmp.getline(record, 100);
	}
	tmp.close();
	remove(fileNameTmp);
	records.close();
}


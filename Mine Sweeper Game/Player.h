#include <fstream>
#pragma once


class Player
{
	int time,
		mines,
		width,
		height,
		lifes;
	char *name;


public:
	Player();
	~Player();
	
	void setLifes(int lifes);
	void setMines(int mines);
	void setTime(int time);
	int getMines();
	int getTime();
	int getLifes();
	void setWidth(int width);
	void setHeight(int height);
	void writeDownRecord(char *name, int &time);

private:
	void createTemp(std::fstream &records, char *fileName, int &line, int &lines);
	void rewriteRecords(char *fileName, char *fileNameTmp, int &line, int &lines);
	void checkRecord(char *fileName);
};


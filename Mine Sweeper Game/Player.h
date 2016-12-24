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
//	void writeDownRecord(std::streampos &pos, std::fstream &records);
	//void saveRecord();
	void checkRecord(char *name);
	void setWidth(int width);
	void setHeight(int height);
		

private:
	void setName(char* name);
	void createTemp(std::fstream &records, char *fileName, int &line, int &lines);
	void rewriteRecords(char *fileName, char *fileNameTmp, int &line, int &lines);
	int countLines(char *fileName);
};


#pragma once
#include "Date.h"
class RunProgram
{
public:
	RunProgram();
	void getUserOption();

private:
	void dashed_line();
	void printMenu();
	void printAllDates();
	void addDate();
	void substractDate();
	void compareDate();
	void assignDate();
	void addTwoDates();

	int numofelems = 0;
	Date dateArr[10];
};



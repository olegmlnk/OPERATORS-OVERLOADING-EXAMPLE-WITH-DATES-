#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() : day(1), month(1), year(1)
{
}

Date::Date(int h, int m, int s)
{
	if (h < 1 || m < 1 || s < 1)
	{
		this->day = 1;
		this->month = 1;
		this->year = 1;
		cerr << "Wrong date input. Your values was set as default.\n";
	}
	else
	{
		this->day = h;
		this->month = m;
		this->year = s;
	}

}

int Date::getDay()
{
	return this->day;
}

int Date::getMonth()
{
	return this->month;
}

int Date::getYear()
{
	return this->year;
}

void Date::setDay(int h)
{
	if (h >= 1 && h <= 31)
	{
		this->day = h;
	}
	else
	{
		cerr << "Invalid value for day (1-31). Setting to default (0)." << endl;
		this->day = 0;
	}
}

void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		this->month = m;
	}
	else
	{
		cerr << "Invalid value for month (1-12). Setting to default (0)." << endl;
		this->month = 0;
	}
}

void Date::setYear(int s)
{
	if (s >= 1 || s <= 2024)
	{
		this->year = s;
	}
	else
	{
		cerr << "Invalid value for year. Setting to default (0)." << endl;
		this->year = 0;
	}
}


void Date::print()
{
	cout << "day - " << day << " | month - " << month << " | year - " << year << endl;
}

bool Date::operator==(const Date& date)
{
	return day == date.day && month == date.month && year == date.year;
}

Date Date::operator=(const Date date)
{
	day = date.day;
	month = date.month;
	year = date.year;
	return *this;
}

Date Date::operator-(const Date& date)
{
	Date newDate;
	newDate.day = this->day - date.day;
	newDate.month = this->month - date.month;
	newDate.year = this->year - date.year;

	if (newDate.day < 0) {
		newDate.month--;
		newDate.day += daysInMonth(this->month - 1, this->year);
	}
	if (newDate.month < 0) {
		newDate.year--;
		newDate.month += 12;
	}
	if (newDate.year <= 0) {
		newDate.year = 0;
		newDate.month = 0;
		newDate.day = 0;
	}

	return newDate;
}

Date Date::operator+(const Date& date)
{
	Date newDate;
	newDate.day = this->day + date.day;
	newDate.month = this->month + date.month;
	newDate.year = this->year + date.year;

	if (newDate.day > daysInMonth(newDate.month, newDate.year)) {
		newDate.day -= daysInMonth(newDate.month, newDate.year);
		newDate.month++;
		if (newDate.month > 12) {
			newDate.month -= 12;
			newDate.year++;
		}
	}

	return newDate;
}



int Date::daysInMonth(int m, int y) const {
	if (m == 2) {
		return (isLeapYear(y)) ? 29 : 28;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		return 30;
	}
	else {
		return 31;
	}
}

bool Date::isLeapYear(int y) const {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}


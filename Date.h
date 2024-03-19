#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(); 
    Date(int h, int m, int s); 

    int getDay();
    int getMonth();
    int getYear();

    void setDay(int h);
    void setMonth(int m);
    void setYear(int s);

    void print();

    bool operator== (const Date& date);
    Date operator= (const Date date);
    Date operator- (const Date& date);
    Date operator+ (const Date& date);

private:
    int daysInMonth(int m, int y) const; 
    bool isLeapYear(int y) const; 
};

#endif DATE_H
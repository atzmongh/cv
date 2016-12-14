// ChelloCPP.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include "opencv2\core.hpp"
#include "opencv2\imgcodecs.hpp"
#include "opencv2\highgui.hpp"
using namespace std;
using namespace cv;



class Date
{
private:
	int daysFromStart = 0;
	Date(int days)
	{
		daysFromStart = days;
	}
public:
	Date(int dd, int mm, int yy)
	{
		setDate(dd, mm, yy);
	}
	Date(const Date& copiedDate) {
		daysFromStart = copiedDate.daysFromStart;
	}
	Date& operator=(const Date& copiedDate)
	{
		this->daysFromStart = copiedDate.daysFromStart;
		return *this;
	}

	void setDate(int dd, int mm, int yy)
	{
		daysFromStart = (yy - 1) * 360 + (mm - 1) * 30 + dd - 1;
	}
	void print() const 
	{
		int day, month, year;
		toDate(day, month, year);
		cout << day << '/' << month << '/' << year<<endl;
	}
	void toDate(int & day, int& month, int&year) const
	{
		year = daysFromStart / 360 + 1;
		month = (daysFromStart % 360) / 30 + 1;
		day = (daysFromStart % 30)+1;
	}
	void addDays(int days=1)
	{
		daysFromStart += days;
	}
	Date addedDays(int days=1) const
	{
		return Date(daysFromStart + days);
	}
	int difference(const Date& otherDate) const 
	{
		return this->daysFromStart - otherDate.daysFromStart;
	}
	int operator-(const Date& otherDate) const 
	{
		return this->difference(otherDate);
	}
	Date operator+ (int days) const 
	{
		return this->addedDays(days);
	}
	const Date& operator<<(const Date& aDate) const
	{
		int day, month, year;
		toDate(day, month, year);
		cout << day << '/' << month << '/' << year;
		return *this;
	}
};

 ostream& operator<<(ostream& aStream, const Date& aDate) {
	int day, month, year;
	aDate.toDate(day, month, year);
	cout << day << '/' << month << '/' << year;
	return aStream;
}
int main()
{
	Date birthDate(30,12,1957);
	cout << birthDate<<endl;
	Date newDate(1,1,1);
	newDate = birthDate.addedDays(1);
	newDate.print();
	(newDate + 30).print();
	cout << "diff:" << newDate-birthDate<<endl;
	return 0;
}


#include "Test2.h"
#include "iostream"
using namespace std;

void Date::SetDate(int year,int mouth,int day){
	_year = year;
	_mouth = mouth;
	_day = day;
}


void Date::PrintDate(){
	cout << _year << " " << _mouth << ' ' << _day << endl;
}
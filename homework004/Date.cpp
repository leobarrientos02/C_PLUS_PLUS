//******************************************************************
// Class: Date
//
// Purpose: A class for Date that takes in 3 integers month,
//			date, and year, and includes their get methods, 
//			set methods, and a default constructor.
//
//******************************************************************
#include "Date.h"

// Get Methods
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}
int Date::getYear() {
	return year;
}

// Set Methods
void Date::setMonth(int m) {
	month = m;
}
void Date::setDay(int d) {
	day = d;
}
void Date::setYear(int y) {
	year = y;
}

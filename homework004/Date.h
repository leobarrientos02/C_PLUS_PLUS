//******************************************************************
// Class: Date
//
// Purpose: A class for Date that takes in 3 integers month,
//			date, and year, and includes their get methods, 
//			set methods, and a default constructor.
//
//******************************************************************
#ifndef Date_H
#define Date_H
class Date
{
private:
	int month, day, year;

public:

	// Get Methods
	int getMonth();
	int getDay();
	int getYear();

	// Set Methods
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);

	// Default Constructor
	Date() {
		month = 00;
		day = 00;
		year = 0000;
	}
};

#endif

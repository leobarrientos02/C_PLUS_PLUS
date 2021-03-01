//******************************************************************
// Class: OrderSummary
//
// Purpose: A class for Ordersummry that takes in customerFirstName
//			(string), customerLastName(string), and a lineItem Array
//			(LineItem). It includes the get methods, set methods,
//			default constructor, Read function, Write function,
//			Display function, and a GetHighestPriceItem function.
//
//******************************************************************
#ifndef OrderSummary_H
#define OrderSummary_H
#include <iostream>
#include "LineItem.h"
#include <iomanip>
using namespace std;

class OrderSummary
{
private:
	string CustomerFirstName;
	string CustomerLastName;

	LineItem li[4];

public:

	// Get methods
	string getFirstName();
	string getLastName();

	// Set methods
	void setFirstName(string first);
	void setLastName(string last);

	// Default constructor
	OrderSummary() {
		CustomerFirstName = "No_First_Name";
		CustomerLastName = "No_Last_Name";

		for (int i = 0; i < 4; i++) {
			LineItem();
			li[i].setQuantity(0);
			li[i].setDiscountPct(0);
		}
	}

//*********************************************************************
// Function: Read
//
// Purpose: The read function uses a string parameter to read in 
//			the input file, creates variables to catergorize the
//			data from the file and fill the OrderSummary Instance
//			variables with data from a file.
//
//*********************************************************************
	void Read(string fileName);

//*********************************************************************
// Function: Write
//
// Purpose: The write function uses a string parameter to open
//			an output file, write all the member variable data 
//			to the user specified file.
//
//*********************************************************************
	void Write(string fileName);

//*********************************************************************
// Function: Display
//
// Purpose: The Display function Write the contents of all member
//			variables of the OrderSummary instance to the screen.
//			This function should show data in report format.
//
//*********************************************************************
	void Display();

//*********************************************************************
// Function: GetHighestPriceItem
//
// Purpose: The GetHighestPriceItem function Shows the highest
//			price line item on screen.
//
//*********************************************************************
	LineItem GetHighestPriceItem();
};

#endif
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
#include "OrderSummary.h"
#include <fstream>
using namespace std;

string OrderSummary::getFirstName() {
	return CustomerFirstName;
}
string OrderSummary::getLastName() {
	return CustomerLastName;
}

void OrderSummary::setFirstName(string f) {
	CustomerFirstName = f;
}

void OrderSummary::setLastName(string l) {
	CustomerLastName = l;
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
void OrderSummary::Read(string filename) {

	string fName;
	string lName;
	string itemName;
	double Quantity, Discount, Price;
	int month, day, year;

	ifstream inFile;
	inFile.open(filename);

	inFile >> fName >> lName;

	OrderSummary::setFirstName(fName);
	OrderSummary::setLastName(lName);

	// For loop to read and categorize the data from
	// the input file
	for (int i = 0; i < 4; i++) {

		inFile >> month >> day >> year
			>> itemName >> Price >> Quantity >> Discount;
		
		Date date[4];
		date[i].setMonth(month);
		date[i].setDay(day);
		date[i].setYear(year);

		Item items[4];
		items[i].setItemName(itemName);
		items[i].setPrice(Price);

		OrderSummary::li[i].setDate(date[i]);
		OrderSummary::li[i].setItem(items[i]);
		OrderSummary::li[i].setQuantity(Quantity);
		OrderSummary::li[i].setDiscountPct(Discount);
	}
	
	inFile.close();
}
//*********************************************************************
// Function: Write
//
// Purpose: The write function uses a string parameter to open
//			an output file, write all the member variable data 
//			to the user specified file.
//
//*********************************************************************
void OrderSummary::Write(string fileName) {

	ofstream outFile;
	outFile.open(fileName);

	// Get the First and Last Name First
	outFile << OrderSummary::getFirstName() << endl;
	outFile << OrderSummary::getLastName() << endl;
	
	// For loop to get the rest of the data
	for (int i = 0; i < 4; i++) {
		
		outFile << OrderSummary::li[i].getDate().getMonth() << endl;
		outFile << OrderSummary::li[i].getDate().getDay() << endl;;
		outFile << OrderSummary::li[i].getDate().getYear() << endl;
		outFile << OrderSummary::li[i].getItem().getItemName() << endl;
		outFile << OrderSummary::li[i].getItem().getPrice() << endl;
		outFile << OrderSummary::li[i].getQuantity() << endl;
		outFile << OrderSummary::li[i].getDiscountPct() << endl;
	}
	
	outFile.close();
}

//*********************************************************************
// Function: Display
//
// Purpose: The Display function Write the contents of all member
//			variables of the OrderSummary instance to the screen.
//			This function should show data in report format.
//
//*********************************************************************
void OrderSummary::Display() {

	double cost, discountPrice;

	cout << "First Name: " << OrderSummary::getFirstName() << endl;
	cout << "Last Name: " << OrderSummary::getLastName() << endl;
	cout << setw(10) << "ItemName" << setw(14) << "Price" << setw(12) << "Quantity"
		<< setw(10) << "Discount" << setw(8) << "Cost" << endl;
	cout << setw(10) << "--------" << setw(14) << "-----" << setw(12) << "--------"
		<< setw(10) << "--------" << setw(8) << "----" << endl;
	// Print data out of the order lineItem Arrays
	for (int i = 0; i < 4; i++) {
		
		discountPrice = OrderSummary::li[i].getItem().getPrice() 
			* OrderSummary::li[i].getDiscountPct();

		cost = OrderSummary::li[i].getItem().getPrice() - discountPrice;

		cout << setw(10) << OrderSummary::li[i].getItem().getItemName() << setw(10)
			<< "$" << fixed << setprecision(2) << OrderSummary::li[i].getItem().getPrice() << setw(9)
			<< fixed << setprecision(0) << OrderSummary::li[i].getQuantity() << setw(11)
			<< fixed << setprecision(2) << OrderSummary::li[i].getDiscountPct() << setw(7)
			<< "$" << fixed << setprecision(2) << cost << endl;
	}
	cout << endl;
}

//*********************************************************************
// Function: GetHighestPriceItem
//
// Purpose: The GetHighestPriceItem function Shows the highest
//			price line item on screen.
//
//*********************************************************************
LineItem OrderSummary::GetHighestPriceItem() {

	int maxIndex = 0;
	LineItem max = OrderSummary::li[0];
	double maxPrice = max.getItem().getPrice();

	// For loop to search the array for the highest price
	for (int i = 0; i < 4; i++) {
		if (OrderSummary::li[i].getItem().getPrice() > maxPrice) {
			maxPrice = OrderSummary::li[i].getItem().getPrice();
			maxIndex = i;
		}
	}

	max = OrderSummary::li[maxIndex];

	return max;
}
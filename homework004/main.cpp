//*****************************************************************
//	File: HomeWork004
//
//	Purpose: Creates a Item, Date, LineItem, and OrderSummary
//			class. The Item and Date class is used to create the
//			LineItem class and the LineItem class is used to create
//			the OrderSummary class. In the main, an OrderSummary class
//			is created and its functions are called throughout a do while
//			loop that reads an inputfile, writes to an outputfile,
//			created a table and finds the highest price.
//
//	Written By: Leonel Barrientos
//
//	Compiler: Visual C++ 2019
//
//*****************************************************************
#include <iostream>
#include "OrderSummary.h"

using namespace std;

int main() {

	string inputFile, outputFile;
	int userchoice;
	OrderSummary order;

	do {

		// Create MENU each option would include
		// a function
		cout << "Order Summary Program" << endl;
		cout << "---------------------" << endl;
		cout << "1 - Read order summary info from a file" << endl;
		cout << "2 - Write order summary info to a file" << endl;
		cout << "3 - Show all order summary info on screen" << endl;
		cout << "4 - Show highest price line item on screen" << endl;
		cout << "5 - Exit" << endl;
		cout << "Enter Choice: ";
		cin >> userchoice;
		cout << endl;

		if (userchoice == 1) {

			cout << "Enter input filename: ";
			cin >> inputFile;
			order.Read(inputFile);
			cout << endl;
		}

		else if (userchoice == 2) {
			
			cout << "Enter output filename: ";
			cin >> outputFile;
			order.Write(outputFile);
			cout << endl;
		}

		else if (userchoice == 3) {
			
			order.Display();
		}
		else if (userchoice == 4) {
			
			LineItem Max = order.GetHighestPriceItem();

			cout << "Highest Price LineItem" << endl;
			cout << Max.getItem().getItemName() << setw(10)
				<< "$" << fixed << setprecision(2) << Max.getItem().getPrice() << endl;
			cout << endl;
		}
		else if (userchoice == 5) {
			cout << "EXIT" << endl;
			cout << endl;
			return 0;
		}
		else {
			// Test if the user enter valid choices
			cout << "Invalid Choice, Try Again" << endl;
			cout << endl;
		}

	} while (userchoice != 5);
	return 0;
}
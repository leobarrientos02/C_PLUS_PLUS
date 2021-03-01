//*****************************************************************
//	File: HomeWork3
//
//	Purpose: Reads data from an input file, organize
//			the data into Struct arrays that also organzize
//			the data into categories, and shows the data
//			on the screen in an organized way.
//
//	Written By: Leonel Barrientos
//
//	Compiler: Visual C++ 2019
//
//*****************************************************************
#include <iostream>
#include "MyFunctions.h"
#include "LineItem.h"
#include <iomanip>

using namespace std;

int main()
{
	// Declare variables
	int userchoice;

	// create an array of LineItem structs
	LineItem li[4];

	do {

		// Create MENU each option would include
		// a function
		cout << "LineItem Program" << endl;
		cout << "----------------" << endl;
		cout << "1 - Load line item data from file" << endl;
		cout << "2 - Show all line item data" << endl;
		cout << "3 - Show highest price line item" << endl;
		cout << "4 - Exit" << endl;
		cout << "Enter Choice: ";
		cin >> userchoice;
		cout << endl;

		if (userchoice == 1) {
			
			LoadLineItemDataFromFile(li);
		}

		else if (userchoice == 2) {

			ShowLineItemData(li);
		}

		else if (userchoice == 3) {
			
			cout << "Highest Price LineItem" << endl;
			LineItem Max;
			Max = GetHighestPriceLineItem(li);
			
			cout << Max.Item.Name << endl;
			cout << "$" << fixed << setprecision(2) << Max.Item.Price << endl;
			cout << endl;
		}
		else if (userchoice == 4) {
			cout << "EXIT" << endl;
			cout << endl;
			return 0;
		}
		else {
			// Test if the user enter valid choices
			cout << "Invalid Choice, Try Again" << endl;
			cout << endl;
		}

	} while (userchoice != 4);

	return 0;
}
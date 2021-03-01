#include "MyFunctions.h"

//*************************************************************************
// Function: LoadLineItemDataFromFile
//
// Purpose: Reads item data from the given filename
//			and populates into LineItem Arrays
//
//*************************************************************************
void LoadLineItemDataFromFile(LineItem li[]) {

	// Declare variables
	string InputFileName;

	// Ask user to enter Input Filename
	cout << "Enter Input Filename: ";
	cin >> InputFileName;
	cout << endl;

	// Use fstream to open the data file
	ifstream inFile;
	inFile.open(InputFileName);
	
	for (int i = 0; i < 4; i++) {

		inFile >> li[i].Date.month
			>> li[i].Date.day
			>> li[i].Date.year
			>> li[i].Item.Name
			>> li[i].Item.Price
			>> li[i].Quantity
			>> li[i].DiscountPct;
	}

	inFile.close();
	
}

//*************************************************************************
// Function: ShowLineItemData
//
// Purpose: Creates a template and prints the data
//			in the LineItem Arrays on the template
//
//*************************************************************************
void ShowLineItemData(LineItem li[]) {

	for (int i = 0; i < 4; i++) {
		
		cout << "Month: " << li[i].Date.month << endl;
		cout << "Date: " << li[i].Date.day << endl;
		cout << "Year: " << li[i].Date.year << endl;
		cout << "Name: " << li[i].Item.Name << endl;
		cout << "Price: $" << fixed << setprecision(2) << li[i].Item.Price << endl;
		cout << "Quantity: " << li[i].Quantity << endl;
		cout << "Discount Pct: " << fixed << setprecision(2) << li[i].DiscountPct << endl;
	}
	cout << endl;
}

//*************************************************************************
// Function: GetHighestPriceLineItem
//
// Purpose: Search the arra for the highest price
//			and creates a highestPrice Struct
//
//*************************************************************************
LineItem GetHighestPriceLineItem(LineItem li[]) {
	
	int max = 0;
	
	for (int i = 1; i < 4; i++) {
		if (li[max].Item.Price < li[i].Item.Price) {
			max = i;
		}
	}
	
	// Create a Max Price struct
	LineItem MaxPriceItem;
	MaxPriceItem.Date.month = li[max].Date.month;
	MaxPriceItem.Date.day = li[max].Date.day;
	MaxPriceItem.Date.year = li[max].Date.year;
	MaxPriceItem.Item.Name = li[max].Item.Name;
	MaxPriceItem.Item.Price = li[max].Item.Price;
	MaxPriceItem.DiscountPct = li[max].DiscountPct;
	MaxPriceItem.Quantity = li[max].Quantity;

	return MaxPriceItem;
}
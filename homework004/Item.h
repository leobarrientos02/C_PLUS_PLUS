//******************************************************************
// Class: Item
//
// Purpose: A class for Item that takes in an ItemName(string) 
//			and a price(double)and includes the get methods, 
//			set methods, and a default constructor.
//
//******************************************************************
#ifndef Item_H
#define Item_H
#include <iostream>
using namespace std;

class Item {

private:
	string itemName;
	double price;
public:

	// Get Methods
	string getItemName();
	double getPrice();

	// Set Methods
	void setItemName(string i);
	void setPrice(double p);

	// Default Constructor
	Item() {
		itemName = "None";
		price = 0;
	}
};
#endif
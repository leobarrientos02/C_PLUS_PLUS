//******************************************************************
// Class: Item
//
// Purpose: A class for Item that takes in an ItemName(string) 
//			and a price(double)and includes the get methods, 
//			set methods, and a default constructor.
//
//******************************************************************
#include "Item.h"

// Get Methods
string Item::getItemName() {
	return itemName;
}

double Item::getPrice() {
	return price;
}

// Set Methods

void Item::setItemName(string i) {
	itemName = i;
}

void Item::setPrice(double p) {
	price = p;
}
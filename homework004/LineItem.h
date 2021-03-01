//******************************************************************
// Class: LineItem
//
// Purpose: A class for LineItem that takes in an item(Item) 
//			date(Date), quantity(double) and a discountPct(Double)
//			includes the get methods, set methods, and a default 
//			constructor.
//
//******************************************************************
#ifndef LineItem_H
#define LineItem_H
#include "Item.h"
#include "Date.h"

class LineItem
{
private:
	Item item;
	Date date;
	double Quantity, DiscountPct;

public:
	// Get Methods
	Item getItem();
	Date getDate();
	double getQuantity();
	double getDiscountPct();

	// Set Methods
	void setItem(Item i);
	void setDate(Date d);
	void setQuantity(double q);
	void setDiscountPct(double q);

	// Default Constructor
	LineItem() {

		Date();
		Item();
		Quantity = 0;
		DiscountPct = 0;
	}
};

#endif
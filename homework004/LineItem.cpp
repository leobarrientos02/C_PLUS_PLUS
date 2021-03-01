//******************************************************************
// Class: LineItem
//
// Purpose: A class for LineItem that takes in an item(Item) 
//			date(Date), quantity(double) and a discountPct(Double)
//			includes the get methods, set methods, and a default 
//			constructor.
//
//******************************************************************
#include "LineItem.h"

Item LineItem::getItem() {
	return item;
}

Date LineItem::getDate() {
	return date;
}

double LineItem::getQuantity() {
	return Quantity;
}

double LineItem::getDiscountPct() {
	return DiscountPct;
}

void LineItem::setItem(Item i) {
	item = i;
}

void LineItem::setDate(Date d) {
	date = d;
}
void LineItem::setQuantity(double q) {
	Quantity = q;
}

void LineItem::setDiscountPct(double d) {
	DiscountPct = d;
}
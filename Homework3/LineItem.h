//*************************************************************************
// Struct: LineItem
//
// Purpose: A struct for LineItems including a Date
//			and Item Struct members and a quantity
//			and discount members
//
//*************************************************************************
#pragma once
#include "Date.h"
#include "Item.h"
struct LineItem {

	Date Date;
	Item Item;
	double Quantity;
	double DiscountPct;

};
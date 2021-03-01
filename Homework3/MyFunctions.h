#pragma once
#include "LineItem.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//*************************************************************************
// Function: LoadLineItemDataFromFile
//
// Purpose: Reads item data from the given filename
//			and populates into LineItem Arrays
//
//*************************************************************************
void LoadLineItemDataFromFile(LineItem li[]);

//*************************************************************************
// Function: ShowLineItemData
//
// Purpose: Creates a template and prints the data
//			in the LineItem Arrays on the template
//
//*************************************************************************
void ShowLineItemData(LineItem li[]);

//*************************************************************************
// Function: GetHighestPriceLineItem
//
// Purpose: Search the arra for the highest price
//			and creates a highestPrice Struct
//
//*************************************************************************
LineItem GetHighestPriceLineItem(LineItem li[]);

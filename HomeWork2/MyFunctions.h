#pragma once
#include <fstream>
using namespace std;


//*********************************************************************************
// Function: ReadItemsFromFile
//
// Purpose: Reads item data from the given filename
//			and populates multiple arrays of data.
// 
// Update Information
// ------------------
//
// Name: Leonel Barrientos
// Date: 2/12/2020
// Description: The arrays were not being filled with all the
//				data in the textfile and only allowing the first
//				item in ItemData.txt. I decided to call Infile 
//				and all the arrays on the first index(0), then
//				use a while loop to fill up the array with the 
//				data in the ItemData.txt File.
//
//*************************************************************************
void ReadItemsFromFile(string inputFilename, string nameArray[], double priceArray[], double quantityArray[],double discountPctArray[]);

//*********************************************************************************
// Function: ItemReport
//
// Purpose: Writes an item report to a given output filename.
// 
// Update Information
// ------------------
//
// Name: Leonel Barrientos
// Date: 2/13/2020
// Description: I had noticed that my function was not opening
//				the arrays but instead i had open ItemData file
//				I updated the code by adding a for loop capable
//				of reading everything in each arrays.
//
//*************************************************************************
void ItemReport(string outputFilename, string nameArray[], double priceArray[], double quantityArray[], double discountPctArray[]);

//*********************************************************************************
// Function: FindMaxPriceIndex
//
// Purpose: Searches the price array for the max price amount,
//			returns the index of the max price, and set the 
//			max price reference parameter to the max price
//			in the array. 
// 
// Name: Leonel Barrientos
// Date: 2/18/20
// Description: Added a bool variable named found set equal
//				to false, this allow to search the priceArray
//				for the index of the MaxPrice, if found it
//				changes the bool to true. With an if statement
//				if found equal true it retruns the index of the
//				MaxPrice.
//
//*************************************************************************
int FindMaxPriceIndex(double price[], double &maxPrice);

//*********************************************************************************
// Function: FindMinPriceIndex
//
// Purpose: Searches the price array for the minimum price amount,
//			returns the index of the minimum price, and set the 
//			minimum price reference parameter to the minimum price
//			in the array. 
// 
// Update Information
// ------------------
//
// Name: Leonel Barrientos
// Date: 2/18/20
// Description: Added a bool variable named found set equal
//				to false, this allow to search the priceArray
//				for the index of the minPrice, if found it
//				changes the bool to true. With an if statement
//				if found equal true it retruns the index of the
//				minPrice.
//				
//*************************************************************************
int FindMinPriceIndex(double priceArray[], double &minPrice);

//*************************************************************************
// Function: CalculateAvgPrice
//
// Purpose: Calculates the average price for the array.
// 
//*************************************************************************
double CalculateAvgPrice(double priceArray[]);

//*********************************************************************************
// Function: CalculateTotalQuantity
//
// Purpose:  Calculates the total quantity for the array.
//
//*************************************************************************
double CalculateTotalQuantity(double quantity[]);


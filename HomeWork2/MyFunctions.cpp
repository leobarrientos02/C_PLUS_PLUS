#include "MyFunctions.h"
#include <iostream>
#include <fstream>
#include <iomanip>
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
void ReadItemsFromFile(string inputFilename, string nameArray[], double priceArray[], double quantityArray[], double discountPctArray[]) {
	
	ifstream inFile;
	inFile.open(inputFilename);

	int i = 0;

	inFile >> nameArray[i] >> priceArray[i]
		>> quantityArray[i] >> discountPctArray[i];

	while (inFile && i < 4) {
		i++;
		inFile >> nameArray[i] >> priceArray[i]
			>> quantityArray[i] >> discountPctArray[i];
	}

	inFile.close();
}


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
void ItemReport(string outputFilename, string nameArray[], double priceArray[], double quantityArray[], double discountPctArray[]) {

	// open outfile
	ofstream outFile;
	outFile.open(outputFilename);

	outFile << "Item Report" << endl;
	outFile << "-----------" << endl;
	outFile << endl;

	// create table
	outFile << setw(15) << "Name";
	outFile << setw(15) << "Price";
	outFile << setw(15) << "Quantity";
	outFile << setw(15) << "DiscountPct" << endl;
	outFile << setw(15) << "----";
	outFile << setw(15) << "-----";
	outFile << setw(15) << "-------";
	outFile << setw(15) << "-----------";
	outFile << endl;

		for (int i = 0; i < 4; i++) {

		outFile << setw(15) << nameArray[i]
		<< setw(15) << fixed << setprecision(2) << priceArray[i]
		<< setw(15) << fixed << setprecision(2) << quantityArray[i]
		<< setw(15) << fixed << setprecision(2) << discountPctArray[i];
		outFile << endl;
	}

	outFile << endl;
	outFile << endl;
	
	// sets avg equal to the output of CalculateAvgPrice()
	double avg = CalculateAvgPrice(priceArray);
	outFile << "Average Price: " 
		<< fixed << setprecision(2) << avg << endl;
	
	// sets total equal to the output of CalculateTotalQuantity()
	int total = CalculateTotalQuantity(quantityArray);
	outFile << "Total Quantity: " << total << endl;
	outFile << endl;

	// sets maxPrice equal to the first element in the priceArray
	double maxPrice = priceArray[0];
	
	// sets maxIndex equal to the output of the FindMaxPriceIndex
	int maxIndex = FindMaxPriceIndex(priceArray, maxPrice);
	outFile << "Max Price Item Name:" 
		<< nameArray[maxIndex] << endl;
	outFile << "Max Price Amount: "
		<< fixed << setprecision(2) << maxPrice << endl;
	outFile << endl;
	
	// sets minPrice equal to the first element in the priceArray
	double minPrice = priceArray[0];

	// sets maxIndex equal to the output of the FindMaxPriceIndex
	int minIndex = FindMinPriceIndex(priceArray, minPrice);
	outFile << "Min Price Item Name: " 
		<< nameArray[minIndex] << endl;
	outFile << "Min Price Amount: "
		<< fixed << setprecision(2) << minPrice << endl;

	// close the file
	outFile.close();
}


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
int FindMaxPriceIndex(double priceArray[], double &maxPrice) {
	
	int index;
	bool found = false;

	index = 0;
	// sets maxPrice equal to the first element in the priceArray
	maxPrice = priceArray[0];

	for (int i = 0; i < 4; i++) {

		if (priceArray[i] > maxPrice) {

			// sets maxPrice to the highest value in the array
			maxPrice = priceArray[i];

		}
	}

	while (index < 4 && !found) {
		if (priceArray[index] == maxPrice)
			found = true;
		else {
			index++;
		}
	}
	if (found) {
		return index;
	}
	else {
		return -1;
	}

}


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
int FindMinPriceIndex(double priceArray[], double &minPrice) {
	
	int index;
	bool found = false;

	index = 0;
	// sets minPrice equal to the first element in the priceArray
	minPrice = priceArray[0];
	
	for (int i = 0; i < 4; i++) {

		if (priceArray[i] < minPrice) {
			// sets minPrice to the lowest value in the array
			minPrice = priceArray[i];

		}
	}

	while (index < 4 && !found) {
		if (priceArray[index] == minPrice)
			found = true;
		else {
			index++;
		}
	}
	if (found) {
		return index;
	}
	else {
		return -1;
	}
}


//*************************************************************************
// Function: CalculateAvgPrice
//
// Purpose: Calculates the average price for the array.
// 
//*************************************************************************
double CalculateAvgPrice(double priceArray[]) {

	double total = 0;
	double avg = 0;
	
	for (int i = 0; i < 4; i++) {
		
		total += priceArray[i];
		avg = total / 4;
	}
	return avg;
}


//*********************************************************************************
// Function: CalculateTotalQuantity
//
// Purpose:  Calculates the total quantity for the array.
//
//*************************************************************************
double CalculateTotalQuantity(double quantity[]) {
	
	double total = 0;

	for (int i = 0; i < 4; i++) {

		total += quantity[i];
	}
	
	return total;
}


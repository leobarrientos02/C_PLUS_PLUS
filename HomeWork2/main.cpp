//*****************************************************************
//	File: HomeWork2
//
//	Purpose: Reads data from an input file, adds
//			the data into parallel arrays, and uses
//			the arrays to print into an output file.
//
//	Written By: Leonel Barrientos
//
//	Compiler: Visual C++ 2019
//
//*****************************************************************
#include <iostream>
#include <fstream>
#include "MyFunctions.h"
using namespace std;

int main() {
	
	// Declare variables
	string inputFilename;
	string outputFilename;

	// Declare four arrays
	string nameArray[4];
	double priceArray[4];
	double quantitiesArray[4];
	double discountPctArray[4];

	// Ask user to enter the input file name
	cout << "Enter the input file name: ";
	cin >> inputFilename;
	cout << endl;

	// Use the ReadItemsFromFile() to read the file
	// and add the data into parallel arrays
	ReadItemsFromFile(inputFilename, nameArray, priceArray, quantitiesArray, discountPctArray);

	// Ask the user for the output file
	cout << "Enter the output file name: ";
	cin >> outputFilename;
	cout << endl;

	// Use the ItemReport() to prints the arrays
	// into an output file
	ItemReport(outputFilename, nameArray, priceArray, quantitiesArray, discountPctArray);

	return 0;
}
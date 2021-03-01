//*****************************************************************************
//	File: FinalProject
//
//	Purpose: The program uses a class containing many functions, 
//			 a copy constructor(Deep Copy), and two operator overloads.
//			 In main, a dynamic array of Ingredient is created and is filled
//			 with data from an inputFile. The data are output on the screen
//			 in a table format from the dynamic arrays.
//
//	Written By: Leonel Barrientos
//
//	Compiler: Visual C++ 2019
//
//*****************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Ingredient.h"

using namespace std;

int main() {
	
	
	// Declare an instance of Ingredient with constructor
	Ingredient a("Milk", 2, "Gallon");
	cout << "Ingredient A:\n" << a << endl;
	
	// Declare an instance of Ingredient with copy constructor
	Ingredient b(a);
	cout << "Ingredient B:\n" << b << endl;
	
	// Declare an instance of Ingredient with default constructor
	cout << "Default Constructor called" << endl;
	Ingredient c;
	cout << "Ingredient C:\n" << c << endl;

	// Operator Overload uses to copy a to c;
	c = a;
	cout << "Ingredient C:\n" << c << endl;

	// A dynamic array of Ingredients
	Ingredient* p;
	p = new Ingredient[3];
	
	// Use ifstream to open the input File
	ifstream InputFile;
	InputFile.open("inputFile.txt");
	
	// Declare variables
	string name, unit;
	int quantity;

	// Use loop to read in the data from the File and
	// fill the dynamic arrays with the data.
	for (int i = 0; i < 3; i++) {
		InputFile >> name >> quantity >> unit;
		p[i].SetName(name);
		p[i].SetQuantity(quantity);
		p[i].SetUnit(unit);
	}
	
	// Create a table for the output
	cout << "Ingredient Report From File Data" << endl;
	cout << endl;
	cout << setw(12) << "Name";
	cout << setw(15) << "Quantity";
	cout << setw(25) << "Unit of Measurement" << endl;

	cout << setw(12) << "----";
	cout << setw(15) << "--------";
	cout << setw(25) << "-------------------" << endl;
	
	// Use a loop to read in the data from the dynamic arrays
	for (int i = 0; i < 3; i++) {
		cout << setw(12) << p[i].GetName();
		cout << setw(15) << p[i].GetQuantity();
		cout << setw(25) << p[i].GetUnit() << endl;
	}
	
	cout << endl;

	// Use delete for the dynamic array to avoid memory leaks
	delete [] p;

	return 0;
}
#pragma once
#include <iostream>
using namespace std;
//******************************************************************************
//	Class: Ingredient
//	
//	Purpose: This class uses private member variables name,
//			 quantity, and unit. In addition, the class has
//			 get/set methods, default constructor, copy
//			 constructor, constructors, deconstructor 
//			 Operator= overload, and Operator>> overload.
//
//******************************************************************************
class Ingredient {
	
//******************************************************************************
//	Operator Overload<<(Prototype): ostream& operator<<
//	
//	Purpose: This is a non-member function, which prints
//			 member variable data on the given ostream parameter.
//			
//******************************************************************************
	friend ostream& operator<< (ostream&, const Ingredient &);

	private:
		// Declare pointer variables
		string *name;
		int *quantity;
		string *unit_of_measurement;
	
	public:

//******************************************************************************
//	Default Construntor(Prototype): Ingredient()
//	
//	Purpose: Initiallize all variable with data
//			
//******************************************************************************
		Ingredient();

//******************************************************************************
//	Constructor(Prototype): Ingredient(string n, int q, string u)
//	
//	Purpose: A constructor that takes parameters for each
//			 member variable (Using normal variable as the
//			 parameters,not pointers).
//			
//******************************************************************************
		Ingredient(string n, int q, string u);

//******************************************************************************
//	Copy Constructor(Prototype):  Ingredient(const Ingredient& rhs)
//	
//	Purpose: A copy constructor that performs a deep
//			 copy of the other instance.			 			 
//			
//******************************************************************************
		Ingredient(const Ingredient& rhs);
		
//******************************************************************************
//	Destructor(Prototype): ~Ingredient()
//	
//	Purpose: A destructor that perform the neccessary cleanup.		
//			
//******************************************************************************
		~Ingredient();

//******************************************************************************
//	Get method (Prototype): GetName()
//	
//	Purpose: Gets the string name member variable
//			
//******************************************************************************
		string GetName();

//******************************************************************************
//	Set method (Prototype): SetName()
//	
//	Purpose: Set the string name member variable using a
//			 string parameter.
//			
//******************************************************************************
		void SetName(string n);
//******************************************************************************
//	Get method (Prototype): GetQuantity()
//	
//	Purpose: Gets the integer quantity member variable.
//			
//******************************************************************************		
		int GetQuantity();

//******************************************************************************
//	Set method (Definition): SetQuantity()
//	
//	Purpose: Set the quantity member variable using a integer
//			 parameter.
//			
//******************************************************************************
		void SetQuantity(int q);

//******************************************************************************
//	Get method (Prototype): GetUnit()
//	
//	Purpose: Gets the string unit_of_measurement member variable.
//			
//******************************************************************************
		string GetUnit();
		
//******************************************************************************
//	Set method (Prototype): SetUnit()
//	
//	Purpose: Set the unit member variable using a string parameter.
//			
//******************************************************************************
		void SetUnit(string u);

//******************************************************************************
//	Operator Overload (Prototype): operator=(const Ingredient& rhs)
//	
//	Purpose: A member function that performs a deep
//			 copy of the other instance.
//			
//******************************************************************************
		Ingredient& operator=(const Ingredient& rhs);

};
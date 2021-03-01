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
#include "Ingredient.h"

//******************************************************************************
//	Default Constructor(Definition): Ingredient()
//	
//	Purpose: Initiallize all variable with data
//			
//******************************************************************************
Ingredient::Ingredient() {
	name = new string;
	*name = "no_name";

	quantity = new int;
	*quantity = 0;

	unit_of_measurement = new string;
	*unit_of_measurement = "no_unit_measurement";

}

//******************************************************************************
//	Constructor(Definition): Ingredient(string n, int q, string u) 
//	
//	Purpose: A constructor that takes parameters for each
//			 member variable (Using normal variable as the
//			 parameters,not pointers).
//			
//******************************************************************************
Ingredient::Ingredient(string n, int q, string u) {
	name = new string;
	*name = n;
	quantity = new int;
	*quantity = q;
	unit_of_measurement = new string;
	*unit_of_measurement = u;
}

//******************************************************************************
//	Copy Constructor(Definition):  Ingredient(const Ingredient& rhs)
//	
//	Purpose: A copy constructor that performs a deep
//			 copy of the other instance.			 			 
//			
//******************************************************************************
Ingredient::Ingredient(const Ingredient& rhs) {
	name = new string;
	quantity = new int;
	unit_of_measurement = new string;
	*this = rhs;
}

//******************************************************************************
//	Destructor(Definition): ~Ingredient()
//	
//	Purpose: A destructor that perform the neccessary cleanup.		
//			
//******************************************************************************
Ingredient::~Ingredient() {
	delete name, quantity, unit_of_measurement;
}

//******************************************************************************
//	Get method (Definition): GetName()
//	
//	Purpose: Gets the string name member variable.
//			
//******************************************************************************
string Ingredient::GetName() {
	return *name;
}

//******************************************************************************
//	Set method (Prototype): SetName()
//	
//	Purpose: Set the string name member variable using a
//			 string parameter.
//			
//******************************************************************************
void Ingredient::SetName(string n) {
	*name = n;
}

//******************************************************************************
//	Get method (Definition): GetQuantity()
//	
//	Purpose: Gets the integer quantity member variable.
//			
//******************************************************************************
int Ingredient::GetQuantity() {
	return *quantity;
}

//******************************************************************************
//	Set method (Definition): SetQuantity()
//	
//	Purpose: Set the quantity member variable using a integer
//			 parameter.
//			
//******************************************************************************
void Ingredient::SetQuantity(int q) {
	*quantity = q;
}

//******************************************************************************
//	Get method (Definition): GetUnit()
//	
//	Purpose: Gets the string unit_of_measurement member variable.
//			
//******************************************************************************
string Ingredient::GetUnit() {
	return *unit_of_measurement;
}

//******************************************************************************
//	Set method (Definition): SetUnit()
//	
//	Purpose: Set the unit member variable using a string parameter.
//			
//******************************************************************************
void Ingredient::SetUnit(string u) {
	*unit_of_measurement = u;
}

//******************************************************************************
//	Operator Overload (Definition): operator=(const Ingredient& rhs)
//	
//	Purpose: A member function that performs a deep
//			 copy of the other instance.
//			
//******************************************************************************
Ingredient& Ingredient::operator=(const Ingredient& rhs){
	cout << "Operator= running" << endl;

	if (this == &rhs) {
		return *this;
	}

	*name = *rhs.name;
	*quantity = *rhs.quantity;
	*unit_of_measurement = *rhs.unit_of_measurement;
	return *this;
}

//******************************************************************************
//	Operator Overload<<: ostream& operator<< Definition
//	
//	Purpose: This is a non-member function, which prints
//			 member variable data on the given ostream parameter.
//			
//******************************************************************************
ostream& operator<< (ostream& out, const Ingredient& ingredient) {

	cout << "Operator<< running" << endl;
	out << *ingredient.name<< endl;
	out << *ingredient.quantity << endl;
	out << *ingredient.unit_of_measurement << endl;
	return out;
}
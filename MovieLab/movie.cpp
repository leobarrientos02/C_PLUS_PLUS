#include "Movie.h"
#include <iostream>
using namespace std;


Movie::Movie() {

	*name = "NO_NAME";
	*rating = "NO_RATING";
}

Movie::Movie(string n, string r) {
	
	name = new string;
	rating = new string;

	*name = n;
	*rating = r;
}

Movie::~Movie() {

	delete name;
	delete rating;
	name = nullptr;
	rating = nullptr;
	cout << "Destructor ran..." << endl;
}

string Movie::GetName() {

	return *name;
}

void Movie::SetName(string n) {
	
	*name = n;
}
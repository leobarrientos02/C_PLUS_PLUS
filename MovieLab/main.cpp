#include <iostream>
#include "Movie.h"

using namespace std;

int main() {

	cout << "LEO" << endl;
	Movie m; // calls default constructor
	Movie m2("John Wick", "R");

	m.SetName("LEO");
	cout << m.GetName() << endl;
	cout << m2.GetName() << endl;

	return 0;
}
#include <iostream>
#include "Functions.h"
using namespace std;

int main() {
	
	Address b[10];

	Address addr;
	addr.Number = "6400";
	addr.City = "Farmingdale";
	addr.State = "NY";
	addr.Zip = "11735";

	DisplayAddress(addr);

	/* int choice;

	cout << "Menu" << endl;
	cout << "1 - Print the word Yankees" << endl;
	cout << "2 - Print the word Mets" << endl;
	cout << "3 - Exit" << endl;
	cout << "Enter Choice: ";
	cin >> choice;

	while (choice != 3) {

		if (choice == 1) {
			cout << "Yankees" << endl;
		}
		if (choice == 2) {
			cout << "Mets" << endl;
		}
	}
	*/
	
}
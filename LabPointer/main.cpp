#include <iostream>
#include "Player.h"
#include <fstream>
using namespace std;

int main() {
	// Part 2
	Player leo;
	leo.setScore(50);
	leo.setName("leo");

	cout << leo.getName() << endl;
	cout << leo.getScore() << endl;


	// Part 3
	Player *p;
	int arraySize;
	cout << "What size would you like the Dynamic Array: ";
	cin >> arraySize;

	p = new Player[arraySize];

	cout << "Please enter the data for the arrays" << endl;

	int score, teamSize;
	string name;
	for (int i=0; i < arraySize; i++) {
		
		cout << "Enter Name for player " << i  << ":";
		cin >> name;
		p[i].setName(name);
		cout << "Enter Score for player " << i << ":";
		cin >> score;
		p[i].setScore(score);
		cout << endl;
	} 	
	/*string inputFile;
	ifstream inFile;
	cout << "Please enter fileName:";
	cin >> inputFile;
	inFile.open(inputFile);
	inFile >> teamSize >> name >> score;
	
	for(int i = 0; i < arraySize << i++ ) {
			
		p[i].setName(name);
		p[i].setScore(score);
	}
	*/
	
	delete [] p;
	p = nullptr;
	
	return 0;
}
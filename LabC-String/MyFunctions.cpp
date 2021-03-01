#include "MyFunctions.h"
#include <iostream>
using namespace std;

// declare functions
void print(char Array[]) {

	int i = 0;
	while (Array[i] != '\0'){

		cout << Array[i];
		i++;
	}

	cout << endl;
}

void copy(char target[], char source[]) {
	
	int i = 0;
	
	while (source[i] != '\0') {

		target[i] = source[i];
		i++;
	}

	target[i] = source[i];
}

void concat(char Array1[], char Array2[], char Array3[]) {

	int i = 0;

	while (Array1[i] != '\0') {

		Array3[i] == Array1[i] + Array2[i];

	}

	Array3[i] == Array1[i] + Array2[i];
}
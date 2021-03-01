#include <iostream>
#include "FindMyFunctions.h"
using namespace std;

int main() {

	//cout << "HI" << endl;

	double scores[] = { 40, 30, 66, 70, 60 };
	double max = FindMax(scores);
	cout << max << endl;

	int index = FindIndexofValues(scores, 70);
	cout << index;
	return 0;
}
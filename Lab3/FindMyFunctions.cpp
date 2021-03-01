#include "FindMyFunctions.h"

// Function defitions
double FindMax(double scores[]) {

	double Max;
	Max = scores[0];

	for (int i = 0; i < 5; i++) {

		if (scores[i] > Max) {

			Max = scores[i];
		}
	}



	return Max;
}

int FindIndexofValue(double scores[], int targetValue) {

	int index = 0;
	double maxValue = scores[0];

	for (int i = 0; i < 5; i++) {

		if (scores[i] > maxValue) {
			maxValue = scores[i];
		}
		index++;
	}
	return index;
}
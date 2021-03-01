#include "MyFunctions.h"

double Average(double monthlySales[]) {

	double total = 0;
	double avg = 0;

	for (int i = 0; i < 12; i++) {

		total += monthlySales[i];
		avg = total / 12;
	}

	return avg;
}
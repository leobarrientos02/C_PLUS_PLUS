#include <iostream>
#include "MyFunctions.h"
#include <iomanip>
using namespace std;


int main() {

	double sales[12] = {100,200,300,400,500,600,700,800,900,1000,1100,1200};

	double avg;
	avg = Average(sales);
	cout << avg << endl;

	return 0;
}
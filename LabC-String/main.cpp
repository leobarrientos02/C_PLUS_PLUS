#include <iostream>
#include "MyFunctions.h"
using namespace std;



int main() {

	char Array1[] = {'T', 'o', 'd', 'a', 'y','\0'};
	char Array2[] = { 'i','s','\0'};
	char Array3[]= { 'T','h','u','r','s','d','a','y','\0'};

	copy(Array1, Array2);

	//concat(Array1, Array2, Array3);

	print(Array1);
	print(Array2);
	print(Array3);

	return 0;
}
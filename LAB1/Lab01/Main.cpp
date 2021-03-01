#include <iostream>
#include <fstream>
#include "MyMath.h"
#include <iomanip>
using namespace std;


int main()
{
	//cout << "hello" << endl;
	int num1;
	int num2;
	int results;

	//cin >> num1;
	//cin >> num2;

	//read from a file
	ifstream infile;
	infile.open("MyInput.txt");
	infile >> num1;
	infile >> num2;

	//results = num1 * num2;
	results = multiply(num1, num2);

	//cout << results;
	
	//code under writes to the file ( << )
	ofstream outfile;
	outfile.open("output.txt");
	outfile << setw(10) << results;
	outfile << setw(10) << 100;
	outfile << setw(10) << 2000;

	return 0;
}


#pragma once
#include <string>
using namespace std;

class Movie
{

	private:
		string *name;
		string *rating;

	public:
		
		Movie();

		Movie(string n, string r);

		~Movie();

		string GetName();
		void SetName(string n);

};
#pragma once
#include <iostream>
using namespace std;

class Player {

	private:
		string name;
		int score;
	public:
		Player();
		~Player();
	
		string getName();
		void setName(string n);
		int getScore();
		void setScore(int a);

};
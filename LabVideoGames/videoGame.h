#pragma once
#include <iostream>

using namespace std;

enum RatingType { EVERYONE, EVERYONE10PLUS, TEEN, MATURE };
enum SystemType { XBOXONE, PLAYSTATION4, PC};

class VideoGame {
	
	// Attribute
	private:
		string Title;
		double Cost;
		RatingType Rating;
		SystemType System;
	
		// Behaivors
	public:
		string GetTitle();
		double GetCost();
		RatingType GetRating();
		SystemType GetSystem();

		void SetTitle(string newTitle);
		void SetCost(double newCost);
		void SetRating(RatingType newRating);
		void SetSystem( SystemType newSystem);
		
		// Default Constructors
		VideoGame() {
			Title = "none";
			Cost = 0;
			Rating = EVERYONE;
			System = PLAYSTATION4;
		}

		// Constructor
		VideoGame(string t, double c, RatingType r, SystemType s);

		//destructor
		~VideoGame();
};


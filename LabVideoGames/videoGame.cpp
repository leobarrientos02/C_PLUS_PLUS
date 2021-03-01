#include "videoGame.h"

// Function Definitions
string VideoGame::GetTitle() {
	return Title;
}

double VideoGame::GetCost() {
	return Cost;
}

RatingType VideoGame::GetRating() {
	return Rating;
}

SystemType VideoGame::GetSystem() {
	return System;
}

void VideoGame::SetTitle(string newTitle) {
	Title = newTitle;
}
void VideoGame::SetCost(double newCost) {
	Cost = newCost;
}
void VideoGame::SetRating(RatingType newRating) {
	Rating = newRating;
}
void VideoGame::SetSystem(SystemType newSystem) {
	System = newSystem;
}

// Constructor
VideoGame::VideoGame(string t, double c, RatingType r, SystemType s) {

	Title = t;
	Cost = c;
	Rating = r;
	System = s;
}

//destructor

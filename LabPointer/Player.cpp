#include "Player.h"

int Player::getScore() {
	return score;
}

string Player::getName() {
	return name;
}

void Player::setScore(int a) {

	score = a;
}

void Player::setName(string n) {
	name = n;
}

Player::Player() {
	name = "none";
	score = 0;
}

Player::~Player() {
	cout << "Destructor called...";
}


#include <iostream>
#include "videoGame.h"
using namespace std;

int main() {

	VideoGame vg;
	vg.SetTitle("COD");
	vg.SetCost(60);
	vg.SetRating(TEEN);
	vg.SetSystem(PLAYSTATION4);

	cout << vg.GetTitle() << endl;
	cout << vg.GetCost() << endl;
	cout << vg.GetRating() << endl;
	cout << vg.GetSystem() << endl;

	VideoGame vg2("GTA", 60, MATURE, XBOXONE);

	return 0;
}
// OOP 244 NHH 
// Name: Ritik Bheda
// student #: 169174182
// Date: 05/02/2020
/////////////////////////////

#include <iostream>
#include "Saiyan.h"
#include "Saiyan.h"  // this is on purpose

using namespace std;
using namespace sdds;

int main() {
	// constructors
	Saiyan s1("Goku", 1990, 23000);
	Saiyan s2, s3;
	Saiyan badData[] = {
	  Saiyan("Nappa", 2025, 1),
	  Saiyan("Nappa", 2018, -1),
	  Saiyan(nullptr, 2015, 1),
	  Saiyan("", 2018, 5),
	};

	cout << "Testing Saiyan objects" << endl << endl;

	// testing two invalid Saiyans
	s3.display();
	s2.display();

	cout << endl;

	// testing Valid Saiyan
	s1.display();

	// setting the second one to Vegeta
	s2.set("Vegeta", 1989, 22000);

	s2.display();

	// setting the Saiyan Goku to SuperSaiyan;
	s1.set("Goku", 1990, 23000, true);

	s1.display();

	// Checking hasLost;

	cout << "S1 attacking S2, Battle " << (!(s1.hasLost(s2)) ? "Won" : "Lost") << endl;

	cout << "S2 attacking S1, Battle " << (!(s2.hasLost(s1)) ? "Won" : "Lost") << endl;


	// making sure all the conditions are met for an inValid Saiyan.
	cout << endl << "None should be Valid:" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "index: " << i << " - " << (badData[i].isValid() ? "V" : "Not v") << "alid." << endl;
	}
	return 0;
}
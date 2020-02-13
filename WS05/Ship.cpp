// Name: Ritik Bheda
// Student #: 169174182
// OOP 244 LAB 5
// Date: 12/02/2020
/////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cstring>
#include"Ship.h"
using namespace std;
namespace sdds {
	// 0 argument constructor
	Ship::Ship() {
		shipName[0] = '\0';
		for_sorting = 0;
	}

	// 3 argument constructor 
	Ship::Ship(const char* name, Engine* eng_obj, int eng) {
		setEmpty();
		set(name, eng_obj, eng);
	}
	// the function to set empty 
	void Ship::setEmpty() {
		shipName[0] = '\0';
		for_sorting = 0;
	}

	// the function to set the data members of the Engine class
	void Ship::set(const char* name, Engine* e, int size) {
		int lenght = strlen(name);
		if ((name != nullptr && name[0] != '\0' && lenght <= 6) && e != nullptr) {
			for (int i = 0; i < size; i++) {
				engine_obj[i] = e[i];
			}
			strncpy(shipName, name, lenght);

			this->shipName[lenght] = '\0';
			if (size > 0 && size <= 10)
				for_sorting = size;
		}
		else {
			setEmpty();
		}

	}

	// the function to check if the class object is empty or not
	bool Ship::empty() const {
		if ((shipName[0] == '\0') || for_sorting == 0) {
			
			return true;
		}
		else {
			return false;
		}
	}

	// the function used to calculate power
	float Ship::calculatePower() const {
		float power;
		double answer = 0;
		for (int i = 0; i < for_sorting; i++) {
			answer += engine_obj[i].get();
		}
		power = float(answer) * 5;
		return power;
	}

	// the function used to display the details of the class objects
	void Ship::display() const {
		if (empty() == false) {
			cout << shipName << "-" << fixed << setw(6);
			cout.precision(2);
			cout << calculatePower() << endl;
			for (int i = 0; i < for_sorting; i++) {
				cout << engine_obj[i].get() << "liters-";
				engine_obj[i].display();
				//cout << endl;
			}
		}
		else {
			cout << "No available data" << endl;
		}
	}

	// the member operator done as per the question
	Ship& Ship::operator+=(Engine e) {
		if (for_sorting >= 10 || shipName[0] == '\0') {
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
		}
		else {
			this->engine_obj[for_sorting++] = e;

		}
		return *this;
	}

	// to check if compare 2 ship object's power
	bool operator==(const Ship& p1, const Ship& p2) {
		if (p1.calculatePower() > p2.calculatePower() || p1.calculatePower() < p2.calculatePower()) {
			return false;
		}
		else {
			return true;
		}
	}

	// to compare ship's power to input
	bool operator<(const Ship& ship1, double compare) {
		if (ship1.calculatePower() < compare)
			return true;
		else
			return false;
	}
}
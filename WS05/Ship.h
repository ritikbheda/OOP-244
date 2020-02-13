// Name: Ritik Bheda
// Student #: 169174182
// OOP 244 LAB 5
// Date: 12/02/2020
/////////////////////////////////////////////

#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include"Engine.h"
const int MAX_NAME = 7;
using namespace std;

namespace sdds {
	class Ship {
		char shipName[7];
		int for_sorting;
		Engine engine_obj[10];
	public: 
		Ship();
		Ship(const char*, Engine*, int);
		void setEmpty();
		void set(const char* name, Engine*, int size);
		bool empty()const;
		float calculatePower() const;
		void display() const;
		Ship& operator+=(Engine e);
		friend bool operator==(const Ship&, const Ship&);


	};

	bool operator<(const Ship&, const double);
}
#endif // !SDDS_SHIP_H

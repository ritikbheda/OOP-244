// OOP 244 NHH 
// Name: Ritik Bheda
// student #: 169174182
// Date: 05/02/2020
/////////////////////////////


#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

#include <iostream>
#include <string>

using namespace std;

namespace sdds {

	const int MAX_NAME = 30;

	class Saiyan {
		char m_name[MAX_NAME + 1];
		int m_dob;
		int m_power;
		bool m_super;
	public:
		Saiyan() {
			this->setEmpty();
		}
		Saiyan(const char* name, int dob, int power) {
			this->set(name, dob, power, 0);
		}
		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, bool super = false);
		bool hasLost(const Saiyan&) const;

	};

}


#endif // !SDDS_SAIYAN_H
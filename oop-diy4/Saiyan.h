// OOP 244 NHH DIY
// Name: Ritik Bheda
// student #: 169174182
// Date: 06/02/2020
/////////////////////////////


#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

namespace sdds {

	const int MAX_NAME = 30;

	class Saiyan {
		char* m_name;
		int m_dob;
		int m_power;
		bool m_super;
		int m_level = 0;
	public:
		Saiyan() {
			this->setEmpty();
		}
		Saiyan(const char* name, int dob, int power) {
			this->set(name, dob, power);
		}
		~Saiyan() {
			m_name = nullptr;
			delete[] m_name;
			
		}
		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool hasLost(Saiyan& other);
		void powerup();

	};

}


#endif // !SDDS_SAIYAN_H

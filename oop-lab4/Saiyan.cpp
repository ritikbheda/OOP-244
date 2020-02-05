// OOP 244 NHH 
// Name: Ritik Bheda
// student #: 169174182
// Date: 05/02/2020
/////////////////////////////

#include "Saiyan.h"

using namespace std;

namespace sdds {
	
	bool Saiyan::isSuper() const {
		return m_super; 
	}

	bool Saiyan::isValid() const {
		if (m_name == nullptr || m_name[0] == '\0' || m_dob > 2020 || m_power < 0) {
			return false;
		}
		else {
			return true;
		}
	}

	void Saiyan::setEmpty() {
		m_name[0] = '\0';
		m_dob = 0;
		m_power = 0;
		m_super = false;
	}

	void Saiyan::display() const{
		if (this->isValid()) {
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;
			cout << "Super Saiyan Ability: ";
			cout << ((m_super == 1) ? "Super Saiyan" : "Not super Saiyan") << endl << endl;
		}
		else {
			cout << "Invalid Saiyan!" << endl;
		}
	}

	void Saiyan::set(const char* name, int dob, int power, bool super) {
		
		if (name == nullptr || strlen(name) == 0 || dob > 2020 || power < 0) {
			
			m_name[0] = '\0';
			m_dob = 0;
			m_power = 0;
			m_super = super;

		}
		else {
			strcpy_s(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
	}

	bool Saiyan::hasLost(const Saiyan& other) const {
		if (this->isValid() && other.isValid()) {
			if (m_power > other.m_power) {
				return false;
			}
			else {
				return true; 
			}
		}
		else {
			return false;
		}
	}
}
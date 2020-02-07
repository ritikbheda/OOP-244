// OOP 244 NHH DIY
// Name: Ritik Bheda
// student #: 169174182
// Date: 06/02/2020
/////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
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
		
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_super = false;
	}

	void Saiyan::display() const {
		if (this->isValid()) {
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;
			cout << "Super Saiyan Ability: ";
			if (m_super == 1) {
				cout << "Super Saiyan." << endl<< "Super Saiyan level is: "<<m_level<<endl;
			}
			else {
				cout << "Not super Saiyan." << endl << endl;
			}
		}
		else {
			cout << "Invalid Saiyan!" << endl;
		}
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {

		if (name == nullptr || strlen(name) == 0 || dob > 2020 || power < 0) {

			m_name = nullptr;
			m_dob = 0;
			m_power = 0;
			m_super = super;
			m_level = 0;
		}
		else { 
			m_name = new char[strlen(name)];
			strcpy(this->m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
			m_level = level;
		}
	}

	bool Saiyan::hasLost( Saiyan& other)  {
		if (this->isValid() && other.isValid()) {

			this->powerup();
			other.powerup();

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

	void Saiyan::powerup() {
		if (m_super) {
			m_power *= (m_level + 1);
		}
	}
}

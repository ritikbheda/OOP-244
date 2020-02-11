// OOP 244 NHH DIY
// Name: Ritik Bheda
// student #: 169174182
// Date: 10/02/2020
/////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Saiyan.h"


using namespace std;

namespace sdds {
	
	// 0 argument constructor used to set to safe empty state
	Saiyan::Saiyan() {
		this->setEmpty();
	}
	
	// the 3argument constroctor calls the set function to set the values
	Saiyan::Saiyan(const char* name, int dob, int power) {
		this->set(name, dob, power);
	}

	// the destructor the deletes the function 
	Saiyan::~Saiyan() {
		delete[] m_name;
		m_name = nullptr;
		
	}

	// teh function used to return m_super
	bool Saiyan::isSuper() const {
		return m_super;
	}

	// the function to check whether the function is valid or not 
	bool Saiyan::isValid() const {
		if (m_name == nullptr || m_name[0] == '\0' || m_dob > 2020 || m_power < 0) {
			return false;
		}
		else {
			return true;
		}
	}

	// the function used to set safe Empty state
	void Saiyan::setEmpty() {
		
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_super = false;
		m_level = 0;
	}

	// the function used to display the meber variables if they are valid 
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
	
	// the function sets the member variables
	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {

		if (name == nullptr || strlen(name) == 0 || dob > 2020 || power < 0) {

			setEmpty();
		
		}
		else {
			if (m_name == nullptr){

				m_name = new char[strlen(name) + 1];
			}
			strcpy(this->m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
			if (level >= 0 && m_super) {
				m_level = level;

			}
		}
	}

	// the function to check who has lost of the two operators 
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

	// the function to powerup the m_power if m_super is valid
	void Saiyan::powerup() {
		if (m_super) {
			m_power *= (m_level + 1);
		}
	}
}

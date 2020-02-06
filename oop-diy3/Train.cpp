// Name: Ritik Bheda
// username: rnbheda
// student #: 169174182
// OOP 244 DIY 3



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Train.h"
using namespace std;

namespace sdds {


	// function used to return description which cannot be accessed directly because it is private
	const char* Cargo::getDesc() const {
		return description;
	}
	// same concept and logic like the decription that is to access the weight
	double Cargo::getWeight() const {
		return weight;
	}

	// the function to set the description to the class which me input from the user,
	//we need a function because it cannot be accessed directly as it is in the private
	void Cargo::setDesc(const char* desc) {
		strcpy(description, desc);
	}

	// same logic and concept like the description 
	void Cargo::setWeight(double weight) {
		this->weight = weight;
	}

	// the function to set the class's data members
	void Cargo::init(const char* desc, int weight) {
		if (strlen(desc) <= MAX_DESC + 1)
			setDesc(desc);
		else
			setDesc("\0");

		if (weight >= MIN_WEIGHT && weight <= MAX_WEIGHT)
			setWeight(weight);
		else
			setWeight(MIN_WEIGHT);
	}

	// function to set the train value( name and id)
	void Train::setTrain(const char* name, int id) {

		if ((name == nullptr) || (strcmp(name, "\0") == 0))
			strcpy(this->name, "\0");
		else
			strcpy(this->name, name);

		if (id < 1)
			this->id = 0;
		else
			this->id = id;

		cargo = nullptr;
	}

	// function to check if the train is empty or not  
	bool Train::isEmpty() const {
		if ((strcmp(name, "\0") == 0) || (id == 0))
			return true;
		return false;
	}

	// function used to display all the details of the train
	void Train::display() const {
		cout << "***Train Summary***" << endl;

		if (isEmpty())
			cout << "This is an empty train." << endl;
		else {
			cout << "Name: " << name << " ID: " << id << endl;

			if (cargo == nullptr)
				cout << "No cargo on this train." << endl;
			else {
				cout << fixed << setprecision(2);
				cout << "Cargo: " << cargo->getDesc() << " Weight: " << cargo->getWeight() << endl;
			}
		}
	}

	// the function used to load the cargo
	void Train::loadCargo(Cargo cargo) {
		this->cargo = new Cargo;
		this->cargo->setDesc(cargo.getDesc());
		this->cargo->setWeight(cargo.getWeight());
	}

	// function to unload the cargo
	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}

	// the function to swap the Cargo the data members
	bool Train::swapCargo(Train& that) {
		bool swapped;
		if (cargo == nullptr || that.cargo == nullptr)
			swapped = false;
		else {
			Cargo* temp = cargo;
			cargo = that.cargo;
			that.cargo = temp;
			swapped = true;
		}
		return swapped;
	}

	// the function to increase the cargo weight
	bool Train::increaseCargo(double incr) {
		bool increased;
		if (cargo == nullptr || cargo->getWeight() == MAX_WEIGHT)
			increased = false;
		else {
			if (cargo->getWeight() + incr > MAX_WEIGHT)
				cargo->setWeight(MAX_WEIGHT);
			else
				cargo->setWeight(cargo->getWeight() + incr);

			increased = true;

		}
		return increased;
	}

	// the function to decrease the cargo weight
	bool Train::decreaseCargo(double decr) {
		bool decreased;
		if (cargo == nullptr || cargo->getWeight() == MIN_WEIGHT)
			decreased = false;
		else {
			if (cargo->getWeight() - decr < MIN_WEIGHT)
				cargo->setWeight(MIN_WEIGHT);
			else
				cargo->setWeight(cargo->getWeight() - decr);
			decreased = true;
		}
		return decreased;
	}
}
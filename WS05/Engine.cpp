// Name: Ritik Bheda
// Student #: 169174182
// OOP 244 LAB 5
// Date: 12/02/2020
/////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cctype>
//#include <iomanip>
//#include <sstream>
#include <cstring>
#include"Engine.h"
using namespace std;
namespace sdds {

	// the 0 argument constructor
	Engine::Engine() {
		engine_type[0] = '\0';
		engine_size = 0;
	}

	// the 2 srgument constructor
	Engine::Engine(const char* name, double size) {
		setEmpty();
		set(name, size);
	}

	// to set the data members to safe empty state
	void Engine::setEmpty() {
		engine_type[0] = '\0';
		engine_size = 0;
	}

	// the function to set the data members of the class engine
	void Engine::set(const char* name, double size) {
		
		if ((name != nullptr && name[0] != '\0') && size > 0) {
			int lenght = strlen(name);
			strncpy(this->engine_type, name, lenght);
			strncpy(engine_type, name, lenght);
			this->engine_type[lenght] = '\0';
			this->engine_size = size;
		}
		else {
			setEmpty();
		}

	}

	// to return engine_size 
	double Engine::get() const {
		double answer = engine_size;
		return answer;
	}

	// to display the engine contents
	void Engine::display() const {
		cout << engine_type << endl;
	}
}
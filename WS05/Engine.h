// Name: Ritik Bheda
// Student #: 169174182
// OOP 244 LAB 5
// Date: 12/02/2020
/////////////////////////////////////////////
#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H
const int MAX_TYPE = 30;

namespace sdds
{

	class Engine {
		double engine_size;
		char engine_type[MAX_TYPE + 1];
	public:
		Engine();
		Engine(const char*, double);
		void setEmpty();
		void set(const char* name, double size);
		double get() const;
		void display() const;
	};

};

#endif
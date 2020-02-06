// Name: Ritik Bheda
// username: rnbheda
// student #: 169174182
// OOP 244 DIY 3


#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {

	const int MAX_NAME = 30; 
	const int MAX_DESC = 20;
	const double MAX_WEIGHT = 700.555;
	const double MIN_WEIGHT = 40.444;

	class Cargo {
		char description[MAX_DESC + 1];
		double weight;

	public:		
		const char* getDesc() const;
		
		double getWeight() const;
		
		void setDesc(const char* desc);
		
		void setWeight(double weight);
		
		void init(const char* desc, int weight);
	};

	class Train {
		char name[MAX_NAME + 1]; 
		int id; 
		Cargo* cargo;

	public:
		void setTrain(const char* name, int id);
		
		bool isEmpty() const;
		
		void display() const;
		
		void loadCargo(Cargo cargo);
		
		void unloadCargo();
		
		bool swapCargo(Train& that);
		
		bool increaseCargo(double incr);
		
		bool decreaseCargo(double decr);
	};

}

#endif
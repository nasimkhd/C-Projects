
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

	struct Population {
		char* postalCode;
		int Number;
	};
	
	void sort();
	bool load(Population& rec);
	bool load(const char filename[]);
	void display(Population inf, int i);
	void display();
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_
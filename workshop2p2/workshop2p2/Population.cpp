
#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {

    int numOfRecords;
    Population* population;

    void sort() {
        int i, j;
        Population temp;
        for (i = numOfRecords - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].Number > population[j + 1].Number) {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population& rec) {
        bool ok = false;
        char name[128];
        if (read(name)) {
            if (read(rec.Number)) {
                rec.postalCode = new char[strLen(name) + 1];
                strCpy(rec.postalCode, name);
                ok = true;
            }
            else ok = false;
        }
        return ok;
    }

	bool load(const char filename[]) {
		bool ok = false;
		int i = 0;
		if (openFile(filename)) {
            numOfRecords = noOfRecords();
            population = new Population[numOfRecords];
            while (load(population[i])) {
                i++;
            }
            if (i != numOfRecords) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            else {
                ok = true;
            }
            closeFile();
		}
        else {
            cout << "Could not open data file: " << filename << endl;
        }
        return ok;
	}

    void display(Population inf, int i) {
        cout << i << "- " << inf.postalCode << ":  " << inf.Number << endl;

    }

    void display() {
        sort();
        int i, sum = 0;;
        cout << "Postal Code: population\n" <<
            "-------------------------\n";
        for (i = 0; i < numOfRecords; i++) {
            display(population[i], i + 1);
            sum += population[i].Number;
        }
        cout << "-------------------------\n" << "Population of Canada: " << sum << endl;
    }
    void deallocateMemory() {
        for (int i = 0; i < numOfRecords; i++) {

            delete[] population[i].postalCode;
            population->postalCode = nullptr;
        }
        delete[] population;
        population = nullptr;
    }

}
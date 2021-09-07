//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 3: part 2
// Email: nkhodapanah@myseneca.ca
// Date: 6/8/2021
/////////////////////////////////

#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"
namespace sdds {
    class CalorieList
    {
        Food* m_items;
        int m_noOfItems;
        int itemsAdded;
        int size;
        int totalCal()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(int size);
        bool add(const char* item_name, int calories, int when);
        void display()const;
        void deallocate();
    };
}
#endif //SDDS_CALORIELIST_H
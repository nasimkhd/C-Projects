//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 4: part 1
// Email: nkhodapanah@myseneca.ca
// Date: 2021/6/14
/////////////////////////////////
#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds {
    class Canister {

        char* m_contentName;


        double m_diameter; // in centimeters 
        double m_height;   // in centimeters
        double m_contentVolume;  // in CCs
        bool m_usable;


        void setToDefault();
        void setName(const char* Cstr);
        bool isEmpty()const;
        bool hasSameContent(const Canister& C)const;
        bool isUnusable()const;
        void setUnusable();

    public:
        Canister();
        Canister(const char* contentName);
        Canister(double height, double diameter,
            const char* contentName = nullptr);
        ~Canister();

        
        Canister& setContent(const char* contentName);
        Canister& pour(double quantity);
        Canister& pour(Canister& C);
        double volume()const;
        std::ostream& display()const;
        double capacity()const;
        void clear();
    };
}

#endif // !SDDS_BOX_H
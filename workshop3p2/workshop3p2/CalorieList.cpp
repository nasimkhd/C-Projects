
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds
{
    int CalorieList::totalCal() const
    {
        int i;
        int totalPrice = 0;
        for (i = 0; i < itemsAdded; i++) {
            totalPrice += m_items[i].calNumber();
        }
        return totalPrice;
    }
    void CalorieList::Title() const
    {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }
    void CalorieList::footer() const
    {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid())
        {
            cout << "|    Total Calories for today: ";
            cout.width(8);
            cout << totalCal();
            cout << " | ";
            cout.width(12);
            cout << "|" << endl;
        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }
    void CalorieList::setEmpty()
    {
        m_items = nullptr;
    }
    bool CalorieList::isValid() const
    {
        int i;
        bool valid = true;
        if ( m_items == nullptr) {
            valid = false;
        }
        for (i = 0; i < m_noOfItems; i++) {
            if (!m_items[i].isValid()) {
                valid = false;
            }
        }
        return valid;
        return false;
    }
    void CalorieList::init(int noOfFoods)
    {
        if ( noOfFoods <= 0)
        {
            setEmpty();
        }
        else
        {
            m_noOfItems = noOfFoods;
            itemsAdded = 0;
            m_items = new Food[noOfFoods];

            for (int i = 0; i < m_noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
       
    }

    bool CalorieList::add(const char* item_name, int calories, int when)
    {
        bool valid = false;
        if (itemsAdded < m_noOfItems)
        {
            m_items[itemsAdded].set(item_name, calories, when);
            itemsAdded++;
            valid = true;
        }
        return valid;
    }

    void CalorieList::display() const
    {
        int i;

        Title();

        for (i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }

        footer();
    }

    void CalorieList::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }

}

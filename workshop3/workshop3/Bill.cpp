
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds
{
	double Bill::totalTax() const
	{
		int i;
		double sumOfTax = 0.0;
		for (i = 0; i < m_itemsAdded; i++)
		{
			sumOfTax += m_items[i].tax();
		}
		return sumOfTax;
	}
	double Bill::totalPrice() const
	{
		int i;
		double totalPrice = 0.0;
		for (i = 0; i < m_itemsAdded; i++)
		{
			totalPrice += m_items[i].price();
		}
		return totalPrice;
	}
	void Bill::Title() const
	{
		cout << "+--------------------------------------+" << endl;
		if (isValid())
		{
			cout << "| ";
			cout.width(36);
			cout.setf(ios::left);
			cout << m_title;
			cout << " |" << endl;
			cout.unsetf(ios::left);
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}
	void Bill::footer() const
	{
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid())
		{
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.setf(ios::right);
			cout << totalTax();
			cout << " |" << endl;
			cout.precision(2);
			cout << "|              Total Price: ";
			cout.width(10);
			cout << totalPrice();
			cout << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout << totalPrice() + totalTax();
			cout << " |" << endl;
			cout.unsetf(ios::right);
			cout.precision(6);
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}
	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}
	bool Bill::isValid() const
	{
		int i;
		bool valid = true;
		if (m_title[0] == '\0' || m_items == nullptr) {
			valid = false;
		}
		for (i = 0; i < m_noOfItems; i++) {
			if (!m_items[i].isValid()) {
				valid = false;
			}
		}
		return valid;
	}

	void Bill::init(const char* title, int noOfItems)
	{
		if (m_title == NULL || noOfItems <= 0)
		{
			setEmpty();
		}
		else
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;

			strnCpy(m_title, title, 36);
			m_items = new Item[noOfItems];

			for (int i = 0; i < m_noOfItems; i++)
			{
				m_items[i].setEmpty();
			}
		}
	}
	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		bool valid = false;
		if (m_itemsAdded < m_noOfItems)
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			valid = true;
		}
		return valid;
	}
	void Bill::display() const
	{
		int i;

		Title();

		for (i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}

		footer();
	}
	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}

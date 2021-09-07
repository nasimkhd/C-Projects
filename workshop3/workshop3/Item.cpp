

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds
{

	void Item::setName(const char* name)
	{
		strnCpy(m_itemName, name, 20);
	}

	void Item::setEmpty()
	{

		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed)
	{
		if (price < 0 || name == nullptr)
		{
			setEmpty();
		}
		else
		{
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	void Item::display() const
	{
		if (isValid())
		{

			cout << "| ";
			cout.width(20);
			cout.fill('.');
			cout.setf(ios::left);
			cout << m_itemName;
			cout.unsetf(ios::left);
			cout << " | ";
			cout.fill(' ');
			cout.width(7);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_price;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
			cout << " | " << (m_taxed == true ? "Yes" : "No ") << " |" << endl;
			cout.precision(6);
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}

	bool Item::isValid() const
	{
		bool valid = false;

		if (m_price != 0.0 && m_itemName[0] != '\0')
		{

			valid = true;
		}
		return valid;
	}

	double Item::price() const
	{
		return m_price;
	}

	double Item::tax() const
	{
		double rate = 0.0;
		const double tax = 0.13;

		if (m_taxed == true)
		{

			rate = tax * m_price;
		}
		else
		{
			rate = 0.0;
		}

		return rate;
	}

}

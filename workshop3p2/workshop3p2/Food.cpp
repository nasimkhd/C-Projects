
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds
{

	void Food::setName(const char* name)
	{
		strnCpy(foodName, name, 30);
	}

	void Food::setEmpty()
	{

		calNum = 0;
		foodName[0] = '\0';
	}

	void Food::set(const char* foodName, int calNumber, int FoodCode)
	{
		if (calNumber < 0 || foodName == nullptr)
		{
			setEmpty();
		}
		else
		{
			setName(foodName);
			calNum = calNumber;
			foodCode = FoodCode;

		}
	}

	void sdds::Food::display() const
	{
		if (isValid()) {
			cout << "| ";
			cout.width(30);
			cout.fill('.');
			cout.setf(ios::left);
			cout << foodName;
			cout.unsetf(ios::left);
			cout << " | ";
			cout.fill(' ');
			cout.width(4);
			cout.setf(ios::right);
			cout << calNum;
			cout.unsetf(ios::right);
			cout << " | ";
			cout.width(9);
			cout.setf(ios::left);
			if (foodCode == 1)
				cout << "Breakfast";
			else if (foodCode == 2)
				cout << "Lunch";
			else if (foodCode == 3)
				cout << "Dinner";
			else if (foodCode == 4)
				cout << "Snack";
			else
				cout << "Invalid!";
			cout.unsetf(ios::left);
			cout.width(3);
			cout << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

	bool Food::isValid() const
	{
		bool valid = false;

		if (calNum != 0 && foodName[0] != '\0' && foodCode != 0)
		{

			valid = true;
		}
		return valid;
	}

	int Food::calNumber() const
	{
		return calNum;
	}
}

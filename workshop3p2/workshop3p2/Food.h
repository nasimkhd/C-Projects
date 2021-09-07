//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 3: part 2
// Email: nkhodapanah@myseneca.ca
// Date: 6/8/2021
/////////////////////////////////

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
	class Food
	{
		char foodName[30];
		int calNum;
		int foodCode;
		void setName(const char* name);
	public:
		void setEmpty();
		void set(const char* foodName, int calNumber, int FoodCode);
		void display()const;
		bool isValid()const;
		int calNumber()const;
	};
}
#endif //SDDS_FOOD_H_


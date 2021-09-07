//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 4: part 2
// Email: nkhodapanah@myseneca.ca
// Date: 2021/6/15
/////////////////////////////////
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>

namespace sdds {
	class Label {

		char* m_content;
		

	public:
		char frame[9];
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
	};
}
#endif //SDDS_LABEL_H
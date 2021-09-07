//Name: Nasim Khodapanah
// //Student ID: 131929200
// Workshop 4: part 2
// Email: nkhodapanah@myseneca.ca
// Date: 2021/6/15
/////////////////////////////////
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"
namespace sdds {
	class LabelMaker {

		Label* m_labels;
		char* labels;
		int numOfLabels;

	public:

		LabelMaker(int noOfLabels);
		~LabelMaker();
		LabelMaker& readLabels();
		LabelMaker& printLabels();
		
	};
}
#endif //SDDS_LABELMAKER_H
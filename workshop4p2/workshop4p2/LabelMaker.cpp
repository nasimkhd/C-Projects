

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"

using namespace std;
namespace sdds {
	sdds::LabelMaker::LabelMaker(int noOfLabels)
	{
        m_labels = new Label[noOfLabels];
        numOfLabels = noOfLabels;
	}

	sdds::LabelMaker::~LabelMaker()
	{

		delete[] m_labels;
		m_labels = nullptr;
	}

	LabelMaker& LabelMaker::readLabels()
	{
		cout << "Enter " << numOfLabels << " labels:" << endl;
		for (int i = 0; i < numOfLabels; i++) {
			cout << "Enter label number " << i+1 << endl <<"> ";
            m_labels[i].readLabel();
		}
		return *this;
	}

	LabelMaker& LabelMaker::printLabels()
	{
		int i;
		for (i = 0; i < numOfLabels; i++) {
			m_labels[i].printLabel();
			cout << endl;
		}
		return *this;
	}
}

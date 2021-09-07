

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "cstring.h"
#include "Label.h"

using namespace std;
namespace sdds {
    sdds::Label::Label()
    {
        strCpy(frame, "+-+|+-+|");
        m_content = nullptr;
    }

    sdds::Label::Label(const char* frameArg)
    {
        m_content = nullptr;
        strCpy(frame, frameArg);
    }

    sdds::Label::Label(const char* frameArg, const char* content)
    {
        strCpy(frame, frameArg);
        m_content = new char[strLen(content) + 1];
        strCpy(m_content, content);
    }

    sdds::Label::~Label()
    {
            delete[] m_content;
            m_content = nullptr;
    }

    void sdds::Label::readLabel()
    {
        char name[70 + 1];
        cin.get(name, 71, '\n');
        while (cin.get() != '\n');
        if (m_content == nullptr) {
            m_content = new char[71];
        }
        strCpy(m_content, name);
    }

    std::ostream& sdds::Label::printLabel() const
    {
        int l;
        if (m_content == nullptr) {
            cout << "";
        }
        else {
            l = strlen(m_content);

            cout << frame[0];
            cout.width(l + 2);
            cout.fill(frame[1]);
            cout << frame[1];
            cout << frame[2] << endl;

            cout << frame[7];
            cout.width(l + 3);
            cout.fill(' ');
            cout << frame[3] << endl;

            cout << frame[7] << " ";
            cout.width(l);
            cout.setf(ios::left);
            cout << m_content << " ";
            cout.fill(' ');
            cout << frame[3] << endl;
            cout.unsetf(ios::left);

            cout << frame[7];
            cout.width(l + 3);
            cout.fill(' ');
            cout << frame[3] << endl;

            cout << frame[6];
            cout.width(l + 2);
            cout.fill(frame[5]);
            cout << frame[5];
            cout << frame[4];
        }
            return cout;
    }
   
}

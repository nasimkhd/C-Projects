
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {
	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
	}
	void Canister::setName(const char* Cstr)
	{
		if (!isUnusable()) {
			if (Cstr != nullptr)
			{
				if (m_contentName != nullptr)
				{
					delete[] m_contentName;
				}
				m_contentName = new char[strLen(Cstr) + 1];
				strCpy(m_contentName, Cstr);
			}
		}

	}

	bool Canister::isEmpty() const
	{
		bool flag = false;
		if (m_contentVolume < 0.00001) 
		{
			flag = true;
		}
		return flag;
	}

	bool Canister::isUnusable()const {
		bool flag = false;
		if (m_height < 10 || m_height > 40 || m_diameter < 10
			|| m_diameter > 30 || m_contentVolume == -1)
		{
			flag = true;
		}
		return flag;
	}

	void Canister::setUnusable() 
	{
		if (m_contentName != nullptr)
			delete[] m_contentName;
		m_contentName = nullptr;
		
		m_contentVolume = -1;
		
	}

	bool Canister::hasSameContent(const Canister& C) const
	{
		bool flag = true;
		if (strCmp(C.m_contentName, m_contentName) == 0 &&
			C.m_contentName != nullptr && m_contentName != nullptr)
		{
			flag = true ;
		}
		else flag = false;
		return flag;
	}

	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter,
		const char* contentName )
	{
		setToDefault();
		m_contentName = nullptr;
		if (height < 10 || height > 40 || diameter < 10
			|| diameter > 30)
		{
			setUnusable();
		}
		else {
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0;
			setName(contentName);
		}
	}

	Canister::~Canister()
	{
		delete[] m_contentName;
	}

	Canister& Canister::setContent(const char* contentName)
	{
		if (contentName == nullptr) 
		{
			setUnusable();

		}
		else if (isEmpty()) 
		{
			setName(contentName);
		}
		else if (m_contentName != contentName)
		{
			setUnusable();
			}

		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if (quantity > 0 && (quantity + volume()) <= capacity() &&
			!isUnusable()) {
			m_contentVolume += quantity;
		}
		else {
			setUnusable();
		}
		return *this;
	}
	Canister& Canister::pour(Canister& C)
	{
		if (m_contentName == nullptr || volume() == 0)
		{
			setContent(C.m_contentName);
		}
		if (hasSameContent(C.m_contentName)) {
			if (C.volume() > capacity() - volume())
			{
				C.m_contentVolume -= (capacity() - volume());
				m_contentVolume = capacity();
			}
			else {
				pour(C.m_contentVolume);
				C.m_contentVolume = 0;
			}
		}
		else {
			if (C.volume() > capacity() - volume()) {
				C.m_contentVolume -= (capacity() - volume());
			}
			else {
				C.m_contentVolume = 0;
			}
			setUnusable();
		}
		return *this;
	}

	double Canister::volume() const
	{
		return m_contentVolume;
	}

	std::ostream& Canister::display() const
	{
		cout.width(7);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << capacity() << "cc (" << m_height 
			<< "x" << m_diameter << ") Canister";
		if (isUnusable()) {
			cout << " of Unusable content, discard!";
		}if (m_contentName != nullptr) {
			cout << " of ";
			cout.width(7);
			return cout << m_contentVolume << "cc   " << m_contentName;

		}
		return cout;
	}

	double Canister::capacity() const
	{
		double PI = 3.14159265;
		double capacity = 0.0;
		capacity = PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
		return capacity;
	}
	void Canister::clear()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		setToDefault();

	}
}

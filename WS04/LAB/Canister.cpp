//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       4 (LAB)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================


#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

	const double PI = 3.14159265;

	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	bool Canister::isEmpty()const {
		return m_contentVolume < 0.00001 ? true : false;
	}
	bool Canister::hasSameContent(const Canister& C)const {
		return strCmp(m_contentName, C.m_contentName) && m_contentName != nullptr ? true : false;
	}
	void Canister::setName(const char* Cstr) {
		if (Cstr != nullptr && m_usable == true) {
			delete[] m_contentName;
			m_contentName = nullptr;
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}
	}
	Canister::Canister() {
		setToDefault();
	}
	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}
	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();
		if (height >= 10.0 && diameter >= 10.0 && height <= 40.0 && diameter <= 30.0) {
			m_height = height;
			m_diameter = diameter;
			setName(contentName);
		} else {
			m_usable = false;
		}
	}
	Canister::~Canister() {
		delete[] m_contentName;
	}
	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}
	double Canister::capacity()const {
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}
	double Canister::volume()const {
		return m_contentVolume;
	}
	Canister& Canister::setContent(const char* contentName) {
		if (contentName == nullptr) {
			m_usable = false;
		} else if (isEmpty()) {
			setName(contentName);
		} else if (strCmp(m_contentName, contentName)) {
			m_usable = false;
		}
		return *this;
	}
	Canister& Canister::pour(double quantity) {
		if (m_usable == true && quantity > 0 && (quantity + volume()) <= capacity()) {
			m_contentVolume += quantity;
		} else {
			m_usable = false;
		}
		return *this;
	}
	Canister& Canister::pour(Canister& C) {
		setContent(C.m_contentName);
		if (C.m_contentVolume > (capacity() - volume())) {
			C.m_contentVolume -= (capacity() - volume());
			m_contentVolume = capacity();
		} else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}
		return *this;
	}
	std::ostream& Canister::display()const {
		cout << fixed << setw(7) << setprecision(1) << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable) {
			cout << " of Unusable content, discard!";
		} else if (m_contentName != nullptr) {
			cout << fixed << " of " << setw(7) << m_contentVolume << "cc   " << m_contentName;
		}
		return cout;
	}
}
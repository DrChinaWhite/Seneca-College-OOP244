//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       3 (LAB)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
	}
	void Item::setEmpty() {
		m_price = 0.0;
		*m_itemName = '\0';
	}
	void Item::set(const char* name, double price, bool taxed) {
		if (price < 0 || name == nullptr) {
			setEmpty();
		} else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}
	double Item::price()const {
		return m_price;
	}
	double Item::tax()const {
		const double taxRate = 0.13;
		if (m_taxed == true) {
			return m_price * taxRate;
		}
		return 0.0;
	}
	bool Item::isValid()const {
		return m_price != '\0' ? true : false;
	}
	void Item::display()const {
		bool valid = isValid();
		if (valid == true)
		{
			cout << "| ";
			cout.width(20);
			cout.fill('.');
			cout << left << m_itemName;
			cout << " | ";

			cout.width(7);
			cout << fixed;
			cout.fill(' ');
			cout << right << setprecision(2) << m_price;
			cout.fill(' ');
			cout << " | ";
			if (m_taxed == true) {
				cout << "Yes";
			} else {
				cout << "No ";
			}
			cout << " |" << endl;
		} else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}
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
#include "Bill.h"
using namespace std;
namespace sdds {

	void Bill::setEmpty() {
		*m_title = '\0';
		m_items = nullptr;
	}
	bool Bill::isValid()const {
		bool valid = false;
		if (*m_title != '\0' && m_items != nullptr) {
			for (int i = 0; i < m_noOfItems; i++) {
				if (m_items[i].isValid()) {
					valid = true;
				} else {
					valid = false;
				}
			}
		}
		return valid;
	}
	double Bill::totalTax()const {
		double totalTax = 0;
		for (int i = 0; i < m_noOfItems; i++) {
			totalTax += m_items[i].tax();
		}
		return totalTax;
	}
	double Bill::totalPrice()const {
		double totalPrice = 0;
		for (int i = 0; i < m_noOfItems; i++) {
			totalPrice += m_items[i].price();
		}
		return totalPrice;
	}
	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		bool valid = isValid();
		if (valid == true) {
			cout << "| ";
			cout.width(36);
			cout << left << m_title;
			cout << " |" << endl;
		} else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}
	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;
		bool valid = isValid();
		if (valid == true) {
			cout << "|                Total Tax: ";
			cout.width(10);
			cout << right << setprecision(2) << totalTax();
			cout << " |" << endl;
			cout << "|              Total Price: ";
			cout.width(10);
			cout << right << setprecision(2) << totalPrice();
			cout << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout << right << setprecision(2) << totalTax() + totalPrice();
			cout << " |" << endl;
		} else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}
	void Bill::init(const char* title, int noOfItems) {
		if (title == nullptr || noOfItems <= 0) {
			setEmpty();
		} else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}
	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool valid = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			valid = true;
		}
		return valid;
	}
	void Bill::display()const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}
	void Bill::deallocate() {
		delete[] m_items;
	}
}
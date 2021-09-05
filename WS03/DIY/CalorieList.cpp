//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       3 (DIY)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {

	int CalorieList::totalCalories()const {
		int totalCalories = 0;
		for (int i = 0; i < m_noOfItems; i++) {
			totalCalories += m_items[i].calorie();
		}
		return totalCalories;
	}
	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		bool valid = isValid();
		if (valid == true) {
			cout << "| ";
			cout.width(50);
			cout << left << " Daily Calorie Consumption";
			cout << " |" << endl;
		} else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}
	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		bool valid = isValid();
		if (valid == true) {
			cout << "|    Total Calories for today:";
			cout.width(9);
			cout << right << totalCalories();
			cout << " |            |" << endl;
		} else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}
	void CalorieList::setEmpty() {
		m_items = nullptr;
	}
	bool CalorieList::isValid()const {
		bool valid = true;
		if (m_items != nullptr) {
			for (int i = 0; i < m_noOfItems; i++) {
				if (!m_items[i].isValid()) {
					valid = false;
				}
			}
		}
		return valid;
	}
	void CalorieList::init(int noOfItems) {
		if (noOfItems <= 0) {
			setEmpty();
		} else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			m_items = new Food[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}
	bool CalorieList::add(const char* foodName, int calories, int when) {
		bool valid = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(foodName, calories, when);
			m_itemsAdded++;
			valid = true;
		}
		return valid;
	}
	void CalorieList::display()const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}
	void CalorieList::deallocate() {
		delete[] m_items;
	}
}
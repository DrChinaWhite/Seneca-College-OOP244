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
#include "Food.h"
using namespace std;
namespace sdds {

	void Food::setName(const char* name) {
		strnCpy(m_foodName, name, 30);
		m_foodName[30] = '\0';
	}
	void Food::convert()const {
		switch (m_mealCode) {
		case 1:
			cout << "Breakfast";
			break;
		case 2:
			cout << "Lunch";
			break;
		case 3:
			cout << "Dinner";
			break;
		case 4:
			cout << "Snack";
			break;
		}
	}
	void Food::setEmpty() {
		*m_foodName = '\0';
		m_calorie = 0;
		m_mealCode = 0;
	}
	void Food::set(const char* name, int calorie, int mealCode) {
		if (calorie < 0 || calorie >= 3000 || mealCode < 1 || mealCode > 4 || name == nullptr) {
			setEmpty();
		} else {
			setName(name);
			m_calorie = calorie;
			m_mealCode = mealCode;
		}
	}
	void Food::display()const {
		bool valid = isValid();
		if (valid == true)
		{
			cout << "| ";
			cout.width(30);
			cout.fill('.');
			cout << left << m_foodName;
			cout << " | ";

			cout.width(4);
			cout << fixed;
			cout.fill(' ');
			cout << right << m_calorie;
			cout.fill(' ');
			cout << " | ";
			cout.width(10);
			cout << left;
			convert();
			cout << " |" << endl;

		} else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
	bool Food::isValid()const {
		return *m_foodName != '\0' ? true : false;
	}
	int Food::calorie()const {
		return m_calorie;
	}
}
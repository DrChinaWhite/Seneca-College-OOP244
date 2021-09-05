//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       2 (MS)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Menu::Menu(const char* MenuContent, int NoOfSelections) {
		if (MenuContent && MenuContent[0] != '\0') {
			m_text = new char[strlen(MenuContent) + 1];
			strcpy(m_text, MenuContent);
		}
		NoOfSelections > 0 ? m_noOfSel = NoOfSelections : m_noOfSel = 0;
	}
	Menu::~Menu() {
		if (m_text) {
			delete[] m_text;
			m_text = nullptr;
		}
	}
	void Menu::display() const {
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}
	int& Menu::operator >> (int& Selection) {
		display();
		return Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");
	}
	Menu::Menu(const Menu& src) {
		this->m_noOfSel = src.m_noOfSel;
		if (src.m_text) {
			this->m_text = new char[strlen(src.m_text) + 1];
			strcpy(this->m_text, src.m_text);
		}
	}
}
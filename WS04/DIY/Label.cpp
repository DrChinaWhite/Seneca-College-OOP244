//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       4 (DIY)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Label.h"

using namespace std;
namespace sdds {
	void Label::setTitle(const char* content) {
		int length = strLen(content);
		title = nullptr;
		title = new char[length + 1];
		strCpy(title, content);
		if (content && length >= 70) {
			title[70] = '\0';
		}
	}
	Label::Label() {
		title = nullptr;
		strCpy(frame, "+-+|+-+|");
	}
	Label::Label(const char* frameArg) {
		title = nullptr;
		strCpy(frame, frameArg);
	}
	Label::Label(const char* frameArg, const char* content) {
		title = nullptr;
		setTitle(content);
		strCpy(frame, frameArg);
	}
	Label::~Label() {
		delete[] title;
	}
	void Label::readLabel() {
		string content;
		getline(cin, content);
		setTitle(content.c_str());
	}
	bool Label::isEmpty() {
		return title == nullptr ? true : false;
	}
	std::ostream& Label::printLabel()const {
		if (title && frame) {
			int labelLen = strLen(title) + 3;
			cout << frame[0] << setfill(frame[1]) << setw(labelLen) << frame[2] << endl;
			cout << frame[7] << setfill(' ') << setw(labelLen) << frame[3] << endl;
			cout << frame[7] << ' ' << title << ' ' << frame[3] << endl;
			cout << frame[7] << setfill(' ') << setw(labelLen) << frame[3] << endl;
			cout << frame[6] << setfill(frame[5]) << setw(labelLen) << frame[4];
			if (!strCmp(frame, "+-+|+-+|")) {
				cout << endl;
			}
		}
		return cout;
	}
}
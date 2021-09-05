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
#include "cstring.h"
#include "LabelMaker.h"

using namespace std;
namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		numOfLabels = noOfLabels;
		labels = new Label[noOfLabels];
	}
	void LabelMaker::readLabels() {
		cout << "Enter " << numOfLabels << " labels:" << endl;
		for (int i = 0; i < numOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl;
			cout << "> ";
			labels[i].readLabel();
		}
	}
	void LabelMaker::printLabels() {
		for (int i = 0; i < numOfLabels; i++) {
			labels[i].printLabel();
		}
	}
	LabelMaker::~LabelMaker() {
		delete[] labels;
	}
}
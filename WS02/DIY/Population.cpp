//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       2 (DIY)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include <iostream>
#include "cstring.h"
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {

	int noOfPostalCodes;
	int totalPop;
	Population* residents;

	void sort() {
		int i, j;
		Population temp;
		for (i = noOfPostalCodes - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (residents[j].m_population > residents[j + 1].m_population) {
					temp = residents[j];
					residents[j] = residents[j + 1];
					residents[j + 1] = temp;
				}
			}
		}
	}
	bool load(Population& residents) {
		bool ok = false;

		residents.m_postalCode = new char[3 + 1];
		if (read(residents.m_postalCode) && read(residents.m_population)) {
			ok = true;
		}
		return ok;
	}
	bool load(const char* DATAFILE) {
		bool ok = false;
		int i = 0;
		if (openFile(DATAFILE)) {
			noOfPostalCodes = noOfRecords();
			residents = new Population[noOfPostalCodes];
			for (i = 0; i < noOfPostalCodes; i++) {
				load(residents[i]);
				totalPop += residents[i].m_population;
			} if (i != noOfPostalCodes) {
				cout << "Error: incorrect number of records read; the data is possible corrupted" << endl;
			} else {
				ok = true;
			}
		} else {
			cout << "Could not open data file : " << DATAFILE << endl;
		}
		closeFile();
		return ok;
	}
	void display(const Population &residents) {
		cout << residents.m_postalCode << ":  " << residents.m_population << endl;
	}
	void display() {
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		sort();
		for (int i = 0; i < noOfPostalCodes; i++) {
			cout << i + 1 << "- ";
			display(residents[i]);
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << totalPop << endl;
	}
	void deallocateMemory() {
		for (int i = 0; i < noOfPostalCodes; i++) {
			delete[] residents[i].m_postalCode;
		}
		delete[] residents;
		residents = nullptr;
	}
}
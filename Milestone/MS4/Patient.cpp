//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       3 (MS)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Patient::Patient(int ticketNumber, bool fileIO) {
		m_ticket = ticketNumber;
		m_IOFlag = fileIO;
	}
	Patient::~Patient() {
		if (m_NameOfPatient) {
			delete[] m_NameOfPatient;
			m_NameOfPatient = nullptr;
		}
	}
	const bool Patient::fileIO() const {
		return m_IOFlag;
	}
	void Patient::fileIO(bool reset) {
		m_IOFlag = reset;
	}
	bool Patient::operator==(const char singleChar) const {
		return this->type() == singleChar;
	}
	bool Patient::operator==(const Patient& src) const {
		return this->type() == src.type();
	}
	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}
	Patient::operator Time() const {
		return Time(m_ticket);
	}
	int Patient::number() const {
		return m_ticket.number();
	}
	std::ostream& Patient::csvWrite(std::ostream& ostr) const {
		ostr << this->type() << ',' << m_NameOfPatient << ',' << m_NumOfOHIP << ',';
		m_ticket.csvWrite(ostr);
		return ostr;
	}
	std::istream& Patient::csvRead(std::istream& istr) {
		string temp;
		char delimiter;
		getline(istr, temp, ',');
		if (m_NameOfPatient) {
			delete[] m_NameOfPatient;
			m_NameOfPatient = nullptr;
		}
		m_NameOfPatient = new char[strlen(temp.c_str()) + 1];
		strcpy(m_NameOfPatient, temp.c_str());
		istr >> m_NumOfOHIP >> delimiter;
		m_ticket.csvRead(istr);
		return istr;
	}
	std::ostream& Patient::write(std::ostream& ostr) const {
		ostr << "Ticket No: " << m_ticket.number() << ", Issued at: " << Time(*this) << endl;
		if (strlen(m_NameOfPatient) > 25) {
			for (int i = 0; i < 25; i++)
				ostr << m_NameOfPatient[i];
		} else {
			ostr << m_NameOfPatient;
		}
		ostr << ", OHIP: " << m_NumOfOHIP;
		return ostr;
	}
	std::istream& Patient::read(std::istream& istr) {
		char* temp = getcstr("Name: ", istr);
		if (m_NameOfPatient) {
			delete[] m_NameOfPatient;
			m_NameOfPatient = nullptr;
		}
		m_NameOfPatient = new char[strlen(temp) + 1];
		strcpy(m_NameOfPatient, temp);
		delete[] temp;
		m_NumOfOHIP = getInt(100000000, 999999999, "OHIP:", "Invalid OHIP Number, ");
		return istr;
	}
}
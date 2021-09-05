//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       3 (MS)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
	class Patient:public IOAble {
		char* m_NameOfPatient{ nullptr };
		int m_NumOfOHIP{ 0 };
		Ticket m_ticket{ 0 };
		bool m_IOFlag;
	public:
		Patient(int ticketNumber = 0, bool fileIO = false);
		~Patient();
		virtual char type() const = 0;
		const bool fileIO() const;
		void fileIO(bool reset);
		bool operator==(const char singleChar) const;
		bool operator==(const Patient& src) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		std::ostream& csvWrite(std::ostream& ostr) const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
}
#endif
//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       2 (MS)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
namespace sdds {
	class IOAble {
		public:
			virtual std::ostream& csvWrite(std::ostream& ostr) const = 0;
			virtual std::istream& csvRead(std::istream& istr) = 0;
			virtual std::ostream& write(std::ostream& ostr) const = 0;
			virtual std::istream& read(std::istream& istr) = 0;
			virtual ~IOAble() {};
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& src);
	std::istream& operator>>(std::istream& istr, IOAble& src);
}
#endif // !SDDS_IOABLE_H

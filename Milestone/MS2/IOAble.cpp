//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       2 (MS)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include "IOAble.h"
using namespace std;
namespace sdds {
    std::ostream& operator<<(std::ostream& ostr, const IOAble& src) {
        return src.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, IOAble& src) {
        return src.read(istr);
    }
}
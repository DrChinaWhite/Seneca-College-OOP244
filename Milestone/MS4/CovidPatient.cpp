//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       4 (MS)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;
   CovidPatient::CovidPatient() : Patient(nextCovidTicket) {
	   nextCovidTicket++;
   }
   char CovidPatient::type() const {
	   return 'C';
   }
   std::istream& CovidPatient::csvRead(std::istream& istr) {
	   Patient::csvRead(istr);
	   nextCovidTicket = Patient::number() + 1;
	   istr.ignore();
	   return istr;
   }
   std::ostream& CovidPatient::write(std::ostream& ostr) const {
	   if (Patient::fileIO()) {
		   Patient::csvWrite(ostr);
	   } else {
		   ostr << "COVID TEST" << endl;
		   Patient::write(ostr) << endl;
	   }
	   return ostr;
   }
   std::istream& CovidPatient::read(std::istream& istr) {
	   Patient::fileIO() == true ? csvRead(istr) : Patient::read(istr);
	   return istr;
   }
}
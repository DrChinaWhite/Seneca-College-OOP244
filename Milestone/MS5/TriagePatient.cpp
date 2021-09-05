//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       4 (MS)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include <string>
#include <cstring>
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds {
   int nextTriageTicket = 1;
   TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
	   symptoms = nullptr;
	   nextTriageTicket++;
   }
   TriagePatient::~TriagePatient() {
	   if (symptoms) {
		   delete[] symptoms;
		   symptoms = nullptr;
	   }
   }
   char TriagePatient::type() const {
	   return 'T';
   }
   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const {
	   Patient::csvWrite(ostr) << ',' << symptoms;
	   return ostr;
   }
   std::istream& TriagePatient::csvRead(std::istream& istr) {
	   string temp;
	   char delimiter;
	   if (symptoms) {
		   delete[] symptoms;
		   symptoms = nullptr;
	   }
	   Patient::csvRead(istr);
	   istr >> delimiter;
	   getline(istr, temp, '\n');
	   symptoms = new char[strlen(temp.c_str()) + 1];
	   strcpy(symptoms, temp.c_str());
	   nextTriageTicket = Patient::number() + 1;
	   return istr;
   }
   std::ostream& TriagePatient::write(std::ostream& ostr) const {
	   if (Patient::fileIO()) {
		   csvWrite(ostr);
	   } else {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr) << endl;
		   ostr << "Symptoms: " << symptoms << endl;
	   }
	   return ostr;
   }
   std::istream& TriagePatient::read(std::istream& istr) {
	   char* temp;
	   if (Patient::fileIO()) {
		   csvRead(istr);
	   } else {
		   if (symptoms) {
			   delete[] symptoms;
			   symptoms = nullptr;
		   }
		   Patient::read(istr);
		   temp = getcstr("Symptoms: ", istr);
		   symptoms = new char[strlen(temp) + 1];
		   strcpy(symptoms, temp);
		   delete[] temp;
	   }
	   return istr;
   }
}
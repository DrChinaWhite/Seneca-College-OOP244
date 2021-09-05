//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       2 (DIY)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

//#define DATAFILE "PCpopulations.csv"
namespace sdds {
	struct Population {
		char* m_postalCode;
		int m_population;
	};
	void sort();
	bool load(Population &residents);
	bool load(const char* DATAFILE);
	void display(const Population &residents);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_
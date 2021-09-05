//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       3 (DIY)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds {
	class CalorieList {
		Food* m_items;
		int m_noOfItems;
		int m_itemsAdded;
		int totalCalories()const;
		void Title()const;
		void footer()const;
		void setEmpty();
		bool isValid()const;
	public:
		void init(int noOfItems);
		bool add(const char* foodName, int calories, int when);
		void display()const;
		void deallocate();
	};
}
#endif // !SDDS_CALORIELIST_H
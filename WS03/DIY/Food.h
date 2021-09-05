//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       3 (DIY)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
	class Food {
		char m_foodName[31];
		int m_calorie;
		int m_mealCode;
		void setName(const char* name);
		void convert()const;
	public:
		void setEmpty();
		void set(const char* name, int calorie, int mealCode);
		void display()const;
		bool isValid()const;
		int calorie()const;
	};
}
#endif // !SDDS_FOOD_H
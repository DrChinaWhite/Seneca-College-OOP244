//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       5 (DIY)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef  SDDS_MARK_H_
#define SDDS_MARK_H_

namespace sdds {
    class Mark {
        int grade;
    public:
        Mark(int gNum);
        Mark();
        void setEmpty();
        operator bool() const;
        operator int() const;
        Mark& operator+=(int gNum);
        Mark& operator=(int gNum);
        operator double() const;
        operator char() const;
    };
    int operator+=(int& num, Mark& markNum);
}
#endif // ! SDDS_MARK_H_

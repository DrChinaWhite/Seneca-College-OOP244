//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       5 (LAB)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;
      Account& operator=(const int accountNum);
      Account& operator=(Account& account);
      Account& operator+=(const double deposit);
      Account& operator-=(const double withdraw);
      Account& operator>>(Account &account);
      Account& operator<<(Account &account);
  
      friend double operator+(const Account &left, const Account &right);
      friend double operator+=(double &left, const Account &right);
   };
}
#endif // SDDS_ACCOUNT_H_
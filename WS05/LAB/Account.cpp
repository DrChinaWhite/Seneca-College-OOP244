//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       5 (LAB)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const {
        bool result = false;
        if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0) {
            result = true;
        }
        return result;
    }
    Account::operator int() const {
        return m_number;
    }
    Account::operator double() const {
        return m_balance;
    }
    bool Account::operator~() const {
        bool result = false;
        if (m_number == 0) {
            result = true;
        }
        return result;
    }
    Account& Account::operator=(const int accountNum) {
        if (m_number == 0) {
            m_number = accountNum;
        }
        else if (accountNum < 0){
            setEmpty();
        }
        return *this;
    }
    Account& Account::operator=(Account &account) {
        if (this->m_number == 0 && account.m_number > 0) {
            this->m_number = account.m_number;
            this->m_balance = account.m_balance;
            account.m_number = 0;
            account.m_balance = 0;
        }
        return *this;
    }
    Account& Account::operator+=(const double deposit) {
        if (m_number > 0 && m_balance >= 0.0 && deposit > 0.0) {
            m_balance += deposit;
        }
        return *this;
    }
    Account& Account::operator-=(const double withdraw) {
        if (m_number > 0 && m_balance >= withdraw && withdraw >= 0.0) {
            m_balance -= withdraw;
        }
        return *this;
    }
    Account& Account::operator>>(Account& account) {
        if (this->m_number > 0 && account.m_number > 0 && this->m_number != account.m_number) {
            account.m_balance += this->m_balance;
            this->m_balance = 0;
        }
        return *this;
    }
    Account& Account::operator<<(Account& account) {
        if (this->m_number > 0 && account.m_number > 0 && this->m_number != account.m_number)
        {
            this->m_balance += account.m_balance;
            account.m_balance = 0;
        }
        return *this;
    }
    double operator+(const Account &left, const Account &right) {
        double sum = 0.0;
        if (left.m_number > 0 && right.m_number > 0) {
            sum = left.m_balance + right.m_balance;
        }
        return sum;
    }
    double operator+=(double &left, const Account &right)
    {
        if (right.m_number > 0)
            left += right.m_balance;

        return left;
    }
}
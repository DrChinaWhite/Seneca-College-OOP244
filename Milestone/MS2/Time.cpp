//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       1 (MS)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time& Time::setToNow() {
        m_min = getTime();
        return *this;
    }
    Time::Time(unsigned int min) {
        m_min = min;
    }
    std::ostream& Time::write(std::ostream& ostr) const {
        ostr.width(2);
        ostr.fill('0');
        ostr << (m_min / 60);
        ostr << ":";
        ostr.width(2);
        ostr.fill('0');
        ostr << (m_min % 60);
        return ostr;
    }
    std::istream& Time::read(std::istream& istr) {
        int hour = 0;
        int min = 0;
        char colon;

        istr >> hour;
        if (!istr) {
            istr.setstate(ios::failbit);
        } else if (hour < 0) {
            istr.setstate(ios::failbit);
        } else {
            istr >> colon;
            if (colon != ':') {
                istr.setstate(ios::failbit);
            } else {
                istr >> min;
                if (min < 0) {
                    istr.setstate(ios::failbit);
                } else {
                    m_min = (hour * 60) + min;
                }
            }
        }
        return istr;
    }
    Time& Time::operator-=(const Time& D) {
        if (this->m_min > D.m_min) {
            this->m_min -= D.m_min;
        } else {
            this->m_min = this->m_min + (1440 * ((D.m_min / 1440) + 1)) - D.m_min;
        }
        return *this;
    }
    Time Time::operator-(const Time& D)const {
        Time temp;
        if (this->m_min > D.m_min) {
            temp.m_min = this->m_min - D.m_min;
        } else {
            temp.m_min = this->m_min + (1440 * ((D.m_min / 1440) + 1)) - D.m_min;
        }
        return temp;
    }
    Time& Time::operator+=(const Time& D) {
        this->m_min += D.m_min;
        return *this;
    }
    Time Time::operator+(const Time& D)const {
        Time temp;
        temp.m_min = this->m_min + D.m_min;
        return temp;
    }
    Time& Time::operator=(unsigned int val) {
        this->m_min = val;
        return *this;
    }
    Time& Time::operator *= (unsigned int val) {
        this->m_min *= val;
        return *this;
    }
    Time& Time::operator /= (unsigned int val) {
        this->m_min /= val;
        return *this;
    }
    Time Time::operator *(unsigned int val)const {
        Time temp;
        temp.m_min = this->m_min * val;
        return temp;
    }
    Time Time::operator /(unsigned int val)const {
        Time temp;
        temp.m_min = this->m_min / val;
        return temp;
    }
    Time::operator int()const {
        return (int)m_min;
    }
    Time::operator unsigned int()const {
        return m_min;
    }
    std::ostream& operator<<(std::ostream& ostr, const Time& D) {
        return D.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Time& D) {
        return D.read(istr);
    }
}
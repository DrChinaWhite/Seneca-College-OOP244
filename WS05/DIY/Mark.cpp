//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       5 (DIY)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"
using namespace std;

namespace sdds {
    Mark::operator bool() const {
        if (grade <= 100 && grade >= 0) {
            return true;
        }
        return false;
    }
    void Mark::setEmpty() {
        grade = -1;
    }
    Mark::Mark(int gNum) {
        if (gNum >= 0 && gNum <= 100) {
            grade = gNum;
        } else {
            setEmpty();
        }
    }
    Mark::Mark() {
        grade = 0;
    }
    Mark::operator int() const {
        if (*this) {
            return grade;
        }
        return 0;
    }
    Mark& Mark::operator+=(int gNum) {
        if (*this) {
            grade += gNum;
        }
        return *this;
    }
    Mark& Mark::operator=(int gNum) {
        if (gNum >= 0 && gNum <= 100) {
            grade = gNum;
        } else {
            setEmpty();
        }
        return *this;
    }
    Mark::operator double() const {
        double score = 0.0;
        if (grade >= 0 && grade < 50) {
            score = 0.0;
        } else if (grade >= 50 && grade < 60) {
            score = 1.0;
        } else if (grade >= 60 && grade < 70) {
            score = 2.0;
        } else if (grade >= 70 && grade < 80) {
            score = 3.0;
        } else if (grade >= 80 && grade < 100) {
            score = 4.0;
        }
        return score;
    }
    Mark::operator char() const {
        char letter = 'X';
        if (grade >= 0 && grade < 50) {
            letter = 'F';
        } else if (grade >= 50 && grade < 60) {
            letter = 'D';
        } else if (grade >= 60 && grade < 70) {
            letter = 'C';
        } else if (grade >= 70 && grade < 80) {
            letter = 'B';
        } else if (grade >= 80 && grade < 100) {
            letter = 'A';
        }
        return letter;
    }
    int operator+=(int& num, Mark& markNum) {
        if (markNum) {
            num += int(markNum);
        }
        return num;
    }
}
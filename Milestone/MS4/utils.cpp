//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       1 (MS)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;  // made global in utils.h
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    int getInt(const char* prompt) {
        int input;
        char buffer;
        bool flag = false;

        if (prompt) {
            cout << prompt;
        }
        do {
            cin >> input;
            if (!cin) {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(BUFFER_SIZE, '\n');
            }
            else {
                cin.get(buffer);
                if (buffer != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(BUFFER_SIZE, '\n');
                }
                else {
                    flag = true;
                }
            }
        } while (!flag);
        return input;
    }
    int getInt(
        int min,
        int max,
        const char* prompt,
        const char* errorMessage,
        bool showRangeAtError
    ) {
        int input;
        char buffer;
        bool flag = false;

        if (prompt) {
            cout << prompt;
        }
        do {
            cin >> input;
            if (!cin) {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(BUFFER_SIZE, '\n');
            }
            else {
                cin.get(buffer);
                if (buffer != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(BUFFER_SIZE, '\n');
                }
                else if (input < min || input > max) {
                    if (errorMessage) {
                        cout << errorMessage;
                    }
                    if (showRangeAtError) {
                        cout << "[" << min << " <= value <= " << max << "]: ";
                    }
                }
                else {
                    flag = true;
                }
            }
        } while (!flag);
        return input;
    }
    char* getcstr(
        const char* prompt,
        std::istream& istr,
        char delimiter
    ) {
        string input;
        char* outString;
        if (prompt) {
            cout << prompt;
        }
        getline(istr, input, delimiter);
        outString = new char[strlen(input.c_str()) + 1];
        strcpy(outString, input.c_str());
        return outString;
    }
}
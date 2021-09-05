//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       2 (LAB)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
#include <iostream>
#include "cstring.h"
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;

    void sort() {
        int i, sj;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }
    bool load(Employee &employee) {
        bool ok = false;
        char name[128];
        if (read(employee.m_empNo) && read(employee.m_salary) && read(name)) {
            employee.m_name = new char[strLen(name) + 1];
            strCpy(employee.m_name, name);
            ok = true;
        }
        return ok;
    }
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (i = 0; i < noOfEmployees; i++) {
                load(employees[i]);
            }
            if (i != noOfEmployees) {
                cout << "Error: incorrect number of records read; the data is possible corrupted" << endl;
            } else {
                ok = true;
            }
        } else {
         cout << "Could not open data file: " << DATAFILE<< endl;
        }
        closeFile();
        return ok;
    }
    void display(const Employee &employee) {
        cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
    }
    void display() {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        sort();
        for (int i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }
    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }
        delete[] employees;
        employees = nullptr;
    }
}
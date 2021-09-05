//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       9 (LAB)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

/*
listArrayElements Template Function
    This function receives a titale and an arry and outputs them to the console. Using <typename T> I am able to use different types of arrays rather than just one type.
    When the project compiles, the template function will determine the type of array received. Because Car, Employee and Student are inhereted from the ReadWrite class
    the operator << is called inside the function. It will then determine what the object is and calls the proper display() function.
search Template Function
    Collection is a template class and it receives Car, Student and Employee as a type. We use the same type name for both collections and arrays.
    The data is then added to the template collection class. The types are also determined during compilation. The == operator is used to compare and
    see if each class matches. If it matches it will call the template function "add" to add the data.
*/

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"
using namespace std;
namespace sdds {
    template <typename T>
    void listArrayElements(const char* title, const T* arr, int num) {
        cout << title << endl;
        for (int i = 0; i < num; i++) {
            cout << (i + 1) << ": ";
            cout << arr[i] << endl;
        }
    }
    template <typename T1, typename T2>
    bool search(Collection<T1>& obj, const T1* arr, int num, T2 key) {
        bool result = false;
        for (int i = 0; i < num; i++) {
            if (arr[i] == key) {
                obj.add(arr[i]);
                result = true;
            }
        }
        return result;
    }
}
#endif
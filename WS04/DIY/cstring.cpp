//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       1 (DIY)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include "cstring.h"

namespace sdds {

	void strCpy(char* des, const char* src) {

		while ((*des++ = *src++));
	}

	void strnCpy(char* des, const char* src, int len) {

		while (len > 0) {
			*des++ = *src++;
            len--;
		}
	}

	int strCmp(const char* s1, const char* s2) {

        while (*s1 && *s2 && *s1 == *s2) {
            s1++;
            s2++;
        }
        return (*s1 - *s2);
	}

    int strnCmp(const char* s1, const char* s2, int len) {

        while (len > 0) {
            while (*s1 && *s2 && *s1 == *s2) {
                s1++;
                s2++;
                len--;
            }
            if (len == 0)
                return 0;
            else
                return (*s1 - *s2);
        }
	return 0;
    }

    int strLen(const char* s) {

        int len = 0;

        while (s[len]) {
            len++;
        }

        return len;
    }

    const char* strStr(const char* str1, const char* str2) {

        // The following code was retrieved from Google.ca
        // https://stackoverflow.com/questions/49131175/recreate-the-strstr-function
        const char* a = str1, * b = str2;
        for (;;) {
            if (!*b) return (char*)str1;
            if (!*a) return nullptr;
            if (*a++ != *b++) {
                a = ++str1; b = str2;
            }
        }

        /*
        This was the code the strStr that I was working on; however, unable to get it to function properly.
        const char* start1 = str1;
        const char* start2 = str2;

        while (*str2 && *str1) {
            if (*str1 == *str2)
                str1++, str2++;
            else
                str2 = start2, str1++;
        }

        if (!*str1) {
            return (char*)((str1 - start1) - (str2 - start2));
        }
        else {
            return nullptr;
        }
        */
    }

    void strCat(char* des, const char* src) {

        while (*des) {
            des++;
        }

        while (*src) {
            *des++ = *src++;
        }

        *des = '\0';
    }
}
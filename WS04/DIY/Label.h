//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       4 (DIY)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_LABEL_H 
#define SDDS_LABEL_H
namespace sdds {
    class Label {
        char* title;
        char frame[9]; 
        void setTitle(const char* content);
    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        bool isEmpty();
        std::ostream& printLabel()const;
    };
}
#endif
//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        OOP244-NBB
// Workshop:       5 (MS)
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
using namespace std;
namespace sdds {
    PreTriage::PreTriage(const char* dataFilename) :
        m_averCovidWait(15), m_averTriageWait(5),
        m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
        m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename, dataFilename);
        load();
    }
    PreTriage::~PreTriage() {
        ofstream out(m_dataFilename);
        if (out.is_open()) {
            cout << "Saving Average Wait Times," << endl;
            cout << "   COVID Test: " << m_averCovidWait << endl;
            cout << "   Triage: " << m_averTriageWait << endl;
            cout << "Saving m_lineup..." << endl;
            out << m_averCovidWait << "," << m_averTriageWait << endl;
            for (int i = 0; i < m_lineupSize; i++) {
                m_lineup[i]->fileIO(true);
                cout << (i + 1) << "- " << *m_lineup[i] << endl;
                out << *m_lineup[i] << endl;
            }
        } else {
            cout << "Failed to SAVE File !!" << endl;
        }
        for (int i = 0; i < m_lineupSize; i++) {
            delete m_lineup[i];
            m_lineup[i] = nullptr;
        }
        delete[] m_dataFilename;
        m_dataFilename = nullptr;
        cout << "done!" << endl;
    }
    void PreTriage::run(void) {
        int menu;
        while (m_appMenu >> menu) {
            switch (menu) {
            case 1:
                reg();
                break;
            case 2:
                admit();
                break;
            default:
                break;
            }
        }
    }
    void PreTriage::reg() {
        if (m_lineupSize == maxNoOfPatients) {
            cout << "Line up full!" << endl;
        } else {
            int menu;
            m_pMenu >> menu;
            switch (menu) {
            case 1:
                m_lineup[m_lineupSize] = new CovidPatient();
                break;
            case 2:
                m_lineup[m_lineupSize] = new TriagePatient();
                break;
            default:
                break;
            }
            m_lineup[m_lineupSize]->setArrivalTime();
            cout << "Please enter patient information: " << endl;
            m_lineup[m_lineupSize]->fileIO(false);
            cin >> *m_lineup[m_lineupSize];
            cout << endl;
            cout << "******************************************" << endl;
            cout << *m_lineup[m_lineupSize];
            cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
            cout << "******************************************" << endl << endl;
            m_lineupSize++;
        }
    }
    void PreTriage::admit() {
        int menu;
        int found;
        char patient = '\0';
        m_pMenu >> menu;
        switch (menu) {
        case 1:
            patient = 'C';
            break;
        case 2:
            patient = 'T';
            break;
        default:
            break;
        }
        found = indexOfFirstInLine(patient);
        if (found != -1) {
            cout << endl;
            cout << "******************************************" << endl;
            m_lineup[found]->fileIO(false);
            cout << "Calling for " << *m_lineup[found];
            cout << "******************************************" << endl << endl;
            setAverageWaitTime(*m_lineup[found]);
            removePatientFromLineup(found);
        }
    }
    const Time PreTriage::getWaitTime(const Patient& p) const {
        unsigned int count = 0;
        for (int i = 0; i < m_lineupSize; i++) {
            if (p == *m_lineup[i]) {
                count++;
            }
        }
        return Time(p) * count;
    }
    void PreTriage::setAverageWaitTime(const Patient& p) {
        int ticketTime = Time(p);
        if (p == 'C') {
            m_averCovidWait = ((getTime() - ticketTime) + (int(m_averCovidWait) * (p.number() - 1))) / p.number();
        } else {
            m_averTriageWait = ((getTime() - ticketTime) + (int(m_averTriageWait) * (p.number() - 1))) / p.number();
        }
    }
    void PreTriage::removePatientFromLineup(int index) {
        removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
    }
    int PreTriage::indexOfFirstInLine(char type) const {
        int i = 0;
        int find = -1;
        while (i < m_lineupSize && find == -1) {
            if (*m_lineup[i] == type) {
                find = i;
            }
            i++;
        }
        return find;
    }
    void PreTriage::load() {
        int index = 0;
        char delimiter = '\0';
        bool exit = false;
        cout << "Loading data..." << endl;
        ifstream readfile(m_dataFilename);
        if (!readfile) {
            cout << "No data or bad data file!" << endl << endl;
        } else {
            readfile >> m_averCovidWait;
            if (!readfile) {
                exit = true;
            }
            readfile >> delimiter >> m_averTriageWait;
            readfile.ignore(32767, '\n');
            while (index < maxNoOfPatients && !readfile.eof() && !exit) {
                char patient = '\0';
                Patient* temp = nullptr;
                readfile >> patient >> delimiter;
                if (patient == 'C') {
                    temp = new CovidPatient();
                } else if (patient == 'T') {
                    temp = new TriagePatient();
                }
                if (temp != nullptr) {
                    temp->fileIO(true);
                    readfile >> *temp;
                    temp->fileIO(false);
                    m_lineup[index] = temp;
                    m_lineupSize++;
                }
                index++;
            }
            if (!readfile.eof()) {
                cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
                cout << m_lineupSize << " Records imported..." << endl << endl;
            } else if (exit) {
                cout << "No data or bad data file!" << endl << endl;
            } else {
                cout << m_lineupSize << " Records imported..." << endl << endl;
            }
        }
    }

}

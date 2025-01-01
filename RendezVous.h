#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <string>
#include <iostream>
using namespace std;

class RendezVous {
public:
    int idPatient;
    int idMedecin;
    string date;
    string time;
    RendezVous* next;

    RendezVous(int idPatient, int idMedecin, string date, string time)
        : idPatient(idPatient), idMedecin(idMedecin), date(date), time(time), next(nullptr) {}

    void display() {
        cout << "Patient ID: " << idPatient << ", Medecin ID: " << idMedecin
             << ", Date: " << date << ", Time: " << time << endl;
    }
};

#endif

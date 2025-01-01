#ifndef MEDECIN_H
#define MEDECIN_H

#include <string>
#include <iostream>
#include "RendezVous.h"
using namespace std;

class Medecin {
public:
    int id;
    string name;
    string specialty;
    RendezVous* rendezVousList;

    Medecin(int id, string name, string specialty)
        : id(id), name(name), specialty(specialty), rendezVousList(nullptr) {}

    void addRendezVous(RendezVous* rdv) {
        rdv->next = rendezVousList;
        rendezVousList = rdv;
    }

    void display() const {
        cout << "Medecin ID: " << id << ", Name: " << name << ", Specialty: " << specialty << endl;
        cout << "Appointments:\n";
        RendezVous* temp = rendezVousList;
        while (temp) {
            temp->display();
            temp = temp->next;
        }
    }

    bool isAvailable(string date, string time) const {
        RendezVous* temp = rendezVousList;
        while (temp) {
            if (temp->date == date && temp->time == time) {
                return false;  // Medecin is already booked at this time
            }
            temp = temp->next;
        }
        return true;
    }

    void displayAppointmentsByDate(string date) const {
        RendezVous* temp = rendezVousList;
        while (temp) {
            if (temp->date == date) {
                temp->display();
            }
            temp = temp->next;
        }
    }
};

#endif

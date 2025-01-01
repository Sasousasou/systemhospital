#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
#include "RendezVous.h"
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string medicalHistory;
    RendezVous* rendezVousList;

    Patient(int id, string name, int age, string medicalHistory)
        : id(id), name(name), age(age), medicalHistory(medicalHistory), rendezVousList(nullptr) {}

    void addRendezVous(RendezVous* rdv) {
        rdv->next = rendezVousList;
        rendezVousList = rdv;
    }

    void display() const {
        cout << "Patient ID: " << id << ", Name: " << name << ", Age: " << age
             << ", Medical History: " << medicalHistory << endl;
        cout << "Appointments:\n";
        RendezVous* temp = rendezVousList;
        while (temp) {
            temp->display();
            temp = temp->next;
        }
    }

    void displayFutureAppointments() const {
        RendezVous* temp = rendezVousList;
        while (temp) {
            if (isFutureAppointment(temp->date)) {
                temp->display();
            }
            temp = temp->next;
        }
    }

    bool isFutureAppointment(string date) const {
        // Implement a basic future date check (e.g., compare with current date)
        return true;  // Just for demonstration
    }
};

#endif

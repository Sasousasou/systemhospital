#include <iostream>
#include <vector>
#include <string>
#include "Patient.h"
#include "Medecin.h"
#include "RendezVous.h"

using namespace std;

vector<Patient> patientList;
vector<Medecin> medecinList;

void ajouterPatient() {
    int id, age;
    string name, medicalHistory;
    cout << "Enter Patient ID: ";
    cin >> id;
    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Patient Age: ";
    cin >> age;
    cout << "Enter Medical History: ";
    cin.ignore();
    getline(cin, medicalHistory);
    patientList.emplace_back(id, name, age, medicalHistory);
    cout << "Patient added successfully!\n";
}

void ajouterMedecin() {
    int id;
    string name, specialty;
    cout << "Enter Medecin ID: ";
    cin >> id;
    cout << "Enter Medecin Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Specialty: ";
    getline(cin, specialty);
    medecinList.emplace_back(id, name, specialty);
    cout << "Medecin added successfully!\n";
}

void ajouterRendezVous() {
    int idPatient, idMedecin;
    string date, time;
    cout << "Enter Patient ID: ";
    cin >> idPatient;
    cout << "Enter Medecin ID: ";
    cin >> idMedecin;
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter Time (HH:MM): ";
    cin >> time;

    RendezVous* rdv = new RendezVous(idPatient, idMedecin, date, time);

    bool foundPatient = false, foundMedecin = false;
    for (auto& patient : patientList) {
        if (patient.id == idPatient) {
            patient.addRendezVous(rdv);
            foundPatient = true;
            break;
        }
    }

    for (auto& medecin : medecinList) {
        if (medecin.id == idMedecin && medecin.isAvailable(date, time)) {
            medecin.addRendezVous(rdv);
            foundMedecin = true;
            break;
        }
    }

    if (foundPatient && foundMedecin) {
        cout << "Rendez-vous added successfully!\n";
    } else {
        cout << "Either patient or medecin not found or medecin not available at this time.\n";
    }
}

void afficherMedecins() {
    for (const auto& medecin : medecinList) {
        medecin.display();
    }
}

void afficherPatients() {
    for (const auto& patient : patientList) {
        patient.display();
    }
}

void afficherRendezVous() {
    for (const auto& rdv : patientList) {
        RendezVous* temp = rdv.rendezVousList;
        while (temp) {
            temp->display();
            temp = temp->next;
        }
    }
}

void menu() {
    int choice;
    do {
        cout << "--- Hospital Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Medecin\n";
        cout << "3. Add Rendez-vous\n";
        cout << "4. Display Patients\n";
        cout << "5. Display Medecins\n";
        cout << "6. Display Rendez-vous\n";
        cout << "7. Display Medecin Appointments by Date\n";
        cout << "8. Display Future Appointments for Patient\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: ajouterPatient(); break;
            case 2: ajouterMedecin(); break;
            case 3: ajouterRendezVous(); break;
            case 4: afficherPatients(); break;
            case 5: afficherMedecins(); break;
            case 6: afficherRendezVous(); break;
            case 7: {
                int medecinID;
                string date;
                cout << "Enter Medecin ID: ";
                cin >> medecinID;
                cout << "Enter Date (YYYY-MM-DD): ";
                cin >> date;
                for (auto& medecin : medecinList) {
                    if (medecin.id == medecinID) {
                        medecin.displayAppointmentsByDate(date);
                    }
                }
                break;
            }
            case 8: {
                int patientID;
                cout << "Enter Patient ID: ";
                cin >> patientID;
                for (auto& patient : patientList) {
                    if (patient.id == patientID) {
                        patient.displayFutureAppointments();
                    }
                }
                break;
            }
            case 9: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);
}

int main() {
    menu();
    return 0;
}

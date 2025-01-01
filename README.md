# Hospital Management System

## Description
Ce projet est un **système de gestion d'hôpital** conçu pour aider à gérer efficacement les patients, les médecins et leurs rendez-vous. Il utilise la programmation orientée objet (POO) en C++ pour offrir une structure modulaire et extensible. 

Le système permet de :
- Suivre les informations des patients (ID, nom, historique médical, etc.).
- Suivre les informations des médecins (ID, nom, spécialité, etc.).
- Planifier et gérer les rendez-vous entre patients et médecins.

---

## Structure de la Gestion
La gestion repose sur trois entités principales :
1. **Patient** : Chaque patient a un ID unique, un nom, un historique médical et une liste chaînée des rendez-vous associés.
2. **Médecin** : Chaque médecin a un ID unique, un nom, une spécialité et une liste chaînée des rendez-vous associés.
3. **Rendez-vous** : Chaque rendez-vous associe un patient et un médecin à une date spécifique.

Ces trois entités sont interconnectées :
- Les patients et les médecins pointent chacun vers leurs propres listes chaînées de rendez-vous.
- Lorsqu'un rendez-vous est ajouté, il est mis à jour dans les deux listes chaînées (celle du patient et celle du médecin).

---

## Structure du Code
Le code est organisé en plusieurs fichiers pour favoriser la modularité et la maintenabilité :

1. **`Patient.h`** :
   - Contient la définition de la classe `Patient`.
   - Attributs : ID, nom, historique médical, liste chaînée des rendez-vous.
   - Méthodes :
     - `addRendezVous(RendezVous* rdv)` : Ajoute un rendez-vous à la liste chaînée du patient.
     - `display()` : Affiche les informations du patient et ses rendez-vous.

2. **`Medecin.h`** :
   - Contient la définition de la classe `Medecin`.
   - Attributs : ID, nom, spécialité, liste chaînée des rendez-vous.
   - Méthodes :
     - `addRendezVous(RendezVous* rdv)` : Ajoute un rendez-vous à la liste chaînée du médecin.
     - `display()` : Affiche les informations du médecin et ses rendez-vous.

3. **`RendezVous.h`** :
   - Contient la définition de la classe `RendezVous`.
   - Attributs : ID patient, ID médecin, date, pointeur vers le rendez-vous suivant dans la liste chaînée.
   - Méthodes :
     - `display()` : Affiche les détails du rendez-vous.

4. **`main.cpp`** :
   - Gère l'exécution principale du programme.
   - Contient le menu principal pour ajouter des patients, des médecins, et planifier ou afficher des rendez-vous.
   - Implémente les fonctions principales telles que `ajouterPatient()`, `ajouterMedecin()`, `ajouterRendezVous()`, et les fonctions d'affichage.

---

## Classe Principale
La **classe principale** du projet est le fichier `main.cpp`, qui orchestre toutes les interactions entre les entités `Patient`, `Medecin`, et `RendezVous`. Elle gère les opérations suivantes :

1. Ajout de patients et de médecins dans leurs listes respectives.
2. Création de nouveaux rendez-vous.
3. Affichage des informations des patients, des médecins, et des rendez-vous.
4. Planification et recherche de rendez-vous.

---

## Fonctionnalités Principales
1. **Ajouter un patient** :
   - ID, nom, âge, historique médical.
   - Enregistre les données dans une liste de patients.

2. **Ajouter un médecin** :
   - ID, nom, spécialité.
   - Enregistre les données dans une liste de médecins.

3. **Ajouter un rendez-vous** :
   - ID du patient, ID du médecin, date.
   - Ajoute le rendez-vous à la liste chaînée du patient et du médecin.

4. **Planifier un rendez-vous** :
   - Recherche un médecin disponible pour une date donnée.

5. **Afficher les rendez-vous d'un médecin** :
   - Affiche tous les rendez-vous associés à un médecin spécifique.

6. **Afficher les rendez-vous d’un médecin pour une date donnée** :
   - Filtre les rendez-vous d’un médecin pour une date donnée.

7. **Afficher les rendez-vous futurs d’un patient triés par date** :
   - Trie les rendez-vous par date croissante et les affiche.

---

## Conclusion
Ce projet est une solution simple mais puissante pour gérer efficacement les données hospitalières. La séparation des classes pour chaque entité principale garantit une meilleure organisation du code et une grande extensibilité.

### Points Clés :
- **Modularité** : Chaque entité est gérée séparément via des classes.
- **Extensibilité** : De nouvelles fonctionnalités peuvent être ajoutées facilement.
- **Utilisation de listes chaînées** : Gère efficacement les relations entre les patients, les médecins, et leurs rendez-vous.

---

## Comment Exécuter
1. Clonez le repository GitHub :
   ```bash
   git clone https://github.com/sasousasou/systemhospital.git
   cd systemhospital

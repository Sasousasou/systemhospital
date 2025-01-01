# Hospital Management System

## Description
Ce projet est un système de gestion d'hôpital qui permet de gérer les patients, les médecins et les rendez-vous. Le programme permet aux utilisateurs de :

- Ajouter de nouveaux patients et médecins.
- Planifier des rendez-vous entre les patients et les médecins.
- Afficher les patients, les médecins et les rendez-vous.

## Fonctionnalités

1. **Ajouter un patient** : Permet d'ajouter un patient avec son ID, son nom, son âge et son historique médical.
2. **Ajouter un médecin** : Permet d'ajouter un médecin avec son ID, son nom et sa spécialité.
3. **Ajouter un rendez-vous** : Permet de planifier un rendez-vous entre un patient et un médecin avec une date et une heure spécifiques.
4. **Afficher les patients** : Affiche la liste des patients enregistrés.
5. **Afficher les médecins** : Affiche la liste des médecins enregistrés.
6. **Afficher les rendez-vous** : Affiche la liste de tous les rendez-vous planifiés.

## Structure du Projet

Le projet est constitué des fichiers suivants :

- **`Patient.h`** : Contient la classe `Patient` et la gestion des rendez-vous liés.
- **`Medecin.h`** : Contient la classe `Medecin` et la gestion des rendez-vous liés.
- **`RendezVous.h`** : Contient la classe `RendezVous` qui lie un patient à un médecin pour un rendez-vous.
- **`main.cpp`** : Contient le menu principal et l'implémentation du programme.


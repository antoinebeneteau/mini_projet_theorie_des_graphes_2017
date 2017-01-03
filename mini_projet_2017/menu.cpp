//
//  menu.cpp
//  mini_projet_2017
//
//  Created by antoine beneteau on 2017-01-03.
//  Copyright © 2017 antoine beneteau. All rights reserved.
//

#include <iostream>
#include <limits>
#include "menu.h"

using namespace std;


int menu1() {
    
    cout << " -------------------------------------------------------------------------------" << endl;
    cout << "|         Mini-projet Théorie des Graphes - Problème d'ordonnancement           |" << endl;
    cout << "|               Antoine BENETEAU - Antoine MALINUR - Pascal AKOURI              |" << endl;
    cout << " ------------------------------------------------------------------------------- " << endl;
    
    int choice = 0;
    bool check = false;
    
    cout << "*-------------------------------------------------------------------------------*" << endl;
    cout << "|                                       Menu 1                                  |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|  1 - Lire un des fichiers de la bdd                                           |" << endl;
    cout << "|  2 - Lire un fichier par saisie du chemin                                     |" << endl;
    cout << "|  0 - Quitter                                                                  |" << endl;
    cout << "*-------------------------------------------------------------------------------*" << endl;
    
    string filePath;
    
    do {
        cout << "Choix: " << endl;
       cin >> choice;
    }
    while (choice < 0 || choice > 3);
    
    switch(choice) {
        case 0:
            cout << "Quitter !" << endl;
            break;
            
        case 1:
            menu2();
            break;
            
        case 2:
                cout << "chemin de votre matrice: " << endl;
                cin >> filePath;


    }
    return 1;
}

int menu2() {
    
    int choice = 0;
    bool check = false;
    string filePath;
    
    cout << "*-------------------------------------------------------------------------------*" << endl;
    cout << "|                                       Menu 2                                  |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|  1 - Lire le fichier 1                                                        |" << endl;
    cout << "|  2 - Lire le fichier 2                                                        |" << endl;
    cout << "|  3 - Lire le fichier 3                                                        |" << endl;
    cout << "|  4 - Lire le fichier 4                                                        |" << endl;
    cout << "*-------------------------------------------------------------------------------*" << endl;
    
    do {
        cout << "Choix: " << endl;
        cin >> choice;
    }
    while (choice < 1 || choice > 4);
    
    switch(choice) {
        
        case 1:
            cout << "Lecture du fichier 1 ... " << endl;
            menu3();
            break;
            
        case 2:
            cout << "Lecture du fichier 2 ... " << endl;
            menu3();
            break;
        case 3:
            cout << "Lecture du fichier 3 ... " << endl;
            menu3();
            break;
        case 4:
            cout << "Lecture du fichier 4 ... " << endl;
            menu3();
            break;
        
            
    }
    return 1;
}

int menu3() {
    
    
    int choice = 0;
    bool check = false;
    
    cout << "*-------------------------------------------------------------------------------*" << endl;
    cout << "|                                       Menu 3                                  |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|  1 - Afficher la liste de toutes les taches (sommets)                         |" << endl;
    cout << "|  2 - Afficher les contraintes/predecesseurs des sommets                       |" << endl;
    cout << "|  3 - Afficher les successeurs des sommets                                     |" << endl;
    cout << "|  4 - Afficher la liste des arcs du graphes                                    |" << endl;
    cout << "|  5 - Afficher la matrice d'adjacence                                          |" << endl;
    cout << "|  6 - Afficher la matrice des valeurs                                          |" << endl;
    cout << "|  7 - Afficher la matrice d'adjacence associée a sa fermeture transitive       |" << endl;
    
//    if (circuit == false) {
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|  Le graghe a un circuit, nous pouvons donc effectuer ces operations !         |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|  8 - Afficher le rang de chaques sommets                                      |" << endl;
    cout << "|  9 - Afficher les dates au plus tôt et au plus tard de chaque sommet          |" << endl;
    cout << "| 10 - Afficher le diagramme de GANTT au plus tôt                               |" << endl;
    cout << "| 11 - Afficher le diagramme de GANTT au plus tard                              |" << endl;
    cout << "|  0 - Menu principal                                                           |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    
    do {
        cout << "Choix: " << endl;
        cin >> choice;
    }
    while (choice < 0 || choice > 11);
    
    switch(choice) {
            
        case 1:
            cout << "Affichage de la liste de toutes les contraintes... " << endl;
            break;
            
        case 2:
            cout << "Affichage des contraintes/predecesseurs des sommets..." << endl;
            break;
            
        case 3:
            cout << "Affichage des successeurs des sommets..." << endl;
            break;
            
        case 4:
            cout << "Affichage des listes des arcs du graphes..." << endl;
            break;
        
        case 5:
            cout << "Affichage de la matrice adjacente..." << endl;
            break;
        
        case 6:
            cout << "Affichage de la matrice des valeurs... " << endl;
            break;
        
        case 7:
            cout << "Affichage la matrice d'adjacence associée a sa fermeture transitive..." << endl;
            break;
            
        case 8:
            cout << "Affichage du rang de chaques sommets... " << endl;
            break;
            
        case 9:
            cout << "Affichage des dates au plus tôt et au plus tard de chaques sommets... " << endl;
            break;
            
        case 10:
            cout << "Affichage du diagramme de GANTT au plus tot " << endl;
            break;
            
        case 11:
            cout << "Affichage du diagramme de GANTT au plus tard" << endl;
            break;
        
        case 0:
            menu1();
            break;
            
            
            
            

   }
    return 1;
}

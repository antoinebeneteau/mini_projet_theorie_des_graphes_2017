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
    
    int choix = 0;
    
    cout << "*-------------------------------------------------------------------------------*" << endl;
    cout << "|                                       Menu 1                                  |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|  1 - Lire un des fichiers de la bdd                                           |" << endl;
    cout << "|  2 - Lire un fichier par saisie du chemin                                     |" << endl;
    cout << "|  0 - Quitter                                                                  |" << endl;
    cout << "*-------------------------------------------------------------------------------*" << endl;
    
    do
    {
        cout << "Votre choix: ";
        cin >> choix;
        
    } while ((choix != 1) && (choix != 2) && (choix != 0));
    
    return choix;
    
}

int menu2() {
    
    int choix = 0;
    
    cout << "*-------------------------------------------------------------------------------*" << endl;
    cout << "|                                       Menu 2                                  |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|  1 - Lire le fichier 1                                                        |" << endl;
    cout << "|  2 - Lire le fichier 2                                                        |" << endl;
    cout << "|  3 - Lire le fichier 3                                                        |" << endl;
    cout << "|  4 - Lire le fichier 4                                                        |" << endl;
    cout << "|  5 - Lire le fichier 5                                                        |" << endl;
    cout << "*-------------------------------------------------------------------------------*" << endl;
    
    do
    {
        cout << "Votre choix: ";
        cin >> choix;
        
    } while ((choix != 1) && (choix != 2) && (choix != 3) && (choix != 4) && (choix != 5));
    
    return choix;
}

int menu3(bool circuit) {
    
    
    int choix = 0;
    
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
    
    if (!circuit) {
        cout << "|-------------------------------------------------------------------------------|" << endl;
        cout << "|  Le graghe a un circuit, nous pouvons donc effectuer ces operations !         |" << endl;
        cout << "|-------------------------------------------------------------------------------|" << endl;
        cout << "|  8 - Afficher le rang de chaques sommets                                      |" << endl;
        cout << "|  9 - Afficher les dates au plus tôt et au plus tard de chaque sommet          |" << endl;
        cout << "| 10 - Afficher le diagramme de GANTT au plus tôt                               |" << endl;
        cout << "| 11 - Afficher le diagramme de GANTT au plus tard                              |" << endl;
        cout << "|  0 - Menu principal                                                           |" << endl;
        cout << "|-------------------------------------------------------------------------------|" << endl;
        
        do
        {
            cout << "Votre choix: ";
            cin >> choix;
            
        } while ((choix != 1) && (choix != 2) && (choix != 3) && (choix != 4) && (choix != 5) && (choix != 6) && (choix != 7) && (choix != 8) && (choix != 9) && (choix != 10) && (choix != 11) && (choix != 0));
        
    } else {
        do
        {
            cout << "Votre choix: ";
            cin >> choix;
            
        } while ((choix != 1) && (choix != 2) && (choix != 3) && (choix != 4) && (choix != 5) && (choix != 6) && (choix != 7));
    }

    
    return choix;
}

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
    cout << " ------------------------------------------------------------------------------- " << endl << endl;
    
    int choix = 0;
    bool check = false;
    
    cout << "*-------------------------------------------------------------------------------*" << endl;
    cout << "|                                       Menu 1                                  |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|  1 - Lire un des fichiers de la bdd                                           |" << endl;
    cout << "|  2 - Lire un fichier par saisie du nom du fichier                             |" << endl;
    cout << "|  0 - Quitter                                                                  |" << endl;
    cout << "*-------------------------------------------------------------------------------*" << endl;
    return 1;
}

int menu2() {
    
    int choix = 0;
    bool check = false;
    
    cout << "*-------------------------------------------------------------------------------*" << endl;
    cout << "|                                       Menu 2                                  |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|  1 - Lire le fichier 1                                                        |" << endl;
    cout << "|  2 - Lire le fichier 2                                                        |" << endl;
    cout << "|  3 - Lire le fichier 3                                                        |" << endl;
    cout << "|  4 - Lire le fichier 4                                                        |" << endl;
    cout << "*-------------------------------------------------------------------------------*" << endl;
    
    return 1;
}

int menu3() {
    
    
    int choix = 0;
    bool check = false;
    
    cout << "*-------------------------------------------------------------------------------*" << endl;
    cout << "|                                       Menu 3                                  |" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|  1 - Lire un des fichiers officiels de test                                   |" << endl;
    cout << "|  2 - Lire un fichier par saisie manuelle du nom du fichier (avec son chemin)  |" << endl;
    cout << "|  0 - Quitter                                                                  |" << endl;
    cout << "*-------------------------------------------------------------------------------*" << endl;
    
    return 1;
}

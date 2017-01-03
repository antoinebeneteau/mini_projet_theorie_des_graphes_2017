//
//  graphe.cpp
//  mini_projet_2017
//
//  Created by antoine beneteau on 2017-01-03.
//  Copyright © 2017 antoine beneteau. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
#include "graphe.h"


Graphe::Graphe(string nom_fichier)
{
    string a;
    int nombre_taches;
    
    ifstream fichier(nom_fichier.c_str()); // Ouverture du fichier
    
    getline(fichier, a); // On passe la première line
    
    if (fichier) // Si le fichier existe
    {
        fichier >> nombre_taches; // Lecture nombre de tâches
        nombre_taches += 2; // + alpha et omega
        int i,j;
        
        /*  --------------------------------
            MATRICE ADJACENCE
            --------------------------------  */
        
        matrice_adjacence = new bool * [nombre_taches]; // Allocation dynamique de la matrice de type bool (1ere dim)
        i = 0;
        do {
            matrice_adjacence[i] = new bool[nombre_taches]; // Allocation dynamique de la matrice de type bool (2eme dim)
            i++;
        } while(i < nombre_taches);
        
        // Initialisation de la matrice d'adjacence
        for (i = 0; i < nombre_taches; i++)
        {
            for (j = 0; j < nombre_taches; j++)
            {
                matrice_adjacence[i][j] = false; // Initialisation de la matrice avec des 0
            }
        }
        
        /*  --------------------------------
            MATRICE VALEURS
            --------------------------------  */
        
        matrice_valeurs = new int * [nombre_taches]; // Allocation dynamique de la matrice de type int (1ere dim)
        i = 0;
        do {
            matrice_valeurs[i] = new int[nombre_taches]; // Allocation dynamique de la matrice de type int (2eme dim)
            i++;
        } while(i < nombre_taches);
        
        for (i = 0; i < nombre_taches; i++)
        {
            for (j = 0; j < nombre_taches; j++)
            {
                matrice_valeurs[i][j] = -1; // Initialisation de la matrice avec des -1
            }
        }
        
        
        /*  --------------------------------
            MATRICE TRANSITIVE
            --------------------------------  */
        
        matrice_transitive = new bool * [nombre_taches]; // Allocation dynamique de la matrice de type bool (1ere dim)
        i = 0;
        do {
            matrice_transitive[i] = new bool[nombre_taches]; // Allocation dynamique de la matrice de type bool (2eme dim)
            i++;
        } while(i < nombre_taches);
        
        for (i = 0; i < nombre_taches; i++)
        {
            for (j = 0; j < nombre_taches; j++)
            {
                matrice_transitive[i][j] = false; // Initialisation de la matrice avec des 0
            }
        }
    }
    else
    {
        cout << "Erreur Fichier !" << endl;
    }
}


Graphe::~Graphe()
{
    /*  --------------------------------
        MATRICE ADJACENCE
        --------------------------------  */
    for (int i = 0; i < taches; i++)
    {
        delete [] matrice_adjacence[i];
    }
    delete [] matrice_adjacence;
    
    
    
    /*  --------------------------------
        MATRICE VALEURS
        --------------------------------  */
    for (int i = 0; i < taches; i++)
    {
        delete [] matrice_valeurs[i];
    }
    delete [] matrice_valeurs;
    
    
    
    /*  --------------------------------
        MATRICE TRANSITIVE
        --------------------------------  */
    
    for (int i = 0; i < taches; i++)
    {
        delete [] matrice_transitive[i];
    }
    delete [] matrice_transitive;
}

int Graphe::lectureFichierAvecContraintes(string nom_fichier, ofstream& fichier_resultat) {
    
    string chaine;
    int i,j,duree;
    
    ifstream fichier(nom_fichier.c_str());
    
    wcout << L"Vérification de l'existence du fichier... ";
    cout << nom_fichier << "... ";
    
    // Vérification de l'existence du fichier
    if ((fichier) && (fichier_resultat))
    {
        cout << "OK" << endl;
        wcout << L"-> Chaque étape d'exécution pour générer le graphe sera sauvegardé automatiquement dans un fichier résultat" << endl << endl;
        
        fichier_resultat << "Traces d'exécution du graphe: " << endl << endl;
        
        getline(fichier, chaine); // La chaîne "Sommets" est lue, on passe à la suite
        
        // Lire le nombre de tâches (1ère ligne du fichier)
        fichier >> taches;
        
        if (taches > 1)
        {
            cout << ">>> Étape 1: Lecture du nombre de tâches -> " << taches << " sommets." << endl << endl;
            fichier_resultat << "-> Lecture du nombre de tâches -> " << taches << " sommets." << endl;
        }
        else
        {
            cout << ">>> Étape 1: Lecture du nombre de tâches -> " << taches << " sommet." << endl << endl;
            fichier_resultat << "-> Lecture du nombre de tâches -> " << taches << " sommet." << endl;
        }
        
        getline(fichier, chaine); // La chaîne "Sommets + valeurs" est lue, on passe à la suite
        cout << ">>> Étape 2: Lecture des tâches avec leurs durées respectives et sauvegarde en mémoire..." << endl << endl;
        fichier_resultat << "-> Lecture des tâches avec leurs durées respectives" << endl;
        
        // Lecture des tâches
        for (int i = 0; i <= taches; i++)
        {
            getline(fichier, chaine);
            
            if (i >= 1)
            {
                // Ajout en mémoire des tâches
                if (chaine.size() > 3)
                {
                    duree = conversionFluxInt(chaine.substr(2, chaine.size() - 2));
                }
                else
                {
                    duree = conversionFluxInt(chaine.substr(2, 1));
                }
                
                liste_taches.push_back(chaine.substr(0, 1));
                liste_duree.push_back(duree);
                
                wcout << L">>> Ajout de la tâche " << i << " -> Sommet: ";
                cout << chaine.substr(0, 1) << endl;
                fichier_resultat << " * Tâche " << i << " -> Sommet: " << chaine.substr(0, 1) << endl;
            }
        }
        
        Pause();
        system("clear");
        
        getline(fichier, chaine); // La chaîne "Sommets + contraintes" est lue, on passe à la suite
        wcout << L">>> Étape 3: Lecture des contraintes..." << endl << endl;
        fichier_resultat << "-> Lecture des contraintes" << endl;
        
        // Lecture des contraintes
        for (int i = 0; i < nombre_taches; i++)
        {
            /* Dans la ligne lue du fichier:
             - Premier caractère: Sommet
             - Chaque caractère à partir du 2ème, les prédécesseurs (contraintes)
             - La méthode définitionContraintes procèdera à l'extraction de chaque caractère pour l'ajouter en mémoire
             */
            getline(fichier, chaine);
            liste_sommet.push_back(this->definitionContraintes(chaine, fichier_resultat));
        }
        
        cout << endl;
        getline(fichier, chaine); // La chaîne de fin de fichier signifiant qu'on s'arrête de lire
        fichier.close(); // On n'a plus besoin du fichier après
        
        return 1;
    }
    else
    {
        cout << "Erreur, le fichier n'existe pas !" << endl;
        return 0;
    }
    
    return 0;
}




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
#include "utils.h"


void Sommet::ajoutContrainte(string sommet)
{
    liste_contraintes.push_back(sommet);
}

string Sommet::getContrainte(int indice) const
{
    return liste_contraintes[indice];
}

string Sommet::getNomSommet() const
{
    return sommet;
}

void Sommet::setNomSommet(string sommet)
{
    this->sommet = sommet;
}

void Sommet::setRangSommet(int rang)
{
    this->rang = rang;
}

int Sommet::getRangSommet() const
{
    return rang;
}

int Sommet::getNombreContraintes() const
{
    return nbr_contraintes;
}

void Sommet::setNombreContraintes(int nombre_contraintes)
{
    this->nbr_contraintes = nombre_contraintes;
}

string Sommet::getSuccesseur(int indice) const
{
    return liste_successeurs[indice];
}

void Sommet::ajoutSuccesseur(string sommet)
{
    liste_successeurs.push_back(sommet);
}

void Sommet::setNombreSuccesseurs(int nombre_successeurs)
{
    this->nbr_successeurs = nombre_successeurs;
}

int Sommet::getNombreSuccesseurs() const
{
    return nbr_successeurs;
}

void Arc::ajoutArc(string sommet, string contrainte)
{
    this->sommet = sommet;
    predecesseur = contrainte;
}

void Arc::setDuree(int duree)
{
    this->duree = duree;
}

int Arc::getDuree() const
{
    return duree;
}

string Arc::getNomSommet() const
{
    return sommet;
}

string Arc::getPredecesseur() const
{
    return predecesseur;
}


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
        cout << "Error !" << endl;
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

int Graphe::getNombreTaches() const {
    return this->taches;
}

// SET
void Graphe::setNombreTaches(int taches) {
    this->taches = taches;
}

int Graphe::lectureFichierAvecContraintes(string nom_fichier, ofstream& fichier_resultat) {
    
    string chaine;
    int i,j,duree;
    
    ifstream fichier(nom_fichier.c_str());
    
    cout << "Cherche le fichier... ";
    
    if ((fichier) && (fichier_resultat))
    {
        cout << "Trouvé!" << endl;
        
        fichier_resultat << "Traces d'execution :" << endl << endl;
        
        getline(fichier, chaine); // Sommets
        
        // Lire le nombre de tâches (1ère ligne du fichier)
        fichier >> taches;
        
        cout << ">>> Étape 1: Lecture du nombre de taches : " << taches << " sommets." << endl << endl;
        fichier_resultat << "Lecture du nombre de taches " << taches << " sommets." << endl;
        
        getline(fichier, chaine); // Durees
        cout << ">>> Étape 2: Lecture des taches avec leurs durees respectives..." << endl << endl;
        fichier_resultat << "Lecture des taches avec leurs durees respectives" << endl;
        
        // Lecture des tâches
        for (int i = 0; i <= taches; i++)
        {
            getline(fichier, chaine);
            
            if (i >= 1)
            {
                // Ajout en mémoire des tâches
                if (chaine.size() > 3)
                {
                    duree = convStringVersInt(chaine.substr(2, chaine.size() - 2));
                }
                else
                {
                    duree = convStringVersInt(chaine.substr(2, 1));
                }
                
                tab_taches.push_back(chaine.substr(0, 1));
                tab_durees.push_back(duree);
                
                cout << ">>> Ajout de la tache " << i << "Sommet(s): ";
                cout << chaine.substr(0, 1) << endl;
                fichier_resultat << " Tache " << i << "Sommet(s): " << chaine.substr(0, 1) << endl;
            }
        }
        
        Pause();
        
        getline(fichier, chaine); // La chaîne "Sommets + contraintes" est lue, on passe à la suite
        cout << ">>> Etape 3: Lecture des contraintes..." << endl << endl;
        fichier_resultat << "-> Lecture des contraintes" << endl;
        
        // Lecture des contraintes
        for (int i = 0; i < taches; i++)
        {
            /* Dans la ligne lue du fichier:
             - Premier caractère: Sommet
             - Chaque caractère à partir du 2ème, les prédécesseurs (contraintes)
             - La méthode définitionContraintes procèdera à l'extraction de chaque caractère pour l'ajouter en mémoire
             */
            getline(fichier, chaine);
            tab_sommets.push_back(this->definitionContraintes(chaine, fichier_resultat));
        }
        
        cout << endl;
        getline(fichier, chaine); // La chaîne de fin de fichier signifiant qu'on s'arrête de lire
        fichier.close(); // On n'a plus besoin du fichier après
        
        return 1;
    }
    else
    {
        cout << "Error, no file !" << endl;
        return 0;
    }
    
    return 0;
}

Sommet Graphe::definitionContraintes(string chaine, ofstream& fichier_resultat)
{
    Sommet S;
    
    // Ajout du nom du sommet dans l'instance
    S.setNomSommet(chaine.substr(0, 1));
    
    if (chaine.length() == 1) // Aucune contrainte
    {
        // Ajout du nombre de contraintes du sommet dans l'instance: ici 0
        S.setNombreContraintes(chaine.length() - 1);
        
        cout << "Sommet " << chaine.substr(0, 1) << ", ";
        cout << "Il y a donc aucune contrainte à ajouter." << endl;
        
        fichier_resultat << " * Sommet " << chaine.substr(0, 1) << ", aucune contrainte à ajouter." << endl;
    }
    else if (chaine.length() == 3) // 1 contrainte
    {
        // Ajout du nombre de contraintes du sommet dans l'instance: ici 1
        S.setNombreContraintes(chaine.length() - 2);
        
        cout << " Sommet " << chaine.substr(0, 1) << ", ajout de la contrainte... " << endl;
        cout << "Ajout de la contrainte " << chaine.substr(2, 1) << "." << endl << endl;
        S.ajoutContrainte(chaine.substr(2, 1));
        
        fichier_resultat << " Sommet " << chaine.substr(0, 1) << ", ajout d'une contrainte... " << endl;
        fichier_resultat << " Ajout de la contrainte... " << chaine.substr(2, 1) << "." << endl << endl;
    }
    else // 2 contraintes ou plus
    {
        int contraintes = chaine.length() - 2; // Nombre de contraintes
        
        // Ajout du nombre de contraintes du sommet dans l'instance: 2 ou plus
        S.setNombreContraintes(contraintes);
        
        cout << "Sommet " << chaine.substr(0, 1) << ", ajout de " << contraintes << " contrainte(s)... " << endl;
        fichier_resultat << " * Sommet " << chaine.substr(0, 1) << ", ajout de " << contraintes << " contrainte(s)... " << endl;
        
        for (int i = 2; i < (contraintes + 2); i++)
        {
            cout << " Ajout de la contrainte... " << chaine.substr(i, 1) << "." << endl;
            fichier_resultat << " Ajout de la contrainte... " << chaine.substr(i, 1) << "." << endl;
            S.ajoutContrainte(chaine.substr(i, 1));
        }
        
        cout << endl;
    }
    
    return S;
}

void Graphe::creationGrapheOrdonnancement(ofstream& fichier_resultat) {
    
    vector<string>::iterator it;
    int position = 0;
    string sommet_actuel;
    string sommet_cible;
    int nombre_successeurs = 0;
    
    if (fichier_resultat)
    {
        cout << "Création du graphe..." << endl << endl;
        cout << "Propriétés du graphe:" << endl;
        cout << "Nombre de sommet(s): " << this->getNombreTaches() + 2 << " (" << this->getNombreTaches() << " + 2 sommets incidents a et z)" << endl;
        cout << " * Graphe orienté." << endl;
        cout << " * 1 valeur numérique (durée) pour chaque arc." << endl;
        cout << " Maximum 1 arc d'un sommet X vers un sommet Y donné." << endl << endl;
        
        cout << "--> Création des arcs associés aux contraintes de type \"X ne peut commencer lorsque la tâche Y est terminée\"." << endl;
        
        fichier_resultat << "--> Création du graphe..." << endl;
        fichier_resultat << "--> Propriétés du graphe:" << endl;
        fichier_resultat << " - Nombre de sommets: " << this->getNombreTaches() + 2 << " (" << this->getNombreTaches() << " + 2 sommets incidents a et z)" << endl;
        fichier_resultat << " - Graphe orienté." << endl;
        fichier_resultat << " - 1 valeur numérique (durée) pour chaque arc." << endl;
        fichier_resultat << " - Maximum 1 arc d'un sommet X vers un sommet Y donné." << endl << endl;
        fichier_resultat << "--> Création des arcs associés aux contraintes de type \"X ne peut commencer lorsque la tâche Y est terminée\"..." << endl;
        
        // Ajout des arcs
        
        
        cout << endl;
        
        Pause();
        
        // Ajout des successeurs pour chaque arc
        cout << "--> Identification des successeurs de chaques sommets" << endl;
        fichier_resultat << "-> Identification des successeurs de chaque sommet..." << endl;
        
        for (int i = 0; i < taches; i++)
        {
            sommet_actuel = tab_sommets[i].getNomSommet();
            cout << " sommets " << sommet_actuel << ": ";
            fichier_resultat << " sommets " << sommet_actuel << ": ";
            nombre_successeurs = 0;
            
            for (int j = 0; j < taches; j++)
            {
                if (i != j)
                {
                    sommet_cible = tab_sommets[j].getNomSommet();
                    
                    for (int k = 0; k < tab_sommets[j].getNombreContraintes(); k++)
                    {
                        if (tab_sommets[j].getContrainte(k) == sommet_actuel)
                        {
                            nombre_successeurs++;
                            tab_sommets[i].ajoutSuccesseur(sommet_cible);
                            cout << sommet_cible;
                            fichier_resultat << sommet_cible;
                        }
                    }
                    
                    tab_sommets[i].setNombreSuccesseurs(nombre_successeurs);
                }
            }
            
            if (nombre_successeurs == 0)
            {
                cout << "Pas de successeurs." << endl;
                fichier_resultat << "Pas de successeurs." << endl;
                
            }
            else
            {
                cout << " - Successeurs: " << nombre_successeurs << endl;
                fichier_resultat << " - Successeurs: " << nombre_successeurs << endl;
            }
            
            cout << endl;
        }
    }
}
void Graphe::ajoutSommetsIncidents(ofstream& fichier_resultat) {
    
}
void Graphe::definitionMatrices(ofstream& fichier_resultat) {
    
}
void Graphe::FermetureTransitiveMatrice(ofstream& fichier_resultat) {
    
}




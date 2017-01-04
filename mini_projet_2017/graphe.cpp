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
//    /*  --------------------------------
//        MATRICE ADJACENCE
//        --------------------------------  */
//    for (int i = 0; i < taches; i++)
//    {
//        delete [] matrice_adjacence[i];
//    }
//    delete [] matrice_adjacence;
//    
//    
//    
//    /*  --------------------------------
//        MATRICE VALEURS
//        --------------------------------  */
//    for (int i = 0; i < taches; i++)
//    {
//        delete [] matrice_valeurs[i];
//    }
//    delete [] matrice_valeurs;
//    
//    
//    
//    /*  --------------------------------
//        MATRICE TRANSITIVE
//        --------------------------------  */
//    
//    for (int i = 0; i < taches; i++)
//    {
//        delete [] matrice_transitive[i];
//    }
//    delete [] matrice_transitive;
}


int Graphe::getNombreTaches() const {
    return this->taches;
}


int Graphe::getDuree(int i) const {
    return tab_durees[i];
}

bool Graphe::isCircuit() const {
    return this->circuit;
}

int Graphe::getPuissance() const {
    return this->puissance_fermeture_transitive;
}

vector<string> Graphe::getTaches() const {
    return this->tab_taches;
}

vector<Sommet> Graphe::getSommets() const {
    return this->tab_sommets;
}
vector<Arc> Graphe::getArcs() const {
    return this->tab_arcs;
}
vector<int> Graphe::getDurees() const {
    return this->tab_durees;
}

bool** Graphe::getMatriceAdjacence() const {
    return this->matrice_adjacence;
}

int** Graphe::getMatriceValeurs() const {
    return this->matrice_valeurs;
}
bool** Graphe::getMatriceTransitive() const {
    return this->matrice_transitive;
}

map<string, int> Graphe::getRangsSommets() const {
    return this->rangs_sommets;
}
map<string, int> Graphe::getDateTot() const {
    return this->dates_plus_tot;
}
map<string, int> Graphe::getDateTard() const {
    return this->dates_plus_tard;
}

// SET
void Graphe::setNombreTaches(int taches) {
    this->taches = taches;
}

int Graphe::lectureFichierAvecContraintes(string nom_fichier, ofstream& fichier_resultat) {
    
    string chaine;
    int i,j,duree;
    
    cout << "***********   Lecture du fichier contenant le graphe" << endl << endl;
    
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

Arc Graphe::definitionArc(int duree, string sommet, string predecesseur) {
    Arc A;
    A.setDuree(duree);
    A.ajoutArc(sommet, predecesseur);
    
    return A;
}


Sommet Graphe::definitionSommetAlpha(string sommet, int nombre_contraintes, int nombre_successeurs, vector<string> liste_successeurs)
{
    Sommet S;
    
    // Sommet alpha
    S.setNomSommet(sommet);
    S.setNombreContraintes(nombre_contraintes);
    S.setNombreSuccesseurs(nombre_successeurs);
    
    for (int i = 0; i < liste_successeurs.size(); i++)
    {
        S.ajoutSuccesseur(liste_successeurs[i]);
    }
    
    return S;
}

Sommet Graphe::definitionSommetOmega(string sommet, int nombre_contraintes, int nombre_successeurs, vector<string> liste_contraintes)
{
    Sommet S;
    
    // Sommet omega
    S.setNomSommet(sommet);
    S.setNombreContraintes(nombre_contraintes);
    S.setNombreSuccesseurs(nombre_successeurs);
    
    for (int i = 0; i < liste_contraintes.size(); i++)
    {
        S.ajoutContrainte(liste_contraintes[i]);
    }
    
    return S;
}

void Graphe::creationGrapheOrdonnancement(ofstream& fichier_resultat) {
    
    
    cout << "***********   Création du graphe d'ordonancement" << endl << endl;
    
    
    vector<string>::iterator it;
    int position = 0;
    string sommet_actuel;
    string sommet_cible;
    int nombre_successeurs = 0;
    
    if (fichier_resultat)
    {
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
        for (int i = 0; i < taches; i++)
        {
            for (int j = 0; j < tab_sommets[i].getNombreContraintes(); j++)
            {
                if (tab_sommets[i].getNombreContraintes() >= 1)
                {
                    it = find(tab_taches.begin(), tab_taches.end(), tab_sommets[i].getContrainte(j)); // it++
                    position = distance(tab_taches.begin(), it);
                    cout << tab_sommets[i].getContrainte(j) << " --[" << tab_durees[position] << "]--> " << tab_sommets[i].getNomSommet() << endl;
                    tab_arcs.push_back(this->definitionArc(tab_durees[position],tab_sommets[i].getNomSommet(), tab_sommets[i].getContrainte(j)));
                    
                    fichier_resultat << " * " << tab_sommets[i].getContrainte(j) << " --[" << tab_durees[position] << "]--> " << tab_sommets[i].getNomSommet() << endl;
                }
            }
        }
        
        cout << endl;
        
        
        // Ajout des successeurs pour chaque arc
        for (int i = 0; i < taches; i++)
        {
            sommet_actuel = tab_sommets[i].getNomSommet();
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
                        }
                    }
                    
                    tab_sommets[i].setNombreSuccesseurs(nombre_successeurs);
                }
            }
        }
    }
}
void Graphe::ajoutSommetsIncidents(ofstream& fichier_resultat) {
    cout << "***********   Ajout des sommetes incidents" << endl << endl;
    
    int nombre_contraintes, duree;
    string nom_sommet;
    vector<string> successeurs_alpha;
    vector<string> predecesseurs_omega;
    vector<string>::iterator it;
    int position = 0, position_alpha, position_omega;
    string sommet_alpha = "a";
    string sommet_omega = "z";
    int nombre_predecesseurs_omega = 0, nombre_successeurs_alpha = 0, nombre_successeurs;
    
    cout << ">>> Étape 7: Ajout des sommets incidents..." << endl << endl;
    fichier_resultat << "-> Ajout des sommets incidents..." << endl;
    
    // Lecture des contraintes
    int i = 0;
    do {
        nombre_contraintes = tab_sommets[i].getNombreContraintes();
        nombre_successeurs = tab_sommets[i].getNombreSuccesseurs();
        nom_sommet = tab_sommets[i].getNomSommet();
        
        it = find(tab_taches.begin(), tab_taches.end(), nom_sommet); // it++
        position = distance(tab_taches.begin(), it);
        
        duree = this->getDuree(i);
        
        // Si le sommet n'a pas de prédécesseur, alors le sommet incident de début sera son prédécesseur avec une durée nulle (0)
        if (nombre_contraintes == 0)
        {
            successeurs_alpha.push_back(nom_sommet);
            nombre_successeurs_alpha++;
            cout << " * Ajout de l'arc a --[" << tab_durees[position] << "]--> " << nom_sommet << endl;
            fichier_resultat << " * Ajout de l'arc a --[" << tab_durees[position] << "]--> " << nom_sommet << endl;
            tab_arcs.push_back(this->definitionArc(0,nom_sommet, "a")); // Sommet incident de début: "a" (alpha)
        }
        
        // Si le sommet n'a pas de successeur, alors le sommet incident de fin sera son successeur
        if (nombre_successeurs == 0)
        {
            predecesseurs_omega.push_back(nom_sommet);
            nombre_predecesseurs_omega++;
            cout << " * Ajout de l'arc " << nom_sommet << " --[" << tab_durees[position] << "]--> z" << endl;
            fichier_resultat << " * Ajout de l'arc " << nom_sommet << " --[" << tab_durees[position] << "]--> z" << endl;
            tab_arcs.push_back(this->definitionArc(duree, "z", nom_sommet)); // Sommet incident de fin: "z" (omega)
        }
        
        i++;
    } while (i < taches);

    
    // Définition des sommets incidents: ajout des 2 sommets incidents dans la liste des tâches
    this->setNombreTaches(taches + 2);
    
    tab_taches.push_back(sommet_alpha);
    tab_durees.push_back(0);
    tab_taches.push_back(sommet_omega);
    tab_durees.push_back(duree);
    
    tab_sommets.push_back(this->definitionSommetAlpha(sommet_alpha, 0, nombre_successeurs_alpha, successeurs_alpha));
    tab_sommets.push_back(this->definitionSommetOmega(sommet_omega, nombre_predecesseurs_omega, 0, predecesseurs_omega));
    
    // Vu qu'on a ajouté le sommet incident alpha, on doit mettre à jour les sommets qui ont alpha en prédécesseur
    
    cout << endl;
}
void Graphe::definitionMatrices(ofstream& fichier_resultat) {
    cout << "***********   Definition des matrices" << endl << endl;
    
    int nombre_arcs = tab_arcs.size();
    int position1, position2;
    string predecesseur_actuel;
    string sommet_actuel;
    int duree_actuelle;
    vector<string>::iterator it; // Itérateur pour rechercher la position d'un élément
    
    cout << ">>> Etape 8: Lecture des arcs et initialisation des matrices d'adjacence et des valeurs..." << endl << endl;
    fichier_resultat << "-> Lecture des arcs et initialisation des matrices d'adjacence et des valeurs..." << endl;
    
    // Lecture des arcs
    for (int i = 0; i < nombre_arcs; i++)
    {
        predecesseur_actuel = tab_arcs[i].getPredecesseur();
        sommet_actuel = tab_arcs[i].getNomSommet();
        duree_actuelle = tab_arcs[i].getDuree();
        
        cout << " * Arc " << (i + 1) << ": " << tab_arcs[i].getPredecesseur() << " --[" << tab_arcs[i].getDuree() << "]--> " << tab_arcs[i].getNomSommet() << endl;
        fichier_resultat << " * Arc " << (i + 1) << ": " << tab_arcs[i].getPredecesseur() << " --[" << tab_arcs[i].getDuree() << "]--> " << tab_arcs[i].getNomSommet() << endl;
        
        it = find(tab_taches.begin(), tab_taches.end(), sommet_actuel); // it++
        position1 = distance(tab_taches.begin(), it);
        
        it = find(tab_taches.begin(), tab_taches.end(), predecesseur_actuel); // it++
        position2 = distance(tab_taches.begin(), it);
        
        wcout << L"   -> Passage a 1 dans la matrice d'adjacence, case[" << position2 << "][" << position1 << "]" << endl;
        wcout << L"   -> Passage a " << duree_actuelle << " dans la matrice des valeurs, case[" << position2 << "][" << position1 << "]" << endl;
        
        fichier_resultat << "   -> Passage a 1 dans la matrice d'adjacence, case[" << position2 << "][" << position1 << "]" << endl;
        fichier_resultat << "   -> Passage a " << duree_actuelle << " dans la matrice des valeurs, case[" << position2 << "][" << position1 << "]" << endl;
        
        matrice_adjacence[position2][position1] = true;
        matrice_valeurs[position2][position1] = duree_actuelle;
    }
}
void Graphe::FermetureTransitiveMatrice(ofstream& fichier_resultat) {
    cout << "***********   Fermeture transitive matrice" << endl << endl;
    
    /* Méthode pour calculer la fermeture transitive d'un graphe à l'aide de la matrice d'adjacence
     -> On utilisera l'algorithme de Warshall ou Roy-Warshall:
     - Cet algorithme consiste à
     
     */
    
    // Initialisation d'une matrice booléenne: tableau à 2 dimensions du type bool
    bool **matrice_adjacence1 = new bool * [taches];
    
    for (int i = 0; i < taches; i++)
    {
        matrice_adjacence1[i] = new bool[taches];
    }
    
    // Initialisation de la matrice d'adjacence
    for (int i = 0; i < taches; i++)
    {
        for (int j = 0; j < taches; j++)
        {
            matrice_adjacence1[i][j] = false;
        }
    }
    
    cout << ">>> Étape 9: Calcul de la matrice d'adjacence associée à sa fermeture transitive (" << taches << " sommets -> " << taches - 2 << L" puissances de 2 à " << taches - 1 << ")..." << endl << endl;
    wcout << L" -> Matrice d'adjacence M avant calcul de la fermeture transitive: " << endl << endl;
    
   	fichier_resultat << "-> Calcul de la matrice d'adjacence associée à sa fermeture transitive (" << taches << " sommets -> " << taches - 2 << " puissances de 2 à " << taches - 1 << ")..." << endl << endl;
    fichier_resultat << " * Matrice d'adjacence M avant calcul de la fermeture transitive: " << endl << endl;
    
    affichageMatriceAdjacencePuissance(1, false, fichier_resultat);
    
    cout << endl;
    
    for (int n = 2; n < taches; n++)
    {
        if (n == 2)
        {
            wcout << L" -> Iteration " << (n - 1) << ": M^" << n << " = M x M" << endl << endl;
            fichier_resultat << " -> Itération " << (n - 1) << ": M^" << n << " = M x M" << endl << endl;
        }
        else
        {
            wcout << L" -> Iteration " << (n - 1) << ": M^" << n << " = M^" << (n - 1) << " x M" << endl << endl;
            fichier_resultat << " -> Iteration " << (n - 1) << ": M^" << n << " = M x M" << endl << endl;
        }
        
        for (int i = 0; i < taches; i++)
        {
            for (int j = 0; j < taches; j++)
            {
                for (int k = 0; k < taches; k++)
                {
                    if (n == 2)
                    {
                        matrice_adjacence1[i][j] += (bool)((int)matrice_adjacence[i][k] * (int)matrice_adjacence[k][j]);
                    }
                    else
                    {
                        matrice_adjacence1[i][j] += (bool)((int)matrice_adjacence[i][k] * (int)matrice_adjacence1[k][j]);
                    }
                }
                
                if (n == 2)
                {
                    matrice_transitive[i][j] = (matrice_adjacence1[i][j] || matrice_adjacence[i][j]);
                }
                else
                {
                    matrice_transitive[i][j] = (matrice_adjacence1[i][j] || matrice_transitive[i][j]);
                }
            }
        }
        
        affichageMatriceAdjacencePuissance(n, false, fichier_resultat);
        puissance_fermeture_transitive = n;
    }
}

void Graphe::affichageMatriceAdjacence() const
{
    system("clear");
    
    cout << ">>> Matrice d'adjacence: " << endl << endl;
    
    for (int i = 0; i < taches; i++)
    {
        if (i == 0)
        {
            cout << "    " << tab_sommets[i].getNomSommet() << "  ";
        }
        else
        {
            cout << tab_sommets[i].getNomSommet() << "  ";
        }
    }
    
    cout << endl;
    
    // Affichage du contenu de la matrice
    for (int i = 0; i < taches; i++)
    {
        cout << tab_sommets[i].getNomSommet() << "   ";
        
        for (int j = 0; j < taches; j++)
        {
            if (matrice_adjacence[i][j])
            {
                cout << "1  "; 
            }
            else
            {
                cout << "0  ";
            }
        }
        
        cout << endl;
    }
    
    cout << endl;
}


void Graphe::affichageMatriceAdjacencePuissance(int puissance, bool affichage, ofstream& fichier_resultat) const
{
    // Si on n'est pas dans la détection de circuit
    if (affichage == true)
    {
        system("clear");
        
        wcout << L">>> Matrice d'adjacence associée à sa fermeture transitive: " << endl;
        wcout << L" -> Ici, avec " << taches << " sommets: M^" << puissance << endl << endl;
    }
    
    // Affichage du contenu de la matrice
    for (int i = 0; i < taches; i++)
    {
        // Alignement du signe égal de l'expression au milieu de la hauteur de la matrice
        if (((taches % 2) == 0) && (i == (taches / 2) - 1))
        {
            if (puissance == 1)
            {
                cout << "M =    ";
                
                // Sauvegarde de la trace d'exécution sur le fichier
                if (affichage == false)
                {
                    fichier_resultat << "M =    ";
                }
            }
            else
            {
                cout << "M^" << puissance << " =   ";
                
                // Sauvegarde de la trace d'exécution sur le fichier
                if (affichage == false)
                {
                    fichier_resultat << "M^" << puissance << " =   ";
                }
            }
        }
        else if (((taches % 2) == 1) && (i == taches / 2))
        {
            if (puissance == 1)
            {
                cout << "M =    ";
                
                // Sauvegarde de la trace d'exécution sur le fichier
                if (affichage == false)
                {
                    fichier_resultat << "M =    ";
                }
            }
            else
            {
                cout << "M^" << puissance << " =   ";
                
                // Sauvegarde de la trace d'exécution sur le fichier
                if (affichage == false)
                {
                    fichier_resultat << "M^" << puissance << " =   ";
                }
            }
        }
        else
        {
            if (puissance >= 10)
            {
                cout << "         ";
                
                // Sauvegarde de la trace d'exécution sur le fichier
                if (affichage == false)
                {
                    fichier_resultat << "         ";
                }
            }
            else if (puissance == 1)
            {
                cout << "       ";
                
                // Sauvegarde de la trace d'exécution sur le fichier
                if (affichage == false)
                {
                    fichier_resultat << "       ";
                }
            }
            else
            {
                cout << "        ";
                
                // Sauvegarde de la trace d'exécution sur le fichier
                if (affichage == false)
                {
                    fichier_resultat << "        ";
                }
            }
        }
        
        for (int j = 0; j < taches; j++)
        {
            // Puissance = 1: on s'intéresse à la matrice d'adjacence originale, puissance > 1: la matrice transitive actuelle
            if (puissance == 1)
            {
                if (matrice_adjacence[i][j])
                {
                    cout << "1  "; 
                    
                    // Sauvegarde de la trace d'exécution sur le fichier
                    if (affichage == false)
                    {
                        fichier_resultat << "1  ";
                    }
                }
                else
                {
                    cout << "0  ";
                    
                    // Sauvegarde de la trace d'exécution sur le fichier
                    if (affichage == false)
                    {
                        fichier_resultat << "0  ";
                    }
                }
            }
            else
            {
                if (matrice_transitive[i][j])
                {
                    cout << "1  "; 
                    
                    // Sauvegarde de la trace d'exécution sur le fichier
                    if (affichage == false)
                    {
                        fichier_resultat << "1  ";
                    }
                }
                else
                {
                    cout << "0  ";
                    
                    // Sauvegarde de la trace d'exécution sur le fichier
                    if (affichage == false)
                    {
                        fichier_resultat << "0  ";
                    }
                }
            }
        }
        
        cout << endl;
        fichier_resultat << endl;
    }
    
    cout << endl;
    fichier_resultat << endl;
}

bool Graphe::detectionCircuit(ofstream& fichier_resultat) {
    wcout << L">>> Étape 10: Détection de circuit dans le graphe..." << endl;
   	fichier_resultat << "-> Détection de circuit dans le graphe..." << endl;
    
   	/* La méthode la plus simple pour détecter un circuit est de lire le contenu de la matrice d'adjacence associée à sa fermeture transitive:
     - Il faut lire chaque case de la diagonale
     - Si toutes les cases de la diagonale sont à 0, alors le graphe est sans circuit
     - Sinon, si au moins 1 case de la diagonale est égale à 1, le graphe contient alors un circuit, on interrompt la lecture */
    
   	// Étape 1: Vérification de la présence de boucles
   	wcout << L"-> Lecture de la matrice d'adjacence associée à sa fermeture transitive: " << endl << endl;
    
   	affichageMatriceAdjacencePuissance(puissance_fermeture_transitive, false, fichier_resultat);
    
   	for (int i = 0; i < taches; i++)
   	{
        for (int j = 0; j < taches; j++)
        {
            if (i == j)
            {
                // Si la case de la diagonale est un 1 (ici si c'est un booléen à l'état "vrai"), alors il y a un circuit
                if (matrice_transitive[i][j] == true)
                {
                    cout << " -> ATTENTION: Le graphe contient au moins un circuit (il y a au moins un 1 dans la diagonale) !" << endl;
                    fichier_resultat << " -> ATTENTION: Le graphe contient au moins un circuit (il y a au moins un 1 dans la diagonale) !" << endl;
                    fichier_resultat << endl << ">>> ALERTE: Le calcul du rang de chaque sommet est impossible !" << endl;
                    circuit = true;
                    
                    Pause();
                    return true;
                }
            }
        }
   	}
    
   	// Si aucune case de la diagonale de la matrice d'adjacence associée à sa fermeture transitive
   	cout << " -> Le graphe n'a pas de circuit (que des 0 dans la diagonale)." << endl;
   	fichier_resultat << " -> Le graphe n'a pas de circuit (que des 0 dans la diagonale)." << endl;
    fichier_resultat << endl << ">>> Le calcul du rang de chaque sommet est possible !" << endl << endl;
   	circuit = false;
    
   	return false;
}


void Graphe::definitionRangsSommets(ofstream& fichier_resultat)
{
    system("clear");
    
    string sommet_cible;
    wcout << L">>> Étape 11: Définition des rangs des sommets..." << endl << endl;
    fichier_resultat << "-> Définition des rangs des sommets..." << endl;
    
    for (int i = 0; i < taches; i++)
    {
        sommet_cible = tab_sommets[i].getNomSommet();
        cout << " * Sommet : " << sommet_cible;
        rangs_sommets[sommet_cible] = calculRecursifRangSommet(i);
        wcout << L"  -> Rang attribué: " << rangs_sommets[sommet_cible] << endl;
        
        fichier_resultat << " * Sommet : " << sommet_cible << "  -> Rang attribué: " << rangs_sommets[sommet_cible] << endl;
        
        // On sauvegarde le rang dans une instance de la classe Sommet via le tableau liste_sommet
        tab_sommets[i].setRangSommet(rangs_sommets[sommet_cible]);
    }
}

int Graphe::calculRecursifRangSommet(int position_sommet)
{
    /* Le conteneur de la STL set permet de décrire un ensemble ordonné et sans doublons d'éléments, de complexité O(log(n)) pour la recherche et l'insertion.
     En effet, la structure std::set tire partie de l'ordre sur T pour construire une structure d'arbre rouge noir, ce qui permet une recherche
     logarithmique d'un élément. Cela va nous être extrêmement utile pour procéder à la définition du rang du sommet ciblé en procédant à des
     appels récursifs de la méthode pour parcourir le graphe depuis le sommet ciblé en passant par ses prédécesseurs. Si le sommet n'a pas de
     prédécesseur, il aura automatiquement le rang 0.
     On parcourt la graphe à l'aide de la matrice d'adjacence en appelant récursivement la méthode s'il y a une relation (un 1) à la case situé à la position:
     - Ligne: la valeur de i dans la boucle for
     - Colonne: le sommet qui nous intéresse
     -> Après avoir effectué ses appels récursifs successifs, c'est à dire dès que le parcours du graphe sera terminé par un sommet sans prédécesseur.
     Le rang est déterminé par le dernier élément du conteneur set<int> rempli par le parcours récursif de la méthode. */
    
    set<int> predecesseur;
    
    for (int i = 0; i < taches; i++)
    {
        if (matrice_adjacence[i][position_sommet])
        {
            /* Recherche du predecesseur du sommet actuel en lisant la matrice d'adjacence, on cible:
             -> Ligne numéro i dans la boucle for
             -> Colonne numéro position_sommet (numéro sommet)
             -> Si la case est à 1 (true): appel récursif de la méthode */
            predecesseur.insert(calculRecursifRangSommet(i));
        }
    }
    
    // S'il n'y a pas de successeur, alors le rang du sommet est donc 0 par défaut
    if (predecesseur.size() == 0)
    {
        return 0;
    }
    else
    {
        /* Si le conteneur set est rempli après appels récursifs successifs, on retourne le dernier élément du conteneur
         -> Le dernier élément de predecesseur est le rang sommet en question
         -> rbegin = dernier élément de set<int>, parcours en sens inverse (reverse_iterator) */
        return *predecesseur.rbegin() + 1;
    }
}

void Graphe::definitionCalendrierAuPlusTot(ofstream& fichier_resultat)
{
    
    /* L'utilisation d'un tableau associatif map<string, int> est très utile ici:
     -> On va récupérer les rangs du tableau associatif map<string, int> rangs_sommets
     -> On va stocker le résultat du calcul récursif de la date au plus tard dans le tableau associatif
     map<string, int> dates_plus_tard
     */
    wcout << L">>> Étape 12: Définition du calendrier au plus tôt..." << endl << endl;
    fichier_resultat << "-> Définition du calendrier au plus tôt..." << endl;
    int i = 0;
    
    // Pour chaque sommet, on calcule sa date au plus tôt
    for (map<string, int>::iterator it = rangs_sommets.begin(); it != rangs_sommets.end(); it++)
    {
        dates_plus_tot[it->first] = calculRecursifDateAuPlusTot(i);
        cout << " -> Sommet: " << it->first << ", ";
        wcout << L"Date au plus tôt attribuée: " << dates_plus_tot[it->first] << endl;
        fichier_resultat << " * Sommet: " << it->first << ", Date au plus tôt attribuée: " << dates_plus_tot[it->first] << endl;
        i++;
    }
}

int Graphe::calculRecursifDateAuPlusTot(int position_sommet)
{
    /* Pour calculer la date au plus tôt d'un sommet = max(date au plus tôt(prédécesseur)) - duree prédécesseur
     max(date au plus tôt(prédécesseur)) -> matrice_valeurs[*it][position_sommet]
     calculRecursifDateAuPlusTot(*it), it dans un boucle for itérée par un iterator sur set<int> prédecesseur
     duree_sommet[sommet] -> matrice_valeurs[position_sommet][*it] */
    
    set<int> predecesseur; // La liste de tous les prédécesseurs du graphe
    
    for (int i = 0; i < taches; i++)
    {
        if (matrice_adjacence[i][position_sommet])
        {
            /* Recherche du predecesseur du sommet actuel en lisant la matrice d'adjacence, on cible:
             -> Ligne numéro i dans la boucle for
             -> Colonne numéro position_sommet (numéro sommet) */
            predecesseur.insert(i);
        }
    }
    
    // Cette liste nous permettra de séléctionner le maximum de la date au plus tôt du prédécesseur
    set<int> date_predecesseur;
    
   	for (set<int>::iterator it = predecesseur.begin(); it != predecesseur.end(); it++)
    {
        date_predecesseur.insert(matrice_valeurs[*it][position_sommet] + calculRecursifDateAuPlusTot(*it));
    }
    
    // S'il n'y a pas de successeur, alors la date au plus tard du sommet est donc 0 par défaut
    if (date_predecesseur.empty())
    {
        return 0;
    }
    else
    {
        /* Si le conteneur set est rempli après appels récursifs successifs, on retourne le dernier élément du conteneur
         -> Le dernier élément de date_predecesseur est la date au plus tôt du sommet en question
         -> rbegin = dernier élément de set<int>, parcours en sens inverse (reverse_iterator) */
        return *date_predecesseur.rbegin();
    }
}

void Graphe::definitionCalendrierAuPlusTard(ofstream& fichier_resultat)
{
    system("clear");
    
    wcout << L">>> Étape 13: Définition du calendrier au plus tard..." << endl << endl;
    fichier_resultat << "-> Définition du calendrier au plus tard..." << endl;
    int i = 0;
    
    /* L'utilisation d'un tableau associatif map<string, int> est très utile ici:
     -> On va récupérer les rangs du tableau associatif map<string, int> rangs_sommets
     -> On va stocker le résultat du calcul récursif de la date au plus tard dans le tableau associatif
     map<string, int> dates_plus_tard */
    
    // Pour chaque sommet, on calcule sa date au plus tard
    for (map<string, int>::iterator it = rangs_sommets.begin(); it != rangs_sommets.end(); it++)
    {
        // Les sommets sont dans l'ordre, on prend le numéro (ici i) faisant référence au nom du sommet
        dates_plus_tard[it->first] = calculRecursifDateAuPlusTard(i);
        cout << " -> Sommet: " << it->first << ", ";
        wcout << L"Date au plus tard attribuée: " << dates_plus_tard[it->first] << endl;
        fichier_resultat << " * Sommet: " << it->first << ", Date au plus tard attribuée: " << dates_plus_tard[it->first] << endl;
        i++;
    }
}

int Graphe::calculRecursifDateAuPlusTard(int position_sommet)
{
    /* Pour calculer la date au plus tard d'un sommet = min(date au plus tard(successeur)) - duree_sommet[sommet]
     min(date au plus tard(successeur)) -> calculRecursifDateAuPlusTard(*it), it dans un boucle for itérée par un iterator sur set<int> successeur
     duree_sommet[sommet] -> matrice_valeurs[position_sommet][*it] */
    
    set<int> successeur;
    
    for (int i = 0; i < taches; i++)
    {
        /* Recherche du successeur du sommet actuel en lisant la matrice d'adjacence, on cible:
         -> Ligne numéro position_sommet (numéro sommet)
         -> Colonne numéro i dans la boucle for */
        if (matrice_adjacence[position_sommet][i])
        {
            // Recherche du successeur du sommet actuel
            successeur.insert(i);
        }
    }
    
    // Cette liste nous permettra de séléctionner le minimum de la date au plus tard du prédécesseur
    set<int> date_successeur;
    
   	for (set<int>::iterator it = successeur.begin(); it != successeur.end(); it++)
    {
        // La date au plus tard minimale des successeurs s'obtient par appels récursifs successifs de la méthode avec le successeur en question
        date_successeur.insert(calculRecursifDateAuPlusTard(*it) - matrice_valeurs[position_sommet][*it]);
    }
    
    // S'il n'y a pas de successeur, alors la date au plus tard du sommet est égale à la date au plus tôt
    if (date_successeur.empty())
    {
        return calculRecursifDateAuPlusTot(position_sommet);
    }
    else
    {
        /* Si le conteneur set est rempli après appels récursifs successifs, on retourne le premier élément du conteneur
         -> Le premier élément de date_successeur est la date au plus tard du sommet en question */
        return *date_successeur.begin();
    }
}




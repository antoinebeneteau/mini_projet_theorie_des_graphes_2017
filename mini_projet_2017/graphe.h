//
//  graphe.hpp
//  mini_projet_2017
//
//  Created by antoine beneteau on 2017-01-03.
//  Copyright © 2017 antoine beneteau. All rights reserved.
//

#ifndef graphe_h
#define graphe_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

class Sommet
{
private:
    string sommet;
    int nbr_contraintes;
    int nbr_successeurs;
    int rang;
    vector<string> liste_contraintes;
    vector<string> liste_successeurs;
    
public:
    void ajoutContrainte(string sommet);
    string getContrainte(int indice) const;
    string getNomSommet() const;
    void setNomSommet(string sommet);
    void setRangSommet(int rang);
    int getRangSommet() const;
    int getNombreContraintes() const;
    void setNombreContraintes(int nombre_contraintes);
    string getSuccesseur(int indice) const;
    void ajoutSuccesseur(string sommet);
    void setNombreSuccesseurs(int nombre_successeurs);
    int getNombreSuccesseurs() const;
};

class Arc
{
private:
    string predecesseur;
    string sommet;
    int duree;
    
public:
    void ajoutArc(string sommet, string contrainte);
    void setDuree(int duree);
    int getDuree() const;
    string getNomSommet() const;
    string getPredecesseur() const;
};

class Graphe
{
private:
    int taches;
    int puissance;
    bool estUnCircuit;
    
    // Tableaux
    vector<string> tabTaches;
    vector<int> tabDurees;
    vector<Sommet> tabSommets;
    vector<Arc> tabArcs;
    
    // Matrices
    bool** matriceAdjacence;
    int** matriceValeurs;
    bool** matriceTransitive;
    
    // Tableaux dictionaire
    map<string, int> rangs_sommets;
    map<string, int> dates_plus_tot;
    map<string, int> dates_plus_tard;
    
public:
    // Destructeur
    ~Graphe();
    
    // Lecture Fichier
    Graphe(string nom_fichier); // Constructeur
    
    int lectureFichierAvecContraintes(string nom_fichier, ofstream& fichier_resultat);
    
    // GET
    int obtenirNombreTaches() const;
    vector<string> obtenirTaches() const;
    vector<Sommet> obtenirSommets() const;
    vector<Arc> obtenirArcs() const;
    vector<int> obtenirDurees() const;
    int obtenirPuissance() const;
    int obtenirDuree(int i) const;
    bool estCircuit() const;
    bool** obtenirMatriceAdjacence() const;
    int** obtenirMatriceValeurs() const;
    bool** obtenirMatriceTransitive() const;
    map<string, int> obtenirRangsSommets() const;
    map<string, int> obtenirDateTot() const;
    map<string, int> obtenirDateTard() const;
    
    // SET
    void definirNombreTaches(int taches);
    
    // Principales
    Sommet initContraintes(string chaine, ofstream& fichier_resultat);
    Arc initArc(int duree, string sommet, string predecesseur);
    Sommet initSommetAlpha(string sommet, int nombre_contraintes, int nombre_successeurs, vector<string> liste_successeurs);
    Sommet initSommetOmega(string sommet, int nombre_contraintes, int nombre_successeurs, vector<string> liste_contraintes);
    
    void grapheOrdonnancement(ofstream& fichier_resultat);
    void ajoutSommetsIncidents(ofstream& fichier_resultat);
    void initMatrices(ofstream& fichier_resultat);
    void matriceTransitiveFermeture(ofstream& fichier_resultat);
    bool detectionCircuit(ofstream& fichier_resultat);
    
    void initRangsSommets(ofstream& fichier_resultat);
    int calculRecursifRangSommet(int position_sommet);
    void initCalendrierAuPlusTard(ofstream& fichier_resultat);
    void initCalendrierAuPlusTot(ofstream& fichier_resultat);
    int calculRecursifDateAuPlusTard(int position_sommet);
    int calculRecursifDateAuPlusTot(int position_sommet);
    
    
    // Affichages
    void affichageMatriceAdjacence() const;
    void affichageMatriceAdjacencePuissance(int puissance, bool affichage, ofstream& fichier_resultat) const;
    
    
};

#endif /* graphe_h */

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
    vector<string> tab_taches;
    vector<int> tab_durees;
    vector<Sommet> tab_sommets;
    vector<Arc> tab_arcs;
    
    bool **matrice_adjacence;
    bool **matrice_transitive;
    int **matrice_valeurs;
    
public:
    ~Graphe();
    
    // Lecture Fichier
    Graphe(string nom_fichier);
    int lectureFichierAvecContraintes(string nom_fichier, ofstream& fichier_resultat);
    
    // GET
    int getNombreTaches() const;
    int getDuree(int i) const;
    
    // SET
    void setNombreTaches(int taches);
    
    // Principales
    Sommet definitionContraintes(string chaine, ofstream& fichier_resultat);
    Arc definitionArc(int duree, string sommet, string predecesseur);
    Sommet definitionSommetAlpha(string sommet, int nombre_contraintes, int nombre_successeurs, vector<string> liste_successeurs);
    Sommet definitionSommetOmega(string sommet, int nombre_contraintes, int nombre_successeurs, vector<string> liste_contraintes);
    
    void creationGrapheOrdonnancement(ofstream& fichier_resultat);
    void ajoutSommetsIncidents(ofstream& fichier_resultat);
    void definitionMatrices(ofstream& fichier_resultat);
    void FermetureTransitiveMatrice(ofstream& fichier_resultat);
    
    
};

#endif /* graphe_h */

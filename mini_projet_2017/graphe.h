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
    string ObtenirContrainte(int indice) const;
    string ObtenirNomSommet() const;
    void DefinirNomSommet(string sommet);
    void DefinirRangSommet(int rang);
    int ObtenirRangSommet() const;
    int ObtenirNombreContraintes() const;
    void DefinirNombreContraintes(int nombre_contraintes);
    string ObtenirSuccesseur(int indice) const;
    void ajoutSuccesseur(string sommet);
    void DefinirNombreSuccesseurs(int nombre_successeurs);
    int ObtenirNombreSuccesseurs() const;
};

class Arc
{
private:
    string predecesseur;
    string sommet;
    int duree;
    
public:
    void ajoutArc(string sommet, string contrainte);
    void DefinirDuree(int duree);
    int ObtenirDuree() const;
    string ObtenirNomSommet() const;
    string ObtenirPredecesseur() const;
};

class Graphe
{
private:
    int taches;
    int puissance_fermeture_transitive;
    bool circuit;
    
    
    vector<string> tab_taches;
    vector<int> tab_durees;
    vector<Sommet> tab_sommets;
    vector<Arc> tab_arcs;
    
    bool **matrice_adjacence;
    bool **matrice_transitive;
    int **matrice_valeurs;
    
    map<string, int> rangs_sommets;
    map<string, int> dates_plus_tot;
    map<string, int> dates_plus_tard;
    
public:
    ~Graphe();
    
    // Lecture Fichier
    Graphe(string nom_fichier);
    int lectureFichierAvecContraintes(string nom_fichier, ofstream& fichier_resultat);
    
    // GET
    int getNombreTaches() const;
    vector<string> getTaches() const;
    vector<Sommet> getSommets() const;
    vector<Arc> getArcs() const;
    vector<int> getDurees() const;
    int getPuissance() const;
    int getDuree(int i) const;
    bool isCircuit() const;
    bool** getMatriceAdjacence() const;
    int** getMatriceValeurs() const;
    bool** getMatriceTransitive() const;
    map<string, int> getRangsSommets() const;
    map<string, int> getDateTot() const;
    map<string, int> getDateTard() const;
    
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
    bool detectionCircuit(ofstream& fichier_resultat);
    
    void definitionRangsSommets(ofstream& fichier_resultat);
    int calculRecursifRangSommet(int position_sommet);
    void definitionCalendrierAuPlusTard(ofstream& fichier_resultat);
    void definitionCalendrierAuPlusTot(ofstream& fichier_resultat);
    int calculRecursifDateAuPlusTard(int position_sommet);
    int calculRecursifDateAuPlusTot(int position_sommet);
    
    
    // Affichages
    void affichageMatriceAdjacence() const;
    void affichageMatriceAdjacencePuissance(int puissance, bool affichage, ofstream& fichier_resultat) const;
    
    
};

#endif /* graphe_h */

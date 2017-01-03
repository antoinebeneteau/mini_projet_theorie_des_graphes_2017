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


class Graphe
{
private:
    int taches;
    vector<string> liste_taches;
    
    bool **matrice_adjacence;
    bool **matrice_transitive;
    int **matrice_valeurs;
    
public:
    Graphe(string nom_fichier);
    ~Graphe();
    
    int lectureFichierAvecContraintes(string nom_fichier, ofstream& fichier_resultat);
    int getNombreTaches() const;
    void setNombreTaches(int nombre_taches);
    
};

#endif /* graphe_h */

//
//  utils.hpp
//  mini_projet_2017
//
//  Created by antoine beneteau on 2017-01-03.
//  Copyright © 2017 antoine beneteau. All rights reserved.
//

#ifndef utils_h
#define utils_h

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

using namespace std;


// String -> Int
int convStringVersInt(string flux);
void Pause();

void affichageListeTaches(Graphe g);
void affichageListeContraintes(Graphe g);
void affichageListeSuccesseurs(Graphe g);
void affichageListeArcs(Graphe g);
void affichageMatriceAdjacence(Graphe g);
void affichageMatriceValeur(Graphe g);
void affichageMatriceTransitive(Graphe g);
void affichageRangsSommets(Graphe g);
void affichageTableauDates(Graphe g);
void affichageDiagrammeGanttCalendrierPlusTot(Graphe g);
void affichageDiagrammeGanttCalendrierPlusTard(Graphe g);


#endif /* utils_h */

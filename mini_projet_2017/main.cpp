//
//  main.cpp
//  mini_projet_2017
//
//  Created by antoine beneteau on 2017-01-03.
//  Copyright © 2017 antoine beneteau. All rights reserved.
//

#include <stdio.h>
#include "graphe.h"
#include "menu.h"
#include "utils.h"


int main(void)
{
    map<int, string> fichiers;
    map<int, string> fichiers_R;
    
    fichiers[1] = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes1.txt";
    fichiers[2] = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes2.txt";
    fichiers[3] = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes3.txt";
    fichiers[4] = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes4.txt";
    fichiers[5] = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes5.txt";
    
    fichiers_R[1] = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes1_R.txt";
    fichiers_R[2] = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes2_R.txt";
    fichiers_R[3] = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes3_R.txt";
    fichiers_R[4] = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes4_R.txt";
    fichiers_R[5] = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes5_R.txt";

    
    int choix = 0;
    string nom_fichier, nom_fichier_resultat;
    
    do {
        
        int choix = menu1();
        
        if (choix == 1) {
            choix = menu2();
            
            nom_fichier = fichiers[choix];
            nom_fichier_resultat = fichiers_R[choix];
            
            ofstream fichier_resultat(nom_fichier_resultat.c_str(), ios::trunc);
            
            Pause();
            
            Graphe graphe(nom_fichier);
            
            bool fichierOK = graphe.lectureFichierAvecContraintes(nom_fichier, fichier_resultat);
            
            if (fichierOK)
            {
                Pause();
                graphe.creationGrapheOrdonnancement(fichier_resultat);
                Pause();
                graphe.ajoutSommetsIncidents(fichier_resultat);
                Pause();
                graphe.definitionMatrices(fichier_resultat);
                Pause();
                graphe.FermetureTransitiveMatrice(fichier_resultat);
                Pause();
                
                bool circuit = graphe.detectionCircuit(fichier_resultat);
                if (!circuit) {
                    Pause();
                    graphe.definitionRangsSommets(fichier_resultat);
                    Pause();
                    graphe.definitionCalendrierAuPlusTot(fichier_resultat);
                    Pause();
                    graphe.definitionCalendrierAuPlusTard(fichier_resultat);
                    Pause();
                }
                
                fichier_resultat << endl << ">>> Fin des résultats." << endl;
                fichier_resultat.close();
                
                choix = 11111;
                while (choix != 0) {
                    choix = menu3(graphe.estCircuit());
                    
                    if (choix == 1) {
                        // Affichage taches
                        affichageListeTaches(graphe);
                    } else if (choix == 2) {
                        // Affichage contraintes
                        affichageListeContraintes(graphe);
                    } else if (choix == 3) {
                        // Affichage successeur
                        affichageListeSuccesseurs(graphe);
                    } else if (choix == 4) {
                        // Affichage arcs
                        affichageListeArcs(graphe);
                    } else if (choix == 5) {
                        // Affichage Matrice adjacence
                        affichageMatriceAdjacence(graphe);
                    } else if (choix == 6) {
                        // Affichage Matrice valeurs
                        affichageMatriceValeur(graphe);
                    } else if (choix == 7) {
                        // Affichage Matrice puissance
                        graphe.affichageMatriceAdjacencePuissance(graphe.obtenirPuissance(), true, fichier_resultat);
                    } else if (choix == 8) {
                        // Affichage rangs sommet
                        cout << "Pas fait" << endl;
                    } else if (choix == 9) {
                        // Affichage tableau dates
                        cout << "Pas fait" << endl;
                    } else if (choix == 10) {
                        // Affichage  Diagramme gant calendrier plus tot
                        cout << "Pas fait" << endl;
                    } else if (choix == 11) {
                        // Affichage  Diagramme gant calendrier plus tard
                        cout << "Pas fait" << endl;
                    }
                }
                
            } else {
                cout << ">>> Probleme de fichier !" << endl << endl;
            }
            
            
        } else if(choix == 2) {
            
        } else if (choix == 0){
            
        }
    
    } while (choix != 0);



    return 0;
}



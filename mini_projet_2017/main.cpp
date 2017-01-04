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
    
    int choix = 0, fichier_choisi = 0, option = 0;
    bool check = false;
    string nom_fichier, nom_fichier_resultat;
    
    
    do {
        
        int choix = menu1();
        
        if (choix == 1) {
            choix = menu2();
            
            switch (choix) {
                case 0:
                    
                    break;
                case 1:
                    nom_fichier = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes1.txt";
                    nom_fichier_resultat = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes1_R.txt";
                    break;
                case 2:
                    nom_fichier = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes2.txt";
                    nom_fichier_resultat = "tableau_contraintes2_R.txt";
                    break;
                case 3:
                    nom_fichier = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes3.txt";
                    nom_fichier_resultat = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes3_R.txt";
                    break;
                case 4:
                    nom_fichier = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes4.txt";
                    nom_fichier_resultat = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes4_R.txt";
                    break;
                case 5:
                    nom_fichier = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes5.txt";
                    nom_fichier_resultat = "/Users/antoinebeneteau/Documents/mini_projet_2017/mini_projet_2017/tableau_contraintes5_R.txt";
                    break;
                    
                default:
                    break;
            }
            
            ofstream fichier_resultat(nom_fichier_resultat.c_str(), ios::trunc);
            
            cout << "Generation du graphe" << endl;
            
            Pause();
            
            Graphe G1(nom_fichier);
            
            if (G1.lectureFichierAvecContraintes(nom_fichier, fichier_resultat))
            {
                Pause();
                G1.creationGrapheOrdonnancement(fichier_resultat);
                Pause();
                //G1.ajoutSommetsIncidents(fichier_resultat);
                Pause();
                //G1.definitionMatrices(fichier_resultat);
                Pause();
                //G1.FermetureTransitiveMatrice(fichier_resultat);
                Pause();
                
            }
            else
            {
                cout << ">>> ERREUR: Impossible d'initialiser la liste des sommets avec ses contraintes !" << endl << endl;
                Pause();
            }
            
            
        } else if(choix == 2) {
            
        } else if (choix == 0){
            
        }
    
    } while (choix != 0);



    return 0;
}



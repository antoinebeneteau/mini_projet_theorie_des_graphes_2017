//
//  utils.cpp
//  mini_projet_2017
//
//  Created by antoine beneteau on 2017-01-03.
//  Copyright © 2017 antoine beneteau. All rights reserved.
//

#include "utils.h"

multimap<int, string> triClees(map<string, int> m)
{
    multimap<int, string> cible;
    
    for (map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        cible.insert(pair<int, string>(it->second, it->first));
    }
    
    return cible;
}

int convStringVersInt(string flux)
{
    int valeur;
    
    istringstream iss;
    iss.str(flux);
    iss >> valeur;
    
    return valeur;
}

void Pause()
{
    cout << "Appuyer pour continuer ...";
    cin.ignore().get(); // Cette commande de saisie sécurisée ordonne a l'utilisateur d'appuyer sur entrée (et seul entrée marche)
    cout << endl;
    
    return;
}

void affichageListeTaches(Graphe g) {
    cout << ">>> Liste des tâches: " << endl << endl;
    // Lecture des tâches
    for (int i = 0; i < g.getNombreTaches(); i++)
    {
        wcout << L">>> Tâche " << (i + 1) << " -> Sommet: ";
        cout << g.getTaches()[i] << ", ";
        wcout << L"durée: ";
        cout << g.getDurees()[i] << endl;
    }
    
    cout << endl;
}


void affichageListeContraintes(Graphe g) {
    system("clear");
    
    int nombre_contraintes;
    string nom_sommet;
    
    cout << ">>> Liste des contraintes: " << endl << endl;
    
    for (int i = 0; i < g.getNombreTaches(); i++)
    {
        nombre_contraintes = g.getSommets()[i].ObtenirNombreContraintes();
        nom_sommet = g.getSommets()[i].ObtenirNomSommet();
        
        if (nombre_contraintes == 0) // Aucune contrainte
        {
            if (nom_sommet == "a")
            {
                cout << ">>> Le sommet " << nom_sommet << " n'a aucune contrainte -> ";
                wcout << L"Il s'agit du sommet incident de début de projet." << endl;
            }
            else
            {
                cout << ">>> Le sommet " << nom_sommet << " n'a aucune contrainte -> ";
                wcout << L"Le sommet incident a sera son prédécesseur." << endl;
            }
        }
        else if (nombre_contraintes == 1) // 1 contrainte
        {
            cout << ">>> Sommet " << nom_sommet << ": 1 contrainte." << endl;
            
            cout << " * " << nom_sommet;
            wcout << L" ne peut commencer que lorsque la tâche ";
            cout << g.getSommets()[i].ObtenirContrainte(0); // Tableau d'une valeur = premier indice
            wcout << L" est terminée." << endl << endl;
        }
        else // 2 contraintes ou plus
        {
            cout << ">>> Sommet " << nom_sommet << ": " << g.ObtenirSommets()[i].ObtenirNombreContraintes() << " contraintes." << endl;
            
            if (g.getSommets()[i].ObtenirNombreContraintes() >= 1)
            {
                for (int j = 0; j < g.getSommets()[i].ObtenirNombreContraintes(); j++)
                {
                    cout << " * " << nom_sommet;
                    wcout << L" ne peut commencer que lorsque la tâche ";
                    cout << g.ObtenirSommets()[i].ObtenirContrainte(j);
                    wcout << L" est terminée." << endl;
                }
            }
            
            cout << endl;
        }
    }
}

void affichageListeSuccesseurs(Graphe g) {
    system("clear");
    
    int nombre_successeurs;
    int nombre_contraintes;
    string nom_sommet;
    
    cout << ">>> Liste des successeurs de chaque sommet: " << endl << endl;
    
    for (int i = 0; i < g.getNombreTaches(); i++)
    {
        nombre_successeurs = g.ObtenirSommets()[i].ObtenirNombreSuccesseurs();
        nom_sommet = g.ObtenirSommets()[i].ObtenirNomSommet();
        
        if (nombre_successeurs == 0) // Aucune contrainte
        {
            if (nom_sommet == "z")
            {
                cout << ">>> Le sommet " << nom_sommet << " n'a pas de successeur -> Il s'agit du sommet incident de fin de projet." << endl;
            }
            else
            {
                cout << ">>> Le sommet " << nom_sommet << " n'a pas de successeur -> Le sommet incident z sera son successeur." << endl;
            }
        }
        else if (nombre_successeurs == 1) // 1 contrainte
        {
            cout << ">>> Sommet " << nom_sommet << ": 1 successeur -> " << g.ObtenirSommets()[i].ObtenirSuccesseur(0) << endl;
        }
        else // 2 contraintes ou plus
        {
            cout << ">>> Sommet " << nom_sommet << ": " << g.ObtenirSommets()[i].getNombreSuccesseurs() << " successeurs -> ";
            
            if (g.ObtenirSommets()[i].ObtenirNombreSuccesseurs() >= 1)
            {
                for (int j = 0; j < nombre_successeurs; j++)
                {
                    if (j < nombre_successeurs - 1)
                    {
                        cout << g.getSommets()[i].getSuccesseur(j) << ", ";
                    }
                    else
                    {
                        cout << g.getSommets()[i].getSuccesseur(j) << endl;
                    }
                }
            }
        }
    }
}

void affichageListeArcs(Graphe g) {
    system("clear");
    
    cout << ">>> Liste des arcs: " << endl << endl;
    
    // Vérification des arcs alloués en mémoire
    for (int i = 0; i < g.getArcs().size(); i++)
    {
        cout << g.getArcs()[i].getPredecesseur() << " --[" << g.getArcs()[i].getDuree() << "]--> " << g.getArcs()[i].getNomSommet() << endl;
    }
}

void affichageMatriceAdjacence(Graphe g) {
    system("clear");
    
    cout << ">>> Matrice d'adjacence: " << endl << endl;
    
    for (int i = 0; i < g.getNombreTaches(); i++)
    {
        if (i == 0)
        {
            cout << "    " << g.getSommets()[i].getNomSommet() << "  ";
        }
        else
        {
            cout << g.getSommets()[i].getNomSommet() << "  ";
        }
    }
    
    cout << endl;
    
    // Affichage du contenu de la matrice
    for (int i = 0; i < g.getNombreTaches(); i++)
    {
        cout << g.getSommets()[i].getNomSommet() << "   ";
        
        for (int j = 0; j < g.getNombreTaches(); j++)
        {
            if (g.getMatriceAdjacence()[i][j])
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

void affichageMatriceValeur(Graphe g) {
    system("clear");
    
    cout << ">>> Matrice des valeurs: " << endl << endl;
    
    for (int i = 0; i < g.getNombreTaches(); i++)
    {
        if (i == 0)
        {
            cout << "    " << g.getSommets()[i].getNomSommet() << "  ";
        }
        else
        {
            cout << g.getSommets()[i].getNomSommet() << "  ";
        }
    }
    
    cout << endl;
    
    // Affichage du contenu de la matrice
    for (int i = 0; i < g.getNombreTaches(); i++)
    {
        cout << g.getSommets()[i].getNomSommet() << "   ";
        
        for (int j = 0; j < g.getNombreTaches(); j++)
        {
            if (g.getMatriceValeurs()[i][j] == -1)
            {
                cout << "   ";
            }
            else
            {
                cout << g.getMatriceValeurs()[i][j] << "  ";
            }
        }
        
        cout << endl;
    }
    
    cout << endl;
}

void affichageMatriceTransitive(Graphe g) {
    system("clear");
    
    cout << ">>> Matrice transitive: " << endl << endl;
    
    for (int i = 0; i < g.getNombreTaches(); i++)
    {
        if (i == 0)
        {
            cout << "    " << g.getSommets()[i].getNomSommet() << "  ";
        }
        else
        {
            cout << g.getSommets()[i].getNomSommet() << "  ";
        }
    }
    
    cout << endl;
    
    // Affichage du contenu de la matrice
    for (int i = 0; i < g.getNombreTaches(); i++)
    {
        cout << g.getSommets()[i].getNomSommet() << "   ";
        
        for (int j = 0; j < g.getNombreTaches(); j++)
        {
            if (g.getMatriceTransitive()[i][j])
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

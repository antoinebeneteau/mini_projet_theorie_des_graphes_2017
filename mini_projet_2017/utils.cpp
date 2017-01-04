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
    for (int i = 0; i < g.obtenirNombreTaches(); i++)
    {
        wcout << L">>> Tâche " << (i + 1) << " -> Sommet: ";
        cout << g.obtenirTaches()[i] << ", ";
        wcout << L"durée: ";
        cout << g.obtenirDurees()[i] << endl;
    }
    
    cout << endl;
}


void affichageListeContraintes(Graphe g) {
    system("clear");
    
    int nombre_contraintes;
    string nom_sommet;
    
    cout << ">>> Liste des contraintes: " << endl << endl;
    
    for (int i = 0; i < g.obtenirNombreTaches(); i++)
    {
        nombre_contraintes = g.obtenirSommets()[i].getNombreContraintes();
        nom_sommet = g.obtenirSommets()[i].getNomSommet();
        
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
            cout << g.obtenirSommets()[i].getContrainte(0); // Tableau d'une valeur = premier indice
            wcout << L" est terminée." << endl << endl;
        }
        else // 2 contraintes ou plus
        {
            cout << ">>> Sommet " << nom_sommet << ": " << g.obtenirSommets()[i].getNombreContraintes() << " contraintes." << endl;
            
            if (g.obtenirSommets()[i].getNombreContraintes() >= 1)
            {
                for (int j = 0; j < g.obtenirSommets()[i].getNombreContraintes(); j++)
                {
                    cout << " * " << nom_sommet;
                    wcout << L" ne peut commencer que lorsque la tâche ";
                    cout << g.obtenirSommets()[i].getContrainte(j);
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
    
    for (int i = 0; i < g.obtenirNombreTaches(); i++)
    {
        nombre_successeurs = g.obtenirSommets()[i].getNombreSuccesseurs();
        nom_sommet = g.obtenirSommets()[i].getNomSommet();
        
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
            cout << ">>> Sommet " << nom_sommet << ": 1 successeur -> " << g.obtenirSommets()[i].getSuccesseur(0) << endl;
        }
        else // 2 contraintes ou plus
        {
            cout << ">>> Sommet " << nom_sommet << ": " << g.obtenirSommets()[i].getNombreSuccesseurs() << " successeurs -> ";
            
            if (g.obtenirSommets()[i].getNombreSuccesseurs() >= 1)
            {
                for (int j = 0; j < nombre_successeurs; j++)
                {
                    if (j < nombre_successeurs - 1)
                    {
                        cout << g.obtenirSommets()[i].getSuccesseur(j) << ", ";
                    }
                    else
                    {
                        cout << g.obtenirSommets()[i].getSuccesseur(j) << endl;
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
    for (int i = 0; i < g.obtenirArcs().size(); i++)
    {
        cout << g.obtenirArcs()[i].getPredecesseur() << " --[" << g.obtenirArcs()[i].getDuree() << "]--> " << g.obtenirArcs()[i].getNomSommet() << endl;
    }
}

void affichageMatriceAdjacence(Graphe g) {
    system("clear");
    
    cout << ">>> Matrice d'adjacence: " << endl << endl;
    
    for (int i = 0; i < g.obtenirNombreTaches(); i++)
    {
        if (i == 0)
        {
            cout << "    " << g.obtenirSommets()[i].getNomSommet() << "  ";
        }
        else
        {
            cout << g.obtenirSommets()[i].getNomSommet() << "  ";
        }
    }
    
    cout << endl;
    
    // Affichage du contenu de la matrice
    for (int i = 0; i < g.obtenirNombreTaches(); i++)
    {
        cout << g.obtenirSommets()[i].getNomSommet() << "   ";
        
        for (int j = 0; j < g.obtenirNombreTaches(); j++)
        {
            if (g.obtenirMatriceAdjacence()[i][j])
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
    
    for (int i = 0; i < g.obtenirNombreTaches(); i++)
    {
        if (i == 0)
        {
            cout << "    " << g.obtenirSommets()[i].getNomSommet() << "  ";
        }
        else
        {
            cout << g.obtenirSommets()[i].getNomSommet() << "  ";
        }
    }
    
    cout << endl;
    
    // Affichage du contenu de la matrice
    for (int i = 0; i < g.obtenirNombreTaches(); i++)
    {
        cout << g.obtenirSommets()[i].getNomSommet() << "   ";
        
        for (int j = 0; j < g.obtenirNombreTaches(); j++)
        {
            if (g.obtenirMatriceValeurs()[i][j] == -1)
            {
                cout << "   ";
            }
            else
            {
                cout << g.obtenirMatriceValeurs()[i][j] << "  ";
            }
        }
        
        cout << endl;
    }
    
    cout << endl;
}

void affichageMatriceTransitive(Graphe g) {
    system("clear");
    
    cout << ">>> Matrice transitive: " << endl << endl;
    
    for (int i = 0; i < g.obtenirNombreTaches(); i++)
    {
        if (i == 0)
        {
            cout << "    " << g.obtenirSommets()[i].getNomSommet() << "  ";
        }
        else
        {
            cout << g.obtenirSommets()[i].getNomSommet() << "  ";
        }
    }
    
    cout << endl;
    
    // Affichage du contenu de la matrice
    for (int i = 0; i < g.obtenirNombreTaches(); i++)
    {
        cout << g.obtenirSommets()[i].getNomSommet() << "   ";
        
        for (int j = 0; j < g.obtenirNombreTaches(); j++)
        {
            if (g.obtenirMatriceTransitive()[i][j])
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

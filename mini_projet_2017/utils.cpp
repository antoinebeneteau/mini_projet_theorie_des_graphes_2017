//
//  utils.cpp
//  mini_projet_2017
//
//  Created by antoine beneteau on 2017-01-03.
//  Copyright © 2017 antoine beneteau. All rights reserved.
//

#include "utils.h"


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


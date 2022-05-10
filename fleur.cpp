#ifndef FLEUR_CPP
#define FLEUR_CPP

#include "fleur.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Fleur::Fleur(): etatActuel(0), jourEclot(0) {};

Fleur::Fleur(string _nom, int _maturiteMax) : Plante(){
    nom = _nom;
    maturiteMax = _maturiteMax;
}

int Fleur::getEtatActuel() {
    return etatActuel;
}

void Fleur::changeEtatActuel() {
    if ((etatActuel == 0) && (maturite == maturiteMax)) {
        etatActuel = 1;
    }
    if ((etatActuel == 1) && (jourEclot == 5)) {
        etatActuel = 2;
    }
};

    void Fleur::dormir() {
        //Check si la plante est assez arrosé
        if (hydratation > 4) {
            sante -= (hydratation - 4);
        }
        else {
            sante += hydratation;
        }
        //Check si la plante est bien tailladée
        if (taillade > 2) {
            sante -= (taillade - 2);
        }
        else {
            sante += (taillade - 1);
        }

        maturite += (sante - 5);
        if (maturite < 0) {maturite = 0;}
        if (maturite > maturiteMax) {maturite = maturiteMax;}
        if (maturite == maturiteMax) {
            cout << "--------------" << endl;
            cout << "Félicitation ! Une de vos plantes à atteint sa maturité ! Elle peut non pas aller boire de l'alcool, mais se vendre plus cher (c'est déjà pas mal)" << endl;
            cout << "--------------" << endl;
        };

        if (etatActuel == 1) {
            jourEclot++;
        };

        this->changeEtatActuel();

        //Baisse des stats
        taillade -= 1;
        hydratation -= 1;
    };



#endif
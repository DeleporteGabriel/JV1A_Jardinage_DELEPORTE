#ifndef CARNIVORE_CPP
#define CARNIVORE_CPP

#include "planteCarnivore.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Carnivore::Carnivore(): miammiam(0) {};

Carnivore::Carnivore(string _nom, int _maturiteMax) : Plante(){
    nom = _nom;
    maturiteMax = _maturiteMax;
}

int Carnivore::getMiam() {
    return miammiam;
}

void Carnivore::nourrir() {
    miammiam = 7;
}

void Carnivore::dormir() {
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
        if (miammiam == 0) {
            sante -= 3;
        }
        else {miammiam -= 1;}

        maturite += (sante - 5);
        if (maturite < 0) {maturite = 0;}
        if (maturite > maturiteMax) {maturite = maturiteMax;}
        if (maturite == maturiteMax) {
            cout << "--------------" << endl;
            cout << "Félicitation ! Une de vos plantes à atteint sa maturité ! Elle peut non pas aller boire de l'alcool, mais se vendre plus cher (c'est déjà pas mal)" << endl;
            cout << "--------------" << endl;
        };

        //Baisse des stats
        taillade -= 1;
        hydratation -= 1;
    };

#endif
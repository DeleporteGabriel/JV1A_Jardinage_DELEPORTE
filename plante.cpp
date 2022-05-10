#ifndef PLANTE_CPP
#define PLANTE_CPP

#include "plante.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

    Plante::Plante(): nom("plante"), sante(5), maturite(0), hydratation(2), taillade(0), maturiteMax(15) {};
    Plante::Plante(string _nom): nom(_nom) {};
    string Plante::getNom() {
        return nom;
    };
    int Plante::getSante() {
        return sante;
    };
    int Plante::getMaturite() {
        return maturite;
    };
    int Plante::getHydratation() {
        return hydratation;
    };
    int Plante::getTaillade() {
        return taillade;
    };
    void Plante::arroser() {
        hydratation += 1;
    };
    void Plante::taillader() {
        taillade += 1;
    };
    void Plante::engrais() {
        sante += 1;
    };
    void Plante::dormir() {
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

        //Baisse des stats
        taillade -= 1;
        hydratation -= 1;
    };

#endif
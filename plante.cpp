#ifndef PLANTE_CPP
#define PLANTE_CPP

#include "plante.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

    Plante::Plante(): nom("plante"), sante(5), maturite(0), hydratation(2), taillade(0) {};
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

        //Baisse des stats
        taillade -= 1;
        hydratation -= 1;
    };

#endif
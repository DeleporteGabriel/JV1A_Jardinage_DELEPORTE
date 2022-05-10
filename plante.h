#ifndef PLANTE_H
#define PLANTE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Plante {

    protected:
        string nom;
        int sante = 5;
        int maturite = 0;
        int hydratation = 2;
        int taillade = 0;
        int maturiteMax = 15;

    public:
        Plante();
        Plante(string nom, int maturiteMax);
        string getNom();
        int getSante();
        int getMaturite();
        int getHydratation();
        int getTaillade();
        int getEtatActuel();
        void arroser();
        void taillader();
        void engrais();
        void dormir();
};

#endif
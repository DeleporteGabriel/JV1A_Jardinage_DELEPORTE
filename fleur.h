#ifndef FLEUR_H
#define FLEUR_H

#include <string>
#include <iostream>
#include <vector>
#include "plante.cpp"
#include "plante.h"

using namespace std;

class Fleur : public Plante {
    protected: 
        int etatActuel = 0;
        int jourEclot = 0;

    public:
    Fleur();
    Fleur(string nom, int maturiteMax);
    int getEtatActuel();
    void changeEtatActuel();
    void dormir();
};

#endif
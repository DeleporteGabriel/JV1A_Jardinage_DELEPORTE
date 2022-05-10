#ifndef FLEUR_H
#define FLEUR_H

#include <string>
#include <iostream>
#include <vector>
#include "plante.cpp"
#include "plante.h"

using namespace std;

class Fleur : public Plante {
    public:
    Fleur();
    Fleur(int x, int y);
    vector<string> Avancer(vector<string> _echiquier);
};

#endif
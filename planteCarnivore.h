#ifndef CARNIVORE_H
#define CARNIVORE_H

#include <string>
#include <iostream>
#include <vector>
#include "plante.cpp"
#include "plante.h"

using namespace std;

class Carnivore : public Plante {
    protected: 
    bool miammiam = 0;

    public:
    Carnivore();
    Carnivore(string nom, int maturiteMax);
    int getMiam();
    void nourrir();
    void dormir();
};

#endif
#ifndef BOTANISTE_H
#define BOTANISTE_H

#include "plante.cpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Botaniste {

    protected:
        vector<Plante> listePlante;
        int argent = 5;
        int quantiteEngrais = 0;

    public:
        Botaniste();
        vector<Plante> getPlantes();
        int getArgent();
        int getQuantiteEngrais();
        void acheterPlante();
        void vendrePlante(int index);
        void remplacerPlante(int index, Plante _plante);
        void acheterEngrais();
        void depenseEngrais();
        void dormir();
};

#endif
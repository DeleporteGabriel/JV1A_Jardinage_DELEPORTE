#ifndef BOTANISTE_CPP
#define BOTANISTE_CPP

#include "botaniste.h"
#include "plante.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

    Botaniste::Botaniste(): listePlante(), argent(100), quantiteEngrais(0) {};
    vector<Plante> Botaniste::getPlantes() {
        return listePlante;
    };
    int Botaniste::getArgent() {
        return argent;
    };
    int Botaniste::getQuantiteEngrais() {
        return quantiteEngrais;
    };
    void Botaniste::acheterPlante() {
        listePlante.push_back(Plante("plante Piranha"));
        argent -= 20;
    };
    void Botaniste::vendrePlante() {
        argent += 20;
        listePlante.pop_back();
    };
    void Botaniste::acheterEngrais() {
        quantiteEngrais += 1;
        argent -= 5;
    };
    void Botaniste::dormir() {
        
        if (size(listePlante) > 0){
            for (int i = 0; i < size(listePlante); i++) {
                listePlante[i].dormir();

                if (listePlante[i].getSante() < 0) {
                    listePlante.erase(listePlante.begin() + i);
                }
            }
        }
    }

#endif
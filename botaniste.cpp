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
    void Botaniste::vendrePlante(int index) {
        argent += 5*(listePlante[index].getMaturite());
        listePlante.erase(listePlante.begin() + index);
    };
    void Botaniste::remplacerPlante(int index, Plante _plante) {
        listePlante[index] = _plante;
    };
    void Botaniste::acheterEngrais() {
        quantiteEngrais += 1;
        argent -= 5;
    };
    void Botaniste::depenseEngrais(){
        quantiteEngrais -= 1;
    };
    void Botaniste::dormir() {
        
        if (size(listePlante) > 0){
            for (int i = 0; i < size(listePlante); i++) {
                listePlante[i].dormir();

                if (listePlante[i].getSante() < 0) {
                    cout << "Une de vos plantes est morte... salo" << endl;
                    listePlante.erase(listePlante.begin() + i);
                }
            }
        }
    }

#endif
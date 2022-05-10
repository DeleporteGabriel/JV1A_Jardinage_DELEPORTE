#ifndef BOTANISTE_H
#define BOTANISTE_H

#include "plante.cpp"
#include "fleur.cpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Botaniste {

    protected:
        vector<Plante> listePlante;
        vector<Fleur> listeFleur;
        int argent = 5;
        int quantiteEngrais = 0;

    public:
        Botaniste();
        vector<Plante> getPlantes();
        vector<Fleur> getFleurs();
        int getArgent();
        int getQuantiteEngrais();
        void acheterPlante(int choix);
        void vendrePlante(int index);
        void vendreFleur(int index);
        void remplacerPlante(int index, Plante _plante);
        void remplacerFleur(int index, Fleur _fleur);
        void acheterEngrais();
        void depenseEngrais();
        void dormir();
};

#endif
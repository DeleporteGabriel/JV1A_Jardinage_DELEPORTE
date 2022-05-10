#ifndef BOTANISTE_CPP
#define BOTANISTE_CPP

#include "botaniste.h"
#include "plante.cpp"
#include "fleur.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

    Botaniste::Botaniste(): listePlante(), listeFleur(), argent(100), quantiteEngrais(0) {};
    vector<Plante> Botaniste::getPlantes() {
        return listePlante;
    };
    vector<Fleur> Botaniste::getFleurs() {
        return listeFleur;
    };
    int Botaniste::getArgent() {
        return argent;
    };
    int Botaniste::getQuantiteEngrais() {
        return quantiteEngrais;
    };
    void Botaniste::acheterPlante(int choix) {
        if (choix == 1) {
            listePlante.push_back(Plante("plante Piranha", 15));
        }
        else if (choix == 2) {
            listeFleur.push_back(Fleur("Flowey la Fleur", 25));
        }
        else {
            listePlante.push_back(Plante("plante Piranha", 15));
        }
        argent -= 20;
    };
    void Botaniste::vendrePlante(int index) {
        Plante _plante = listePlante[index];
        int revenu = 5*((listePlante[index]).getMaturite());

        argent += revenu;
        listePlante.erase(listePlante.begin() + index);
        cout << "Cette plante vous à rapporté " << revenu << " argent" << endl;
    };
    void Botaniste::vendreFleur(int index) {
        int multiplicateur = 1;
        Fleur _fleur = listeFleur[index];
        if (_fleur.getEtatActuel() == 1) {
            multiplicateur = 2;
        }
        else if (_fleur.getEtatActuel() == 2) {
            multiplicateur = 0.1;
        }

        int revenu = 5*((listeFleur[index]).getMaturite()) * multiplicateur;

        argent += revenu;
        listeFleur.erase(listeFleur.begin() + index);
        cout << "Cette plante vous à rapporté " << revenu << " argent" << endl;
    };
    void Botaniste::remplacerPlante(int index, Plante _plante) {
        listePlante[index] = _plante;
    };
    void Botaniste::remplacerFleur(int index, Fleur _fleur) {
        listeFleur[index] = _fleur;
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
        if (size(listeFleur) > 0){
            for (int i = 0; i < size(listeFleur); i++) {
                listeFleur[i].dormir();

                if (listeFleur[i].getSante() < 0) {
                    cout << "Une de vos fleurs est morte... salo" << endl;
                    listeFleur.erase(listeFleur.begin() + i);
                }
            }
        }
    }

#endif
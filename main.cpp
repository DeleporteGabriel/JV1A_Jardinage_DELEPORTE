#include "plante.cpp"
#include "botaniste.cpp"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void checkStats(Plante _plante) {
    cout << "Votre plante est un.e " << _plante.getNom() << endl;
    cout << "Niveau d'hydratation de " << _plante.getHydratation() << endl;
    cout << "Sante : " << _plante.getSante() << endl;
};

void checkStatsBota(Botaniste* _flora){
    for (int i = 0; i < size(_flora->getPlantes()); i++) {
        checkStats((_flora->getPlantes())[i]);
        cout << "-----------" << endl;
    }
    cout << "Il vous reste " << _flora-> getArgent() << " argents" << endl;
    cout << "Il vous reste " << _flora-> getQuantiteEngrais() << " engrais" << endl;
}

int main(){

    Botaniste * FloraPiranha = new Botaniste();

    FloraPiranha->acheterPlante();
    FloraPiranha->acheterPlante();
    FloraPiranha->acheterPlante();

    while (1 == 1) {
        checkStatsBota(FloraPiranha);

        int choixJoueur;
        cout << "Que voulez-vous faire? 1. Acheter une plante 2. Vendre une plante 3. Acheter de l'engrais 4. Dormir" << endl;
        cin >> choixJoueur;

        if (choixJoueur == 1) {
            if (FloraPiranha->getArgent() >= 20) {
                FloraPiranha->acheterPlante();
            }
        }
        else if (choixJoueur == 2) {
            if (size(FloraPiranha->getPlantes()) > 0) {
                FloraPiranha->vendrePlante();
            }
        }
        else if (choixJoueur == 3) {
            FloraPiranha->acheterEngrais();
        }
        else if (choixJoueur == 4) {
            FloraPiranha->dormir();
        }
    }
}
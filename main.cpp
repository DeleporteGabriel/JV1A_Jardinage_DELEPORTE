#include "plante.cpp"
#include "botaniste.cpp"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void checkStats(Plante _plante) {
    cout << "Votre plante est un.e " << _plante.getNom() << endl;
    cout << "Niveau d'hydratation de " << _plante.getHydratation() << endl;
    cout << "Niveau de tailladage de " << _plante.getTaillade() << endl;
    cout << "Sante : " << _plante.getSante() << endl;
    cout << "Croissance : " << _plante.getMaturite() << endl;
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

    while (1 == 1) {
        checkStatsBota(FloraPiranha);

        int choixJoueur;
        cout << "Que voulez-vous faire? 0. S'occuper d'une plante 1. Acheter une plante 2. Vendre une plante 3. Acheter de l'engrais 4. Dormir" << endl;
        cin >> choixJoueur;

        if (choixJoueur == 0) {
            int choixPlante;
            cout << "De laquelle voulez-vous vous occuper?" << endl;
            cin >> choixPlante;
            while (choixPlante > size(FloraPiranha->getPlantes())) {
                cout << "Vous n'avez pas tant de plante que ça !" << endl;
                cin >> choixPlante;
            }

            Plante planteOccuper;
            planteOccuper = FloraPiranha->getPlantes()[choixPlante-1];
            
            int choixAction;
            cout << "Que voulez-vous faire, avec cette plante? 1. Arroser 2. Taillader 3. Mettre de l'engrais" << endl;
            cin >> choixAction;
            while (choixAction > 3) {
                cout << "Il faut choisir voyons" << endl;
                cin >> choixAction;
            }

            if (choixAction == 1) {
                planteOccuper.arroser();
            }
            else if (choixAction == 2) {
                planteOccuper.taillader();
            }
            else if (choixAction == 3) {
                if (FloraPiranha->getQuantiteEngrais() > 0) {
                    planteOccuper.engrais();
                    FloraPiranha->depenseEngrais();
                }
                else {cout << "Vous n'avez plus d'engrais, arrêtez de vouloir m'arnaquer !" << endl;string attente; cin >> attente;}
            }

            FloraPiranha -> remplacerPlante(choixPlante-1, planteOccuper);


        }
        else if (choixJoueur == 1) {
            if (FloraPiranha->getArgent() >= 20) {
                FloraPiranha->acheterPlante();
            }
        }
        else if (choixJoueur == 2) {
            if (size(FloraPiranha->getPlantes()) > 0) {

                int choixPlante;
                cout << "Quelle plante veux-tu vendre?" << endl;
                cin >> choixPlante;
                while (choixPlante > size(FloraPiranha->getPlantes())) {
                    cout << "Vous n'avez pas tant de plante que ça !" << endl;
                    cin >> choixPlante;
                }

                FloraPiranha->vendrePlante(choixPlante-1);
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
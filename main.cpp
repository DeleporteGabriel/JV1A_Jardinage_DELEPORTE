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
void checkStatsF(Fleur _plante) {
    cout << "Votre plante est un.e " << _plante.getNom() << endl;
    cout << "Niveau d'hydratation de " << _plante.getHydratation() << endl;
    cout << "Niveau de tailladage de " << _plante.getTaillade() << endl;
    cout << "Sante : " << _plante.getSante() << endl;
    cout << "Croissance : " << _plante.getMaturite() << endl;
    cout << "Etat de la plante : " << _plante.getEtatActuel() << endl;
};
void checkStatsC(Carnivore _plante) {
    cout << "Votre plante est un.e " << _plante.getNom() << endl;
    cout << "Niveau d'hydratation de " << _plante.getHydratation() << endl;
    cout << "Niveau de tailladage de " << _plante.getTaillade() << endl;
    cout << "Sante : " << _plante.getSante() << endl;
    cout << "Croissance : " << _plante.getMaturite() << endl;
    cout << "Etat de la plante : " << _plante.getMiam() << endl;
};

void checkStatsBota(Botaniste* _flora){
    for (int i = 0; i < size(_flora->getPlantes()); i++) {
        checkStats((_flora->getPlantes())[i]);
        cout << "-----------" << endl;
    }
    for (int i = 0; i < size(_flora->getFleurs()); i++) {
        checkStatsF((_flora->getFleurs())[i]);
        cout << "-----------" << endl;
    }
    for (int i = 0; i < size(_flora->getCarnivores()); i++) {
        checkStatsC((_flora->getCarnivores())[i]);
        cout << "-----------" << endl;
    }
    cout << "Il vous reste " << _flora-> getArgent() << " argents" << endl;
    cout << "Il vous reste " << _flora-> getQuantiteEngrais() << " engrais" << endl;
}

int main(){

    Botaniste * FloraPiranha = new Botaniste();

    FloraPiranha->acheterPlante(3);

    while (1 == 1) {
        checkStatsBota(FloraPiranha);

        bool engraisUse = false;

        int choixJoueur;
        cout << "Que voulez-vous faire? 0. S'occuper d'une plante 1. Acheter une plante 2. Vendre une plante 3. Acheter de l'engrais 4. Dormir" << endl;
        cin >> choixJoueur;

        if (choixJoueur == 0) {
            int choixType;
            cout << "Vous voulez vous occuper 1. d'une plante ou 2. d'une fleur ou 3. d'une carnivore?" << endl;
            cin >> choixType;
            while (choixType > 3) {
                cout << "Par contre y a pas autant de type de plante de coder, d??so" << endl;
                cin >> choixType;
            }
            if (choixType == 1){
                int choixPlante;
                cout << "De laquelle voulez-vous vous occuper?" << endl;
                cin >> choixPlante;
                while (choixPlante > size(FloraPiranha->getPlantes())) {
                    cout << "Vous n'avez pas tant de plante que ??a !" << endl;
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
                        if (engraisUse == false) {
                            planteOccuper.engrais();
                            FloraPiranha->depenseEngrais();
                            engraisUse = true;
                        }
                        else {cout << "Tutututu, pas droit d'utiliser 2 engrais dans une seule journ??e !" << endl;string attente; cin >> attente;}
                    }
                    else {cout << "Vous n'avez plus d'engrais, arr??tez de vouloir m'arnaquer !" << endl;string attente; cin >> attente;}
                }

                FloraPiranha -> remplacerPlante(choixPlante-1, planteOccuper);
        }
        else if (choixType == 2){
                int choixFleur;
                cout << "De laquelle voulez-vous vous occuper?" << endl;
                cin >> choixFleur;
                while (choixFleur > size(FloraPiranha->getFleurs())) {
                    cout << "Vous n'avez pas tant de plante que ??a !" << endl;
                    cin >> choixFleur;
                }

                Fleur planteOccuper;
                planteOccuper = FloraPiranha->getFleurs()[choixFleur-1];
                
                int choixAction;
                cout << "Que voulez-vous faire, avec cette fleur? 1. Arroser 2. Taillader 3. Mettre de l'engrais" << endl;
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
                        if (engraisUse == false) {
                            planteOccuper.engrais();
                            FloraPiranha->depenseEngrais();
                            engraisUse = true;
                        }
                        else {cout << "Tutututu, pas droit d'utiliser 2 engrais dans une seule journ??e !" << endl;string attente; cin >> attente;}
                    }
                    else {cout << "Vous n'avez plus d'engrais, arr??tez de vouloir m'arnaquer !" << endl;string attente; cin >> attente;}
                }

                FloraPiranha -> remplacerFleur(choixFleur-1, planteOccuper);
        }
        else if (choixType == 3){
                int choixPlante;
                cout << "De laquelle voulez-vous vous occuper?" << endl;
                cin >> choixPlante;
                while (choixPlante > size(FloraPiranha->getCarnivores())) {
                    cout << "Vous n'avez pas tant de carnivore que ??a !" << endl;
                    cin >> choixPlante;
                }

                Carnivore planteOccuper;
                planteOccuper = FloraPiranha->getCarnivores()[choixPlante-1];
                
                int choixAction;
                cout << "Que voulez-vous faire, avec cette carnivore? 1. Arroser 2. Taillader 3. Mettre de l'engrais 4. Nourrir" << endl;
                cin >> choixAction;
                while (choixAction > 4) {
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
                        if (engraisUse == false) {
                            planteOccuper.engrais();
                            FloraPiranha->depenseEngrais();
                            engraisUse = true;
                        }
                        else {cout << "Tutututu, pas droit d'utiliser 2 engrais dans une seule journ??e !" << endl;string attente; cin >> attente;}
                    }
                    else {cout << "Vous n'avez plus d'engrais, arr??tez de vouloir m'arnaquer !" << endl;string attente; cin >> attente;}
                }
                else if (choixAction == 4){
                    planteOccuper.nourrir();
                }

                FloraPiranha -> remplacerCarnivore(choixPlante-1, planteOccuper);
        }


        }
        else if (choixJoueur == 1) {
            if (FloraPiranha->getArgent() >= 20) {
                int choixPlante;
                cout << "Voulez-vous choisir 1. une plante piranha 2. Flowey la Fleur 3. Empiflor ?" << endl;
                cin >> choixPlante;
                FloraPiranha->acheterPlante(choixPlante);
            }
        }
        else if (choixJoueur == 2) {

            int choixType;
            cout << "Vous voulez vendre une plante ou une fleur?" << endl;
            cin >> choixType;
            while (choixType > 3) {
                cout << "Par contre y a pas autant de type de plante de coder, d??so" << endl;
                cin >> choixType;
            }
            
            if (choixType == 1) {
                if (size(FloraPiranha->getPlantes()) > 0) {

                    int choixPlante;
                    cout << "Quelle plante veux-tu vendre?" << endl;
                    cin >> choixPlante;
                    while (choixPlante > size(FloraPiranha->getPlantes())) {
                        cout << "Vous n'avez pas tant de plante que ??a !" << endl;
                        cin >> choixPlante;
                    }

                    FloraPiranha->vendrePlante(choixPlante-1);
                }
            }
            else if (choixType == 2) {
                if (size(FloraPiranha->getFleurs()) > 0) {

                    int choixFleur;
                    cout << "Quelle fleur veux-tu vendre?" << endl;
                    cin >> choixFleur;
                    while (choixFleur > size(FloraPiranha->getFleurs())) {
                        cout << "Vous n'avez pas tant de fleur que ??a !" << endl;
                        cin >> choixFleur;
                    }

                    FloraPiranha->vendreFleur(choixFleur-1);
                }
            }
            else if (choixType == 3) {
                if (size(FloraPiranha->getCarnivores()) > 0) {

                    int choixCarnivore;
                    cout << "Quelle plante carnivore veux-tu vendre?" << endl;
                    cin >> choixCarnivore;
                    while (choixCarnivore > size(FloraPiranha->getCarnivores())) {
                        cout << "Vous n'avez pas tant de carnivore que ??a !" << endl;
                        cin >> choixCarnivore;
                    }

                    FloraPiranha->vendrePlante(choixCarnivore-1);
                }
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
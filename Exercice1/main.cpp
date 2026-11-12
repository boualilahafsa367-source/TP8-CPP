#include <iostream>

#include "SortieAudio.hpp"
#include "HautParleur.hpp"
#include "CasqueBT.hpp"
#include "SortieHDMI.hpp"

using namespace std;

// Cette fonction utilise le polymorphisme.
// Elle fonctionne avec n'importe quelle classe dérivée de SortieAudio.
void tester(SortieAudio* sortie) {

    if (sortie == nullptr) {
        cout << "Peripherique audio invalide." << endl;
        return;
    }

    sortie->ouvrir();

    sortie->jouer("Melodie de demonstration - Atlas");

    sortie->fermer();
}

int main() {

    // Création d'un tableau dynamique de trois pointeurs.
    SortieAudio** sorties = new SortieAudio*[3];

    // Chaque pointeur désigne un périphérique différent.
    sorties[0] = new HautParleur();
    sorties[1] = new CasqueBT();
    sorties[2] = new SortieHDMI();

    cout << "===== TEST DES PERIPHERIQUES AUDIO =====" << endl;

    // Le même appel fonctionne avec les trois types d'objets.
    for (int i = 0; i < 3; i++) {

        cout << "\n--- Peripherique " << i + 1 << " ---" << endl;

        tester(sorties[i]);
    }

    // Libération de chaque objet créé avec new.
    cout << "\n===== LIBERATION DE LA MEMOIRE =====" << endl;

    for (int i = 0; i < 3; i++) {
        delete sorties[i];
    }

    // Libération du tableau dynamique.
    delete[] sorties;

    cout << "\nFin du programme." << endl;

    return 0;
}
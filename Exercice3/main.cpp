#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "Plugin.hpp"

using namespace std;

int main() {

    // Saisie du texte à traiter.
    string texte;

    cout << "===== SYSTEME DE PLUGINS =====" << endl;

    cout << "\nSaisissez votre texte :" << endl;
    getline(cin, texte);

    // Création d'une collection de plugins.
    vector<unique_ptr<Plugin>> plugins;

    // Création des plugins avec la factory.
    plugins.push_back(Plugin::creerPlugin("correcteur"));
    plugins.push_back(Plugin::creerPlugin("traducteur"));
    plugins.push_back(Plugin::creerPlugin("analyseur"));

    cout << "\n===== TRAITEMENT DU TEXTE =====" << endl;

    // Application successive de chaque plugin.
    for (const auto& plugin : plugins) {

        if (plugin == nullptr) {
            cout << "Erreur : plugin indisponible." << endl;
            continue;
        }

        cout << "\nPlugin applique : " << plugin->nom() << endl;

        // Le résultat d'un plugin devient l'entrée du suivant.
        texte = plugin->traiter(texte);

        cout << "Texte apres traitement :" << endl;
        cout << texte << endl;
    }

    cout << "\n===== FIN DU TRAITEMENT =====" << endl;

    return 0;
}
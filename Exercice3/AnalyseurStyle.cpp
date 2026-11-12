#include "AnalyseurStyle.hpp"
#include <sstream>

std::string AnalyseurStyle::nom() const {
    return "Analyseur de style";
}

std::string AnalyseurStyle::traiter(
    const std::string& texte
) {
    std::istringstream flux(texte);

    int nombreMots = 0;
    int phrasesLongues = 0;
    bool dansUnMot = false;

    char caractere;

    while (flux.get(caractere)) {

        if (caractere == '.' ||
            caractere == '?' ||
            caractere == '!') {

            if (nombreMots > 12) {
                phrasesLongues++;
            }

            nombreMots = 0;
            dansUnMot = false;
        }
        else if (caractere == ' ' ||
                 caractere == '\n' ||
                 caractere == '\t') {

            dansUnMot = false;
        }
        else if (!dansUnMot) {
            nombreMots++;
            dansUnMot = true;
        }
    }

    // Vérifie également la dernière phrase sans ponctuation finale.
    if (nombreMots > 12) {
        phrasesLongues++;
    }

    std::string resultat = texte;

    if (phrasesLongues > 0) {
        resultat += "\n[Analyse de style] Attention : ";
        resultat += std::to_string(phrasesLongues);
        resultat += " phrase(s) trop longue(s).";
    } else {
        resultat += "\n[Analyse de style] Aucune phrase trop longue.";
    }

    return resultat;
}
#include "TraducteurAnglais.hpp"

std::string TraducteurAnglais::nom() const {
    return "Traducteur francais-anglais";
}

std::string TraducteurAnglais::traiter(
    const std::string& texte
) {
    std::string resultat = texte;

    const std::string motsFrancais[] = {
        "bonjour",
        "ecole",
        "livre",
        "informatique"
    };

    const std::string motsAnglais[] = {
        "hello",
        "school",
        "book",
        "computer science"
    };

    for (int i = 0; i < 4; i++) {
        size_t position = 0;

        while ((position = resultat.find(
                    motsFrancais[i], position))
               != std::string::npos) {

            resultat.replace(
                position,
                motsFrancais[i].length(),
                motsAnglais[i]
            );

            position += motsAnglais[i].length();
        }
    }

    return resultat;
}
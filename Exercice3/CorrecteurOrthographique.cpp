#include "CorrecteurOrthographique.hpp"

std::string CorrecteurOrthographique::nom() const {
    return "Correcteur orthographique";
}

std::string CorrecteurOrthographique::traiter(
    const std::string& texte
) {
    std::string resultat = texte;

    // Liste de corrections simples pour notre démonstration.
    const std::string fautes[] = {
        "bonjor",
        "ecole",
        "aprentissage"
    };

    const std::string corrections[] = {
        "bonjour",
        "ecole",
        "apprentissage"
    };

    for (int i = 0; i < 3; i++) {
        size_t position = 0;

        // Remplace toutes les occurrences du mot incorrect.
        while ((position = resultat.find(fautes[i], position))
               != std::string::npos) {

            resultat.replace(
                position,
                fautes[i].length(),
                corrections[i]
            );

            position += corrections[i].length();
        }
    }

    return resultat;
}
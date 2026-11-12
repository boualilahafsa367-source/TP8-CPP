#include "HautParleur.hpp"

void HautParleur::ouvrir() {
    std::cout << "Haut-parleur : connexion active." << std::endl;
}

void HautParleur::jouer(const std::string& son) {
    std::cout << "Haut-parleur : lecture de \"" << son << "\"." << std::endl;
}

void HautParleur::fermer() {
    std::cout << "Haut-parleur : connexion fermee." << std::endl;
}

HautParleur::~HautParleur() {
    std::cout << "Destruction du haut-parleur." << std::endl;
}
#include "SortieHDMI.hpp"

void SortieHDMI::ouvrir() {
    std::cout << "Sortie HDMI : liaison avec l'ecran etablie." << std::endl;
}

void SortieHDMI::jouer(const std::string& son) {
    std::cout << "Sortie HDMI : transmission de \"" << son << "\"." << std::endl;
}

void SortieHDMI::fermer() {
    std::cout << "Sortie HDMI : liaison terminee." << std::endl;
}

SortieHDMI::~SortieHDMI() {
    std::cout << "Destruction de la sortie HDMI." << std::endl;
}
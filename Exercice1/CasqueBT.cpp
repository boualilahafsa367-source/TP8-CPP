#include "CasqueBT.hpp"

void CasqueBT::ouvrir() {
    std::cout << "Casque Bluetooth : appairage reussi." << std::endl;
}

void CasqueBT::jouer(const std::string& son) {
    std::cout << "Casque Bluetooth : lecture de \"" << son << "\"." << std::endl;
}

void CasqueBT::fermer() {
    std::cout << "Casque Bluetooth : deconnexion effectuee." << std::endl;
}

CasqueBT::~CasqueBT() {
    std::cout << "Destruction du casque Bluetooth." << std::endl;
}
#ifndef SORTIEHDMI_HPP
#define SORTIEHDMI_HPP

#include "SortieAudio.hpp"

class SortieHDMI : public SortieAudio {
public:
    void ouvrir() override;

    void jouer(const std::string& son) override;

    void fermer() override;

    ~SortieHDMI() override;
};

#endif
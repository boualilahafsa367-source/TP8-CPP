#ifndef CASQUEBT_HPP
#define CASQUEBT_HPP

#include "SortieAudio.hpp"

class CasqueBT : public SortieAudio {
public:
    void ouvrir() override;

    void jouer(const std::string& son) override;

    void fermer() override;

    ~CasqueBT() override;
};

#endif
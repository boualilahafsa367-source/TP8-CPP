#ifndef SORTIEAUDIO_HPP
#define SORTIEAUDIO_HPP

#include <iostream>
#include <string>

class SortieAudio {
public:
    // Une méthode virtuelle pure rend la classe abstraite.
    virtual void ouvrir() = 0;

    virtual void jouer(const std::string& son) = 0;

    virtual void fermer() = 0;

    // Le destructeur virtuel garantit la destruction correcte
    // des objets dérivés à travers un pointeur SortieAudio.
    virtual ~SortieAudio() = default;
};

#endif
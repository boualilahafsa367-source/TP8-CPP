#ifndef LUMIERE_HPP
#define LUMIERE_HPP

#include "Vec3.hpp"

class Lumiere {
public:
    // Chaque type de lumière doit définir son propre calcul.
    virtual float intensite(const Vec3& position) = 0;

    // Destructeur virtuel pour les classes dérivées.
    virtual ~Lumiere() = default;
};

#endif
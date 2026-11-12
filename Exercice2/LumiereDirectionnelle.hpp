#ifndef LUMIERE_DIRECTIONNELLE_HPP
#define LUMIERE_DIRECTIONNELLE_HPP

#include "Lumiere.hpp"

class LumiereDirectionnelle : public Lumiere {
private:
    Vec3 direction;
    Vec3 couleur;

public:
    LumiereDirectionnelle(const Vec3& dir, const Vec3& coul);

    float intensite(const Vec3& position) override;
};

#endif
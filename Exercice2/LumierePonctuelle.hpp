#ifndef LUMIERE_PONCTUELLE_HPP
#define LUMIERE_PONCTUELLE_HPP

#include "Lumiere.hpp"

class LumierePonctuelle : public Lumiere {
private:
    Vec3 positionSource;
    float attenuation;

public:
    LumierePonctuelle(const Vec3& position, float att);

    float intensite(const Vec3& position) override;
};

#endif
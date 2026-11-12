#ifndef LUMIERE_SPOT_HPP
#define LUMIERE_SPOT_HPP

#include "Lumiere.hpp"

class LumiereSpot : public Lumiere {
private:
    Vec3 positionSource;
    Vec3 direction;
    float angleOuverture;

public:
    LumiereSpot(
        const Vec3& position,
        const Vec3& dir,
        float angle
    );

    float intensite(const Vec3& position) override;
};

#endif
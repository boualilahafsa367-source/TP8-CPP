#include "LumiereSpot.hpp"
#include <cmath>

LumiereSpot::LumiereSpot(
    const Vec3& position,
    const Vec3& dir,
    float angle
) {
    positionSource = position;
    direction = normaliser(dir);

    // L'angle est limité entre 0 et 180 degrés.
    if (angle < 0) {
        angleOuverture = 0;
    } else if (angle > 180) {
        angleOuverture = 180;
    } else {
        angleOuverture = angle;
    }
}

float LumiereSpot::intensite(const Vec3& position) {

    // Vecteur allant de la source vers le point observé.
    Vec3 versPoint(
        position.x - positionSource.x,
        position.y - positionSource.y,
        position.z - positionSource.z
    );

    float distance = norme(versPoint);

    if (distance == 0) {
        return 1.0f;
    }

    Vec3 directionPoint = normaliser(versPoint);

    // Comparaison entre la direction du spot et celle du point.
    float cosAngle = produitScalaire(direction, directionPoint);

    // Conversion du demi-angle d'ouverture en radians.
    const float PI = 3.14159265f;
    float demiAngle = (angleOuverture / 2.0f) * PI / 180.0f;

    float limite = std::cos(demiAngle);

    // Le point est hors du cône lumineux.
    if (cosAngle < limite) {
        return 0.0f;
    }

    // Le point est dans le cône : l'intensité diminue avec la distance.
    return 1.0f / (1.0f + distance * distance);
}
#include "LumierePonctuelle.hpp"

LumierePonctuelle::LumierePonctuelle(
    const Vec3& position, float att
) {
    positionSource = position;

    // On évite un coefficient d'atténuation négatif.
    attenuation = (att < 0) ? 0 : att;
}

float LumierePonctuelle::intensite(const Vec3& position) {

    float dx = position.x - positionSource.x;
    float dy = position.y - positionSource.y;
    float dz = position.z - positionSource.z;

    // Calcul de la distance au carré.
    float distanceCarree = dx * dx + dy * dy + dz * dz;

    return 1.0f / (1.0f + attenuation * distanceCarree);
}
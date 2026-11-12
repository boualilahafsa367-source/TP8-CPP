#include "LumiereDirectionnelle.hpp"

LumiereDirectionnelle::LumiereDirectionnelle(
    const Vec3& dir, const Vec3& coul
) {
    direction = normaliser(dir);
    couleur = coul;
}

float LumiereDirectionnelle::intensite(const Vec3& position) {

    // Sans normale de surface, on utilise ici une intensité
    // uniforme basée sur la couleur de la source.
    // La direction sera utile dans un modèle avec surfaces 3D.

    float intensiteCouleur =
        (couleur.x + couleur.y + couleur.z) / 3.0f;

    return intensiteCouleur;
}
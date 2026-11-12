#ifndef VEC3_HPP
#define VEC3_HPP

#include <cmath>

// Représente un point ou un vecteur dans l'espace 3D.
struct Vec3 {
    float x;
    float y;
    float z;

    Vec3(float x = 0, float y = 0, float z = 0)
        : x(x), y(y), z(z) {
    }
};

// Calcule la longueur d'un vecteur.
inline float norme(const Vec3& v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Calcule le produit scalaire de deux vecteurs.
inline float produitScalaire(const Vec3& a, const Vec3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Retourne un vecteur de longueur 1.
inline Vec3 normaliser(const Vec3& v) {
    float longueur = norme(v);

    if (longueur == 0) {
        return Vec3();
    }

    return Vec3(v.x / longueur, v.y / longueur, v.z / longueur);
}

#endif
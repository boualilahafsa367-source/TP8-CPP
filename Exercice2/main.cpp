#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>

#include "Vec3.hpp"
#include "Lumiere.hpp"
#include "LumiereDirectionnelle.hpp"
#include "LumierePonctuelle.hpp"
#include "LumiereSpot.hpp"

using namespace std;

// Additionne les intensités de toutes les lumières au point demandé.
float calculerEclairage(
    const Vec3& point,
    const vector<unique_ptr<Lumiere>>& lumieres
) {
    float total = 0.0f;

    for (const auto& lumiere : lumieres) {
        total += lumiere->intensite(point);
    }

    return total;
}

int main() {

    // Collection de lumières gérées automatiquement en mémoire.
    vector<unique_ptr<Lumiere>> lumieres;

    // Ajout d'une lumière directionnelle.
    lumieres.push_back(
        make_unique<LumiereDirectionnelle>(
            Vec3(-1, -1, -1),
            Vec3(0.8f, 0.7f, 0.6f)
        )
    );

    // Ajout d'une lumière ponctuelle.
    lumieres.push_back(
        make_unique<LumierePonctuelle>(
            Vec3(2, 1, 3),
            0.08f
        )
    );

    // Ajout d'un projecteur avec un angle d'ouverture de 55 degrés.
    lumieres.push_back(
        make_unique<LumiereSpot>(
            Vec3(-2, 2, 1),
            Vec3(1, -1, 0),
            55.0f
        )
    );

    // Trois points de test dans l'espace 3D.
    Vec3 points[] = {
        Vec3(0, 0, 0),
        Vec3(2, 1, 2),
        Vec3(-1, 1, 0)
    };

    cout << "===== MOTEUR DE RENDU 3D =====" << endl;

    // Affichage de l'éclairage calculé pour chaque point.
    for (int i = 0; i < 3; i++) {

        cout << "\n--- Point " << i + 1 << " ---" << endl;

        cout << "Coordonnees : ("
             << points[i].x << ", "
             << points[i].y << ", "
             << points[i].z << ")" << endl;

        cout << "Intensite totale : "
             << fixed << setprecision(3)
             << calculerEclairage(points[i], lumieres)
             << endl;
    }

    // Les unique_ptr libèrent automatiquement les objets.
    cout << "\nFin du calcul d'eclairage." << endl;

    return 0;
}
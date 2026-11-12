#include "Plugin.hpp"

#include "CorrecteurOrthographique.hpp"
#include "TraducteurAnglais.hpp"
#include "AnalyseurStyle.hpp"

std::unique_ptr<Plugin> Plugin::creerPlugin(
    const std::string& type
) {
    if (type == "correcteur") {
        return std::make_unique<CorrecteurOrthographique>();
    }

    if (type == "traducteur") {
        return std::make_unique<TraducteurAnglais>();
    }

    if (type == "analyseur") {
        return std::make_unique<AnalyseurStyle>();
    }

    // Retourne nullptr si le type demandé n'existe pas.
    return nullptr;
}
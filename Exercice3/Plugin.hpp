#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#include <iostream>
#include <string>
#include <memory>

class Plugin {
public:
    // Retourne le nom du plugin.
    virtual std::string nom() const = 0;

    // Transforme le texte reçu.
    virtual std::string traiter(const std::string& texte) = 0;

    // Factory : crée un plugin selon le type demandé.
    static std::unique_ptr<Plugin> creerPlugin(const std::string& type);

    // Destructeur virtuel pour les classes dérivées.
    virtual ~Plugin() = default;
};

#endif
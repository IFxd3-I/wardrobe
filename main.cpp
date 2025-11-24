#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include "wardrobe.h"
#include "json.hpp"
#include "cxxopts.hpp"

using json = nlohmann::json;

int main(int argc, char* argv[]) {

    std::vector<ClothingItem> wardrobe;

    cxxopts::Options options("wardrobe", "Gestione dell'armadio personale");

    options.add_options()
        ("s, sort", "Ordina per <campo>", cxxopts::value<std::string>())
        ("h,help", "Mostra l'aiuto");

    checkWardrobe(wardrobe);

    try {
        auto result = options.parse(argc, argv);

        if (argc == 1) {
            showWardrobe(wardrobe);
            return 0;
        }

        if (result.count("sort")) {
            std::string sortField = result["sort"].as<std::string>();

            if (sortField == "nome") {
                std::sort(wardrobe.begin(), wardrobe.end(), [](const ClothingItem& a, const ClothingItem& b) {
                    return a.name < b.name;
                });
            } else if (sortField == "categoria") {
                std::sort(wardrobe.begin(), wardrobe.end(), [](const ClothingItem& a, const ClothingItem& b) {
                    return a.type < b.type;
                });
            } else if (sortField == "colore") {
                std::sort(wardrobe.begin(), wardrobe.end(), [](const ClothingItem& a, const ClothingItem& b) {
                    return a.color < b.color;
                });
            } else if (sortField == "stagione") {
                std::sort(wardrobe.begin(), wardrobe.end(), [](const ClothingItem& a, const ClothingItem& b) {
                    return a.season < b.season;
                });
            } else {
                std::cerr << "Campo di ordinamento non valido: " << sortField << std::endl;
                return 1;
            }

            showWardrobe(wardrobe);
            return 0;
        }
        
        if (result.count("help")) {
            std::cout << options.help() << std::endl;
            return 0;
        }

    } catch (const cxxopts::exceptions::exception& e) {
        std::cerr << "Errore nelle opzioni: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
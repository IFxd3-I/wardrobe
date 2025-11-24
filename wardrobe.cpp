#include "wardrobe.h"
#include <iostream>
#include <fstream>
#include <algorithm>


void checkWardrobe(std::vector<ClothingItem>& wardrobe)
{

    std::ifstream file("wardrobe.json");

    if (!file.is_open()) {
        std::cerr << "Errore nell'apertura del file wardrobe.json" << std::endl;
        return;
    }

    json j;
    file >> j;

    for (const auto& item : j) {
        ClothingItem ci;
        ci.name = item["nome"];
        ci.type = item["categoria"];
        ci.color = item["colore"];
        ci.season = item["stagione"];
        wardrobe.push_back(ci);
    }

    file.close(); 
};


void showWardrobe(const std::vector<ClothingItem>& wardrobe) {
    std::cout << "Contenuto dell'armadio:" << std::endl;
    for (const auto& ci : wardrobe) {
        std::cout << "Nome: " << ci.name << ", Categoria: " << ci.type
                  << ", Colore: " << ci.color << ", Stagione: " << ci.season << std::endl;
    }
}
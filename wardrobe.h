#ifndef WARDROBE_H
#define WARDROBE_H

#include <string>
#include "json.hpp"
#include <vector>

using json = nlohmann::json;

// Data structures

struct ClothingItem {
    std::string name;
    std::string type; 
    std::string color;
    std::string season;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(ClothingItem, name, type, color, season)

// Functions to serialize and deserialize wardrobe data

void checkWardrobe(std::vector<ClothingItem>& wardrobe);

void showWardrobe(const std::vector<ClothingItem>& wardrobe);

#endif // WARDROBE_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct PizzaPlace {
    std::string name;
    int visitsByMen;
    int visitsByWomen;
};

int main() {
    std::vector<PizzaPlace> pizzaPlaces = {
        {"Pizza Place 1", 100, 150},
        {"Pizza Place 2", 120, 80},
        {"Pizza Place 3", 200, 100},
        {"Pizza Place 4", 80, 120},
        {"Pizza Place 5", 150, 150}
    };
    
    std::vector<std::string> placesVisitedByMenOnly;
    std::vector<std::string> placesVisitedByWomenOnly;
    
    for (const auto& place : pizzaPlaces) {
        if (place.visitsByMen > 0 && place.visitsByWomen == 0) {
            placesVisitedByMenOnly.push_back(place.name);
        } else if (place.visitsByWomen > 0 && place.visitsByMen == 0) {
            placesVisitedByWomenOnly.push_back(place.name);
        }
    }
    
    std::cout << "Pizza places visited only by men: " << std::endl;
    for (const auto& place : placesVisitedByMenOnly) {
        std::cout << place << std::endl;
    }
    
    std::cout << "Pizza places visited only by women: " << std::endl;
    for (const auto& place : placesVisitedByWomenOnly) {
        std::cout << place << std::endl;
    }
    
    return 0;
}

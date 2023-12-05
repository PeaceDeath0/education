#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::map<std::string, int> pizzaVisits = {
        {"PizzaHut", 15},
        {"Dominos", 20},
        {"PapaJohns", 25},
        {"LittleCaesars", 30}
    };

    std::map<std::string, std::string> pizzaGender = {
        {"PizzaHut", "female"},
        {"Dominos", "male"},
        {"PapaJohns", "female"},
        {"LittleCaesars", "male"}
    };

    std::map<std::string, bool> pizzaOrders = {
        {"PizzaHut", false},
        {"Dominos", true},
        {"PapaJohns", true},
        {"LittleCaesars", false}
    };

    std::map<std::string, float> pizzaPrices = {
        {"Margherita", 10.0},
        {"Pepperoni", 12.0},
        {"Vegetarian", 11.0},
        {"Supreme", 13.0}
    };

    std::vector<std::string> femaleVisits;
    std::vector<std::string> maleVisits;
    std::vector<std::string> andreyVisitsNoOrder;
    std::vector<std::string> differentPrices;

    for (auto it = pizzaVisits.begin(); it != pizzaVisits.end(); ++it) {
        if (pizzaGender[it->first] == "female") {
            femaleVisits.push_back(it->first);
        } else {
            maleVisits.push_back(it->first);
        }
    }

    std::sort(femaleVisits.begin(), femaleVisits.end());
    std::sort(maleVisits.begin(), maleVisits.end());

    std::set_intersection(
        femaleVisits.begin(), femaleVisits.end(),
        maleVisits.begin(), maleVisits.end(),
        std::back_inserter(andreyVisitsNoOrder)
    );

    for (auto it = pizzaOrders.begin(); it != pizzaOrders.end(); ++it) {
        if (it->second == false) {
            andreyVisitsNoOrder.push_back(it->first);
        }
    }

    for (auto it = pizzaPrices.begin(); it != pizzaPrices.end(); ++it) {
        auto found = std::adjacent_find(pizzaPrices.begin(), pizzaPrices.end(), 
            [it](const std::pair<std::string, float>& p) {
                return it->second != p.second;
            });

        if (found != pizzaPrices.end()) {
            differentPrices.push_back(it->first);
        }
    }

    std::cout << "Pizzerias visited by more women: ";
    for (const auto& pizzeria : femaleVisits) {
        std::cout << pizzeria << " ";
    }
    std::cout << std::endl;

    std::cout << "Pizzerias visited by more men: ";
    for (const auto& pizzeria : maleVisits) {
        std::cout << pizzeria << " ";
    }
    std::cout << std::endl;

    std::cout << "Pizzerias visited only by women or men: ";
    for (const auto& pizzeria : andreyVisitsNoOrder) {
        std::cout << pizzeria << " ";
    }
    std::cout << std::endl;

    std::cout << "Pizzas with different prices: ";
    for (const auto& pizza : differentPrices) {
        std::cout << pizza << " ";
    }
    std::cout << std::endl;

    return 0;
}

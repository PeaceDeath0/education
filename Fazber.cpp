#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::map<std::string, std::vector<std::string>> pizzaMenu = {
        {"PizzaHut", {"Margherita", "Pepperoni", "Vegetarian"}},
        {"Dominos", {"Pepperoni", "Supreme", "Hawaiian"}},
        {"PapaJohns", {"Pepperoni", "Hawaiian", "Meat Lovers"}},
        {"LittleCaesars", {"Cheese", "Sausage", "Pepperoni"}}
    };

    std::map<std::string, std::string> pizzaVisitors = {
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
        {"Supreme", 13.0},
        {"Hawaiian", 12.0},
        {"Meat Lovers", 14.0},
        {"Cheese", 9.0},
        {"Sausage", 11.0}
    };

    std::map<std::string, int> maleVisits;
    std::map<std::string, int> femaleVisits;
    std::vector<std::string> andreyVisitsNoOrder;
    std::vector<std::string> differentPrices;

    for (const auto& entry : pizzaVisitors) {
        if (entry.second == "male") {
            maleVisits[entry.first]++;
        } else {
            femaleVisits[entry.first]++;
        }
    }

    std::vector<std::string> maleOnlyVisits;
    std::vector<std::string> femaleOnlyVisits;
    for (const auto& entry : maleVisits) {
        if (femaleVisits.find(entry.first) == femaleVisits.end()) {
            maleOnlyVisits.push_back(entry.first);
        }
    }
    for (const auto& entry : femaleVisits) {
        if (maleVisits.find(entry.first) == maleVisits.end()) {
            femaleOnlyVisits.push_back(entry.first);
        }
    }

    for (const auto& entry : pizzaOrders) {
        if (entry.second == false) {
            andreyVisitsNoOrder.push_back(entry.first);
        }
    }

    for (const auto& entry : pizzaPrices) {
        auto it = entry;
        auto found = std::find_if(pizzaPrices.begin(), pizzaPrices.end(),
            [it](const std::pair<std::string, float>& p) {
                return it.second != p.second;
            });
        if (found != pizzaPrices.end()) {
            differentPrices.push_back(it.first);
        }
    }

    std::cout << "Pizzerias visited more by women: ";
    for (const auto& entry : femaleVisits) {
        if (entry.second > maleVisits[entry.first]) {
            std::cout << entry.first << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Pizzerias visited only by women or men: ";
    for (const auto& pizzeria : femaleOnlyVisits) {
        std::cout << pizzeria << " ";
    }
    for (const auto& pizzeria : maleOnlyVisits) {
        std::cout << pizzeria << " ";
    }
    std::cout << std::endl;

    std::cout << "Pizzerias visited by Andrey but did not place an order: ";
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

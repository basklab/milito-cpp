#include <iostream>
#include "entity/LeaderCard.h"
#include "config/decks/AncientBritish.h"
#include <nlohmann/json.hpp>
#include <iomanip>

int main() {
    std::cout << "Hello, World!" << std::endl;

    xyz();

    return 0;

//    LeaderCard l(12,12,12,"");


    auto deck = make_deck_ab();

    std::cout << deck.getJson() << std::endl;

    nlohmann::json j;

    j["dsada"] = 123;

    std::cout << std::setw(4) << j << std::endl;

    return 0;
}

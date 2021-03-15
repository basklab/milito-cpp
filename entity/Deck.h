#ifndef MILITO_CPP_DECK_H
#define MILITO_CPP_DECK_H


#include <variant>
#include <vector>
#include "LeaderCard.h"
#include "UnitCard.h"

using namespace std;

class Deck {
public:
    explicit Deck(vector<variant<LeaderCard, UnitCard>> vv);

    vector<variant<LeaderCard, UnitCard>> cards{};


    nlohmann::json getJson();

};

nlohmann::json Deck::getJson() {
    vector<nlohmann::json> result;
    for (auto card : cards) {
        if (card.index() == 0) {
            auto v = std::get<LeaderCard>(card);
            result.push_back(v.getJson());
        } else {
            auto v = std::get<UnitCard>(card);
            result.push_back(v.getJson());
        }
    }
    return result;
}

Deck::Deck(vector<variant<LeaderCard, UnitCard>> vv) : cards(vv) {}

#endif //MILITO_CPP_DECK_H

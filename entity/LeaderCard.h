#ifndef MILITO_CPP_LEADERCARD_H
#define MILITO_CPP_LEADERCARD_H

#include <nlohmann/json.hpp>
#include <utility>
#include "Card.h"

class LeaderCard : Card {
public:
    int id;
    int combat_value;
    int place_unit_ability;
    std::string special_effect;

    LeaderCard(int combatValue, int placeUnitAbility, std::string specialEffect = "");

    nlohmann::json getJson() override;

};

nlohmann::json LeaderCard::getJson() {
    nlohmann::json result;
    result["id"] = id;
    result["combat_value"] = combat_value;
    result["place_unit_ability"] = place_unit_ability;
    result["special_effect"] = special_effect;
    return result;
}

LeaderCard::LeaderCard(int combatValue, int placeUnitAbility, std::string specialEffect) : combat_value(
        combatValue),
                                                                                           place_unit_ability(
                                                                                                   placeUnitAbility),
                                                                                           special_effect(std::move(
                                                                                                   specialEffect)) {}

#endif //MILITO_CPP_LEADERCARD_H

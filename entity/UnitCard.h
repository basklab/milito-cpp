#ifndef MILITO_CPP_UNITCARD_H
#define MILITO_CPP_UNITCARD_H

#include <nlohmann/json.hpp>
#include <utility>
#include "Card.h"

class UnitCard : Card {
public:
    int id;
    std::string unit_type;

//    UnitCard(std::string unitType, int speed, int attackStrength, int defenceStrength);
    UnitCard(std::string unitType, int speed, int attackStrength, int defenceStrength, bool combineAbility=false);

    int speed;
    int attack_strength;
    int defence_strength;
    int deploy_penalty;
    int flank_penalty;
    bool combine_ability;
    std::string attack_modifiers;
    std::string defence_modifiers;

    nlohmann::json getJson() override;

};

nlohmann::json UnitCard::getJson() {
    nlohmann::json result;
    result["id"] = id;
    result["unit_type"] = unit_type;
    result["speed"] = speed;
    return result;
}

UnitCard::UnitCard(std::string unitType, int speed, int attackStrength, int defenceStrength, bool combineAbility)
        : unit_type(std::move(
                  unitType)),
          speed(speed),
          attack_strength(
                  attackStrength),
          defence_strength(
                  defenceStrength),
          combine_ability(combineAbility) {}


#endif //MILITO_CPP_UNITCARD_H

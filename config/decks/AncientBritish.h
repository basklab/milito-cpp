#ifndef MILITO_CPP_ANCIENTBRITISH_H
#define MILITO_CPP_ANCIENTBRITISH_H


#include "../../entity/UnitCard.h"
#include "commonDecks.h"
#include "../../entity/Deck.h"
#include <variant>


void append_to_vector(std::vector<UnitCard> &vec, int num, const UnitCard &card) {
    for (int i = 0; i < num; i++) {
        vec.emplace_back(card);
    }
}

const UnitCard chariots(
        "Chariots",
        3,
        4,
        2
);

const UnitCard warband_medium_infantry(
        "Warband_Med_Inf",
        2,
        4,
        2
);

std::vector<UnitCard> make_unit_cards() {
    std::vector<UnitCard> result;
    append_to_vector(result, 6, warband_medium_infantry);
    append_to_vector(result, 6, slingers);
    append_to_vector(result, 6, chariots);
    append_to_vector(result, 4, light_cavalry);
    return result;
}


std::vector<LeaderCard> make_leader_cards() {
    auto xyz = std::vector<LeaderCard>{
            {3,
             3,
            },
            {2,
                    2,
            },
            {2,
                    1,
                    "if win combat"
            },
            {1,
                    2,
                    "+2 if played in Wood or Rough column.",
            },
            {1,
                    1,
                    "+2 if played with 2x Chariots",
            },
            {1,
                    1,
                    "+2 if played with 2x Slingers",
            },
            {1,
                    1,
                    "+2 if played with 2x Warband Medium Infantry",
            },
            {-1,
                    1,
            },
    };
    return xyz;
}

typedef std::variant<LeaderCard, UnitCard> PolyCard;


Deck make_deck_ab() {
    std::vector<PolyCard> result;
    auto leaders = make_leader_cards();
    auto units = make_unit_cards();
    result.insert(std::end(result), std::begin(leaders), std::end(leaders));
    result.insert(std::end(result), std::begin(units), std::end(units));
    return Deck(result);
}




#endif //MILITO_CPP_ANCIENTBRITISH_H





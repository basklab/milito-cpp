#ifndef MILITO_CPP_CARD_H
#define MILITO_CPP_CARD_H


class Card {

    virtual nlohmann::json getJson() = 0;

};


#endif //MILITO_CPP_CARD_H

//
// Created by astraeven on 2021/6/3.
//

#ifndef SFML_GAME_PROJECT_DEALER_H
#define SFML_GAME_PROJECT_DEALER_H
#include <SFML/Graphics.hpp>
#include "StackOfCard.h"
#include "Scorer.h"
class Dealer : public Scorer{
private:
    std::vector<Cards> handCards;
public:
    Dealer();
    void setDealerCard(StackOfCard& deckOfCards);
    int getDealerValue();
    Cards getCardAt(int i);
    int getCardAmount();
    void initializeHandCards();
};


#endif //SFML_GAME_PROJECT_DEALER_H

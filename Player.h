//
// Created by astraeven on 2021/6/8.
//

#ifndef SFML_GAME_PROJECT_PLAYER_H
#define SFML_GAME_PROJECT_PLAYER_H
#include <SFML/Graphics.hpp>
#include "StackOfCard.h"
#include "Scorer.h"

class Player : public Scorer{
private:
    std::vector<Cards> handCards;
public:
    Player();
    void setPlayerCard(StackOfCard& deckOfCards);
    void hitPlayerCard(StackOfCard& deckOfCards);
    void initializeHandCards();
    void updateValue();
    int getPlayerValue();
    int getCardAmount();
    Cards getCardAt(int i);
};


#endif //SFML_GAME_PROJECT_PLAYER_H

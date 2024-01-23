//
// Created by astraeven on 2021/5/18.
//

#ifndef SFML_GAME_PROJECT_STACKOFCARD_H
#define SFML_GAME_PROJECT_STACKOFCARD_H
#include "Stack.h"
#include "Deck.h"

class StackOfCard {
private:
    Deck deck;
    Stack<Cards> StackCards;
public:
    StackOfCard();
    Cards takeOutCard();
    void addDeckCard(int HowManyDeckOfCard);
    int remainingCards();
};


#endif //SFML_GAME_PROJECT_STACKOFCARD_H

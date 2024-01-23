//
// Created by astraeven on 2021/5/18.
//

#include "StackOfCard.h"
StackOfCard::StackOfCard()
{
    addDeckCard(5);
}

Cards StackOfCard::takeOutCard()
{
    if (StackCards.size() < 15){
        addDeckCard(5);
    }
    Cards temp;
    temp = StackCards.top();
    StackCards.pop();
    return temp;
}

void StackOfCard::addDeckCard(int HowManyDeckOfCard)
{
    for(int j = 0; j < HowManyDeckOfCard;j++)
    {
        deck.shuffle();
        for (int i = 0; i < 52; i++)
            StackCards.push(deck.getCardAt(i));
    }
}

int StackOfCard::remainingCards()
{
    return StackCards.size();
}
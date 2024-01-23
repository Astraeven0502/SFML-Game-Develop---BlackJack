//
// Created by astraeven on 2021/6/3.
//

#include "Dealer.h"

Dealer::Dealer()
{
    this->setPosition({500,300});
}

void Dealer::setDealerCard(StackOfCard& deckOfCards)
{
    handCards.push_back(deckOfCards.takeOutCard());
    handCards.push_back(deckOfCards.takeOutCard());
    for (int i = 0; i < handCards.size(); i++)
    {
        this->addValue(handCards[i]);
    }

    int count = 2;
    while(getDealerValue() < 17) {
        handCards.push_back(deckOfCards.takeOutCard());
        this->addValue(handCards[count]);
        count++;

        int howManyACE = 0;
        for (int i = 0; i < handCards.size(); i++)
        {
            if(handCards[i].getRankAssets() == ACE)
                howManyACE += 1;
        }

        //initialize Score(prevent multiple change)
        initializeScore();
        for (int i = 0; i < handCards.size(); i++)
        {
            this->addValue(handCards[i]);
        }

        for (int i = 0; i < howManyACE; i++)
        {
            if (getDealerValue() > 21)
            {
                changeAceValue();
            }
        }
    }
}

int Dealer::getDealerValue()
{
    return this->getValue();
}
Cards Dealer::getCardAt(int i)
{
    return handCards[i];
}

int Dealer::getCardAmount()
{
    return handCards.size();
}

void Dealer::initializeHandCards()
{
    handCards.erase(handCards.begin(), handCards.end());
}

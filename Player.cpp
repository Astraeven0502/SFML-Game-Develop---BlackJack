//
// Created by astraeven on 2021/6/8.
//

#include "Player.h"

Player::Player() {

}

void Player::setPlayerCard(StackOfCard& deckOfCards)
{
    handCards.push_back(deckOfCards.takeOutCard());
    handCards.push_back(deckOfCards.takeOutCard());
    for (int i = 0; i < handCards.size(); i++)
    {
        this->addValue(handCards[i]);
    }
}

void Player::hitPlayerCard(StackOfCard &deckOfCards)
{
    handCards.push_back(deckOfCards.takeOutCard());
    this->addValue(handCards[handCards.size()-1]);
}

void Player::initializeHandCards()
{
    handCards.erase(handCards.begin(), handCards.end());
}

void Player::updateValue()
{
    //count how many Ace in hand
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

    //change the value if there is Ace
    for (int i = 0; i < howManyACE; i++)
    {
        if (getPlayerValue() > 21)
        {
            changeAceValue();
        }
    }
}

int Player::getPlayerValue()
{
    return this->getValue();
}

int Player::getCardAmount()
{
    return handCards.size();
}

Cards Player::getCardAt(int i)
{
    return handCards[i];
}

//
// Created by astraeven on 2021/5/17.
//

#include "Deck.h"

//constructor
/*--------------------------------------------------------------------------------------------------*/
Deck::Deck()
{
    int count = 0;
    for(int i = SPADES; i <= DIAMONDS; i++)
    {
        for(int j = ACE; j <= KING; j++)
        {
            Cards c(static_cast<suitAssets>(i), static_cast<rankAssets>(j));
            deck[count] = c;
            count++;
        }
    }
}

//gets the Card at the given index
/*--------------------------------------------------------------------------------------------------*/
Cards Deck::getCardAt(int index)
{
    return deck[index];
}

//puts cards in random order
/*--------------------------------------------------------------------------------------------------*/
void Deck::shuffle()
{
    Cards temp;
    for(int i=0; i<10; i++) {
        for (int j = 0; j < 52; j++) {
            int randomNumber=rand() % 52;
            temp = deck[j];
            deck[j] = deck[randomNumber];
            deck[randomNumber] = temp;
        }
    }
}

// returns the next card in the deck
/*--------------------------------------------------------------------------------------------------*/
Cards Deck::dealCard()
{
    cardIndex++;
    return deck[cardIndex];
}

// prints all the cards to the console
/*--------------------------------------------------------------------------------------------------*/
std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
    for(int i = 0; i < 52; i++)
    {
        out << i+1 << ": " << deck.deck[i] <<std::endl;
    }
    return out;
}
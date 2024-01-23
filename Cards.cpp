//
// Created by astraeven on 2021/5/17.
//

#include "Cards.h"

/*--------------------------------------------------------------------------------------------------*/
//default constructor
Cards::Cards() : Cards(SPADES, KING)
{

}

//constructor
Cards::Cards(suitAssets suit, rankAssets value)
{
    Cards::suit = suit;
    Cards::rank = value;
}

/*--------------------------------------------------------------------------------------------------*/
//getters
std::string Cards::getSuit() const
{
    switch (suit) {
        case SPADES: return "Spades";
        case HEARTS: return "Hearts";
        case CLUBS: return "Clubs";
        case DIAMONDS: return "Diamonds";
    }
}
std::string Cards::getRank() const
{
    switch (rank) {
        case ACE: return "Ace";
        case TWO: return "Two";
        case THREE: return "Three";
        case FOUR: return "Four";
        case FIVE: return "Five";
        case SIX: return "Six";
        case SEVEN: return "Seven";
        case EIGHT: return "Eight";
        case NINE: return "Nine";
        case TEN: return "Ten";
        case JACK: return "Jack";
        case QUEEN: return "Queen";
        case KING: return "King";
    }
}
suitAssets Cards::getSuitAssets() const
{
    return suit;
}
rankAssets Cards::getRankAssets() const
{
    return rank;
}

/*--------------------------------------------------------------------------------------------------*/
//setters
void Cards::setSuit(suitAssets suits)
{
    Cards::suit = suits;
}
void Cards::setRank(rankAssets value)
{
    Cards::rank = value;
}

/*--------------------------------------------------------------------------------------------------*/
//operator
std::ostream& operator<<(std::ostream& out, const Cards& card)
{
    out << card.getRank() << " of " << card.getSuit();
    return out;
}
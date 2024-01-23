//
// Created by astraeven on 2021/5/17.
//

#ifndef SFML_GAME_PROJECT_DECK_H
#define SFML_GAME_PROJECT_DECK_H
#include "Cards.h"

class Deck {
private:
    Cards deck[52];// this is your final deck of cards
    const int DECK_SIZE = 52;// this is the size of your deck
    int cardIndex = -1; //marks the index of the next card in the deck

public:
    Deck(); // this is the constructor
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); // prints all the cards to the console
    Cards getCardAt(int index);// gets the Card at the given index
    void shuffle(); // puts cards in random order
    Cards dealCard(); // returns the next card in the deck

//    bool empty(); //returns true if deck has no cards

};


#endif //SFML_GAME_PROJECT_DECK_H

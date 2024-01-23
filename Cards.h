//
// Created by astraeven on 2021/5/17.
//

#ifndef SFML_GAME_PROJECT_CARDS_H
#define SFML_GAME_PROJECT_CARDS_H
#include <iostream>
#include "Ranks.h"
#include "Suits.h"

class Cards : Ranks, Suits{

private:
    Suits suits;
    Ranks value;
public:
//constructor
    Cards();
    Cards(suitAssets suit, rankAssets value);
//getters
    std::string getSuit() const;
    std::string getRank() const;
    suitAssets getSuitAssets() const;
    rankAssets getRankAssets() const;
//setters
    void setSuit(suitAssets suits);
    void setRank(rankAssets value);

    friend std::ostream& operator<<(std::ostream& out, const Cards& card);
};

#endif //SFML_GAME_PROJECT_CARDS_H

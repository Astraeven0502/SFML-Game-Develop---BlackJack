//
// Created by astraeven on 2021/5/19.
//

#include "Scorer.h"

Scorer::Scorer()
{
    text.setFont(Fonts::getFont());
    text.setString( "Total value: "+ std::to_string(value));
    text.setPosition(500,630);
}

void Scorer::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(text);
}

void Scorer::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Scorer::update()
{
    text.setString( "Total value: "+ std::to_string(value));
    if (value > 21)
        text.setString( "Total value: "+ std::to_string(value) + " (bust)");
}

void Scorer::addValue(Cards card)
{
    if (card.getRankAssets() == ACE) {
//        if (value+11 <=21)
            value = value+11;
//        else
//            value = value
    }
    if (card.getRankAssets() == TWO) {
        value = value+2;
    }
    if (card.getRankAssets() == THREE) {
        value = value+3;
    }
    if (card.getRankAssets() == FOUR) {
        value = value+4;
    }
    if (card.getRankAssets() == FIVE) {
        value = value+5;
    }
    if (card.getRankAssets() == SIX) {
        value = value+6;
    }
    if (card.getRankAssets() == SEVEN) {
        value = value+7;
    }
    if (card.getRankAssets() == EIGHT) {
        value = value+8;
    }
    if (card.getRankAssets() == NINE) {
        value = value+9;
    }
    if (card.getRankAssets() == TEN) {
        value = value+10;
    }
    if (card.getRankAssets() == JACK) {
        value = value+10;
    }
    if (card.getRankAssets() == QUEEN) {
        value = value+10;
    }
    if (card.getRankAssets() == KING) {
        value = value+10;
    }
}

int Scorer::getValue() const {
    return value;
}

void Scorer::setValue(int value) {
    Scorer::value = value;
}

void Scorer::changeAceValue() {
    value = value - 10;
}

void Scorer::setPosition(sf::Vector2f position)
{
    text.setPosition(position);
}

void Scorer::initializeScore()
{
    value = 0;
}
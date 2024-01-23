//
// Created by astraeven on 2021/6/3.
//

#ifndef SFML_GAME_PROJECT_MONEYBOX_H
#define SFML_GAME_PROJECT_MONEYBOX_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"

class MoneyBox : public sf::Drawable, public sf::Transformable{
private:
    sf::RectangleShape background;
    sf::Text balance;

public:
    MoneyBox();
    MoneyBox(int balance, sf::Vector2f position);
    void setBalance(int balance);
    int getBalance();
    void setPosition(sf::Vector2f position);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void setMoneyBox(int balance, sf::Vector2f position);
};


#endif //SFML_GAME_PROJECT_MONEYBOX_H

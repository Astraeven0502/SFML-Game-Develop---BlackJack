//
// Created by astraeven on 2021/6/3.
//

#include "MoneyBox.h"

MoneyBox::MoneyBox() : MoneyBox(0, {0,0}) {

}

MoneyBox::MoneyBox(int balance, sf::Vector2f position) {

    setBalance(balance);
    this->balance.setFont(Fonts::getFont());
    this->balance.setCharacterSize(48);
    this->balance.setFillColor(sf::Color::White);

    background.setSize({300, 60});
    background.setFillColor({0,0,0});

    MoneyBox::setPosition(position);

}

void MoneyBox::setBalance(int balance){
    this->balance.setString("$" + std::to_string(balance));
}

int MoneyBox::getBalance() {
    std::string temp = balance.getString().substring(1);
    return std::stoi(temp);
}

void MoneyBox::setPosition(sf::Vector2f position) {
    background.setPosition(position);

    this->balance.setPosition({position.x+5,
                               background.getGlobalBounds().top + background.getGlobalBounds().height/2 - this->balance.getGlobalBounds().height*2/3});
}

void MoneyBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(background);
    window.draw(balance);
}

void MoneyBox::setMoneyBox(int balance, sf::Vector2f position)
{
    setBalance(balance);
    this->balance.setFont(Fonts::getFont());
    this->balance.setCharacterSize(48);
    this->balance.setFillColor(sf::Color::White);

    background.setSize({300, 75});
    background.setFillColor({0,60,0});

    MoneyBox::setPosition(position);
}
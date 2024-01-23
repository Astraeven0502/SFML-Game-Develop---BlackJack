//
// Created by astraeven on 2021/6/3.
//

#ifndef SFML_GAME_PROJECT_ANTE_H
#define SFML_GAME_PROJECT_ANTE_H
#include "MoneyBox.h"
#include "Button.h"
#include "MouseEvents.h"

class Ante : public sf::Drawable, public sf::Transformable{
private:
    MoneyBox betMoneyBox, balanceMoneyBox;
    Button one, five, ten, hundred;
    Button minusOne, minusFive, minusTen, minusHundred;
    Button enter;

public:
    Ante();
    void update();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void setBetMoneyBoxPosition(sf::Vector2f position);
    void setBalanceMoneyBoxPosition(sf::Vector2f position);
    void doubleTheBet();

    void playerWin();
    void playerLose();
    void tie();

    bool playerEnterBet();
    bool canDoubleTheBet();

    void initializeAnteButton();

};


#endif //SFML_GAME_PROJECT_ANTE_H

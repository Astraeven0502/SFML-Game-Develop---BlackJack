//
// Created by astraeven on 2021/6/3.
//

#include "Ante.h"

Ante::Ante()
{
    Ante::setBetMoneyBoxPosition({40,600});
    Ante::setBalanceMoneyBoxPosition({40,400});
    balanceMoneyBox.setBalance(100);

    enter.setButton("enter", {180,60}, {0,60,0}, {350,1000});

    one.setButton("+", {60,60}, {0,60,0}, {250,700});
    five.setButton("+", {60,60}, {0,60,0}, {250,800});
    ten.setButton("+", {60,60}, {0,60,0}, {250,900});
    hundred.setButton("+", {60,60}, {0,60,0}, {250,1000});

    minusOne.setButton("-", {60,60}, {0,60,0}, {150,700});
    minusFive.setButton("-", {60,60}, {0,60,0}, {150,800});
    minusTen.setButton("-", {60,60}, {0,60,0}, {150,900});
    minusHundred.setButton("-", {60,60}, {0,60,0}, {150,1000});

    enter.setTextSize(60);

    one.setTextSize(60);
    five.setTextSize(60);
    ten.setTextSize(60);
    hundred.setTextSize(60);

    minusOne.setTextSize(60);
    minusFive.setTextSize(60);
    minusTen.setTextSize(60);
    minusHundred.setTextSize(60);

    one.buttonTextCalibration({260,695});
    five.buttonTextCalibration({260,795});
    ten.buttonTextCalibration({260,895});
    hundred.buttonTextCalibration({260,995});

    minusOne.buttonTextCalibration({170,680});
    minusFive.buttonTextCalibration({170,780});
    minusTen.buttonTextCalibration({170,880});
    minusHundred.buttonTextCalibration({170,980});

}

void Ante::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(betMoneyBox);
    window.draw(balanceMoneyBox);
    window.draw(one);
    window.draw(five);
    window.draw(ten);
    window.draw(hundred);
    window.draw(minusOne);
    window.draw(minusFive);
    window.draw(minusTen);
    window.draw(minusHundred);
    window.draw(enter);
}

void Ante::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    one.addEventHandler(window, event);
    five.addEventHandler(window, event);
    ten.addEventHandler(window, event);
    hundred.addEventHandler(window, event);
    minusOne.addEventHandler(window, event);
    minusFive.addEventHandler(window, event);
    minusTen.addEventHandler(window, event);
    minusHundred.addEventHandler(window, event);
    enter.addEventHandler(window, event);

    int balance = betMoneyBox.getBalance();
    if(MouseEvents::mouseClicked(one, window) && event.type == sf::Event::MouseButtonPressed)
    {
        balance += 1;
    }
    else if(MouseEvents::mouseClicked(five, window) && event.type == sf::Event::MouseButtonPressed)
    {
        balance += 5;
    }
    else if(MouseEvents::mouseClicked(ten, window) && event.type == sf::Event::MouseButtonPressed)
    {
        balance += 10;
    }
    else if(MouseEvents::mouseClicked(hundred, window) && event.type == sf::Event::MouseButtonPressed)
    {
        balance += 100;
    }
    else if(MouseEvents::mouseClicked(minusOne, window) && event.type == sf::Event::MouseButtonPressed && balance >= 1)
    {
        balance -= 1;
    }
    else if(MouseEvents::mouseClicked(minusFive, window) && event.type == sf::Event::MouseButtonPressed && balance >= 5)
    {
        balance -= 5;
    }
    else if(MouseEvents::mouseClicked(minusTen, window) && event.type == sf::Event::MouseButtonPressed && balance >= 10)
    {
        balance -= 10;
    }
    else if(MouseEvents::mouseClicked(minusHundred, window) && event.type == sf::Event::MouseButtonPressed && balance >= 100)
    {
        balance -= 100;
    }
    betMoneyBox.setBalance(balance);

    if(MouseEvents::mouseClicked(enter, window) && event.type == sf::Event::MouseButtonPressed
    && (balanceMoneyBox.getBalance() - betMoneyBox.getBalance()) >= 0)
    {
        enter.enableState(States::HIDDEN);

        one.enableState(States::HIDDEN);
        five.enableState(States::HIDDEN);
        ten.enableState(States::HIDDEN);
        hundred.enableState(States::HIDDEN);

        minusOne.enableState(States::HIDDEN);
        minusFive.enableState(States::HIDDEN);
        minusTen.enableState(States::HIDDEN);
        minusHundred.enableState(States::HIDDEN);
        balanceMoneyBox.setBalance(balanceMoneyBox.getBalance() - betMoneyBox.getBalance());
    }
}

void Ante::setBetMoneyBoxPosition(sf::Vector2f position)
{
    betMoneyBox.setPosition(position);
}

void Ante::setBalanceMoneyBoxPosition(sf::Vector2f position)
{
    balanceMoneyBox.setPosition(position);
}


void Ante::doubleTheBet() {
    if(canDoubleTheBet())
    {
        int temp = balanceMoneyBox.getBalance();
        balanceMoneyBox.setBalance(temp - betMoneyBox.getBalance());
        betMoneyBox.setBalance(betMoneyBox.getBalance() * 2);
    }
}

void Ante::update()
{
    one.update();
    five.update();
    ten.update();
    hundred.update();
    minusOne.update();
    minusFive.update();
    minusTen.update();
    minusHundred.update();
    enter.update();
}

void Ante::playerWin()
{
    int temp = balanceMoneyBox.getBalance();
    balanceMoneyBox.setBalance(temp + (betMoneyBox.getBalance() * 2));
    betMoneyBox.setBalance(0);

}
void Ante::playerLose()
{
    betMoneyBox.setBalance(0);
}
void Ante::tie()
{
    int temp = balanceMoneyBox.getBalance();
    balanceMoneyBox.setBalance(temp + betMoneyBox.getBalance());
    betMoneyBox.setBalance(0);
}

bool Ante::playerEnterBet()
{
    return enter.checkState(States::HIDDEN);
}

bool Ante::canDoubleTheBet()
{
    if(betMoneyBox.getBalance() * 2 <= balanceMoneyBox.getBalance())
        return true;
    else
        return false;
}


void Ante::initializeAnteButton()
{
    one.disableState(States::HIDDEN);
    one.enableState(States::NORMAL);
    five.disableState(States::HIDDEN);
    five.enableState(States::NORMAL);
    ten.disableState(States::HIDDEN);
    ten.enableState(States::NORMAL);
    hundred.disableState(States::HIDDEN);
    hundred.enableState(States::NORMAL);
    minusOne.disableState(States::HIDDEN);
    minusOne.enableState(States::NORMAL);
    minusFive.disableState(States::HIDDEN);
    minusFive.enableState(States::NORMAL);
    minusTen.disableState(States::HIDDEN);
    minusTen.enableState(States::NORMAL);
    minusHundred.disableState(States::HIDDEN);
    minusHundred.enableState(States::NORMAL);
    enter.disableState(States::HIDDEN);
    enter.enableState(States::NORMAL);
    betMoneyBox.setBalance(0);
}


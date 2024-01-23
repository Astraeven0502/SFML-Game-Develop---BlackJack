//
// Created by astraeven on 2021/5/17.
//

#include "Button.h"

Button::Button() : Button("Text")
{

}
Button::Button(std::string text) : Button(text, {100, 50}, sf::Color::Magenta)
{

}
Button::Button(std::string text, sf::Vector2f size, sf::Color color) : Button(text, size, color, {0,0})
{
    initialize();
}
Button::Button(std::string& text, sf::Vector2f size, sf::Color color, sf::Vector2f position)
{
    this->text.setString(text);
    background.setSize(size);
    this->text.setCharacterSize(80);
    background.setFillColor(color);
    this->color = color;
    background.setPosition(position);
    this->text.setPosition(position);
    initialize();
    tempPosition = position;
}

void Button::center()
{
    sf::FloatRect bBounds = background.getGlobalBounds();
    sf::FloatRect tBounds = text.getGlobalBounds();

    text.setPosition(bBounds.left+((bBounds.width-tBounds.width)/2)
                     , bBounds.top+((bBounds.height-tBounds.height)/2) - text.getCharacterSize()/3);

}
void Button::initialize()
{
    text.setFont(Fonts::getFont());
    center();
}

//polymorphism
void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(background);
    window.draw(text);
}

//event handler
void Button::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    hover(window, event);
}

//make any necessary updates
void Button::update()
{
    if(checkState(HOVERED))
        text.setFillColor(sf::Color(250, 180, 0));
    if(checkState(NORMAL)) {
        background.setFillColor(color);
        text.setFillColor(sf::Color::White);
        this->setPosition(tempPosition);
    }
    if(checkState(EXIT)){
        exit(1);
    }
    if (checkState(HIDDEN)) {
        background.setPosition(10000, 10000);
        text.setPosition(10000, 10000);
    }
}

bool Button::hover(sf::RenderWindow& window, sf::Event event)
{
    sf::FloatRect bBounds = background.getGlobalBounds();
    sf::Vector2f mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    if(bBounds.contains(mPos))
    {
        enableState(HOVERED);
        disableState(NORMAL);
        return true;
    }
    else
    {
        enableState(NORMAL);
        disableState(HOVERED);
        return false;
    }
}

sf::FloatRect Button::getGlobalBounds()
{
    return background.getGlobalBounds();
}

void Button::setButton(std::string text, sf::Vector2f size, sf::Color color, sf::Vector2f position)
{
    this->text.setString(text);
    background.setSize(size);
    this->text.setCharacterSize(80);
    background.setFillColor(color);
    this->color = color;
    background.setPosition(position);
    this->text.setPosition(position);
    initialize();
    tempPosition = position;
}

void Button::setPosition(sf::Vector2f position)
{
    background.setPosition(position);
    this->text.setPosition(position);
    initialize();
    tempPosition = position;
}

sf::Vector2f Button::getPosition()
{
    return background.getPosition();
}

void Button::setTextSize(unsigned int size)
{
    this->text.setCharacterSize(size);
    initialize();
}

void Button::buttonTextCalibration(sf::Vector2f position)
{
    text.setPosition(position);
}
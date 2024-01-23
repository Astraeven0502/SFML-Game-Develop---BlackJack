//
// Created by astraeven on 2021/5/17.
//

#ifndef SFML_GAME_PROJECT_BUTTON_H
#define SFML_GAME_PROJECT_BUTTON_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "States.h"

class Button : public sf::Drawable, public sf::Transformable, public States{

private:
    sf::RectangleShape background;
    sf::Text text;
    sf::Color color;
    sf::Vector2f tempPosition;
    void center();
    void initialize();
    bool hover(sf::RenderWindow& window, sf::Event event);

public:
    Button();
    Button(std::string text);
    Button(std::string text, sf::Vector2f size, sf::Color color);
    Button(std::string& text, sf::Vector2f size, sf::Color color, sf::Vector2f position);

    //polymorphism, pure virtual function defined
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //event handler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //make any necessary updates
    void update();

    sf::FloatRect getGlobalBounds();

    void setButton(std::string text, sf::Vector2f size, sf::Color color, sf::Vector2f position);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    void setTextSize(unsigned int size);
    void buttonTextCalibration(sf::Vector2f position);

};

#endif //SFML_GAME_PROJECT_BUTTON_H

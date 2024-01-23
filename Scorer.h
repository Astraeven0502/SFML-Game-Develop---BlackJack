//
// Created by astraeven on 2021/5/19.
//

#ifndef SFML_GAME_PROJECT_SCORER_H
#define SFML_GAME_PROJECT_SCORER_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "Cards.h"

class Scorer : public sf::Drawable, public sf::Transformable{
private:
    int value = 0;
    sf::Text text;
public:
    Scorer();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void addValue(Cards card);
    int getValue() const;
    void setValue(int value);
    void changeAceValue();
    void setPosition(sf::Vector2f position);
    void initializeScore();
};


#endif //SFML_GAME_PROJECT_SCORER_H

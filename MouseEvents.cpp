//
// Created by astraeven on 2021/6/3.
//
#ifndef SFML_GAME_PROJECT_MOUSEEVENTS_CPP
#define SFML_GAME_PROJECT_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<class T>
bool MouseEvents::mouseClicked(T &object, sf::RenderWindow &window) {
    return (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isHovered(object, window));
}

template<class T>
bool MouseEvents::isHovered(T &object, sf::RenderWindow &window) {
    sf::FloatRect bounds = object.getGlobalBounds();
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return bounds.contains(mPos);
}


#endif //SFML_GAME_PROJECT_MOUSEEVENTS_CPP
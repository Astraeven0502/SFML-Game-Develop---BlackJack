//
// Created by astraeven on 2021/6/3.
//

#ifndef SFML_GAME_PROJECT_MOUSEEVENTS_H
#define SFML_GAME_PROJECT_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>

class MouseEvents {
public:
    template<class T>
    static bool mouseClicked(T& object, sf::RenderWindow& window);
    template<class T>
    static bool isHovered(T& object, sf::RenderWindow& window);
};
#include "MouseEvents.cpp"
#endif //SFML_GAME_PROJECT_MOUSEEVENTS_H

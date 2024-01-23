//
// Created by astraeven on 2021/5/17.
//

#ifndef SFML_GAME_PROJECT_FONTS_H
#define SFML_GAME_PROJECT_FONTS_H
#include <SFML/Graphics.hpp>

class Fonts {
private:
    static sf::Font font;
    static bool loaded;
    static void loadFont();

public:
    static sf::Font& getFont();
};


#endif //SFML_GAME_PROJECT_FONTS_H

//
// Created by astraeven on 2021/5/17.
//

#ifndef SFML_GAME_PROJECT_IMAGES_H
#define SFML_GAME_PROJECT_IMAGES_H
#include <SFML/Graphics.hpp>


class images {
private:
    static sf::Texture texture[59];
    static bool loaded;
    static void loadImages();
public:
    static sf::Texture& getImage(int index);
};


#endif //SFML_GAME_PROJECT_IMAGES_H

//
// Created by astraeven on 2021/5/17.
//

#include "images.h"

sf::Texture images::texture[59];
bool images::loaded = false;

void images::loadImages()
{
    if (!loaded)
    {
        if(!texture[0].loadFromFile("images/ace_of_clubs.png"))
            exit(1);
        if(!texture[1].loadFromFile("images/ace_of_diamonds.png"))
            exit(1);
        if(!texture[2].loadFromFile("images/ace_of_hearts.png"))
            exit(1);
        if(!texture[3].loadFromFile("images/ace_of_spades.png"))
            exit(1);

        if(!texture[4].loadFromFile("images/2_of_clubs.png"))
            exit(1);
        if(!texture[5].loadFromFile("images/2_of_diamonds.png"))
            exit(1);
        if(!texture[6].loadFromFile("images/2_of_hearts.png"))
            exit(1);
        if(!texture[7].loadFromFile("images/2_of_spades.png"))
            exit(1);

        if(!texture[8].loadFromFile("images/3_of_clubs.png"))
            exit(1);
        if(!texture[9].loadFromFile("images/3_of_diamonds.png"))
            exit(1);
        if(!texture[10].loadFromFile("images/3_of_hearts.png"))
            exit(1);
        if(!texture[11].loadFromFile("images/3_of_spades.png"))
            exit(1);

        if(!texture[12].loadFromFile("images/4_of_clubs.png"))
            exit(1);
        if(!texture[13].loadFromFile("images/4_of_diamonds.png"))
            exit(1);
        if(!texture[14].loadFromFile("images/4_of_hearts.png"))
            exit(1);
        if(!texture[15].loadFromFile("images/4_of_spades.png"))
            exit(1);

        if(!texture[16].loadFromFile("images/5_of_clubs.png"))
            exit(1);
        if(!texture[17].loadFromFile("images/5_of_diamonds.png"))
            exit(1);
        if(!texture[18].loadFromFile("images/5_of_hearts.png"))
            exit(1);
        if(!texture[19].loadFromFile("images/5_of_spades.png"))
            exit(1);

        if(!texture[20].loadFromFile("images/6_of_clubs.png"))
            exit(1);
        if(!texture[21].loadFromFile("images/6_of_diamonds.png"))
            exit(1);
        if(!texture[22].loadFromFile("images/6_of_hearts.png"))
            exit(1);
        if(!texture[23].loadFromFile("images/6_of_spades.png"))
            exit(1);

        if(!texture[24].loadFromFile("images/7_of_clubs.png"))
            exit(1);
        if(!texture[25].loadFromFile("images/7_of_diamonds.png"))
            exit(1);
        if(!texture[26].loadFromFile("images/7_of_hearts.png"))
            exit(1);
        if(!texture[27].loadFromFile("images/7_of_spades.png"))
            exit(1);

        if(!texture[28].loadFromFile("images/8_of_clubs.png"))
            exit(1);
        if(!texture[29].loadFromFile("images/8_of_diamonds.png"))
            exit(1);
        if(!texture[30].loadFromFile("images/8_of_hearts.png"))
            exit(1);
        if(!texture[31].loadFromFile("images/8_of_spades.png"))
            exit(1);

        if(!texture[32].loadFromFile("images/9_of_clubs.png"))
            exit(1);
        if(!texture[33].loadFromFile("images/9_of_diamonds.png"))
            exit(1);
        if(!texture[34].loadFromFile("images/9_of_hearts.png"))
            exit(1);
        if(!texture[35].loadFromFile("images/9_of_spades.png"))
            exit(1);

        if(!texture[36].loadFromFile("images/10_of_clubs.png"))
            exit(1);
        if(!texture[37].loadFromFile("images/10_of_diamonds.png"))
            exit(1);
        if(!texture[38].loadFromFile("images/10_of_hearts.png"))
            exit(1);
        if(!texture[39].loadFromFile("images/10_of_spades.png"))
            exit(1);

        if(!texture[40].loadFromFile("images/jack_of_clubs.png"))
            exit(1);
        if(!texture[41].loadFromFile("images/jack_of_diamonds.png"))
            exit(1);
        if(!texture[42].loadFromFile("images/jack_of_hearts.png"))
            exit(1);
        if(!texture[43].loadFromFile("images/jack_of_spades.png"))
            exit(1);

        if(!texture[44].loadFromFile("images/queen_of_clubs.png"))
            exit(1);
        if(!texture[45].loadFromFile("images/queen_of_diamonds.png"))
            exit(1);
        if(!texture[46].loadFromFile("images/queen_of_hearts.png"))
            exit(1);
        if(!texture[47].loadFromFile("images/queen_of_spades.png"))
            exit(1);

        if(!texture[48].loadFromFile("images/king_of_clubs.png"))
            exit(1);
        if(!texture[49].loadFromFile("images/king_of_diamonds.png"))
            exit(1);
        if(!texture[50].loadFromFile("images/king_of_hearts.png"))
            exit(1);
        if(!texture[51].loadFromFile("images/king_of_spades.png"))
            exit(1);

        if(!texture[52].loadFromFile("images/deck.png"))
            exit(1);

        if(!texture[53].loadFromFile("images/1.png"))
            exit(1);
        if(!texture[54].loadFromFile("images/5.png"))
            exit(1);
        if(!texture[55].loadFromFile("images/10.png"))
            exit(1);
        if(!texture[56].loadFromFile("images/100.png"))
            exit(1);

        if(!texture[57].loadFromFile("images/cardBack.png"))
            exit(1);

        if(!texture[58].loadFromFile("images/Blackjack.jpg"))
            exit(1);

        loaded = true;
    }
}
sf::Texture& images::getImage(int index)
{
    loadImages();
    return texture[index];
}

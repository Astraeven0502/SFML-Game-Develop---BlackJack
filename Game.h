//
// Created by astraeven on 2021/5/18.
//

#ifndef SFML_GAME_PROJECT_GAME_H
#define SFML_GAME_PROJECT_GAME_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "images.h"
#include "StackOfCard.h"
#include "Ante.h"
#include "Dealer.h"
#include "Player.h"

class Game {
public:
    Game();
    ~Game();
    void run();
private:
    void processInput();
    void update();
    void render();
    void drawPlayerCard();
    void setTexture();
    void printCard(Cards card, sf::Vector2f position);
    bool playerWin(Dealer& dealer, Scorer& scorer);
    bool playerLose(Dealer& dealer, Scorer& scorer);
    void initializeButton();
    void restart();
    void removeCover();
    void coverCards();
    StackOfCard deckOfCards;
    bool start = false;
    bool finish = false;
    bool win = false, lose = false, tie = false;
    sf::RenderWindow window;
    Button startButton;
    Button hitButton, standButton, doubleButton, exitButton;
    Button nextGameButton;
    Ante ante;
    Dealer dealer;
    Player player;
    sf::Text myInfo;
    sf::Text remainingCardsDisplay;
    sf::Text instruction, balanceText, betText;
    sf::Text winText, loseText, tieText;
    sf::Sprite blackJack;
    sf::Sprite deck;
    sf::Sprite ace_of_clubs, ace_of_diamonds, ace_of_hearts, ace_of_spades;
    sf::Sprite two_of_clubs, two_of_diamonds, two_of_hearts, two_of_spades;
    sf::Sprite three_of_clubs, three_of_diamonds, three_of_hearts, three_of_spades;
    sf::Sprite four_of_clubs, four_of_diamonds, four_of_hearts, four_of_spades;
    sf::Sprite five_of_clubs, five_of_diamonds, five_of_hearts, five_of_spades;
    sf::Sprite six_of_clubs, six_of_diamonds, six_of_hearts, six_of_spades;
    sf::Sprite seven_of_clubs, seven_of_diamonds, seven_of_hearts, seven_of_spades;
    sf::Sprite eight_of_clubs, eight_of_diamonds, eight_of_hearts, eight_of_spades;
    sf::Sprite nine_of_clubs, nine_of_diamonds, nine_of_hearts, nine_of_spades;
    sf::Sprite ten_of_clubs, ten_of_diamonds, ten_of_hearts, ten_of_spades;
    sf::Sprite jack_of_clubs, jack_of_diamonds, jack_of_hearts, jack_of_spades;
    sf::Sprite queen_of_clubs, queen_of_diamonds, queen_of_hearts, queen_of_spades;
    sf::Sprite king_of_clubs, king_of_diamonds, king_of_hearts, king_of_spades;
    sf::Sprite chipOne, chipFive, chipTen, chipHundred;
    sf::Sprite cardBack;
    sf::Sprite cardCover_one, cardCover_two, cardCover_three;
};


#endif //SFML_GAME_PROJECT_GAME_H

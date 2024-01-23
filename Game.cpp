//
// Created by astraeven on 2021/5/18.
//

#include "Game.h"

//initialize
Game::Game()
{
    window.create(sf::VideoMode(1920, 1080, 32), "Test");
    startButton.setButton("START", {260,100}, {0,60,0}, {800,550});
    blackJack.setPosition({450,0});
    myInfo.setFont(Fonts::getFont());
    myInfo.setString("Name: Po Yu Lai\nCourse name: CS003A\nCRN: 31195\nSpring 2021");

    hitButton.setButton("HIT", {260,100}, {0,60,0}, {600,495});//600 495
    standButton.setButton("STAND", {260,100}, {0,60,0}, {900,495});// 900 495
    doubleButton.setButton("DOUBLE", {350,100}, {0,60,0}, {1200,495});
    exitButton.setButton("EXIT", {260,100}, {0,60,0}, {1620,950});
    nextGameButton.setButton("Next Game", {500,100}, {0,60,0}, {600,495});
    nextGameButton.enableState(States::HIDDEN);
    deck.setPosition(10,0);

    remainingCardsDisplay.setFont(Fonts::getFont());
    remainingCardsDisplay.setPosition({40,250});

    instruction.setFont(Fonts::getFont());
    instruction.setPosition({600, 495});
    instruction.setString("Please enter your bet");
    instruction.setCharacterSize(48);

    balanceText.setFont(Fonts::getFont());
    balanceText.setPosition({40,350});
    balanceText.setString("Balance");
    balanceText.setCharacterSize(48);

    betText.setFont(Fonts::getFont());
    betText.setPosition({40,550});
    betText.setString("Bet");
    betText.setCharacterSize(48);

    winText.setFont(Fonts::getFont());
    winText.setString("Win");
    winText.setPosition({700, 400});
    winText.setCharacterSize(80);
    winText.setFillColor(sf::Color::Yellow );

    loseText.setFont(Fonts::getFont());
    loseText.setString("Lose");
    loseText.setPosition({700, 400});
    loseText.setCharacterSize(80);
    loseText.setFillColor(sf::Color::Red);

    tieText.setFont(Fonts::getFont());
    tieText.setString("Tie");
    tieText.setPosition({700, 400});
    tieText.setCharacterSize(80);

    chipOne.setPosition(30,680);
    chipOne.setScale(0.2,0.2);
    chipFive.setPosition(30,780);
    chipFive.setScale(0.2,0.2);
    chipTen.setPosition(30,880);
    chipTen.setScale(0.2,0.2);
    chipHundred.setPosition(30,980);
    chipHundred.setScale(0.2,0.2);

    player.setPlayerCard(deckOfCards);

    dealer.setDealerCard(deckOfCards);

    setTexture();
}
Game::~Game()
{

}

//run the game
void Game::run()
{
    while(window.isOpen()) {
        processInput();
        update();
        render();
    }
}

//Input
void Game::processInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if(MouseEvents::mouseClicked(startButton, window))
        start = true;

    //press EXIT
    if(MouseEvents::mouseClicked(exitButton, window))
    {
        exitButton.enableState(States::EXIT);
    }

    //check complete the bet
    if(!ante.playerEnterBet() && !finish)
    {
        hitButton.enableState(States::HIDDEN);
        standButton.enableState(States::HIDDEN);
        doubleButton.enableState(States::HIDDEN);
        hitButton.disableState(States::NORMAL);
        standButton.disableState(States::NORMAL);
        doubleButton.disableState(States::NORMAL);
    }
    else if (!finish)
    {
        hitButton.enableState(States::NORMAL);
        standButton.enableState(States::NORMAL);
        doubleButton.enableState(States::NORMAL);
        hitButton.disableState(States::HIDDEN);
        standButton.disableState(States::HIDDEN);
        doubleButton.disableState(States::HIDDEN);
    }

    //press HIT
    if(MouseEvents::mouseClicked(hitButton, window) && event.type == sf::Event::MouseButtonPressed)
    {
        if (!standButton.checkState(States::STAND))
        {
            player.hitPlayerCard(deckOfCards);
        }
    }
    //press STAND
    if(MouseEvents::mouseClicked(standButton, window)
    && event.type == sf::Event::MouseButtonPressed || standButton.checkState(States::STAND)
    || player.getValue() == 21 && ante.playerEnterBet())
    {
        finish = true;
        standButton.enableState(States::STAND);
        standButton.disableState(States::NORMAL);
        standButton.enableState(States::HIDDEN);
        hitButton.disableState(States::NORMAL);
        hitButton.enableState(States::HIDDEN);
        doubleButton.disableState(States::NORMAL);
        doubleButton.enableState(States::HIDDEN);

        nextGameButton.disableState(States::HIDDEN);

        if (dealer.getValue() == player.getValue()) {
            ante.tie();
            tie = true;
        }
        else if (playerWin(dealer, player)) {
            ante.playerWin();
            win = true;
        }
        else if (playerLose(dealer, player)){
            ante.playerLose();
            lose = true;
        }
    }

    //press double
    if(MouseEvents::mouseClicked(doubleButton, window) && event.type == sf::Event::MouseButtonPressed)
    {
        ante.doubleTheBet();
        player.hitPlayerCard(deckOfCards);
        standButton.enableState(States::STAND);
    }

    //press next Game
    if(MouseEvents::mouseClicked(nextGameButton, window) && event.type == sf::Event::MouseButtonPressed)
    {
        this->restart();
    }

    startButton.addEventHandler(window, event);
    hitButton.addEventHandler(window, event);
    standButton.addEventHandler(window, event);
    doubleButton.addEventHandler(window, event);
    exitButton.addEventHandler(window, event);
    nextGameButton.addEventHandler(window, event);
    ante.addEventHandler(window, event);
}

//update input change
void Game::update()
{
    startButton.update();
    hitButton.update();
    standButton.update();
    doubleButton.update();
    exitButton.update();
    nextGameButton.update();
    dealer.update();
    ante.update();
    player.updateValue();
    player.update();

    if (player.getValue() > 21)
        standButton.enableState(States::STAND);

    if (ante.canDoubleTheBet()) {
        doubleButton.enableState(States::NORMAL);
        doubleButton.disableState(States::HIDDEN);
    }
    else
    {
        doubleButton.enableState(States::HIDDEN);
        doubleButton.disableState(States::NORMAL);
    }

    remainingCardsDisplay.setString("Remaining cards: " + std::to_string(deckOfCards.remainingCards()));

    if(ante.playerEnterBet())
        removeCover();
    else
        coverCards();
}

//draw out something
void Game::render()
{
    window.clear(sf::Color{0,100,0});
    window.draw(exitButton);
    if(!start) {
        window.draw(startButton);
        window.draw(blackJack);
        window.draw(myInfo);
    }
    else {
        window.draw(hitButton);
        window.draw(standButton);
        if(ante.canDoubleTheBet())
            window.draw(doubleButton);
        window.draw(nextGameButton);
        window.draw(deck);
        drawPlayerCard();
        if (ante.playerEnterBet())
            window.draw(player);
        window.draw(ante);
        window.draw(chipOne);
        window.draw(chipFive);
        window.draw(chipTen);
        window.draw(chipHundred);
        window.draw(remainingCardsDisplay);
        window.draw(cardCover_one);
        window.draw(cardCover_two);
        window.draw(cardCover_three);
        window.draw(balanceText);
        window.draw(betText);
//        if (hitButton.checkState(States::HIDDEN) && standButton.checkState(States::HIDDEN)
//        && doubleButton.checkState(States::HIDDEN) && nextGameButton.checkState(States::HIDDEN))
        if(!ante.playerEnterBet())
            window.draw(instruction);

        if (win)
            window.draw(winText);
        else if (lose)
            window.draw(loseText);
        else if (tie)
            window.draw(tieText);
    }

    window.display();
}

void Game::setTexture()
{
    ace_of_clubs.setTexture(images::getImage(0));
    ace_of_diamonds.setTexture(images::getImage(1));
    ace_of_hearts.setTexture(images::getImage(2));
    ace_of_spades.setTexture(images::getImage(3));

    two_of_clubs.setTexture(images::getImage(4));
    two_of_diamonds.setTexture(images::getImage(5));
    two_of_hearts.setTexture(images::getImage(6));
    two_of_spades.setTexture(images::getImage(7));

    three_of_clubs.setTexture(images::getImage(8));
    three_of_diamonds.setTexture(images::getImage(9));
    three_of_hearts.setTexture(images::getImage(10));
    three_of_spades.setTexture(images::getImage(11));

    four_of_clubs.setTexture(images::getImage(12));
    four_of_diamonds.setTexture(images::getImage(13));
    four_of_hearts.setTexture(images::getImage(14));
    four_of_spades.setTexture(images::getImage(15));

    five_of_clubs.setTexture(images::getImage(16));
    five_of_diamonds.setTexture(images::getImage(17));
    five_of_hearts.setTexture(images::getImage(18));
    five_of_spades.setTexture(images::getImage(19));

    six_of_clubs.setTexture(images::getImage(20));
    six_of_diamonds.setTexture(images::getImage(21));
    six_of_hearts.setTexture(images::getImage(22));
    six_of_spades.setTexture(images::getImage(23));

    seven_of_clubs.setTexture(images::getImage(24));
    seven_of_diamonds.setTexture(images::getImage(25));
    seven_of_hearts.setTexture(images::getImage(26));
    seven_of_spades.setTexture(images::getImage(27));

    eight_of_clubs.setTexture(images::getImage(28));
    eight_of_diamonds.setTexture(images::getImage(29));
    eight_of_hearts.setTexture(images::getImage(30));
    eight_of_spades.setTexture(images::getImage(31));

    nine_of_clubs.setTexture(images::getImage(32));
    nine_of_diamonds.setTexture(images::getImage(33));
    nine_of_hearts.setTexture(images::getImage(34));
    nine_of_spades.setTexture(images::getImage(35));

    ten_of_clubs.setTexture(images::getImage(36));
    ten_of_diamonds.setTexture(images::getImage(37));
    ten_of_hearts.setTexture(images::getImage(38));
    ten_of_spades.setTexture(images::getImage(39));

    jack_of_clubs.setTexture(images::getImage(40));
    jack_of_diamonds.setTexture(images::getImage(41));
    jack_of_hearts.setTexture(images::getImage(42));
    jack_of_spades.setTexture(images::getImage(43));

    queen_of_clubs.setTexture(images::getImage(44));
    queen_of_diamonds.setTexture(images::getImage(45));
    queen_of_hearts.setTexture(images::getImage(46));
    queen_of_spades.setTexture(images::getImage(47));

    king_of_clubs.setTexture(images::getImage(48));
    king_of_diamonds.setTexture(images::getImage(49));
    king_of_hearts.setTexture(images::getImage(50));
    king_of_spades.setTexture(images::getImage(51));

    deck.setTexture(images::getImage(52));

    chipOne.setTexture(images::getImage(53));
    chipFive.setTexture(images::getImage(54));
    chipTen.setTexture(images::getImage(55));
    chipHundred.setTexture(images::getImage(56));

    cardBack.setTexture(images::getImage(57));
    cardCover_one.setTexture(images::getImage(57));
    cardCover_two.setTexture(images::getImage(57));
    cardCover_three.setTexture(images::getImage(57));

    blackJack.setTexture(images::getImage(58));
}


void Game::drawPlayerCard()
{
    for (int i = 0; i < player.getCardAmount(); i++)
    {
        int temp = 500 + i*200;
        printCard(player.getCardAt(i), {(float) temp, 700});
    }

    printCard(dealer.getCardAt(0),{500,50});
    if (standButton.checkState(States::STAND))
    {
        for (int i = 1; i < dealer.getCardAmount(); i++)
        {
            int temp = 500 + i*200;
            printCard(dealer.getCardAt(i), {(float) temp, 50});
            window.draw(dealer);
        }
    }
    else
    {
        cardBack.setPosition({700,50});
        window.draw(cardBack);
    }
}

void Game::printCard(Cards card, sf::Vector2f position)
{
    if (card.getSuitAssets() == SPADES)
    {
        if (card.getRankAssets() == ACE) {
            ace_of_spades.setPosition(position);
            window.draw(ace_of_spades);
        }
        if (card.getRankAssets() == TWO) {
            two_of_spades.setPosition(position);
            window.draw(two_of_spades);
        }
        if (card.getRankAssets() == THREE) {
            three_of_spades.setPosition(position);
            window.draw(three_of_spades);
        }
        if (card.getRankAssets() == FOUR) {
            four_of_spades.setPosition(position);
            window.draw(four_of_spades);
        }
        if (card.getRankAssets() == FIVE) {
            five_of_spades.setPosition(position);
            window.draw(five_of_spades);
        }
        if (card.getRankAssets() == SIX) {
            six_of_spades.setPosition(position);
            window.draw(six_of_spades);
        }
        if (card.getRankAssets() == SEVEN) {
            seven_of_spades.setPosition(position);
            window.draw(seven_of_spades);
        }
        if (card.getRankAssets() == EIGHT) {
            eight_of_spades.setPosition(position);
            window.draw(eight_of_spades);
        }
        if (card.getRankAssets() == NINE) {
            nine_of_spades.setPosition(position);
            window.draw(nine_of_spades);
        }
        if (card.getRankAssets() == TEN) {
            ten_of_spades.setPosition(position);
            window.draw(ten_of_spades);
        }
        if (card.getRankAssets() == JACK) {
            jack_of_spades.setPosition(position);
            window.draw(jack_of_spades);
        }
        if (card.getRankAssets() == QUEEN) {
            queen_of_spades.setPosition(position);
            window.draw(queen_of_spades);
        }
        if (card.getRankAssets() == KING) {
            king_of_spades.setPosition(position);
            window.draw(king_of_spades);
        }
    }

    if (card.getSuitAssets() == HEARTS)
    {
        if (card.getRankAssets() == ACE) {
            ace_of_hearts.setPosition(position);
            window.draw(ace_of_hearts);
        }
        if (card.getRankAssets() == TWO) {
            two_of_hearts.setPosition(position);
            window.draw(two_of_hearts);
        }
        if (card.getRankAssets() == THREE) {
            three_of_hearts.setPosition(position);
            window.draw(three_of_hearts);
        }
        if (card.getRankAssets() == FOUR) {
            four_of_hearts.setPosition(position);
            window.draw(four_of_hearts);
        }
        if (card.getRankAssets() == FIVE) {
            five_of_hearts.setPosition(position);
            window.draw(five_of_hearts);
        }
        if (card.getRankAssets() == SIX) {
            six_of_hearts.setPosition(position);
            window.draw(six_of_hearts);
        }
        if (card.getRankAssets() == SEVEN) {
            seven_of_hearts.setPosition(position);
            window.draw(seven_of_hearts);
        }
        if (card.getRankAssets() == EIGHT) {
            eight_of_hearts.setPosition(position);
            window.draw(eight_of_hearts);
        }
        if (card.getRankAssets() == NINE) {
            nine_of_hearts.setPosition(position);
            window.draw(nine_of_hearts);
        }
        if (card.getRankAssets() == TEN) {
            ten_of_hearts.setPosition(position);
            window.draw(ten_of_hearts);
        }
        if (card.getRankAssets() == JACK) {
            jack_of_hearts.setPosition(position);
            window.draw(jack_of_hearts);
        }
        if (card.getRankAssets() == QUEEN) {
            queen_of_hearts.setPosition(position);
            window.draw(queen_of_hearts);
        }
        if (card.getRankAssets() == KING) {
            king_of_hearts.setPosition(position);
            window.draw(king_of_hearts);
        }
    }

    if (card.getSuitAssets() == CLUBS)
    {
        if (card.getRankAssets() == ACE) {
            ace_of_clubs.setPosition(position);
            window.draw(ace_of_clubs);
        }
        if (card.getRankAssets() == TWO) {
            two_of_clubs.setPosition(position);
            window.draw(two_of_clubs);
        }
        if (card.getRankAssets() == THREE) {
            three_of_clubs.setPosition(position);
            window.draw(three_of_clubs);
        }
        if (card.getRankAssets() == FOUR) {
            four_of_clubs.setPosition(position);
            window.draw(four_of_clubs);
        }
        if (card.getRankAssets() == FIVE) {
            five_of_clubs.setPosition(position);
            window.draw(five_of_clubs);
        }
        if (card.getRankAssets() == SIX) {
            six_of_clubs.setPosition(position);
            window.draw(six_of_clubs);
        }
        if (card.getRankAssets() == SEVEN) {
            seven_of_clubs.setPosition(position);
            window.draw(seven_of_clubs);
        }
        if (card.getRankAssets() == EIGHT) {
            eight_of_clubs.setPosition(position);
            window.draw(eight_of_clubs);
        }
        if (card.getRankAssets() == NINE) {
            nine_of_clubs.setPosition(position);
            window.draw(nine_of_clubs);
        }
        if (card.getRankAssets() == TEN) {
            ten_of_clubs.setPosition(position);
            window.draw(ten_of_clubs);
        }
        if (card.getRankAssets() == JACK) {
            jack_of_clubs.setPosition(position);
            window.draw(jack_of_clubs);
        }
        if (card.getRankAssets() == QUEEN) {
            queen_of_clubs.setPosition(position);
            window.draw(queen_of_clubs);
        }
        if (card.getRankAssets() == KING) {
            king_of_clubs.setPosition(position);
            window.draw(king_of_clubs);
        }
    }

    if (card.getSuitAssets() == DIAMONDS)
    {
        if (card.getRankAssets() == ACE) {
            ace_of_diamonds.setPosition(position);
            window.draw(ace_of_diamonds);
        }
        if (card.getRankAssets() == TWO) {
            two_of_diamonds.setPosition(position);
            window.draw(two_of_diamonds);
        }
        if (card.getRankAssets() == THREE) {
            three_of_diamonds.setPosition(position);
            window.draw(three_of_diamonds);
        }
        if (card.getRankAssets() == FOUR) {
            four_of_diamonds.setPosition(position);
            window.draw(four_of_diamonds);
        }
        if (card.getRankAssets() == FIVE) {
            five_of_diamonds.setPosition(position);
            window.draw(five_of_diamonds);
        }
        if (card.getRankAssets() == SIX) {
            six_of_diamonds.setPosition(position);
            window.draw(six_of_diamonds);
        }
        if (card.getRankAssets() == SEVEN) {
            seven_of_diamonds.setPosition(position);
            window.draw(seven_of_diamonds);
        }
        if (card.getRankAssets() == EIGHT) {
            eight_of_diamonds.setPosition(position);
            window.draw(eight_of_diamonds);
        }
        if (card.getRankAssets() == NINE) {
            nine_of_diamonds.setPosition(position);
            window.draw(nine_of_diamonds);
        }
        if (card.getRankAssets() == TEN) {
            ten_of_diamonds.setPosition(position);
            window.draw(ten_of_diamonds);
        }
        if (card.getRankAssets() == JACK) {
            jack_of_diamonds.setPosition(position);
            window.draw(jack_of_diamonds);
        }
        if (card.getRankAssets() == QUEEN) {
            queen_of_diamonds.setPosition(position);
            window.draw(queen_of_diamonds);
        }
        if (card.getRankAssets() == KING) {
            king_of_diamonds.setPosition(position);
            window.draw(king_of_diamonds);
        }
    }
}

bool Game::playerWin(Dealer& dealer, Scorer& scorer)
{
    if(scorer.getValue() > 21)
        return false;
    else if(scorer.getValue() <= 21 && dealer.getValue() > 21)
        return true;
    else
        return (scorer.getValue() > dealer.getValue());
}

bool Game::playerLose(Dealer& dealer, Scorer& scorer)
{
    if(scorer.getValue() > 21)
        return true;
    else if (scorer.getValue() < dealer.getValue())
        return true;
}

void Game::restart()
{
    dealer.initializeScore();
    player.initializeScore();
    dealer.initializeHandCards();
    player.initializeHandCards();
    nextGameButton.enableState(States::HIDDEN);

    player.setPlayerCard(deckOfCards);
    dealer.setDealerCard(deckOfCards);

    finish = false;
    win = false;
    lose = false;
    tie = false;

    this->initializeButton();
    this->run();
}

void Game::initializeButton()
{
    hitButton.disableState(States::HIT1);
    hitButton.disableState(States::HIT2);
    hitButton.disableState(States::HIT3);
    standButton.disableState(States::STAND);
    hitButton.enableState(States::NORMAL);
    standButton.enableState(States::NORMAL);
    doubleButton.enableState(States::NORMAL);
    ante.initializeAnteButton();
}

void Game::removeCover()
{
    cardCover_one.setPosition({10000,10000});
    cardCover_two.setPosition({10000,10000});
    cardCover_three.setPosition({10000,10000});
}

void Game::coverCards()
{
    cardCover_one.setPosition({500,700});
    cardCover_two.setPosition({700,700});
    cardCover_three.setPosition({500,50});
}
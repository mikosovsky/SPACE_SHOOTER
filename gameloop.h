#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "text.h"
#include "spacestation.h"
#include "spaceship.h"
#include "meteor.h"
#include "boost.h"

class GameLoop
{
public:
    GameLoop();
private:
    void gameGUI(const sf::Time &time,text &title,text &PlayGame,text &settings,text &shop,spaceStation &spaceStation1);
    void Game(const sf::Time &time,text &hpStatus,text &hp,text &pointsStatus,text &points,text &gameOver,text &back,text &restart);
    void GameChoose(text &chooseShip,text &back,spaceship &basicMenu,spaceship &smallMenu,spaceship &XwingMenu,spaceStation &spaceStation1,const sf::Time &time);
    void Shop();
    double widthWindow=600.0,heightWindow=900.0;
    sf::VideoMode videoMode;
    sf::RenderWindow window;
    bool bGameGui=true,bGame=false,bSettings=false,bShop=false,bGameChoose=false,bGameOver=false;
    spaceship ship;
    Ammunition ammunition1,ammunition2;
    std::vector<Ammunition> ammunitions;
    std::vector<meteor> meteors;
    sf::Clock click,shoot,comets,boostClock,cEffect;
    meteor met;
    int shipPoints=0;
    double shootDelay,standardShootDelay;
    double bulletX1,bulletX2;
    boost boosted;
};

#endif // GAMELOOP_H

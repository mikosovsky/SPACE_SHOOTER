#ifndef SPACESTATION_H
#define SPACESTATION_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <random>

class spaceStation :public sf::Sprite
{
public:
    spaceStation(int seed,double windowWidth,double windowHeight);
    void movin(const sf::Time &time);
private:
    double windowWidth,windowHeight,velocity;
    int startingX;
    sf::Texture tex;
};

#endif // SPACESTATION_H

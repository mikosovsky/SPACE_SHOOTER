#ifndef BOOST_H
#define BOOST_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class boost: public sf::Sprite
{
public:
    boost(int rand);
    void respawn(int rand);
    void movin(sf::Clock &clock,const sf::Time &time);
    int collected(const sf::FloatRect &ship,sf::Clock &clock);
private:
    sf::Texture texture;
    double windowWidth=600.0,windowHeight=900.0,velocity=300.0,angel=60.0;
    int numTexture;
};

#endif // BOOST_H

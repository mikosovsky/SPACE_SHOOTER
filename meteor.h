#ifndef METEOR_H
#define METEOR_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>

class meteor :public sf::Sprite
{
public:
    meteor(int numTexture);
    void movin(int rand,const sf::Time &time);
    bool bulletCol(int rand,const sf::FloatRect &bullet);
    void shipCol(int rand,const sf::FloatRect &ship);
    void restartGame(int rand);
    void meteorCol(int rand,sf::FloatRect otherMeteor);
private:
    sf::Texture texture;
    double windowWidth=600.0,windowHeight=900.0;
    double velocity=200.0,acceleration=5000.0;
};

#endif // METEOR_H

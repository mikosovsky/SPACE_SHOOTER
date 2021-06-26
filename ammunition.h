#ifndef AMMUNITION_H
#define AMMUNITION_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Ammunition: public sf::Sprite
{
public:
    Ammunition(int numTexture);
    void setup(int numTexture);
    void meteorCol(const sf::FloatRect &meteor);
    Ammunition();
private:
    sf::Texture texture;
};

#endif // AMMUNITION_H

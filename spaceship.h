#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "ammunition.h"
#include <vector>
#include <memory>

class spaceship :public sf::Sprite
{
public:
    spaceship(bool playable,int numTexture);
    spaceship();
    void setings(bool playable,int numTexture);
    bool clicked(const sf::Window &window);
    void mouseChoose(const sf::Window &window);
    sf::RectangleShape rectangle;
    void control(const sf::Time &time);
    void hpControl(const sf::FloatRect &meteor);
    int hpStatus();
    void setMaxHP();
    void effects(int effect,int &points,double &shootDelay,sf::Clock &cEffect);
private:
    bool playable;
    sf::Texture texture;
    double windowWidth=600.0,windowHeight=900.0,velocity=400.0,ammoVelocity=200.0;
    int numTexture;
    int life,maxLife;
};

#endif // SPACESHIP_H

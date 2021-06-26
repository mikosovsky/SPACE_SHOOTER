#ifndef TEXT_H
#define TEXT_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class text: public sf::Text
{
public:
    text(std::string str,double windowWidth, double windowHeight,double width,double height,double size);
    void GUImouse(const sf::Window &window);
    bool clicked(const sf::Window &window);
private:
    std::string str;
    sf::Font font;
    double windowWidth,windowHeight,width,height,size;
};

#endif // TEXT_H

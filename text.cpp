#include "text.h"

text::text(std::string str,double windowWidth, double windowHeight,double width,double height,double size)
{
    this->str = str;
    this->windowHeight=windowHeight;
    this->windowWidth=windowWidth;
    this->width=width;
    this->height=height;
    this->size=size;
    if(!font.loadFromFile("font/fonts.ttf"))
    {
        std::cout<<"ERROR font"<<std::endl;
    }
    setFont(font);
    setString(str);
    setCharacterSize(size);
    sf::FloatRect rect=getGlobalBounds();
    setPosition(width-rect.width/2,height-rect.height/2);
}


void text::GUImouse(const sf::Window &window)
{
    sf::FloatRect rect=getGlobalBounds();
    sf::FloatRect mouse;
    mouse.left=sf::Mouse::getPosition(window).x;
    mouse.top=sf::Mouse::getPosition(window).y;
//    std::cout<<mouse.left<<" "<<mouse.top<<std::endl;

//    std::cout<<rect.left<<" "<<rect.top<<std::endl;
    mouse.height=1;
    mouse.width=1;
    if(rect.intersects(mouse))
    {
        setFillColor(sf::Color::Red);
    }else
    {
        setFillColor(sf::Color::White);
    }
}

bool text::clicked(const sf::Window &window)
{
    sf::FloatRect rect=getGlobalBounds();
    sf::FloatRect mouse;
    mouse.left=sf::Mouse::getPosition(window).x;
    mouse.top=sf::Mouse::getPosition(window).y;
    mouse.height=1;
    mouse.width=1;
    if(rect.intersects(mouse)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return true;
    }else
    {
        return false;
    }
}

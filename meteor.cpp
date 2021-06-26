#include "meteor.h"

meteor::meteor(int numTexture)
{
    switch (numTexture%4+1) {

    case 1:
    {
        if(!texture.loadFromFile("imagines/meteors/meteor1.png"))
        {
            std::cout<<"ERROR imagines/meteors/meteor1.png"<<std::endl;
        }
        break;
    }
    case 2:
    {
        if(!texture.loadFromFile("imagines/meteors/meteor2.png"))
        {
            std::cout<<"ERROR imagines/meteors/meteor2.png"<<std::endl;
        }
        break;
    }
    case 3:
    {
        if(!texture.loadFromFile("imagines/meteors/meteor3.png"))
        {
            std::cout<<"ERROR imagines/meteors/meteor3.png"<<std::endl;
        }
        break;
    }
    case 4:
    {
        if(!texture.loadFromFile("imagines/meteors/meteor4.png"))
        {
            std::cout<<"ERROR imagines/meteors/meteor4.png"<<std::endl;
        }
        break;
    }
    }
    setTexture(texture);
    setScale(0.5,0.5);
    setPosition(sf::Vector2f(static_cast<float>(numTexture%(static_cast<int>(windowWidth-getGlobalBounds().width))),-getGlobalBounds().height));
}

void meteor::movin(int rand,const sf::Time &time)
{
    sf::FloatRect rect=getGlobalBounds();
    if(rect.top>=windowHeight)
    {
        setPosition(sf::Vector2f(static_cast<float>(rand%(static_cast<int>(windowWidth-getGlobalBounds().width))),-getGlobalBounds().height));
    }
    velocity+=0.5*acceleration*pow(time.asSeconds(),2);
    move(0,velocity*time.asSeconds());
}

bool meteor::bulletCol(int rand, const sf::FloatRect &bullet)
{
    sf::FloatRect rect=getGlobalBounds();
    if(rect.intersects(bullet)&&rect.top>=0)
    {
        setPosition(sf::Vector2f(static_cast<float>(rand%(static_cast<int>(windowWidth-getGlobalBounds().width))),-getGlobalBounds().height));
        return true;
    }else
    {
        return false;
    }
}


void meteor::shipCol(int rand, const sf::FloatRect &ship)
{
    sf::FloatRect rect=getGlobalBounds();
    if(ship.intersects(rect))
    {
        setPosition(sf::Vector2f(static_cast<float>(rand%(static_cast<int>(windowWidth-getGlobalBounds().width))),-getGlobalBounds().height));
    }
}

void meteor::restartGame(int rand)
{
    setPosition(sf::Vector2f(static_cast<float>(rand%(static_cast<int>(windowWidth-getGlobalBounds().width))),-getGlobalBounds().height));
    velocity=200.0;
}

void meteor::meteorCol(int rand, sf::FloatRect otherMeteor)
{
    sf::FloatRect rect=getGlobalBounds();
    if(rect.intersects(otherMeteor))
    {
        setPosition(sf::Vector2f(static_cast<float>(rand%(static_cast<int>(windowWidth-getGlobalBounds().width))),-getGlobalBounds().height));
    }
}

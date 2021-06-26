#include "boost.h"

boost::boost(int rand)
{
    numTexture=rand%3+1;
    switch (numTexture) {
    case 1:
    {
        if(!texture.loadFromFile("imagines/boosts/health.png"))
        {
            std::cout<<"ERROR imagines/boosts/health.png"<<std::endl;
        }
        break;
    }
    case 2:
    {
        if(!texture.loadFromFile("imagines/boosts/coin.png"))
        {
            std::cout<<"ERROR imagines/boosts/coin.png"<<std::endl;
        }
        break;
    }
    case 3:
    {
        if(!texture.loadFromFile("imagines/boosts/key.png"))
        {
            std::cout<<"ERROR imagines/boosts/key.png"<<std::endl;
        }
        break;
    }
    }
    setTexture(texture,true);
    setScale(0.5,0.5);
    setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
    setPosition(sf::Vector2f(static_cast<float>(rand%(static_cast<int>(windowWidth-getGlobalBounds().width))),-getGlobalBounds().height));
}

void boost::respawn(int rand)
{
    numTexture=rand%3+1;
    switch (numTexture) {
    case 1:
    {
        if(!texture.loadFromFile("imagines/boosts/health.png"))
        {
            std::cout<<"ERROR imagines/boosts/health.png"<<std::endl;
        }
        break;
    }
    case 2:
    {
        if(!texture.loadFromFile("imagines/boosts/coin.png"))
        {
            std::cout<<"ERROR imagines/boosts/coin.png"<<std::endl;
        }
        break;
    }
    case 3:
    {
        if(!texture.loadFromFile("imagines/boosts/key.png"))
        {
            std::cout<<"ERROR imagines/boosts/key.png"<<std::endl;
        }
        break;
    }
    }
    setTexture(texture,true);
    setScale(0.5,0.5);
    setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
    setPosition(sf::Vector2f(static_cast<float>(rand%(static_cast<int>(windowWidth-getGlobalBounds().width))),-getGlobalBounds().height));
}

int boost::collected(const sf::FloatRect &ship,sf::Clock &clock)
{
    sf::FloatRect rect=getGlobalBounds();
    if(rect.intersects(ship))
    {
        int effect=numTexture;
        respawn(rand());
        clock.restart();
        return effect;
    }else if(rect.top>=windowHeight)
    {
       respawn(rand());
       clock.restart();
    }
    return 0;
}

void boost::movin(sf::Clock &clock,const sf::Time &time)
{
    if(clock.getElapsedTime().asSeconds()>=5)
    {
        move(0,velocity*time.asSeconds());
        rotate(angel*time.asSeconds());
    }
}

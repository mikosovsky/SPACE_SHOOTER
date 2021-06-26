#include "ammunition.h"

Ammunition::Ammunition(int numTexture)
{
    switch (numTexture) {

    case 2:
    {
        if(!texture.loadFromFile("imagines/ammo/smallammo.png"))
        {
            std::cout<<"ERROR imagines/ammo/smallammo.png"<<std::endl;
        }
        break;
    }

    case 1:
    {
        if(!texture.loadFromFile("imagines/ammo/midammo.png"))
        {
            std::cout<<"ERROR imagines/ammo/midammo.png"<<std::endl;
        }
        break;
    }

    case 3:
    {
        if(!texture.loadFromFile("imagines/ammo/bigammo.png"))
        {
            std::cout<<"ERROR imagines/ammo/bigammo.png"<<std::endl;
        }
        break;
    }
    }
    setTexture(texture,true);
}

void Ammunition::setup(int numTexture)
{
    switch (numTexture) {

    case 2:
    {
        if(!texture.loadFromFile("imagines/ammo/smallammo.png"))
        {
            std::cout<<"ERROR imagines/ammo/smallammo.png"<<std::endl;
        }
        break;
    }

    case 1:
    {
        if(!texture.loadFromFile("imagines/ammo/midammo.png"))
        {
            std::cout<<"ERROR imagines/ammo/midammo.png"<<std::endl;
        }
        break;
    }

    case 3:
    {
        if(!texture.loadFromFile("imagines/ammo/bigammo.png"))
        {
            std::cout<<"ERROR imagines/ammo/bigammo.png"<<std::endl;
        }
        break;
    }
    }
    setTexture(texture,true);
    setScale(0.5,0.5);
}

Ammunition::Ammunition()
{

}


void Ammunition::meteorCol(const sf::FloatRect &meteor)
{
    sf::FloatRect bullet=getGlobalBounds();
    if(bullet.intersects(meteor))
    {
        setScale(0,0);
    }
}

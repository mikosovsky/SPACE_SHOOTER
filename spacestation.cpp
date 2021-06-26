#include "spacestation.h"

spaceStation::spaceStation(int seed,double windowWidth,double windowHeight)
{
    this->windowHeight=windowHeight;
    this->windowWidth=windowWidth;
    int ans=seed%6+1;
    switch (ans) {
    case 1:
    {

        if(!tex.loadFromFile("imagines/stations/spaceStation1.png"))
        {
            std::cout<<"ERROR imagines/stations/spaceStation1.png"<<std::endl;
        }
        setTexture(tex);
        sf::FloatRect rect=getGlobalBounds();
        startingX=seed%static_cast<int>(windowWidth-rect.width);
        setPosition(startingX,windowHeight);
        setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
        velocity=seed%200+100;
        break;
    }
    case 2:
    {

        if(!tex.loadFromFile("imagines/stations/spaceStation2.png"))
        {
            std::cout<<"ERROR imagines/stations/spaceStation2.png"<<std::endl;
        }
        setTexture(tex);
        sf::FloatRect rect=getGlobalBounds();
        startingX=seed%static_cast<int>(windowWidth-rect.width);
        setPosition(startingX,windowHeight);
        setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
        velocity=seed%200+100;
        break;
    }
    case 3:
    {

        if(!tex.loadFromFile("imagines/stations/spaceStation3.png"))
        {
            std::cout<<"ERROR imagines/stations/spaceStation3.png"<<std::endl;
        }
        setTexture(tex);
        sf::FloatRect rect=getGlobalBounds();
        startingX=seed%static_cast<int>(windowWidth-rect.width);
        setPosition(startingX,windowHeight);
        setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
        velocity=seed%200+100;
        break;
    }
    case 4:
    {

        if(!tex.loadFromFile("imagines/stations/spaceStation4.png"))
        {
            std::cout<<"ERROR imagines/stations/spaceStation4.png"<<std::endl;
        }
        setTexture(tex);
        sf::FloatRect rect=getGlobalBounds();
        startingX=seed%static_cast<int>(windowWidth-rect.width);
        setPosition(startingX,windowHeight);
        setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
        velocity=seed%200+100;
        break;
    }
    case 5:
    {

        if(!tex.loadFromFile("imagines/stations/spaceStation5.png"))
        {
            std::cout<<"ERROR imagines/stations/spaceStation5.png"<<std::endl;
        }
        setTexture(tex);
        sf::FloatRect rect=getGlobalBounds();
        startingX=seed%static_cast<int>(windowWidth-rect.width);
        setPosition(startingX,windowHeight);
        setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
        velocity=seed%200+100;
        break;
    }
    case 6:
    {

        if(!tex.loadFromFile("imagines/stations/spaceStation6.png"))
        {
            std::cout<<"ERROR imagines/stations/spaceStation6.png"<<std::endl;
        }
        setTexture(tex);
        sf::FloatRect rect=getGlobalBounds();
        startingX=seed%static_cast<int>(windowWidth-rect.width);
        setPosition(startingX,windowHeight);
        setOrigin(getGlobalBounds().width/2,getGlobalBounds().height/2);
        velocity=seed%200+100;
        break;
    }
    }
}

void spaceStation::movin(const sf::Time &time)
{
    sf::FloatRect rect=getGlobalBounds();
    if(rect.top+rect.height<=0)
    {
        setPosition(startingX,windowHeight+200);
    }

    rotate(30*time.asSeconds());
    move(0,-velocity*time.asSeconds());
}

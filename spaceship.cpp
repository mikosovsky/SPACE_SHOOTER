#include "spaceship.h"

spaceship::spaceship(bool playable,int numTexture)
{
    this->numTexture=numTexture;
    this->playable=playable;
    switch(numTexture)
    {
    case 1:
    {
        if(!texture.loadFromFile("imagines/ships/basic.png"))
        {
            std::cout<<"ERROR imagines/ships/basic.png"<<std::endl;
        }
        setTexture(texture,true);
        setScale(0.5,0.5);
        sf::FloatRect rect=getGlobalBounds();
        life=3;
        maxLife=3;
        if(playable)
        {
            setPosition(windowWidth/2.0-rect.width/2.0,windowHeight-rect.height-20);
        }else
        {
            rectangle.setSize(sf::Vector2f(rect.width,rect.height));
            rectangle.setFillColor(sf::Color::Black);
            setPosition(windowWidth/2.0-rect.width/2.0,1.0*windowHeight/3.0-rect.width/2.0-100);
            rectangle.setPosition(windowWidth/2.0-rect.width/2.0,1.0*windowHeight/3.0-rect.width/2.0-100);
        }
        break;
    }
    case 2:
    {
        if(!texture.loadFromFile("imagines/ships/small.png"))
        {
            std::cout<<"ERROR imagines/ships/small.png"<<std::endl;
        }
        setTexture(texture,true);
        setScale(0.5,0.5);
        sf::FloatRect rect=getGlobalBounds();
        life=2;
        maxLife=2;
        if(playable)
        {
            setPosition(windowWidth/2.0-rect.width/2.0,windowHeight-rect.height-20);
        }else
        {
            rectangle.setSize(sf::Vector2f(rect.width,rect.height));
            rectangle.setFillColor(sf::Color::Black);
            setPosition(windowWidth/2.0-rect.width/2.0,2*windowHeight/3.0-rect.width/2.0-150);
            rectangle.setPosition(windowWidth/2.0-rect.width/2.0,2*windowHeight/3.0-rect.width/2.0-150);
        }
        break;
    }
    case 3:
    {
        if(!texture.loadFromFile("imagines/ships/Xwing.png"))
        {
            std::cout<<"ERROR imagines/ships/Xwing.png"<<std::endl;
        }
        setTexture(texture,true);
        setScale(0.5,0.5);
        sf::FloatRect rect=getGlobalBounds();
        life=4;
        maxLife=4;
        if(playable)
        {
            setPosition(windowWidth/2.0-rect.width/2.0,windowHeight-rect.height-20);
        }else
        {
            rectangle.setSize(sf::Vector2f(rect.width,rect.height));
            rectangle.setFillColor(sf::Color::Black);
            setPosition(windowWidth/2.0-rect.width/2.0,3*windowHeight/3.0-rect.width/2.0-200);
            rectangle.setPosition(windowWidth/2.0-rect.width/2.0,3*windowHeight/3.0-rect.width/2.0-200);
        }
        break;
    }
    }
}
bool spaceship::clicked(const sf::Window &window)
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


void spaceship::mouseChoose(const sf::Window &window)
{
    sf::FloatRect rect=getGlobalBounds();
    sf::FloatRect mouse;
    mouse.left=sf::Mouse::getPosition(window).x;
    mouse.top=sf::Mouse::getPosition(window).y;

    mouse.height=1;
    mouse.width=1;
    if(rect.intersects(mouse))
    {
        rectangle.setFillColor(sf::Color::Green);
    }else
    {
        rectangle.setFillColor(sf::Color::Black);
    }
}

void spaceship::setings(bool playable, int numTexture)
{
    this->numTexture=numTexture;
    this->playable=playable;
    switch(numTexture)
    {
    case 1:
    {
        if(!texture.loadFromFile("imagines/ships/basic.png"))
        {
            std::cout<<"ERROR imagines/ships/basic.png"<<std::endl;
        }
        setTexture(texture,true);
        setScale(0.5,0.5);
        sf::FloatRect rect=getGlobalBounds();
        life=3;
        maxLife=3;
        if(playable)
        {
            setPosition(windowWidth/2.0-rect.width/2.0,windowHeight-rect.height-20);
        }else
        {
            rectangle.setSize(sf::Vector2f(rect.width,rect.height));
            rectangle.setFillColor(sf::Color::Black);
            setPosition(windowWidth/2.0-rect.width/2.0,1.0*windowHeight/3.0-rect.width/2.0-100);
            rectangle.setPosition(windowWidth/2.0-rect.width/2.0,1.0*windowHeight/3.0-rect.width/2.0-100);
        }
        break;
    }
    case 2:
    {
        if(!texture.loadFromFile("imagines/ships/small.png"))
        {
            std::cout<<"ERROR imagines/ships/small.png"<<std::endl;
        }
        setTexture(texture,true);
        setScale(0.5,0.5);
        sf::FloatRect rect=getGlobalBounds();
        life=2;
        maxLife=2;
        if(playable)
        {
            setPosition(windowWidth/2.0-rect.width/2.0,windowHeight-rect.height-20);
        }else
        {
            rectangle.setSize(sf::Vector2f(rect.width,rect.height));
            rectangle.setFillColor(sf::Color::Black);
            setPosition(windowWidth/2.0-rect.width/2.0,2*windowHeight/3.0-rect.width/2.0-150);
            rectangle.setPosition(windowWidth/2.0-rect.width/2.0,2*windowHeight/3.0-rect.width/2.0-150);
        }
        break;
    }
    case 3:
    {
        if(!texture.loadFromFile("imagines/ships/Xwing.png"))
        {
            std::cout<<"ERROR imagines/ships/Xwing.png"<<std::endl;
        }
        setTexture(texture,true);
        setScale(0.5,0.5);
        sf::FloatRect rect=getGlobalBounds();
        life=4;
        maxLife=4;
        if(playable)
        {
            setPosition(windowWidth/2.0-rect.width/2.0,windowHeight-rect.height-20);
        }else
        {
            rectangle.setSize(sf::Vector2f(rect.width,rect.height));
            rectangle.setFillColor(sf::Color::Black);
            setPosition(windowWidth/2.0-rect.width/2.0,3*windowHeight/3.0-rect.width/2.0-200);
            rectangle.setPosition(windowWidth/2.0-rect.width/2.0,3*windowHeight/3.0-rect.width/2.0-200);
        }
        break;
    }
    }
}

void spaceship::control(const sf::Time &time)
{
    sf::FloatRect rect=getGlobalBounds();
    if(playable)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&rect.left>=0)
        {
            move(-velocity*time.asSeconds(),0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&rect.left+rect.width<=windowWidth)
        {
            move(velocity*time.asSeconds(),0);
        }

    }
}


spaceship::spaceship()
{

}

void spaceship::hpControl(const sf::FloatRect &meteor)
{
    sf::FloatRect rect=getGlobalBounds();
    if(rect.intersects(meteor))
    {
        life--;
    }
}

int spaceship::hpStatus()
{
    return life;
}

void spaceship::setMaxHP()
{
    life=maxLife;
}

void spaceship::effects(int effect,int &points,double &shootDelay,sf::Clock &cEffect)
{
    if(effect!=0)
    {
    switch (effect) {

    case 1:
    {
        if(life<maxLife)
        {
            std::cout<<"LIFE BOOST"<<std::endl;
            life++;
        }
        break;
    }
    case 2:
    {
        points+=200;
        std::cout<<"POINTS BOOST"<<std::endl;
        break;
    }
    case 3:
    {
        shootDelay/=2;
        std::cout<<"SPEED BOOST"<<std::endl;
        cEffect.restart();
    }
    }}
}

#include "gameloop.h"

GameLoop::GameLoop():met(rand()),boosted(rand())
{
    //GENEROWANIE OKNA
    videoMode.height=heightWindow;
    videoMode.width=widthWindow;
    window.create(videoMode,"SPACE SHOOTER");

    //GENEROWANIE TEKSTÓW I GRAFIKI POD MENU
    text title("SPACE SHOOTER", widthWindow,heightWindow,widthWindow/2,200,35);
    text PlayGame("Play Game",widthWindow,heightWindow,widthWindow/2,400,25);
    text shop("Shop",widthWindow,heightWindow,widthWindow/2,500,25);
    text settings("Settings",widthWindow,heightWindow,widthWindow/2,600,25);
    spaceStation spaceStation1(rand(),widthWindow,heightWindow);

    //GENEROWANIE TEKSTÓW I GRAFIK POD GAME CHOOSE
    text chooseShip("CHOOSE SHIP",widthWindow,heightWindow,widthWindow/2,50,40);
    spaceship smallMenu(false,2);
    spaceship basicMenu(false,1);
    spaceship XwingMenu(false,3);

    //GENEROWANIE TEKSTÓW I GRAFIK POD GAME
    for(int i=0;i<5;i++)
    {
        meteors.emplace_back(met);
        meteors[i].restartGame(rand());
    }
    text hp("HP:",widthWindow,heightWindow,widthWindow-60,20,20);
    text hpStatus("s",widthWindow,heightWindow,hp.getGlobalBounds().left+hp.getGlobalBounds().width+10,20,20);
    text pointsStatus("Score:",widthWindow,heightWindow,widthWindow-60,hp.getGlobalBounds().top+hp.getGlobalBounds().height+20,20);
    text points("",widthWindow,heightWindow,pointsStatus.getGlobalBounds().left,pointsStatus.getGlobalBounds().height+pointsStatus.getGlobalBounds().top,20);
    text gameOver("GAME OVER",widthWindow,heightWindow,widthWindow/2,heightWindow/2,35);
    text restart("RESTART",widthWindow,heightWindow,widthWindow/2,gameOver.getGlobalBounds().top+gameOver.getGlobalBounds().height+20,20);
    gameOver.setFillColor(sf::Color::Red);


    //GUZIK BACK
    text back("<- BACK",widthWindow, heightWindow,100,heightWindow-50,25);

    //ZEGARY
    sf::Clock clock;
    click.restart();
    while(window.isOpen())
    {
        //Ustawianie koloru okna
        window.clear(sf::Color::Black);
        //Restart czasu i przypisanie obecnego do zmiennej time
        sf::Time time=clock.restart();
        //Stworzenie eventu
        sf::Event event;
        //Obsługa eventów
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        gameGUI(time,title,PlayGame,settings,shop,spaceStation1);
        if(bGame)
        {
            if(bGameChoose)
            {
               GameChoose(chooseShip,back,basicMenu,smallMenu,XwingMenu,spaceStation1,time);
            }else
            {
                Game(time,hpStatus,hp,pointsStatus,points,gameOver,back,restart);
            }
        }

        window.display();
    }

}


void GameLoop::gameGUI(const sf::Time &time,text &title,text &PlayGame,text &settings,text &shop,spaceStation &spaceStation1)
{
    if(bGameGui)
    {
    PlayGame.GUImouse(window);
    shop.GUImouse(window);
    settings.GUImouse(window);
    spaceStation1.movin(time);


    window.draw(spaceStation1);
    window.draw(settings);
    window.draw(shop);
    window.draw(PlayGame);
    window.draw(title);
    if(click.getElapsedTime().asSeconds()>=0.3)
    {
    if(PlayGame.clicked(window))
    {
        bGameGui=false;
        bGame=true;
        bSettings=false;
        bShop=false;
        bGameChoose=true;
        bGameOver=false;
        click.restart();
    }
    if(settings.clicked(window))
    {
        bGameGui=false;
        bGame=false;
        bSettings=true;
        bShop=false;
        bGameChoose=false;
        bGameOver=false;
        click.restart();
    }
    if(shop.clicked(window))
    {
        bGameGui=false;
        bGame=false;
        bSettings=false;
        bShop=true;
        bGameChoose=false;
        bGameOver=false;
        click.restart();
    }
    }}
}


void GameLoop::GameChoose(text &chooseShip, text &back, spaceship &basicMenu, spaceship &smallMenu, spaceship &XwingMenu,spaceStation &spaceStation1,const sf::Time &time)
{
    window.draw(spaceStation1);
    window.draw(chooseShip);
    window.draw(basicMenu.rectangle);
    window.draw(basicMenu);
    window.draw(XwingMenu.rectangle);
    window.draw(XwingMenu);
    window.draw(smallMenu.rectangle);
    window.draw(smallMenu);
    window.draw(back);

    basicMenu.mouseChoose(window);
    XwingMenu.mouseChoose(window);
    smallMenu.mouseChoose(window);
    back.GUImouse(window);
    spaceStation1.movin(time);

    if(click.getElapsedTime().asSeconds()>0.3)
    {
    if(basicMenu.clicked(window))
    {
        bGameGui=false;
        bGame=true;
        bSettings=false;
        bShop=false;
        bGameChoose=false;
        bGameOver=false;
        ship.setings(true,1);
        ammunition1.setup(1);
        ammunition2.setup(1);
        shootDelay=0.25;
        standardShootDelay=0.25;
        bulletX1=20;
        bulletX2=25;
        click.restart();
        comets.restart();
        boostClock.restart();
    }
    if(smallMenu.clicked(window))
    {
        bGameGui=false;
        bGame=true;
        bSettings=false;
        bShop=false;
        bGameChoose=false;
        bGameOver=false;
        ship.setings(true,2);
        ammunition1.setup(2);
        ammunition2.setup(2);
        shootDelay=0.2;
        standardShootDelay=0.2;
        bulletX1=16;
        bulletX2=23;
        click.restart();
        comets.restart();
        boostClock.restart();
    }
    if(XwingMenu.clicked(window))
    {
        bGameGui=false;
        bGame=true;
        bSettings=false;
        bShop=false;
        bGameChoose=false;
        bGameOver=false;
        ship.setings(true,3);
        ammunition1.setup(3);
        ammunition2.setup(3);
        shootDelay=0.3;
        standardShootDelay=0.3;
        bulletX1=55;
        bulletX2=60;
        click.restart();
        comets.restart();
        boostClock.restart();
    }
    if(back.clicked(window))
    {
        bGameGui=true;
        bGame=false;
        bSettings=false;
        bShop=false;
        bGameChoose=false;
        bGameOver=false;
        click.restart();
    }}
}

void GameLoop::Game(const sf::Time &time,text &hpStatus,text &hp,text &pointsStatus,text &points,text &gameOver,text &back,text &restart)
{
    if(ship.hpStatus()>0)
    {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&shoot.getElapsedTime().asSeconds()>=shootDelay)
    {
        sf::FloatRect rect=ship.getGlobalBounds();
        ammunition1.setPosition(rect.left+bulletX1,rect.top);
        ammunition2.setPosition(rect.left+rect.width-bulletX2,rect.top);
        ammunitions.push_back(ammunition1);
        ammunitions.push_back(ammunition2);
        shoot.restart();
    }
    ship.control(time);

    for(size_t i=0;i<meteors.size();i++)
    {
        if(comets.getElapsedTime().asSeconds()>=(i+1)*0.1)
        {
        meteors[i].movin(rand(),time);
        }
    }
    for(size_t i=0;i<meteors.size();i++)
    {
        for(size_t j=0;j<meteors.size();j++)
        {
            if(i!=j)
            {
                meteors[i].meteorCol(rand(),meteors[j].getGlobalBounds());
            }
        }
    }

    if(ammunitions.size()>0)
    {
    for(auto &ammo:ammunitions)
    {
        for(auto &meteor:meteors)
        {
            sf::FloatRect meteorRect=meteor.getGlobalBounds(),ammoRect=ammo.getGlobalBounds();
            if(meteor.bulletCol(rand(),ammoRect))
            {
                shipPoints+=10;
            }
            ammo.meteorCol(meteorRect);
        }

        ammo.move(0,-200*time.asSeconds());
    }
        if(ammunitions[0].getGlobalBounds().top+ammunitions[0].getGlobalBounds().height<=0)
        {
            ammunitions.erase(ammunitions.begin());
        }
    }
    //HP i punkty
    for(auto &meteor:meteors)
    {
        ship.hpControl(meteor.getGlobalBounds());
        meteor.shipCol(rand(),ship.getGlobalBounds());
    }
    hpStatus.setString(std::to_string(ship.hpStatus()));
    points.setString(std::to_string(shipPoints));
    if(shipPoints>99999)
    {
        shipPoints=99999;
    }
    int effect=boosted.collected(ship.getGlobalBounds(),boostClock);
    ship.effects(effect,shipPoints,shootDelay,cEffect);
    if(standardShootDelay!=shootDelay&&cEffect.getElapsedTime().asSeconds()>=2.5)
    {
        shootDelay=standardShootDelay;
    }
    boosted.movin(boostClock,time);
    }
    //Rysowanie
    for(const auto &meteor:meteors)
    {
        window.draw(meteor);
    }
    window.draw(hp);
    window.draw(hpStatus);
    window.draw(pointsStatus);
    window.draw(points);
    window.draw(ship);
    window.draw(boosted);
    if(ammunitions.size()>0)
    {
        for(const auto &ammo:ammunitions)
        {
            window.draw(ammo);

        }
    }
    //GAME OVER MODE
    if(ship.hpStatus()<=0)
    {
            window.draw(gameOver);
            window.draw(back);
            window.draw(restart);
            restart.GUImouse(window);
            back.GUImouse(window);
            if(back.clicked(window))
            {
                bGameGui=false;
                bGame=true;
                bSettings=false;
                bShop=false;
                bGameChoose=true;
                bGameOver=false;
                shipPoints=0;
                ammunitions.clear();
                for(auto &meteor:meteors)
                {
                    meteor.restartGame(rand());
                }
                click.restart();
            }
            if(restart.clicked(window))
            {
                bGameGui=false;
                bGame=true;
                bSettings=false;
                bShop=false;
                bGameChoose=false;
                bGameOver=false;
                shipPoints=0;
                ship.setMaxHP();
                ammunitions.clear();
                for(auto &meteor:meteors)
                {
                    meteor.restartGame(rand());
                }
                click.restart();
                boostClock.restart();
            }
    }
}


void GameLoop::Shop()
{
    if(bShop==true)
    {

    }
}

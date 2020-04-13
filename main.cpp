#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipes.h"
#include <bits/stdc++.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Flappy Bird");
    window.setFramerateLimit(360);

    sf::Texture t;
    t.loadFromFile("Images//background.png");
    sf::Sprite background(t);

    Bird bird;
    Pipe first, second, third;
    second.setX(first.getX() + 500);
    third.setX(first.getX() + 1000);

    sf::Clock delay2;
    //int frame_counter = 0; float fps_counter; sf::Clock delay;

    while (window.isOpen())
    {
        window.clear();
        window.draw(background);
        bird.draw(window);
        for (auto i : { &first,&second,&third }) i->draw(window);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    bird.jump();
                    bird.draw(window);
                }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::R)
                {
                    //for (auto i : { &first,&second,&third }) i->reset();
                    bird.reset(); //default
                }
            }
        }

        if (delay2.getElapsedTime().asSeconds() > 0.005) //  1/0.005 = 200 fps for the bird
            {
                bird.fall(); //updates bird position
                delay2.restart();
            }


        for (auto i : { &first,&second,&third }) i->move();

        window.display();
    }


    return 0;
}

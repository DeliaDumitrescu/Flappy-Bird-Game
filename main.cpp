#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipes.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Flappy Bird");
    window.setFramerateLimit(360);

    sf::Texture t; t.loadFromFile("Images\\background.png"); sf::Sprite background(t);

    Bird bird;
    Pipe first, second, third;
    second.setX(first.getX() + 500);
    third.setX(first.getX() + 1000);

    while (window.isOpen())
    {
        window.clear();
        window.draw(background);
        for (auto i : { &first,&second,&third }) i->draw(window);
 
        window.draw(bird.get_sprite());
        window.display();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

        }
        for (auto i : { &first,&second,&third }) i->move();
    }




    return 0;
}
#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipes.h"
#include "Collision.h"
#include "Score.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Flappy Bird");
    window.setFramerateLimit(360);

    sf::Texture t;
    t.loadFromFile("images//background.png");
    sf::Sprite background(t);

    sf::Text gameOver;
    sf::Font f;
    f.loadFromFile("fonts//Flappy-Bird.ttf");
    gameOver.setFont(f);
    gameOver.setPosition(140, 300);
    gameOver.setOutlineThickness(3);
    gameOver.setCharacterSize(60);
    gameOver.setString("Game Over! Press R for RESTART.");

    Bird bird;
    Pipe first, second, third;
    second.setX(first.getX() + 500);
    third.setX(first.getX() + 1000);
    Score score;

    sf::Clock delay;
    bool started = 0;

    Collision objects(bird, first, second, third, score);

    while (window.isOpen())
    {
        objects.isCollide();
        objects.update();
        if (bird.getY() > 700) bird.die();

        window.clear();
        window.draw(background);
        bird.draw(window);
        for (auto i : { &first,&second,&third }) i->draw(window);
        score.draw(window);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    started = 1;
                    bird.jump();
                    bird.draw(window);
                }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::R)
                {
                    for (auto i : { &first,&second,&third }) i->reset();
                    bird.reset(); //default
                    started = 0;
                    score.resetValue();
                }
            }
        }

        if (bird.isAlive())
        {
            if(started)
            {   if (delay.getElapsedTime().asSeconds() > 0.005) //  1/0.005 = 200 fps for the bird
                {
                    bird.fall(); //updates bird position
                    delay.restart();
                }
            for (auto i : { &first,&second,&third }) i->move();
            }
        }
        else
        {
            window.draw(gameOver);
        }

        window.display();
    }


    return 0;
}
